#include <functional>

#include <gtest/gtest.h>

#include <dma/base/Guard.hpp>
#include <dma/base/GuardedCallback.hpp>

class CClassUnderTest
{};

class Test_CClassUnderTest : public ::testing::Test
{
protected:
    void SetUp()
    {}
    void TearDown()
    {}
};

TEST_F(Test_CClassUnderTest, test_guarded_base)
{
    DMA::tGuarded* pGuarded = new DMA::tGuarded();
    auto guard = pGuarded->getGuard();
    ASSERT_EQ(guard.isAlive(), true);

    delete pGuarded;
    ASSERT_EQ(guard.isAlive(), false);
}

class CIntModifier : public DMA::tCallbackGuardian
{
public:
    typedef std::function<void(void)> tCallback;

    CIntModifier(): mInteger(0)
    {}

    const int& getInteger()
    {
        return mInteger;
    }

    tCallback getIntModificationCallback(DMA::tExpiredCallback expiredCallback)
    {
        return guardCallback([this]()
        {
            mInteger = 10;
        }, expiredCallback);
    }

private:
    int mInteger;
};

TEST_F(Test_CClassUnderTest, test_guarded_callback)
{
    CIntModifier* pIntModifier = new CIntModifier();

    ASSERT_EQ(pIntModifier->getInteger(), 0);

    {
        auto callbackExpiredNotExpected = []()
        {
            FAIL() << "callbacExpiredNotExpected call not expected!";
        };

        auto callback = pIntModifier->getIntModificationCallback(callbackExpiredNotExpected);
        ASSERT_EQ(static_cast<bool>(callback), true);
        callback();
        ASSERT_EQ(pIntModifier->getInteger(), 10);
    }

    {
        bool bExpiredCallbackCalled = false;

        auto callbackExpiredExpected = [&bExpiredCallbackCalled]()
        {
            bExpiredCallbackCalled = true;
        };

        auto callback = pIntModifier->getIntModificationCallback(callbackExpiredExpected);

        delete pIntModifier;

        ASSERT_EQ(static_cast<bool>(callback), true);
        callback();
        ASSERT_EQ(bExpiredCallbackCalled, true);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
