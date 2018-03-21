#include "gtest/gtest.h"

#include "models/voter.h"

TEST( voter, construct_voter) {
    ARK::Voter voter(
        "sleepdeficit",
        "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
        "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
        "8419145341862"
    );

	ASSERT_STREQ("sleepdeficit", voter.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", voter.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", voter.public_key().getValue());
	ASSERT_STREQ("8419145341862", voter.balance().arktoshi());
}