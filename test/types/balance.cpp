#include "types/balance.h"

#include "gtest/gtest.h"

TEST(balance, construct_balance) {
    Balance balance("12984403000000000");
	ASSERT_STREQ("129844030.00000000", balance.ark());
	ASSERT_STREQ("12984403000000000", balance.arktoshi());
    
	Balance balance2("100000000");
	ASSERT_STREQ("1.00000000", balance2.ark());
	ASSERT_STREQ("100000000", balance2.arktoshi());
    
    Balance balance3("10000000");
	ASSERT_STREQ(".10000000", balance3.ark());
	ASSERT_STREQ("10000000", balance3.arktoshi());

    Balance balance4("10000");
	ASSERT_STREQ(".00010000", balance4.ark());
	ASSERT_STREQ("10000", balance4.arktoshi());
}