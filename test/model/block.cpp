#include "gtest/gtest.h"

#include "models/block.h"

TEST(block, construct_block) {
    ARK::Block block(
        "5907849310697169543",
        0,
        "27400752",
        "2467562",
        "7012858385202614513",
        "0",
        "0",
        "0",
        "200000000",
        "0",
        "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
        "03127001718bee76f14133272f0f4a928ffa8c2b38cafd94d7100253dac732c644",
        "D9rv3h61heDYHQ3b3Xk3V5epHSTTC6Vn1d",
        "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe",
        "3",
        "200000000"
    );

	ASSERT_STREQ("5907849310697169543", block.id());
	ASSERT_EQ(0, block.version());
	ASSERT_STREQ("27400752", block.timestamp());
	ASSERT_STREQ("2467562", block.height());
	ASSERT_STREQ("7012858385202614513", block.previous_block());
	ASSERT_STREQ("0", block.number_of_transactions());
	ASSERT_STREQ("0", block.total_amount().arktoshi());
	ASSERT_STREQ("0", block.total_fee().arktoshi());
	ASSERT_STREQ("200000000", block.reward().arktoshi());
	ASSERT_STREQ("0", block.payload_length());
	ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", block.payload_hash().getValue());
	ASSERT_STREQ("03127001718bee76f14133272f0f4a928ffa8c2b38cafd94d7100253dac732c644", block.generator_public_key().getValue());
	ASSERT_STREQ("D9rv3h61heDYHQ3b3Xk3V5epHSTTC6Vn1d", block.generator_id().getValue());
	ASSERT_STREQ("3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe", block.block_signature().getValue());
	ASSERT_STREQ("3", block.confirmations());
	ASSERT_STREQ("200000000", block.total_forged().arktoshi());
}