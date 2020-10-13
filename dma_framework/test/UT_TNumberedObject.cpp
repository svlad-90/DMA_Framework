#include <gtest/gtest.h>

#include <thread>

#include <base/TNumberedObject.hpp>

#include "DMA_Plantuml.hpp"

class CClassUnderTest : public DMA::TNumberedObject<CClassUnderTest>
{};

class CZeroID : public DMA::TNumberedObject<CZeroID>
{};


class Test_CClassUnderTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        DMA::PlantUML::Creator::getInstance().initialize();
    }
    void TearDown()
    {}
};

TEST_F(Test_CClassUnderTest, base_test_1)
{
    auto currentObjectIDCounter = CClassUnderTest::getObjectIDCounter();
    DMA::tObjectID objectsCounter = 0;

    CClassUnderTest item_1;
    CClassUnderTest item_2;
    CClassUnderTest item_3;
    CClassUnderTest item_4;
    CClassUnderTest item_5;

    ASSERT_EQ(item_1.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_2.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_3.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_4.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_5.getObjectID(), currentObjectIDCounter + ++objectsCounter);

    ASSERT_EQ(CZeroID::getObjectIDCounter(), DMA::INVALID_OBJECT_ID);
}

TEST_F(Test_CClassUnderTest, base_test_2)
{
    auto currentObjectIDCounter = CClassUnderTest::getObjectIDCounter();
    DMA::tObjectID objectsCounter = 0;

    CClassUnderTest item_1;
    CClassUnderTest item_2;
    CClassUnderTest item_3;
    CClassUnderTest item_4;
    CClassUnderTest item_5;

    ASSERT_EQ(item_1.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_2.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_3.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_4.getObjectID(), currentObjectIDCounter + ++objectsCounter);
    ASSERT_EQ(item_5.getObjectID(), currentObjectIDCounter + ++objectsCounter);

    ASSERT_EQ(CZeroID::getObjectIDCounter(), DMA::INVALID_OBJECT_ID);
}

TEST_F(Test_CClassUnderTest, base_test_multi_threading)
{
    DMA::tObjectID number_of_threads = 10;
    DMA::tObjectID number_of_iterations = 100;
    auto currentObjectIDCounter = CClassUnderTest::getObjectIDCounter();

    auto threadFunc = [number_of_iterations]()
    {
        for(decltype(number_of_iterations) i = 0; i < number_of_iterations; ++i)
        {
            CClassUnderTest item;
        }
    };

    typedef std::shared_ptr<std::thread> tThreadPtr;
    typedef std::vector<tThreadPtr> tThreadPtrVec;

    tThreadPtrVec threadVec;

    for(decltype(number_of_threads) i = 0; i < number_of_threads; ++i)
    {
        threadVec.push_back( std::make_shared<std::thread>(threadFunc) );
    }

    for(auto pThread : threadVec)
    {
        if(nullptr != pThread)
        {
            pThread->join();
        }
    }

    ASSERT_EQ(CClassUnderTest::getObjectIDCounter(), currentObjectIDCounter + ( number_of_threads * number_of_iterations ) );

    ASSERT_EQ(CZeroID::getObjectIDCounter(), DMA::INVALID_OBJECT_ID);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
