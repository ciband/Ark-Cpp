

#ifndef BLOCK_GETTABLE_H
#define BLOCK_GETTABLE_H

#include "api/blockable/block_respondable.h"
#include "models/block.h"
#include "utilities/connector.h"
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


/*  ==========================================================================  */

/*  ==========================================================================  */
	/*    BROKEN: fix for large callbacks   */
	/*   blocks callback is ~63,712 bytes   */
	/*  /api/blocks  */
	std::unique_ptr<ARK::Block[]> blocks(ARK::Utilities::Network::Connector netConnector);
	

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
    * ARK::API::Block::Gettable::height 
    *   /api/blocks/getHeight
    **************************************************/
    ARK::API::Block::Respondable::Height height(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
    * ARK::API::Block::Gettable::nethash
    *   /api/blocks/getNethash 
    **************************************************/
    Hash nethash(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
    * ARK::API::Block::Gettable::fee 
    *   /api/blocks/getFee
    **************************************************/
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);
   
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getFees  */
    ARK::Fees fees(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
    * ARK::API::Block::Gettable::milestone
    *   /api/blocks/getMilestone
    **************************************************/
    String milestone(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
    * ARK::API::Block::Gettable::reward
    *   /api/blocks/getReward
    **************************************************/
    Balance reward(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
    * ARK::API::Block::Gettable::supply
    *   /api/blocks/getSupply
    **************************************************/
    Balance supply(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
     *  ARK::API::Block::Gettable::status 
     *    api/blocks/getStatus
    **************************************************/
    ARK::API::Block::Respondable::Status status(ARK::Utilities::Network::Connector& _netConnector);


/*  ==========================================================================  */
};
/*  ====================================  */
/*  ==========================================================================  */
}
}
}

#endif
