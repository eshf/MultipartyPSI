<<<<<<< HEAD
#include "stdafx.h"
#ifdef  _MSC_VER
#include "CppUnitTest.h"

#include "ShamirSSScheme_Tests.h"

#include "Common.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace osuCrypto_tests
{
    TEST_CLASS(ShamirSSScheme_Tests)
    {
    public:
        TEST_METHOD(ShamirSSScheme_TestVS)
        {
            InitDebugPrinting();

            ShamirSSScheme_Test(); 
        }


    };
}
#endif
=======
#include "stdafx.h"
#ifdef  _MSC_VER
#include "CppUnitTest.h"

#include "ShamirSSScheme_Tests.h"

#include "Common.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace osuCrypto_tests
{
    TEST_CLASS(ShamirSSScheme_Tests)
    {
    public:
        TEST_METHOD(ShamirSSScheme_TestVS)
        {
            InitDebugPrinting();

            ShamirSSScheme_Test(); 
        }


    };
}
#endif
>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
