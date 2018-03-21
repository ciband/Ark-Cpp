

#ifndef PEERABLE_H
#define PEERABLE_H

#include "api/peerable/peer_respondable.h"
#include "api/peerable/peer_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Peerable
*   	public Peer::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Peer Model
* 
**************************************************/
class Peerable :
    public Peer::Gettable,
    virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*		/api/peers/get?ip=167.114.29.55&port=4002
		*
		*		@uri:	/api/peers/get?ip=
		*		@returnType:	ARK::Peer
		*
		*   @method:	peer(const char* const ip, int port)
    *   @parameters:
    *     const char* const ip
    *     int port
		*
		*   @outs:	ARK::API::Peer::Gettable::peer(this->netConnector, ip, port)
		*
		*   @description:
		*			Gets Ark Network Peer from a Node via API.
		* 
		**************************************************/
    ARK::Peer peer(const char* const ip, int port)
    {
      return ARK::API::Peer::Gettable::peer(this->netConnector, ip, port);
    };
    /*************************************************/

/**************************************************************************************************/

    /*************************************************/
    /*************************************************/
  	/*    BROKEN: fix for large callbacks  */
  	/*    Peers callback is ~11,000 bytes  */
    /*  /api/peers  */
    // ARK::API::PeerGettable::PeersResponse peers()
    // { return ARK::API::PeerGettable::peers(this->netConnector); };
    /*************************************************/
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/peers/version
		*
		*		@uri:	/api/peers/version
		*		@returnType:	ARK::API::Peer::Respondable::Version
		*
		*   @method:	ppeerVersion()
		*
		*   @outs:	ARK::API::Peer::Gettable::version(this->netConnector)
		*
		*   @description:
		*			Gets Ark Network Peer Version from a Node via API.
		* 
		**************************************************/
    ARK::API::Peer::Respondable::Version peerVersion()
    {
      return ARK::API::Peer::Gettable::version(this->netConnector);
    };
    /*************************************************/
	};

};
};

#endif
