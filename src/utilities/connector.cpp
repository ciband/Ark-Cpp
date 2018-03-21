#include "utilities/connector.h"


/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connector
*   Default empty constructor
**************************************************/
ARK::Utilities::Network::Connector::Connector() : 
    network(nullptr),
    netType(ARK::NetworkType::INVALID),
    networkPeer(),
    networkPort(-1)
{}

/**************************************************
* Connects this to the supplied ARK::Network
**************************************************/
ARK::Utilities::Network::Connector::Connector(const ARK::Network& network)
{
    this->connect(network);
}

/**************************************************
* Connects this to the supplied ARK::NetworkType
**************************************************/
ARK::Utilities::Network::Connector::Connector(ARK::NetworkType networkType)
{
    (networkType == DEV)
        ? (this->connect(ARK::Constants::Networks::Devnet::model))
        : (this->connect(ARK::Constants::Networks::Mainnet::model));
}

/**************************************************
* Sets networktype, network, and peer
*
**************************************************/
void ARK::Utilities::Network::Connector::connect(const ARK::Network& network)
{
    if (strcmp(network.nethash(), ARK::Constants::Networks::Devnet::nethash) == 0) {
        this->netType = ARK::NetworkType::DEV;
    }
    else if (strcmp(network.nethash(), ARK::Constants::Networks::Mainnet::nethash) == 0) {
        this->netType = ARK::NetworkType::MAIN;
    }
    else if (strcmp(network.nethash(), "") != 0) {
        this->netType = ARK::NetworkType::CUSTOM;
    }
    else {
        this->netType = ARK::NetworkType::INVALID;
    }

    this->network = &network;
    this->setNetworkPeer(this->randomPeer());
}

/**************************************************
*
*
**************************************************/
void ARK::Utilities::Network::Connector::connectCustom(const ARK::Network& network, const char* peer, int port)
{
    this->netType = ARK::NetworkType::CUSTOM;
    this->network = &network;

    strncpy(this->networkPeer, peer, sizeof(this->networkPeer) / sizeof(this->networkPeer[0]));
    this->networkPort = port;
}

/**************************************************
* Sets Random Peer based on this->NetworkType
*   returns error String if error
**************************************************/
const char* ARK::Utilities::Network::Connector::randomPeer() const
{
    if (this->netType == ARK::NetworkType::DEV) {
        return ARK::Constants::Networks::Devnet::randomPeer();
    }
    if (this->netType == ARK::NetworkType::MAIN) {
        return ARK::Constants::Networks::Mainnet::randomPeer();
    }
    return "Error: Nethash does not match ARK::Constants";
}

/**************************************************
* Checks this->NetworkType
* Assigns ip & port to this
**************************************************/
void ARK::Utilities::Network::Connector::setNetworkPeer(const char* peer)
{
    if (this->netType == ARK::NetworkType::DEV) {
        this->networkPort = ARK::Constants::Networks::Devnet::port;
    }
    else if (this->netType == ARK::NetworkType::MAIN) {
        this->networkPort = ARK::Constants::Networks::Mainnet::port;
    }
    strncpy(networkPeer, peer, sizeof(networkPeer) / sizeof(networkPeer[0]));
}

/**************************************************
* Manages directing the callback from
*   the devices HTTPClient Library
**************************************************/
String ARK::Utilities::Network::Connector::cb(const char* const request)
{
    return this->http->get(this->networkPeer, this->networkPort, request);
}
/*  ==========================================================================  */

