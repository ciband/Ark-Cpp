#include "gtest/gtest.h"

#include "api/api.h"

TEST(api, test_peers_get) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const auto peer = _arkManager.peer("167.114.29.55", 4002);
	ASSERT_STREQ("167.114.29.55", peer.ip());
	ASSERT_EQ(4002, peer.port());
	ASSERT_STREQ("1.1.1", peer.version());
	ASSERT_EQ(0, peer.errors());
	ASSERT_STREQ("linux4.4.0-79-generic", peer.os());
	ASSERT_STRNE("0", peer.height());
	ASSERT_STREQ("OK", peer.status());
	ASSERT_NE(0, peer.delay());
}

TEST(api, test_peers) {
	// TODO
}

TEST(api, test_peers_version) {
	const auto version = _arkManager.peerVersion();
	ASSERT_STREQ("1.1.1", version.version());
	ASSERT_STREQ("", version.build());
}
