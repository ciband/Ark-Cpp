#include "gtest/gtest.h"

#include "api/api.h"

TEST(peer, test_peer) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const auto peer = _arkManager.peer("167.114.29.55", 4002);
	ASSERT_STREQ("167.114.29.55", peer.ip());
	ASSERT_EQ(4002, peer.port());
	ASSERT_STREQ("1.1.1", peer.version());
	ASSERT_EQ(0, peer.errors());
	ASSERT_STREQ("linux4.4.0-79-generic", peer.os());
	//ASSERT_STREQ("2679148", peer.height());
	ASSERT_STREQ("OK", peer.status());
	//ASSERT_EQ(22, peer.delay());


	/*  ==================================  */
	/*  ==================================  */
	/*    BROKEN: fix for large callbacks  */
	/*    Peers callback is ~10,000 bytes  */
	//  String peersDescription = _arkManager.peers().getValue();
	//    Serial.println("peersDescription: ");
	//    Serial.println(peersDescription);
	//    Serial.println("\n=====\n");
	//    delay(50);
	/*  ==================================  */
	/*  ==================================  */

	/*  ==================================  */
	const auto version = _arkManager.peerVersion();
	ASSERT_STREQ("1.1.1", version.version());
	ASSERT_STREQ("", version.build());

}
