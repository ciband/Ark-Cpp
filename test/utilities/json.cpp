#include "gtest/gtest.h"

#include "utilities/json.h"

// Acount
TEST(json, accounts_getBalance) {
	static const auto json_str = 
	"{"
		"\"success\": true,"
		"\"balance\": 55,"
		"\"unconfirmedBalance\": 66"
	"}";

	auto balances = ARK::Utilities::get_json_interface().accounts_getBalance_fromJSON(json_str);
	ASSERT_STREQ(".00000055", balances.confirmed().ark());
	ASSERT_STREQ("55", balances.confirmed().arktoshi());
	ASSERT_STREQ(".00000066", balances.unconfirmed().ark());
	ASSERT_STREQ("66", balances.unconfirmed().arktoshi());
}

TEST(json, accounts_getPublickey) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\""
	"}";

	auto public_key = ARK::Utilities::get_json_interface().accounts_getPublickey_fromJSON(json_str);
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", public_key.getValue());
}

TEST(json, accounts_delegates_fee) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"fee\": 100"
	"}";

	auto fee = ARK::Utilities::get_json_interface().accounts_delegates_fee_fromJSON(json_str);
	ASSERT_STREQ(".00000100", fee.ark());
	ASSERT_STREQ("100", fee.arktoshi());
}

TEST(json, accounts_delegates) {
	static const auto json_str = 
	"{"
		"\"success\": true,"
		"\"delegates\" : ["
			"{"
				"\"username\": \"sleepdeficit\","
				"\"address\" : \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\","
				"\"publicKey\" : \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\","
				"\"vote\" : 111,"
				"\"producedblocks\" : 7,"
				"\"missedblocks\" : 5,"
				"\"rate\" : 3,"
				"\"approval\" : 95.5,"
				"\"productivity\" : 94.4"
			"},"
			"{"
				"\"username\": \"ciband\","
				"\"address\" : \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB\","
				"\"publicKey\" : \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457\","
				"\"vote\" : 122,"
				"\"producedblocks\" : 8,"
				"\"missedblocks\" : 6,"
				"\"rate\" : 4,"
				"\"approval\" : 95.6,"
				"\"productivity\" : 94.5"
			"}"
		"]"
	"}";

	const auto delegates = ARK::Utilities::get_json_interface().accounts_delegates_fromJSON(json_str);
	ASSERT_STREQ("sleepdeficit", delegates[0].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegates[0].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegates[0].public_key().getValue());
	const auto& vote = delegates[0].vote();
	ASSERT_STREQ(".00000111", vote.ark());
	ASSERT_STREQ("111", vote.arktoshi());
	ASSERT_EQ(7, delegates[0].produced_blocks());
	ASSERT_EQ(5, delegates[0].missed_blocks());
	ASSERT_EQ(3, delegates[0].rate());
	ASSERT_NEAR(95.5, delegates[0].approval(), 0.1);
	ASSERT_NEAR(94.4, delegates[0].productivity(), 0.1);

	ASSERT_STREQ("ciband", delegates[1].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB", delegates[1].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457", delegates[1].public_key().getValue());
	const auto& vote1 = delegates[1].vote();
	ASSERT_STREQ(".00000122", vote1.ark());
	ASSERT_STREQ("122", vote1.arktoshi());
	ASSERT_EQ(8, delegates[1].produced_blocks());
	ASSERT_EQ(6, delegates[1].missed_blocks());
	ASSERT_EQ(4, delegates[1].rate());
	ASSERT_NEAR(95.6, delegates[1].approval(), 0.1);
	ASSERT_NEAR(94.5, delegates[1].productivity(), 0.1);
}
TEST(json, accounts) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"account\": ["
			"{"
				"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\","
				"\"unconfirmedBalance\": 1234,"
				"\"balance\": 5678,"
				"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\","
				"\"unconfirmedSignature\": 1,"
				"\"secondSignature\": 1,"
				"\"secondPublicKey\": \"03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869\","
				"\"multisignatures\": [],"
				"\"u_multisignatures\": []"
			"},"
			"{"
				"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB\","
				"\"unconfirmedBalance\": 1235,"
				"\"balance\": 5679,"
				"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457\","
				"\"unconfirmedSignature\": 2,"
				"\"secondSignature\": 2,"
				"\"secondPublicKey\": \"03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2860\","
				"\"multisignatures\": [],"
				"\"u_multisignatures\": []"
			"}"
		"]"
	"}";

	const auto accounts = ARK::Utilities::get_json_interface().accounts_fromJSON(json_str);
	
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", accounts[0].address().getValue());
	const auto& unconfirmed_balance = accounts[0].unconfirmed_balance();
	ASSERT_STREQ(".00001234", unconfirmed_balance.ark());
	ASSERT_STREQ("1234", unconfirmed_balance.arktoshi());
	const auto& balance = accounts[0].balance();
	ASSERT_STREQ(".00005678", balance.ark());
	ASSERT_STREQ("5678", balance.arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", accounts[0].public_key().getValue());
	ASSERT_EQ(1, accounts[0].unconfirmed_signature());
	ASSERT_EQ(1, accounts[0].second_signature());
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", accounts[0].second_public_key().getValue());
	ASSERT_STREQ("[\n\n]", accounts[0].multi_signatures().getValue());
	ASSERT_STREQ("[\n\n]", accounts[0].u_multi_signatures().getValue());

	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB", accounts[1].address().getValue());
	const auto& unconfirmed_balance1 = accounts[1].unconfirmed_balance();
	ASSERT_STREQ(".00001235", unconfirmed_balance1.ark());
	ASSERT_STREQ("1235", unconfirmed_balance1.arktoshi());
	const auto& balance1 = accounts[1].balance();
	ASSERT_STREQ(".00005679", balance1.ark());
	ASSERT_STREQ("5679", balance1.arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457", accounts[1].public_key().getValue());
	ASSERT_EQ(2, accounts[1].unconfirmed_signature());
	ASSERT_EQ(2, accounts[1].second_signature());
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2860", accounts[1].second_public_key().getValue());
	ASSERT_STREQ("[\n\n]", accounts[1].multi_signatures().getValue());
	ASSERT_STREQ("[\n\n]", accounts[1].u_multi_signatures().getValue());
}
TEST(json, accounts_top) {
	static const auto json_str = 
	"{"
		"\"success\": true,"
		"\"accounts\": ["
		"{"
			"\"address\": string,"
			"\"balance\": 0,"
			"\"publicKey\": string"
		"}"
		"]"
	"}";

	//TODO
}

// Block
TEST(json, blocks_get) {
	static const auto json_str = 
	"{"
		"\"success\": true,"
		"\"block\": {"
		"\"id\": 4367122150875693402,"
		"\"version\": 0,"
		"\"timestamp\": 25271824,"
		"\"height\": 2287265,"
		"\"previousBlock\": 17021413347323836951,"
		"\"numberOfTransactions\": 1,"
		"\"totalAmount\": 2,"
		"\"totalFee\": 3,"
		"\"reward\": 200000000,"
		"\"payloadLength\": 0,"
		"\"payloadHash\": \"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\","
		"\"generatorPublicKey\": \"02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586\","
		"\"generatorId\": \"D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz\","
		"\"blockSignature\": \"3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0\","
		"\"confirmations\": 0,"
		"\"totalForged\": 200000000"
		"}"
	"}";

	const auto block = ARK::Utilities::get_json_interface().blocks_get_fromJSON(json_str);
	ASSERT_STREQ("4367122150875693402", block.id());
	ASSERT_EQ(0, block.version());
	ASSERT_STREQ("25271824", block.timestamp());
	ASSERT_STREQ("2287265", block.height());
	ASSERT_STREQ("17021413347323836951", block.previous_block());
	ASSERT_STREQ("1", block.number_of_transactions());
	ASSERT_STREQ("2", block.total_amount().arktoshi());
	ASSERT_STREQ("3", block.total_fee().arktoshi());
	ASSERT_STREQ("200000000", block.reward().arktoshi());
	ASSERT_STREQ("0", block.payload_length());
	ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", block.payload_hash().getValue());
	ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", block.generator_public_key().getValue());
	ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", block.generator_id().getValue());
	ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0", block.block_signature().getValue());
	ASSERT_STREQ("0", block.confirmations());
	ASSERT_STREQ("0", block.confirmations());
	ASSERT_STREQ("200000000", block.total_forged().arktoshi());
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
