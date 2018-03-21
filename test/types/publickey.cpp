#include "types/publickey.h"

#include "gtest/gtest.h"

TEST(publickey, construct_publickey) {
    Publickey pubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", pubkey.getValue());
}