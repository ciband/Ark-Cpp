#include "types/hash.h"

#include "gtest/gtest.h"

TEST(hash, construct_hash) {
	Hash hash("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23");
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", hash.getValue());
}