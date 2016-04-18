
#include "fdlibcppwrapper_utils.h"

double fdlibcppwrapper::FdlibCPPWrappUtils::get_epsilon()
{
	return std::numeric_limits<double>::epsilon();
}

float fdlibcppwrapper::FdlibCPPWrappUtils::get_epsilon_flt()
{
	return std::numeric_limits<float>::epsilon();
}

void fdlibcppwrapper::FdlibCPPWrappUtils::debug_print(const char* msg)
{
	std::cout << "Message #:" << msg << "in File #:" <<  __FILE__ << "in Function #:" << __FUNCTIONW__ <<
		"at Line Of Code #:" << __LINE__ << std::endl;
	
	
}

void fdlibcppwrapper::FdlibCPPWrappUtils::random_fill(std::vector<double>& values, const double lo_bound, const double up_bound)
{
#if defined (_DEBUG)
	_ASSERTE(fabs(up_bound - lo_bound) > fdlibcppwrapper::FdlibCPPWrappUtils::get_epsilon());
#else
	if(fabs(up_bound - lo_bound) <= fdlibcppwrapper::FdlibCPPWrapUtils::get_epsilon())
	{
		throw std::runtime_error(std::basic_string<TCHAR>("ERROR in FdlibCPPWrapper::random_fill() - bounds are less than epsilon\n"))
	}
#endif
	
	size_t seed(clock());
	std::default_random_engine engine(seed);
	std::uniform_real_distribution<double> distro{ lo_bound, up_bound };
	//std::cauchy_distribution<double> cauchy_distr( 0.0, 1.0 );
	//cauchy_distr.operator()(engine);
	for (auto &elems : values)
		elems = distro(engine);
	
}

void fdlibcppwrapper::FdlibCPPWrappUtils::random_fill( std::vector<double>& values, const int range_min, const int range_max)
{
#if defined (_DEBUG)
	_ASSERTE(range_min < range_max);
#else
	if(range_min >= range_max)
	{
		throw std::runtime_error(std::basic_string<TCHAR>("ERROR in FdlibCppWrapper::random_fill() - range_max is less than range_min\n"));
	}
#endif
	auto N = values.size();
	auto M = values.size();
#if defined (__INTEL_COMPILER)

	unsigned int status = 0xFFFFFFFF;
	constexpr  unsigned	long long MAX_VALUE = 4294967295ULL * 100;
	constexpr double INV_RAND_MAX = static_cast<double>(((double)1.0 / MAX_VALUE));
	unsigned int rand = 0;
	
	for (auto i = 0; i != N; ++i)
	{
		for (auto j = 0; j != M; ++j)
		{
			status = _rdrand32_step(&rand);
			if (status == 0)
			{
				return;
			}
			else
			{
				values[j * N + i] = static_cast<double>(rand * INV_RAND_MAX) * (range_max - range_min) + range_max;
			}
			
		}
	}
#elif defined (_MSC_VER_)

	for (auto i = 0; i != N; ++i)
	{
		for (auto j = 0; j != M; ++j)
		{
			values[j * N + i] = static_cast<double>(rand() / RAND_MAX + 1) * (range_max - range_min) + range_min;
		}
	}
#endif
}

unsigned long long fdlibcppwrapper::FdlibCPPWrappUtils::get_cpu_freq()
{
	// Crude approximation of current CPU frequency. On failure return 0ULL frequency.
	// Get system clock time interval
	MMRESULT sys_clock_res = 9999;
	TIMECAPS timecaps;
	ZeroMemory(&timecaps, sizeof(timecaps));
	sys_clock_res = timeGetDevCaps(&timecaps, sizeof(timecaps));
#if defined (_DEBUG)
	printf("timeGetDevCaps returned: min clock period: %d, max clock period: %d\n", timecaps.wPeriodMin, timecaps.wPeriodMax);
#endif
	if (sys_clock_res < 0)
	{
		printf("timeGetDevCaps() failed with an error %d\n", sys_clock_res);
		return 0ULL;
	}
	
	unsigned long long ts0 = 0ULL;
	unsigned long long ts1 = 0ULL;
	ts0 = _rdtsc();
	Sleep(timecaps.wPeriodMin);
	ts1 = _rdtsc();
	// Guard against negative/wraparound value.
	if (ts1 > ts0)
		return ts1 - ts0;
	else
		return 0ULL;
}

bool fdlibcppwrapper::FdlibCPPWrappUtils::set_cpu_affinity_mask(const unsigned int mask)
{
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);
	bool b_result;
#if defined (_DEBUG)
	_ASSERTE(mask >= 0 && mask <= system_info.dwNumberOfProcessors);
#else
	if(mask < 0 || mask > system_info.dwNumberOfProcessors)
	{
		return b_result = false;
	}
#endif
	HANDLE ThHandle = ::GetCurrentThread();
	DWORD_PTR dw_result;
	dw_result = SetThreadAffinityMask(ThHandle, mask);
	if (dw_result == 0)
	{
		printf("SetThreadAffinityMask() failed with an error 0x%x\n", GetLastError());
		return b_result = false;
	}
	return b_result = true;
}