#include "gtest/gtest.h"

#include "models/account.h"

TEST(model, construct_account)
{
	// Hash msigArray[] = { Hash("") };
	// Hash u_msigArray[] = { Hash("") };
	ARK::Account account(
		"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
		"100000000",//Balance("100000000"),
		"100000000", //Balance("100000000"),
		"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", //Publickey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"),
		0,
		0,
		""//, //Publickey(),
		// msigArray, //Hash[],
		// u_msigArray //Hash[]()
	);

	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", account.address().getValue());
	ASSERT_STREQ("100000000", account.unconfirmed_balance().arktoshi());
	ASSERT_STREQ("100000000", account.balance().arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", account.public_key().getValue());
	ASSERT_EQ(0, account.unconfirmed_signature());
	ASSERT_EQ(0, account.second_signature());
	ASSERT_STREQ("", account.second_public_key().getValue());
// 	ASSERT_STREQ("", account.multi_signatures().getValue());
// 	ASSERT_STREQ("", account.u_multi_signatures().getValue());
}
