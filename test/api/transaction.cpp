#include "gtest/gtest.h"

#include "api/api.h"

TEST(transaction, test_transaction) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const Hash transactionID("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e");
	const auto transaction = _arkManager.transaction(transactionID);
	ASSERT_STREQ("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e", transaction.id());
	ASSERT_STREQ("6571939080722822408", transaction.block_id());
	ASSERT_STREQ("1696504", transaction.height());
	ASSERT_EQ(0, transaction.type());
	ASSERT_STREQ("19637685", transaction.timestamp());
	ASSERT_STREQ("149", transaction.amount().arktoshi());
	ASSERT_STREQ("10000000", transaction.fee().arktoshi());
	ASSERT_STREQ("1ARK-GOLang is saying whoop whooop", transaction.vendor_field());
	ASSERT_STREQ("DPJBH7wfE1msZMVDQLeJUPi31fJZodJCkU", transaction.sender_id().getValue());
	ASSERT_STREQ("DFTzLwEHKKn3VGce6vZSueEmoPWpEZswhB", transaction.recipient_id().getValue());
	ASSERT_STREQ("03a151b47a5779949a47dd9c17e05c832304721a242b535f36528cd7e547dac439", transaction.sender_publickey().getValue());
	ASSERT_STREQ("3045022100dc9590c6c6fce66a523481f13237d95518056387076de9a9534cb4a039fbede90220322e7f17b227f8fe9401460980b7b3c1baacf076b9020620ec5c4388673e7e12", transaction.signature());
	//ASSERT_STREQ("1002545", transaction.confirmations());


	/*  ==================================  */
	/*  ==================================  */
	/*    BROKEN: fix for large callbacks  */
	/*    Peers callback is ~28,908 bytes  */
	//  String transactions = _arkManager.transactions();
	//    Serial.println("transactions: ");
	//    Serial.println(transactions);
	//    Serial.println("\n=====\n");
	//    delay(50);
	/*  ==================================  */
	/*  ==================================  */

	/*  ==================================  */
	//ASSERT_STREQ("There are currently No unconfirmed transactions by that transactionID", _arkManager.transactionUnconfirmed(transactionID).c_str());
	//ASSERT_STREQ("There are currently No Unconfirmed Transactions", _arkManager.transactionsUnconfirmed().c_str());
}
