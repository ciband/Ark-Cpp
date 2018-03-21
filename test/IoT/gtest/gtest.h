#ifndef __GTEST_H__
#define __GTEST_H__

#include <ArduinoUnit.h>

#define TEST(category, name) test(category##__##name)

#define ASSERT_EQ assertEqual
#define ASSERT_NE assertNotEqual
#define ASSERT_STREQ assertEqual
#define ASSERT_STRNE assertNotEqual
#define ASSERT_TRUE(x) assertNotEqual(x, 0)
#define ASSERT_FALSE(x) assertEqual(x, 0)

#endif
