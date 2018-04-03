#include "gtest/gtest.h"

#include "api/api.h"

namespace {

const Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

}

TEST(api, test_account_balance) {
	ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);	

	const auto account_balance = arkManager.accountBalance(darkAddress);
	ASSERT_STRNE("0.0", account_balance.confirmed().ark());
	ASSERT_STRNE("0", account_balance.confirmed().arktoshi());
	ASSERT_STRNE("0.0", account_balance.unconfirmed().ark());
	ASSERT_STRNE("0", account_balance.unconfirmed().arktoshi());
}

TEST(api, test_account_public_key) {
	ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);	
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", arkManager.accountPublickey(darkAddress).getValue());
}

TEST(api, test_account_delegates_fee) {
	ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);	
	const auto delegates_fee = arkManager.accountDelegatesFee(darkAddress);
	ASSERT_STREQ("25.00000000", delegates_fee.ark());
	ASSERT_STREQ("2500000000", delegates_fee.arktoshi());
}

TEST(api, test_account_delegates) {
	ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);	
	const auto delegate = arkManager.accountDelegates(darkAddress);

	ASSERT_STREQ("sleepdeficit", delegate[0].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate[0].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate[0].public_key().getValue());
	const auto& vote = delegate[0].vote();
	ASSERT_STRNE("0.0", vote.ark());
	ASSERT_STRNE("0", vote.arktoshi());
	ASSERT_NE(0, delegate[0].produced_blocks());
	ASSERT_NE(0, delegate[0].missed_blocks());
	ASSERT_NE(0, delegate[0].rate());
	ASSERT_NE(0.0, delegate[0].approval());
	ASSERT_NE(0.0, delegate[0].productivity());
}

TEST(api, test_account) {
	ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);	
	const auto account = arkManager.account(darkAddress);
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", account[0].address().getValue());
	const auto& unconfirmed_balance = account[0].unconfirmed_balance();
	ASSERT_STRNE("0.0", unconfirmed_balance.ark());
	ASSERT_STRNE("0", unconfirmed_balance.arktoshi());
	const auto& balance = account[0].balance();
	ASSERT_STRNE("0.0", balance.ark());
	ASSERT_STRNE("0", balance.arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", account[0].public_key().getValue());
	ASSERT_EQ(1, account[0].unconfirmed_signature());
	ASSERT_EQ(1, account[0].second_signature());
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", account[0].second_public_key().getValue());
	ASSERT_STREQ("[]", account[0].multi_signatures().getValue());
	ASSERT_STREQ("[]", account[0].u_multi_signatures().getValue());
}

TEST(api, test_account_top) {
	//TODO
}
