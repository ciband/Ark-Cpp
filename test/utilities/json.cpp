#include "gtest/gtest.h"

#include "utilities/json.h"

// Acount
TEST(json, accounts_getBalance) {
	const auto json_str = 
		"{"
		"\"success\": true,"
		"\"balance\": 55,"
		"\"unconfirmedBalance\": 66"
		"}"
	;
	auto balances = ARK::Utilities::get_json_interface().accounts_getBalance_fromJSON(json_str);
	ASSERT_STREQ(".00000055", balances.confirmed().ark());
	ASSERT_STREQ("55", balances.confirmed().arktoshi());
	ASSERT_STREQ(".00000066", balances.unconfirmed().ark());
	ASSERT_STREQ("66", balances.unconfirmed().arktoshi());
}

TEST(json, accounts_getPublickey) {
}

TEST(json, accounts_delegates_fee) {
}

TEST(json, accounts_delegates) {
}
TEST(json, accounts) {
}
TEST(json, accounts_top) {
}

// Block
TEST(json, blocks_get) {
}

TEST(json, blocks) {
}

TEST(json, blocks_getEpoch) {
}

TEST(json, blocks_getHeight) {
}

TEST(json, blocks_GetNethash) {
}

TEST(json, blocks_getFee) {
}

TEST(json, blocks_getFees) {
}

TEST(json, blocks_getMilestone) {
}

TEST(json, blocks_getReward) {
}

TEST(json, blocks_getSupply) {
}

TEST(json, blocks_getStatus) {
}

// Delegate

TEST(json, delegates_count) {
}

TEST(json, delegates_search) {
}

TEST(json, delegates_voters) {
}

TEST(json, delegates_get) {
}

TEST(json, delegates) {
}

TEST(json, delegates_fee) {
}

TEST(json, delegates_forging_getForgedByAccount) {
}

TEST(json, delegates_getNextForgers) {
}

// Loader
TEST(json, loader_status) {
}

TEST(json, loader_status_sync) {
}

TEST(json, loader_autoconfigure) {
}

// MultiSignature
TEST(json, multisignatures_pending) {
}

TEST(json, multisignatures_accounts) {
}

// Peer
TEST(json, peers_get) {
}

TEST(json, peers) {
}

TEST(json, peers_version) {
}

// Signature
TEST(json, signatures_fee) {
}

// Transaction
TEST(json, transactions_get) {
}

TEST(json, transactions) {
}

TEST(json, transactions_unconfired_get) {
}

TEST(json, transactions_unconfirmed) {
}

// Transport
TEST(json, peer_list) {
}

TEST(json, peer_blocks_common) {
}

TEST(json, peer_block) {
}

TEST(json, peer_blocks) {
}

TEST(json, peer_transactions) {
}

// TODO? POST /peer/transactions

TEST(json, peer_transactionsFromIds) {
}

TEST(json, peer_height) {
}

TEST(json, peer_status) {
}
