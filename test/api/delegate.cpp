#include "gtest/gtest.h"

#include "api/api.h"

TEST(delegate, test_delegate) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

	ASSERT_NE(0, _arkManager.delegatesCount());

	const auto search = _arkManager.delegateSearch("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", search.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", search.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", search.public_key().getValue());
	const auto& vote = search.vote();
	//ASSERT_STREQ("94843.95341862", vote.ark());
	//ASSERT_STREQ("9484395341862", vote.arktoshi());
	//ASSERT_EQ(40668, search.produced_blocks());
	ASSERT_NE(0, search.missed_blocks());
	  


/*  ==================================  */
//  String delegateVotersDescription = _arkManager.delegateVoters(darkPubkey).getValue();
//    Serial.println("delegateVotersDescription: ");
//    Serial.println(delegateVotersDescription);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */

/*  ==================================  */
	auto delegate = _arkManager.delegate("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	//ASSERT_STREQ("9484595341862", delegate.vote().arktoshi());
	//ASSERT_EQ(40669, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	//ASSERT_EQ(92.45f, (float)delegate.productivity());	

    delegate = _arkManager.delegate(darkPubkey.getValue());
    ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	//ASSERT_STREQ("9484595341862", delegate.vote().arktoshi());
	//ASSERT_EQ(40669, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	//ASSERT_EQ(92.45f, (float)delegate.productivity());	

/*  ==================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */

/*  ==================================  */
	//TODO:  fails here
	const auto delegateFee = _arkManager.delegateFee();
	ASSERT_STREQ("25.00000000", delegateFee.ark());
	ASSERT_STREQ("2500000000", delegateFee.arktoshi());

	const auto forged_by_account = _arkManager.delegateForgedByAccount(darkPubkey);
	//ASSERT_STREQ("536.50000000", forged_by_account.fees().ark());
	//ASSERT_STREQ("53650000000", forged_by_account.fees().arktoshi());
	//ASSERT_STREQ("81876.50000000", forged_by_account.forged().ark());
	//ASSERT_STREQ("8187650000000", forged_by_account.forged().arktoshi());
	//ASSERT_STREQ("81340.00000000", forged_by_account.rewards().ark());
	//ASSERT_STREQ("8134000000000", forged_by_account.rewards().arktoshi());
	
	const auto next_forgers = _arkManager.delegateNextForgers();
	//ASSERT_STREQ("2679048", next_forgers.current_block());
	//ASSERT_STREQ("3674254", next_forgers.current_slot());
	//ASSERT_STREQ("", next_forgers.delegates().getValue());  //TODO: compare std::array
}
