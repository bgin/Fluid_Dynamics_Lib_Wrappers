
#ifndef _FDLIBCPPWRAPPER_UTILS_H_
#define _FDLIBCPPWRAPPER_UTILS_H_
#include <iostream>
#include <tchar.h>
#include <vector>
#include <time.h>
#include <random>
#include <Windows.h>
#include <timeapi.h>
#pragma comment(lib, "Winmm")
namespace fdlibcppwrapper
{

	class FdlibCPPWrappUtils

	{
	public:

		static void debug_print(const char *);

		static void random_fill(std::vector<double>&, const double, const double);

		static void random_fill(std::vector<double>&, const int, const int);

		
		static double get_epsilon();

		static float get_epsilon_flt();

		static unsigned long long get_cpu_freq();

		static bool set_cpu_affinity_mask(const unsigned int);
	};

	
}
#endif