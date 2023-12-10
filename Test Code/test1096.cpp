#include <cppunit/extensions/HelperMacros.h>

class YourTestClass : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(YourTestClass);
    CPPUNIT_TEST(testInitializationExceptionOnInvalidLiquidMass);
    CPPUNIT_TEST(testInitializationExceptionOnInvalidReferenceSpeed);
    CPPUNIT_TEST_SUITE_END();

public:
    void testInitializationExceptionOnInvalidLiquidMass() {
        tConfigData->mMaxLiquidMass = DBL_EPSILON;
        CPPUNIT_ASSERT_THROW(tArticle->initialize(*tConfigData, *tInputData, tLinks, tPort0, tPort1),
                             TsInitializationException);
    }

    void testInitializationExceptionOnInvalidReferenceSpeed() {
        // Set up the invalid reference speed in tConfigData
        // ...

        CPPUNIT_ASSERT_THROW(tArticle->initialize(*tConfigData, *tInputData, tLinks, tPort0, tPort1),
                             TsInitializationException);
    }

    // Other test cases for valid initialization can be added here
};
