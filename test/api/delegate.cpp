#include "gtest/gtest.h"

#include "api/api.h"

namespace {

const Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

}

TEST(api, test_delegates_count) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	ASSERT_NE(0, _arkManager.delegatesCount());
}

TEST(api, test_delegates_search) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);
	const auto search = _arkManager.delegateSearch("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", search[0].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", search[0].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", search[0].public_key().getValue());
	const auto& vote = search[0].vote();
	ASSERT_STRNE("0.0", vote.ark());
	ASSERT_STRNE("0", vote.arktoshi());
	ASSERT_NE(0, search[0].produced_blocks());
	ASSERT_NE(0, search[0].missed_blocks());
}

TEST(api, test_delegate_voters) {
	// TODO
}

TEST(api, test_delegate_user) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	auto delegate = _arkManager.delegate("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	ASSERT_STRNE("0", delegate.vote().arktoshi());
	ASSERT_NE(0, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	ASSERT_NE(0.0, delegate.productivity());	
}

TEST(api, test_delegate_pub_key) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);
    auto delegate = _arkManager.delegate(darkPubkey.getValue());
    ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	ASSERT_STRNE("0", delegate.vote().arktoshi());
	ASSERT_NE(0, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	ASSERT_NE(0.0, delegate.productivity());	
}

TEST(api, test_delegates) {
	// TODO
}

TEST(api, test_delegate_fee) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);
	const auto delegateFee = _arkManager.delegateFee();
	ASSERT_STREQ("25.00000000", delegateFee.ark());
	ASSERT_STREQ("2500000000", delegateFee.arktoshi());
}

TEST(api, test_delegate_forged_by_account) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);
	const auto forged_by_account = _arkManager.delegateForgedByAccount(darkPubkey);
	ASSERT_STRNE("0.0", forged_by_account.fees().ark());
	ASSERT_STRNE("0", forged_by_account.fees().arktoshi());
	ASSERT_STRNE("0.0", forged_by_account.forged().ark());
	ASSERT_STRNE("0", forged_by_account.forged().arktoshi());
	ASSERT_STRNE("0.0", forged_by_account.rewards().ark());
	ASSERT_STRNE("0", forged_by_account.rewards().arktoshi());
}

TEST(api, test_delegate_next_forgers) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);
	const auto next_forgers = _arkManager.delegateNextForgers();
	ASSERT_STRNE("0", next_forgers.current_block());
	ASSERT_STRNE("0", next_forgers.current_slot());
	//ASSERT_STREQ("", next_forgers.delegates().getValue());  //TODO: compare std::array
}
