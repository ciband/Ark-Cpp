

#ifndef BLOCK_GETTABLE_H
#define BLOCK_GETTABLE_H

#include "api/blockable/block_respondable.h"
#include "models/block.h"
#include "utilities/connector.h"
#include "utilities/json.h"
#include "models/fees.h"

namespace ARK {
namespace API {
namespace Block {

/*************************************************
*  PROTECTED: ARK::API::Block::Gettable
**************************************************/
class Gettable {
protected:
	/*************************************************
	* ARK::API::Block::Gettable::block
	*   api/blocks/get?id=_blockID
	**************************************************/
	ARK::Block block(ARK::Utilities::Network::Connector& _netConnector, const char* const _blockId);

/*************************************************
    *
    * {
    *   "success":true,
    *   "block":
    *   {
    *     "id": "const char*",
    *     "version":  int,
    *     "timestamp":  const char*,
    *     "height": const char*,
    *     "previousBlock":  "const char*",
    *     "numberOfTransactions": const char*,
    *     "totalAmount":  Balance,
    *     "totalFee": Balance,
    *     "reward": Balance,
    *     "payloadLength":  const char*,
    *     "payloadHash":  "Hash",
    *     "generatorPublicKey": "Publickey",
    *     "generatorId":  "Address",
    *     "blockSignature": "Signature",
    *     "confirmations":  const char*,
    *     "totalForged":" Balance"
    *   }
    * }
    *
    **************************************************/
    ARK::Block blockfromJSON(const char* const jsonStr);
    ARK::Block blockfromJSON(const String& jsonStr) {
        return blockfromJSON(jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
	/*    BROKEN: fix for large callbacks   */
	/*   blocks callback is ~63,712 bytes   */
	/*  /api/blocks  */
	std::unique_ptr<ARK::Block[]> blocks(ARK::Utilities::Network::Connector netConnector);
	std::unique_ptr<ARK::Block[]> blocksfromJSON(const char* const jsonStr);
	std::unique_ptr<ARK::Block[]> blocksfromJSON(const String& jsonStr) {
		return blocksfromJSON(jsonStr.c_str());
	}

/*************************************************
    * ARK::API::Block::Gettable::epoch
    *   /api/blocks/getEpoch
    *
    *   blockEpoch example:
    *     2017-03-21T13:00:00.000Z
    *
    **************************************************/
    String epoch(ARK::Utilities::Network::Connector& _netConnector);
    /*************************************************
    *
    * {
    *   "success":true,
    *   "epoch":  "String"
    * }
    **************************************************/
    String epochfromJSON(const char* const _jsonStr);
    String epochfromJSON(const String& _jsonStr) {
        return epochfromJSON(_jsonStr.c_str());
    }
/*************************************************
    * ARK::API::Block::Gettable::height 
    *   /api/blocks/getHeight
    **************************************************/
    ARK::API::Block::Respondable::Height height(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    *
    * {
    *   "success":true,
    *   "height": String,
    *   "id": "String"
    * }
    *
    **************************************************/
    ARK::API::Block::Respondable::Height heightfromJSON(const char* const _jsonStr);
    ARK::API::Block::Respondable::Height heightfromJSON(const String& _jsonStr) {
        return heightfromJSON(_jsonStr.c_str());
    }

/*************************************************
    * ARK::API::Block::Gettable::nethash
    *   /api/blocks/getNethash 
    **************************************************/
    Hash nethash(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    *
    * {
    *   "success":true,
    *   "nethash":  "Hash"
    * }
    *
    **************************************************/
    Hash nethashfromJSON(const char* const _jsonStr);
    Hash nethashfromJSON(const String& _jsonStr) {
        return nethashfromJSON(_jsonStr.c_str());
    }

/*************************************************
    * ARK::API::Block::Gettable::fee 
    *   /api/blocks/getFee
    **************************************************/
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);
    Balance feefromJSON(const char* const _jsonStr);
    Balance feefromJSON(const String& _jsonStr) {
        return feefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getFees  */
    ARK::Fees fees(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    *
    * {
    *   "success":true,
    *   "fee":  Balance
    * }
    *
    **************************************************/
    ARK::Fees feesfromJSON(const char* const _jsonStr);
    ARK::Fees feesfromJSON(const String& _jsonStr) {
        return feesfromJSON(_jsonStr.c_str());
    }

/*************************************************
    * ARK::API::Block::Gettable::milestone
    *   /api/blocks/getMilestone
    **************************************************/
    String milestone(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    *
    * {
    *   "success":true,
    *   "milestone": String
    * }
    *
    **************************************************/
    String milestonefromJSON(const char* const _jsonStr);
    String milestonefromJSON(const String& _jsonStr) {
        return milestonefromJSON(_jsonStr.c_str());
    }


/*************************************************
    * ARK::API::Block::Gettable::reward
    *   /api/blocks/getReward
    **************************************************/
    Balance reward(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    *
    * { 
    *   "success":true,
    *   "reward": Balance
    * }
    *
    **************************************************/
    Balance rewardfromJSON(const char* const _jsonStr);
    Balance rewardfromJSON(const String& _jsonStr) {
        return rewardfromJSON(_jsonStr.c_str());
    }

/*************************************************
    * ARK::API::Block::Gettable::supply
    *   /api/blocks/getSupply
    **************************************************/
    Balance supply(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    *
    * {
    *   "success":true,
    *   "supply": Balance
    * }
    *
    **************************************************/
    Balance supplyfromJSON(const char* const _jsonStr);
    Balance supplyfromJSON(const String& _jsonStr) {
        return supplyfromJSON(_jsonStr.c_str());
    }

/*************************************************
     *  ARK::API::Block::Gettable::status 
     *    api/blocks/getStatus
    **************************************************/
    ARK::API::Block::Respondable::Status status(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
    * 
    * {
    *   "success":true,
    *   "epoch":  "String",
    *   "height": String,
    *   "fee":  Balance,
    *   "milestone":  String,
    *   "nethash":" Hash",
    *   "reward":_reward,
    *   "supply":_supply
    * }
    *
    **************************************************/
    ARK::API::Block::Respondable::Status statusfromJSON(const char* const _jsonStr);
    ARK::API::Block::Respondable::Status statusfromJSON(const String& _jsonStr) {
        return statusfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  ====================================  */
/*  ==========================================================================  */
}
}
}

#endif
