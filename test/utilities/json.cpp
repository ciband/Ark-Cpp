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
	static const auto json_str = 
	"{"
		"\"success\": true,"
		"\"blocks\" : ["
			"{"
				"\"id\": 4367122150875693402,"
				"\"version\" : 0,"
				"\"timestamp\" : 25271824,"
				"\"height\" : 2287265,"
				"\"previousBlock\" : 17021413347323836951,"
				"\"numberOfTransactions\" : 1,"
				"\"totalAmount\" : 2,"
				"\"totalFee\" : 3,"
				"\"reward\" : 4,"
				"\"payloadLength\" : 5,"
				"\"payloadHash\" : \"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\","
				"\"generatorPublicKey\" : \"02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586\","
				"\"generatorId\" : \"D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz\","
				"\"blockSignature\" : \"3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0\","
				"\"confirmations\" : 7,"
				"\"totalForged\" : 8"
			"},"
			"{"
				"\"id\": 4367122150875693403,"
				"\"version\" : 0,"
				"\"timestamp\" : 25271825,"
				"\"height\" : 2287266,"
				"\"previousBlock\" : 17021413347323836952,"
				"\"numberOfTransactions\" : 2,"
				"\"totalAmount\" : 3,"
				"\"totalFee\" : 4,"
				"\"reward\" : 5,"
				"\"payloadLength\" : 6,"
				"\"payloadHash\" : \"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b856\","
				"\"generatorPublicKey\" : \"02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301587\","
				"\"generatorId\" : \"D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfa\","
				"\"blockSignature\" : \"3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b1\","
				"\"confirmations\" : 8,"
				"\"totalForged\" : 9"
			"}"
		"]"
	"}";

	const auto blocks = ARK::Utilities::get_json_interface().blocks_fromJSON(json_str);

	ASSERT_STREQ("4367122150875693402", blocks[0].id());
	ASSERT_EQ(0, blocks[0].version());
	ASSERT_STREQ("25271824", blocks[0].timestamp());
	ASSERT_STREQ("2287265", blocks[0].height());
	ASSERT_STREQ("17021413347323836951", blocks[0].previous_block());
	ASSERT_STREQ("1", blocks[0].number_of_transactions());
	ASSERT_STREQ("2", blocks[0].total_amount().arktoshi());
	ASSERT_STREQ("3", blocks[0].total_fee().arktoshi());
	ASSERT_STREQ("4", blocks[0].reward().arktoshi());
	ASSERT_STREQ("5", blocks[0].payload_length());
	ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", blocks[0].payload_hash().getValue());
	ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", blocks[0].generator_public_key().getValue());
	ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", blocks[0].generator_id().getValue());
	ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0", blocks[0].block_signature().getValue());
	ASSERT_STREQ("7", blocks[0].confirmations());
	ASSERT_STREQ("8", blocks[0].total_forged().arktoshi());

	ASSERT_STREQ("4367122150875693403", blocks[1].id());
	ASSERT_EQ(0, blocks[1].version());
	ASSERT_STREQ("25271825", blocks[1].timestamp());
	ASSERT_STREQ("2287266", blocks[1].height());
	ASSERT_STREQ("17021413347323836952", blocks[1].previous_block());
	ASSERT_STREQ("2", blocks[1].number_of_transactions());
	ASSERT_STREQ("3", blocks[1].total_amount().arktoshi());
	ASSERT_STREQ("4", blocks[1].total_fee().arktoshi());
	ASSERT_STREQ("5", blocks[1].reward().arktoshi());
	ASSERT_STREQ("6", blocks[1].payload_length());
	ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b856", blocks[1].payload_hash().getValue());
	ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301587", blocks[1].generator_public_key().getValue());
	ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfa", blocks[1].generator_id().getValue());
	ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b1", blocks[1].block_signature().getValue());
	ASSERT_STREQ("8", blocks[1].confirmations());
	ASSERT_STREQ("9", blocks[1].total_forged().arktoshi());
}

TEST(json, blocks_getEpoch) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"epoch\" : \"2017-03-21T13:00:00.000Z\""
	"}";

	ASSERT_STREQ("2017-03-21T13:00:00.000Z", ARK::Utilities::get_json_interface().blocks_getEpoch_fromJSON(json_str).c_str());
}

TEST(json, blocks_getHeight) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"height\" : 44,"
		"\"id\" : 55"
	"}";

	const auto height = ARK::Utilities::get_json_interface().blocks_getHeight_fromJSON(json_str);

	ASSERT_STRNE("44", height.id());
	ASSERT_STRNE("55", height.height());
}

TEST(json, blocks_GetNethash) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"nethash\" : \"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23\""
	"}";

	const auto hash = ARK::Utilities::get_json_interface().blocks_getNethash_fromJSON(json_str);
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", hash.getValue());
}

TEST(json, blocks_getFee) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"fee\" : 10000000"
	"}";

	const auto fee = ARK::Utilities::get_json_interface().blocks_getFee_fromJSON(json_str);

	ASSERT_STREQ(".10000000", fee.ark());
	ASSERT_STREQ("10000000", fee.arktoshi());
}

TEST(json, blocks_getFees) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"send\" : 10000000,"
		"\"vote\" : 100000000,"
		"\"secondsignature\" : 2500000000,"
		"\"delegate\" : 500000000,"
		"\"multisignature\" : 500000000"
	"}";

	const auto fees = ARK::Utilities::get_json_interface().blocks_getFees_fromJSON(json_str);
	ASSERT_STREQ("10000000", fees.send().arktoshi());
	ASSERT_STREQ("100000000", fees.vote().arktoshi());
	ASSERT_STREQ("2500000000", fees.second_signature().arktoshi());
	ASSERT_STREQ("500000000", fees.delegate().arktoshi());
	ASSERT_STREQ("500000000", fees.multi_signature().arktoshi());
}

TEST(json, blocks_getMilestone) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"milestone\" : 990"
	"}";

	ASSERT_STREQ("990", ARK::Utilities::get_json_interface().blocks_getMilestone_fromJSON(json_str).c_str());
}

TEST(json, blocks_getReward) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"reward\" : 900100000000"
	"}";

	const auto block_reward = ARK::Utilities::get_json_interface().blocks_getReward_fromJSON(json_str);
	ASSERT_STREQ("9001.00000000", block_reward.ark());
	ASSERT_STREQ("900100000000", block_reward.arktoshi());
}

TEST(json, blocks_getSupply) {
	static const auto json_str =
		"{"
		"\"success\": true,"
		"\"supply\" : 1900200000000"
		"}";

	const auto supply = ARK::Utilities::get_json_interface().blocks_getSupply_fromJSON(json_str);
	ASSERT_STREQ("19002.00000000", supply.ark());
	ASSERT_STREQ("1900200000000", supply.arktoshi());
}

TEST(json, blocks_getStatus) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"epoch\" : \"2017-03-21T13:00:00.000Z\","
		"\"height\" : 77,"
		"\"fee\" : 10000000,"
		"\"milestone\" : 5,"
		"\"nethash\" : \"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23\","
		"\"reward\" : 200000000,"
		"\"supply\" : 300000000"
	"}";

	const auto block_status = ARK::Utilities::get_json_interface().blocks_getStatus_fromJSON(json_str);
	ASSERT_STREQ("2017-03-21T13:00:00.000Z", block_status.epoch());
	ASSERT_STREQ("77", block_status.height());
	const auto& fee = block_status.fee();
	ASSERT_STREQ(".10000000", fee.ark());
	ASSERT_STREQ("10000000", fee.arktoshi());
	ASSERT_EQ(5, block_status.milestone());
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", block_status.nethash().getValue());
	const auto& reward = block_status.reward();
	ASSERT_STREQ("2.00000000", reward.ark());
	ASSERT_STREQ("200000000", reward.arktoshi());
	const auto& supply = block_status.supply();
	ASSERT_STREQ("3.00000000", supply.ark());
	ASSERT_STREQ("300000000", supply.arktoshi());
}

// Delegate

TEST(json, delegates_count) {
	static const auto json_str = 
	"{"
	  "\"success\": true,"
	  "\"count\": 5"
	"}";

	ASSERT_EQ(5u, ARK::Utilities::get_json_interface().delegates_count_fromJSON(json_str));
}

TEST(json, delegates_search) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"delegates\": ["
			"{"
				"\"username\": \"sleepdeficit\","
				"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\","
				"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\","
				"\"vote\": 56,"
				"\"producedblocks\": 57,"
				"\"missedblocks\": 58"
			"},"
			"{"
				"\"username\": \"ciband\","
				"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB\","
				"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457\","
				"\"vote\": 57,"
				"\"producedblocks\": 58,"
				"\"missedblocks\": 59"
			"}"
		"]"
	"}";

	const auto delegates = ARK::Utilities::get_json_interface().delegates_search_fromJSON(json_str);
	
	ASSERT_STREQ("sleepdeficit", delegates[0].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegates[0].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegates[0].public_key().getValue());
	const auto& vote = delegates[0].vote();
	ASSERT_STREQ(".00000056", vote.ark());
	ASSERT_STREQ("56", vote.arktoshi());
	ASSERT_EQ(57, delegates[0].produced_blocks());
	ASSERT_EQ(58, delegates[0].missed_blocks());

	ASSERT_STREQ("ciband", delegates[1].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB", delegates[1].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457", delegates[1].public_key().getValue());
	const auto& vote1 = delegates[1].vote();
	ASSERT_STREQ(".00000057", vote1.ark());
	ASSERT_STREQ("57", vote1.arktoshi());
	ASSERT_EQ(58, delegates[1].produced_blocks());
	ASSERT_EQ(59, delegates[1].missed_blocks());
}

TEST(json, delegates_voters) {
	// TODO
}

TEST(json, delegates_get) {
	static const auto json_str = 
	"{"
		"\"success\": true,"
		"\"delegate\": {"
			"\"username\": \"sleepdeficit\","
			"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\","
			"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\","
			"\"vote\": \"141988130482360\","
			"\"producedblocks\": 26460,"
			"\"missedblocks\": 359,"
			"\"rate\": 44,"
			"\"approval\": 1.07,"
			"\"productivity\": 98.66"
		"}"
	"}";

	const auto delegate = ARK::Utilities::get_json_interface().delegates_get_fromJSON(json_str);

	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	ASSERT_STREQ("141988130482360", delegate.vote().arktoshi());
	ASSERT_EQ(26460, delegate.produced_blocks());
	ASSERT_EQ(359, delegate.missed_blocks());
	ASSERT_EQ(44, delegate.rate());
	ASSERT_NEAR(1.07, delegate.approval(), 0.01);
	ASSERT_NEAR(98.66, delegate.productivity(), 0.01);	
}

TEST(json, delegates) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"delegates\" : ["
		"{"
			"\"username\": \"sleepdeficit\","
			"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\","
			"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\","
			"\"vote\": \"141988130482360\","
			"\"producedblocks\": 26460,"
			"\"missedblocks\": 359,"
			"\"rate\": 44,"
			"\"approval\": 1.07,"
			"\"productivity\": 98.66"
		"},"
		"{"
			"\"username\": \"ciband\","
			"\"address\": \"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB\","
			"\"publicKey\": \"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457\","
			"\"vote\": \"141988130482361\","
			"\"producedblocks\": 26461,"
			"\"missedblocks\": 360,"
			"\"rate\": 45,"
			"\"approval\": 1.08,"
			"\"productivity\": 98.67"
		"}"
		"]"
	"}";

	const auto delegates = ARK::Utilities::get_json_interface().delegates_fromJSON(json_str);

	ASSERT_STREQ("sleepdeficit", delegates[0].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegates[0].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegates[0].public_key().getValue());
	ASSERT_STREQ("141988130482360", delegates[0].vote().arktoshi());
	ASSERT_EQ(26460, delegates[0].produced_blocks());
	ASSERT_EQ(359, delegates[0].missed_blocks());
	ASSERT_EQ(44, delegates[0].rate());
	ASSERT_NEAR(1.07, delegates[0].approval(), 0.01);
	ASSERT_NEAR(98.66, delegates[0].productivity(), 0.01);

	ASSERT_STREQ("ciband", delegates[1].username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGB", delegates[1].address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a457", delegates[1].public_key().getValue());
	ASSERT_STREQ("141988130482361", delegates[1].vote().arktoshi());
	ASSERT_EQ(26461, delegates[1].produced_blocks());
	ASSERT_EQ(360, delegates[1].missed_blocks());
	ASSERT_EQ(45, delegates[1].rate());
	ASSERT_NEAR(1.08, delegates[1].approval(), 0.01);
	ASSERT_NEAR(98.67, delegates[1].productivity(), 0.01);
}

TEST(json, delegates_fee) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"fee\": 9005"
	"}";

	const auto fee = ARK::Utilities::get_json_interface().delegates_fee_fromJSON(json_str);
	ASSERT_STREQ(".00009005", fee.ark());
	ASSERT_STREQ("9005", fee.arktoshi());
}

TEST(json, delegates_forging_getForgedByAccount) {
	static const auto json_str =
	"{"
		"\"success\": true,"
		"\"fees\" : 123456789,"
		"\"rewards\" : 987654321,"
		"\"forged\" : 132435465768798090"
	"}";

	const auto forged_by_account = ARK::Utilities::get_json_interface().delegates_forging_getForgedByAccount_fromJSON(json_str);
	ASSERT_STREQ("1.23456789", forged_by_account.fees().ark());
	ASSERT_STREQ("123456789", forged_by_account.fees().arktoshi());
	ASSERT_STREQ("9.87654321", forged_by_account.rewards().ark());
	ASSERT_STREQ("987654321", forged_by_account.rewards().arktoshi());
	ASSERT_STREQ("1324354657.68798090", forged_by_account.forged().ark());
	ASSERT_STREQ("132435465768798090", forged_by_account.forged().arktoshi());
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
