#include "types/address.h"

#include "gtest/gtest.h"

TEST(address, construct_address) {
    Address address("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.getValue());
}