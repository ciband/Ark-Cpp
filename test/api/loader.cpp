#include "gtest/gtest.h"

#include "api/api.h"

TEST(api, test_loader_status) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const auto status = _arkManager.loaderStatus();
	ASSERT_FALSE(status.loaded());
	ASSERT_NE(0, status.now());
	ASSERT_STREQ("0", status.blocks_count());
}

TEST(api, test_loader_sync) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const auto sync = _arkManager.loaderSync();
	ASSERT_FALSE(sync.syncing());
	//ASSERT_EQ(-40, sync.blocks());  //TODO:  review, are negative values right?
	ASSERT_STRNE("0", sync.height());
	ASSERT_STRNE("0", sync.id());
}

TEST(api, test_loader_autoconfigure) {
	static const auto dark_symbol = u8"DѦ";

	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);
	const auto configure = _arkManager.loaderAutoconfigure();
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", configure.nethash());
	ASSERT_STREQ("DARK", configure.token());
	ASSERT_STREQ(dark_symbol, configure.symbol());  //TODO: unicode issues with char*, fix
	ASSERT_STREQ("http://dexplorer.ark.io", configure.explorer());
	ASSERT_EQ(30, configure.version());

}
