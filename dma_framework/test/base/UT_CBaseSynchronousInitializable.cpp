#include <functional>

#include <gtest/gtest.h>

#include <dma/base/initializable/CBaseSynchronousInitializable.hpp>

static const int INIT_RETURN_CODE = 1;
static const int SHUTDOWN_RETURN_CODE = 2;

class CClassUnderTest : public DMA::CBaseSynchronousInitializable
{
protected:
    virtual DMA::tSyncInitOperationResult init() override
    {
        DMA::tSyncInitOperationResult result;
        result.returnCode = INIT_RETURN_CODE;
        result.bIsOperationSuccessful = true;
        return result;
    }

    virtual DMA::tSyncInitOperationResult shutdown() override
    {
        DMA::tSyncInitOperationResult result;
        result.returnCode = SHUTDOWN_RETURN_CODE;
        result.bIsOperationSuccessful = true;
        return result;
    }
};

class Test_CClassUnderTest : public ::testing::Test
{
protected:
    void SetUp()
    {}
    void TearDown()
    {}
};

TEST_F(Test_CClassUnderTest, test_init)
{
    CClassUnderTest classUnderTest;

    auto initResult = classUnderTest.startInit();

    ASSERT_EQ(initResult.bIsOperationSuccessful, true);
    ASSERT_EQ(initResult.returnCode, INIT_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), true);
}

TEST_F(Test_CClassUnderTest, test_repetitive_init)
{
    CClassUnderTest classUnderTest;

    auto initResult = classUnderTest.startInit();

    ASSERT_EQ(initResult.bIsOperationSuccessful, true);
    ASSERT_EQ(initResult.returnCode, INIT_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), true);

    auto repetitiveInitResult = classUnderTest.startInit();

    ASSERT_EQ(repetitiveInitResult.bIsOperationSuccessful, true);
    ASSERT_EQ(repetitiveInitResult.returnCode, INIT_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), true);
}

TEST_F(Test_CClassUnderTest, test_shutdown)
{
    CClassUnderTest classUnderTest;

    auto initResult = classUnderTest.startInit();

    ASSERT_EQ(initResult.bIsOperationSuccessful, true);
    ASSERT_EQ(initResult.returnCode, INIT_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), true);

    auto shutdownResult = classUnderTest.startShutdown();

    ASSERT_EQ(shutdownResult.bIsOperationSuccessful, true);
    ASSERT_EQ(shutdownResult.returnCode, SHUTDOWN_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), false);
}

TEST_F(Test_CClassUnderTest, test_repetitive_shutdown)
{
    CClassUnderTest classUnderTest;

    auto initResult = classUnderTest.startInit();

    ASSERT_EQ(initResult.bIsOperationSuccessful, true);
    ASSERT_EQ(initResult.returnCode, INIT_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), true);

    auto shutdownResult = classUnderTest.startShutdown();

    ASSERT_EQ(shutdownResult.bIsOperationSuccessful, true);
    ASSERT_EQ(shutdownResult.returnCode, SHUTDOWN_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), false);

    auto repetitiveShutdownResult = classUnderTest.startShutdown();

    ASSERT_EQ(repetitiveShutdownResult.bIsOperationSuccessful, true);
    ASSERT_EQ(repetitiveShutdownResult.returnCode, SHUTDOWN_RETURN_CODE);

    ASSERT_EQ(classUnderTest.isInitialized(), false);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
