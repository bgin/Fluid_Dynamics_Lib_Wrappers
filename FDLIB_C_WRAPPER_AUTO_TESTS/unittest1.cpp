#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FluidDynamicLibCWrapper/CplusplusWrapper.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FDLIB_C_WRAPPER_AUTO_TESTS
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
	TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		int result = CFdlibWrapper::test_cplusplus_wrapper(10);

		}


	};
}