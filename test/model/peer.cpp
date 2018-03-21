#include "gtest/gtest.h"

#include "models/peer.h"

TEST(Peer, construct_peer) {
    ARK::Peer peer(
        "167.114.29.55",
        4002,
        "1.1.1",
        0,
        "linux4.4.0-79-generic",
        "2467740",
        "OK",
        9
    );

	ASSERT_STREQ("167.114.29.55", peer.ip());
	ASSERT_EQ(4002, peer.port());
	ASSERT_STREQ("1.1.1", peer.version());
	ASSERT_EQ(0, peer.errors());
	ASSERT_STREQ("linux4.4.0-79-generic", peer.os());
	ASSERT_STREQ("2467740", peer.height());
	ASSERT_STREQ("OK", peer.status());
	ASSERT_EQ(9, peer.delay());
}