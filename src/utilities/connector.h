

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "utilities/http.h"
#include "models/network.h"
#include "constants/networks.h"

namespace ARK {
namespace Utilities {
namespace Network {

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable
*   Inheritable Connector object
**************************************************/
class Connectable; 
/*  ==========================================================================  */




/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connector
**************************************************/
class Connector
    : virtual HTTPConnectable
{
/*  ==================================  */
  public:
  
/****************************************
*  ARK::Utilities::Network::Connectable
*  virtual HTTPConnectable
*
*  ARK::Utilities::Network::HTTP http; 
*****************************************/

    const ARK::Network* network;
	  ARK::NetworkType netType;

    char networkPeer[16];
    int networkPort;

    Connector();
    explicit Connector(const ARK::Network& network);
	explicit Connector(ARK::NetworkType networktype);

    Connector(const Connector&) = delete;
    Connector& operator=(const Connector&) = delete;
    Connector(Connector&&) = default;
    Connector& operator=(Connector&&) = default;

    void connect(const ARK::Network& network);
    void connectCustom(const ARK::Network& network, const char* peer, int port);

    bool disconnect();

    String cb(const char* const request);
/*  ==================================  */


/*  ==================================  */
  private:
  
    const char* randomPeer() const;
    void setNetworkPeer(const char* peer);
/*  ==================================  */
/*  ==========================================================================  */

};
};
};
};





/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable
*   Inheritable Connector object
**************************************************/
class ARK::Utilities::Network::Connectable
{
public:

  ARK::Utilities::Network::Connector netConnector;
};
/*  ==========================================================================  */


#endif
