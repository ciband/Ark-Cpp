#include "gtest/gtest.h"

#include "models/fees.h"

TEST(Fees, construct_fees) {
    ARK::Fees fees(
        "10000000",
        "100000000",
        "500000000",
        "2500000000",
        "500000000"
    );

	ASSERT_STREQ("10000000", fees.send().arktoshi());
	ASSERT_STREQ("100000000", fees.vote().arktoshi());
	ASSERT_STREQ("500000000", fees.delegate().arktoshi());
	ASSERT_STREQ("2500000000", fees.second_signature().arktoshi());
	ASSERT_STREQ("500000000", fees.multi_signature().arktoshi());
}