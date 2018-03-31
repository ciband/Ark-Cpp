

#ifndef PEER_GETTABLE_H
#define PEER_GETTABLE_H

#include "models/peer.h"
#include "utilities/connector.h"
#include "api/peerable/peer_respondable.h"

namespace ARK
{
namespace API
{
namespace Peer
{
/*************************************************
*  PROTECTED: ARK::API::Peer::Gettable
**************************************************/
class Gettable
{
  protected:
    /*************************************************
    * ARK::API::Peer::Gettable::peer
    *   /api/peers/get?ip=167.114.29.55&port=4002
    **************************************************/
    ARK::Peer peer(
        ARK::Utilities::Network::Connector& netConnector,
        const char* const _ip,
        int _port
    );


/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
  /*    BROKEN: fix for large callbacks  */
  /*    Peers callback is ~11,000 bytes  */
	std::unique_ptr<ARK::Peer[]> peers(ARK::Utilities::Network::Connector& _netConnector);


 /*************************************************
    * ARK::API::PeerGettable::version
    *   /api/peers/version
    **************************************************/
    ARK::API::Peer::Respondable::Version version(ARK::Utilities::Network::Connector& _netConnector);


/*  ==========================================================================  */
};
/*  ===================================  */
/*  ==========================================================================  */
}
}
}

#endif
