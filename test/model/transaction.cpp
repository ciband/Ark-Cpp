#include "gtest/gtest.h"

#include "models/transaction.h"

TEST(transaction, construct_transaction) {
    ARK::Transaction transaction(
        "f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9",
        "14671461178414977683",
        "1696504",
        0,
        "9656006",
        "51000",
        "10000000",
        "vendorField",
        "DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR",
        "D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD",
        "039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c",
        "3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b",
        "1868079"
    );

	ASSERT_STREQ("f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9", transaction.id());
	ASSERT_STREQ("14671461178414977683", transaction.block_id());
	ASSERT_STREQ("1696504", transaction.height());
	ASSERT_EQ(0, transaction.type());
	ASSERT_STREQ("9656006", transaction.timestamp());
	ASSERT_STREQ("51000", transaction.amount().arktoshi());
	ASSERT_STREQ("10000000", transaction.fee().arktoshi());
	ASSERT_STREQ("vendorField", transaction.vendor_field());
	ASSERT_STREQ("DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR", transaction.sender_id().getValue());
	ASSERT_STREQ("D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD", transaction.recipient_id().getValue());
	ASSERT_STREQ("039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c", transaction.sender_publickey().getValue());
	ASSERT_STREQ("3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b", transaction.signature());
	ASSERT_STREQ("1868079", transaction.confirmations());
}