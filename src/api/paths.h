

#ifndef PATHS_H
#define PATHS_H

namespace ARK {
namespace API {
namespace Paths {

/*************************************************
*  Account
**************************************************/
namespace Account
{
const auto getBalance_s = "/api/accounts/getBalance";
const auto getPublickey_s = "/api/accounts/getPublickey";
const auto delegatesFee_s = "/api/accounts/delegates/fee";
const auto delegates_s = "/api/accounts/delegates";
const auto accounts_s = "/api/accounts";
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*  Blocks
**************************************************/
namespace Block {

const auto get_s = "/api/blocks/get"; //using ID
const auto blocks_s = "/api/blocks";
const auto getEpoch_s = "/api/blocks/getEpoch";
const auto getHeight_s = "/api/blocks/getHeight";
const auto getNethash_s = "/api/blocks/getNethash";
const auto getFee_s = "/api/blocks/getFee";
const auto getFees_s = "/api/blocks/getFees";
const auto getMilestone_s = "/api/blocks/getMilestone";
const auto getReward_s = "/api/blocks/getReward";
const auto getSupply_s = "/api/blocks/getSupply";
const auto getStatus_s = "/api/blocks/getStatus";

}

/*************************************************
*  Delegates
**************************************************/
namespace Delegate {

const auto count_s = "/api/delegates/count";
const auto search_s = "/api/delegates/search";
const auto voters_s = "/api/delegates/voters";
const auto get_s = "/api/delegates/get";
const auto delegates_s = "/api/delegates";
const auto fee_s = "/api/delegates/fee";
const auto getForgedByAccount_s = "/api/delegates/forging/getForgedByAccount";
const auto getNextForgers_s = "/api/delegates/getNextForgers";

}

/*************************************************
*  Loader
**************************************************/
namespace Loader {

const auto status_s = "/api/loader/status";
const auto sync_s = "/api/loader/status/sync";
const auto autoconfigure_s = "/api/loader/autoconfigure";

}

/*************************************************
*  Peers
**************************************************/
namespace Peer {

const auto get_s = "/api/peers/get";
const auto peers_s = "/api/peers";
const auto version_s = "/api/peers/version";

}

/*************************************************
*  Signatures
**************************************************/
namespace Signatures {

const auto fee_s = "/api/signatures/fee";

}

/*************************************************
*  MultiSignatures
**************************************************/
namespace MultiSignatures {

const auto pending_s = "/api/multisignatures/pending";
const auto accounts_s = "/api/multisignatures/accounts";

}

/*************************************************
*  Transactions
**************************************************/
namespace Transaction {

const auto getSingle_s = "/api/transactions/get";
const auto transactions_s = "/api/transactions";
const auto getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get";
const auto unconfirmed_s = "/api/transactions/unconfirmed";

}

/**************************************************************************************************/

// /* Transport */
// namespace Transport {
//   const auto list_s = "/peer/list";
//   const auto common_s = "/peer/blocks/common";
//   const auto block_s = "/peer/block";
//   const auto blocks_s = "/peer/blocks";
//   const auto transactions_s = "/peer/transactions";
//   const auto transactionsPost_s = "/peer/transactions"; // post
//   const auto transactionsFromIds_s = "/peer/transactionsFromIds";
//   const auto height_s = "/peer/height";
//   const auto status_s = "/peer/status";
// }
}
}
}

#endif
