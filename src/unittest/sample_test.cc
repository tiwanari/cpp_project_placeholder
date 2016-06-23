#include <gtest/gtest.h>
// add your the path for target class
// #include "../sample.h"

class SampleTest : public ::testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(SampleTest, doSomething)
{
    // initialize your class
    // Sample sample(arg0);
    // or
    // Sample *sample = new Sample(arg0);
    // etc.

    // do test whatever you want
    // ASSERT_TRUE(sample.valid());
    ASSERT_EQ(2, 1+1);
    ASSERT_TRUE(true);
}
