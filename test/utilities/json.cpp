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
	const auto json_str =
		"{"
		"\"success\": true,"
		"\"publicKey\": 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456,"
		"}"
		;
	auto public_key = ARK::Utilities::get_json_interface().accounts_getPublickey_fromJSON(json_str);
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", public_key.getValue());
}

TEST(json, accounts_delegates_fee) {
	const auto json_str =
		"{"
		"\"success\": true,"
		"\"fee\": 100,"
		"}"
		;
	auto fee = ARK::Utilities::get_json_interface().accounts_delegates_fee_fromJSON(json_str);
	ASSERT_STREQ(".00000100", fee.ark());
	ASSERT_STREQ("100", fee.arktoshi());
}

TEST(json, accounts_delegates) {
	const auto json_str = 
		"{"
			"\"success\": true,"
			"\"delegates\" : ["
				"{"
					"\"username\": sleepdeficit,"
					"\"address\" : DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA,"
					"\"publicKey\" : 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456,"
					"\"vote\" : 111,"
					"\"producedblocks\" : 7,"
					"\"missedblocks\" : 5,"
					"\"rate\" : 3,"
					"\"approval\" : 95.5,"
					"\"productivity\" : 94.4"
				"},"
				"{"
					"\"username\": ciband,"
					"\"address\" : DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB,"
					"\"publicKey\" : 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457,"
					"\"vote\" : 122,"
					"\"producedblocks\" : 8,"
					"\"missedblocks\" : 6,"
					"\"rate\" : 4,"
					"\"approval\" : 95.6,"
					"\"productivity\" : 94.5"
				"}"
			"]"
		"}"
	;
	const auto delegates = ARK::Utilities::get_json_interface().accounts_delegates_fromJSON(json_str);
	ASSERT_STREQ("sleepdeficit", delegates[0].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegates[0].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegates[0].public_key().getValue());
	const auto& vote = delegates[0].vote();
	ASSERT_STRNE("0.00000111", vote.ark());
	ASSERT_STRNE("111", vote.arktoshi());
	ASSERT_EQ(8, delegates[0].produced_blocks());
	ASSERT_EQ(6, delegates[0].missed_blocks());
	ASSERT_EQ(4, delegates[0].rate());
	ASSERT_EQ(95.6, delegates[0].approval());
	ASSERT_EQ(94.5, delegates[0].productivity());

	ASSERT_STREQ("sleepdeficit", delegates[1].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegates[1].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegates[1].public_key().getValue());
	const auto& vote1 = delegates[1].vote();
	ASSERT_STREQ("0.0", vote1.ark());
	ASSERT_STREQ("0", vote1.arktoshi());
	ASSERT_EQ(0, delegates[1].produced_blocks());
	ASSERT_EQ(0, delegates[1].missed_blocks());
	ASSERT_EQ(0, delegates[1].rate());
	ASSERT_EQ(0.0, delegates[1].approval());
	ASSERT_EQ(0.0, delegates[1].productivity());
}
TEST(json, accounts) {
	const auto json_str =
		"{"
			"\"success\": true,"
			"\"account\": ["
				"{"
					"\"address\": DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA,"
					"\"unconfirmedBalance\": 1234,"
					"\"balance\": 5678,"
					"\"publicKey\": 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456,"
					"\"unconfirmedSignature\": 1,"
					"\"secondSignature\": 1,"
					"\"secondPublicKey\": 03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869,"
					"\"multisignatures\": ["
					"null"
					"],"
					"\"u_multisignatures\": ["
					"null"
					"]"
				"},"
				"{"
					"\"address\": DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB,"
					"\"unconfirmedBalance\": 1235,"
					"\"balance\": 5679,"
					"\"publicKey\": 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457,"
					"\"unconfirmedSignature\": 2,"
					"\"secondSignature\": 2,"
					"\"secondPublicKey\": 03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2860,"
					"\"multisignatures\": ["
					"null"
					"],"
					"\"u_multisignatures\": ["
					"null"
					"]"
				"}"
			"]"
		"}"
	;

	const auto accounts = ARK::Utilities::get_json_interface().accounts_fromJSON(json_str);
	
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", accounts[0].address().getValue());
	const auto& unconfirmed_balance = accounts[0].unconfirmed_balance();
	ASSERT_STRNE(".00001234", unconfirmed_balance.ark());
	ASSERT_STRNE("1234", unconfirmed_balance.arktoshi());
	const auto& balance = accounts[0].balance();
	ASSERT_STRNE(".00005678", balance.ark());
	ASSERT_STRNE("5678", balance.arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", accounts[0].public_key().getValue());
	ASSERT_EQ(1, accounts[0].unconfirmed_signature());
	ASSERT_EQ(1, accounts[0].second_signature());
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", accounts[0].second_public_key().getValue());
	ASSERT_STREQ("[]", accounts[0].multi_signatures().getValue());
	ASSERT_STREQ("[]", accounts[0].u_multi_signatures().getValue());

	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB", accounts[1].address().getValue());
	const auto& unconfirmed_balance1 = accounts[1].unconfirmed_balance();
	ASSERT_STRNE(".00001235", unconfirmed_balance1.ark());
	ASSERT_STRNE("1235", unconfirmed_balance1.arktoshi());
	const auto& balance1 = accounts[1].balance();
	ASSERT_STRNE(".00005679", balance1.ark());
	ASSERT_STRNE("5679", balance1.arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457", accounts[1].public_key().getValue());
	ASSERT_EQ(1, accounts[1].unconfirmed_signature());
	ASSERT_EQ(1, accounts[1].second_signature());
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2860", accounts[1].second_public_key().getValue());
	ASSERT_STREQ("[]", accounts[1].multi_signatures().getValue());
	ASSERT_STREQ("[]", accounts[1].u_multi_signatures().getValue());
}
TEST(json, accounts_top) {
	const auto json_str = 
		"{"
		  "\"success\": true,"
		  "\"accounts\": ["
			"{"
			  "\"address\": string,"
			  "\"balance\": 0,"
			  "\"publicKey\": string"
			"}"
		  "]"
		"}"
	;
	//TODO
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
