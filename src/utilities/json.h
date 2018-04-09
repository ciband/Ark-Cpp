

#ifndef JSON_H
#define JSON_H

#include "utilities/platform.h"

#include "api/accountable/accountable.h"
#include "api/blockable/blockable.h"
#include "api/delegatable/delegatable.h"
#include "api/loadable/loadable.h"
#include "api/peerable/peerable.h"
#include "api/transactionable/transactionable.h"
#include "models/block.h"
#include "models/fees.h"


#include <memory>

namespace ARK {
namespace Utilities {

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::JSONInterface 
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
class JSONInterface {
protected:
	JSONInterface() = default;

public:
    virtual ~JSONInterface() { }

	// /api/accounts/getBalance
	virtual ARK::API::Account::Respondable::Balances accounts_getBalance_fromJSON(const char* const json_str) = 0;
	// /api/accounts/getPublickey
	virtual Publickey accounts_getPublickey_fromJSON(const char* const json_str) = 0;
	// /api/accounts/delegates/fee
	virtual Balance accounts_delegates_fee_fromJSON(const char* const json_str) = 0;
	// /api/accounts/delegates
	virtual std::unique_ptr<ARK::Delegate[]> accounts_delegates_fromJSON(const char* const json_str) = 0;
	// /api/accounts
	virtual ARK::Account accounts_fromJSON(const char* const json_str) = 0;

	//TODO: /api/accounts/top 

	// /api/blocks/get
	virtual ARK::Block blocks_get_fromJSON(const char* const json_str) = 0;
	// /api/blocks
	virtual std::unique_ptr<ARK::Block[]> blocks_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getEpoch
	virtual String blocks_getEpoch_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getHeight
	virtual ARK::API::Block::Respondable::Height blocks_getHeight_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getNethash
	virtual Hash blocks_getNethash_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getFee
	virtual Balance blocks_getFee_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getFees
	virtual ARK::Fees blocks_getFees_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getMilestone
	virtual String blocks_getMilestone_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getReward
	virtual Balance blocks_getReward_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getSupply
	virtual Balance blocks_getSupply_fromJSON(const char* const json_str) = 0;
	// /api/blocks/getStatus
	virtual ARK::API::Block::Respondable::Status blocks_getStatus_fromJSON(const char* const json_str) = 0;
	// /api/delegates/count
	virtual uint16_t delegates_count_fromJSON(const char* const json_str) = 0;
	// /api/delegates/search
	virtual std::unique_ptr<ARK::API::Delegate::Respondable::Search[]> delegates_search_fromJSON(const char* const json_str) = 0;
	// /api/delegates/voters
	virtual ARK::API::Delegate::Respondable::Voters delegates_voters_fromJSON(const char* const json_str) = 0;
	// /api/delegates/get
	virtual ARK::Delegate delegates_get_fromJSON(const char* const json_str) = 0;
	// /api/delegates
	virtual std::unique_ptr<ARK::Delegate[]> delegates_fromJSON(const char* const json_str) = 0;
	// /api/delegates/fee
	virtual Balance delegates_fee_fromJSON(const char* const json_str) = 0;
	// /api/delegates/forging/getForgedByAccount
	virtual ARK::API::Delegate::Respondable::ForgedByAccount delegates_forging_getForgedByAccount_fromJSON(const char* const json_str) = 0;
	// /api/delegates/getNextForgers
	virtual ARK::API::Delegate::Respondable::NextForgers delegates_getNextForgers_fromJSON(const char* const json_str) = 0;
	// /api/loader/status
	virtual ARK::API::Loader::Respondable::Status loader_status_fromJSON(const char* const json_str) = 0;
	// /api/loader/status/sync
	virtual ARK::API::Loader::Respondable::Sync loader_status_sync_fromJSON(const char* const json_str) = 0;
	// /api/loader/autoconfigure
	virtual ARK::Network loader_autoconfigure_fromJSON(const char* const json_str) = 0;
	// /api/multisignatures/pending
	virtual String multisignatures_pending_fromJSON(const char* const json_str) = 0;

	// TODO: /api/multisignatures/accounts

	// /api/peers/get
	virtual ARK::Peer peers_get_fromJSON(const char* const json_str) = 0;
	// /api/peers
	virtual std::unique_ptr<ARK::Peer[]> peers_fromJSON(const char* const json_str) = 0;
	// /api/peers/version
	virtual ARK::API::Peer::Respondable::Version peers_version_fromJSON(const char* const json_str) = 0;
	// /api/signatures_fee
	virtual Balance signatures_Fee_fromJSON(const char* const json_str) = 0;
	// /api/transactions/get
	virtual ARK::Transaction transactions_get_fromJSON(const char* const json_str) = 0;
	// /api/transactions
	virtual std::unique_ptr<ARK::Transaction[]> transactions_fromJSON(const char* const json_str) = 0;
	// api/transactions/unconfirmed/get
	virtual ARK::API::Transaction::Respondable::Unconfirmed transactions_unconfirmed_get_fromJSON(const char* const json_str) = 0;
	// api/transactions/unconfirmed
	virtual std::unique_ptr<ARK::API::Transaction::Respondable::Unconfirmed[]> transactions_unconfirmed_fromJSON(const char* const json_str) = 0;


	// TODO: /peer/list
	// TODO: /peer/blocks/common
	// TODO: /peer/block
	// TODO: /peer/blocks
	// TODO: /peer/transactions
	// TODO: POST ?? /peer/trasnactions
	// TODO: /peer/transactionsFromIds
	// TODO: /peer/height
	// TODO: /peer/status

};
/*  ==========================================================================  */

// JSON parser singleton
JSONInterface& get_json_interface();

}
}

#endif
