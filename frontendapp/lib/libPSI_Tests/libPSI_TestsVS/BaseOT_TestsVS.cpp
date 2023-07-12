<<<<<<< HEAD
#include "stdafx.h"
#ifdef  _MSC_VER
#include "CppUnitTest.h"
#include "BaseOT_Tests.h"
#include "Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace osuCrypto_tests
{
    TEST_CLASS(BaseOT_Tests)
    {
    public:
    
        TEST_METHOD(NaorPinkasOt_TestVS)
        {
            InitDebugPrinting();
            NaorPinkasOt_Test_Impl();
        } 

    };
}
=======
#include "stdafx.h"
#ifdef  _MSC_VER
#include "CppUnitTest.h"
#include "BaseOT_Tests.h"
#include "Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace osuCrypto_tests
{
    TEST_CLASS(BaseOT_Tests)
    {
    public:
    
        TEST_METHOD(NaorPinkasOt_TestVS)
        {
            InitDebugPrinting();
            NaorPinkasOt_Test_Impl();
        } 

    };
}
>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
#endif