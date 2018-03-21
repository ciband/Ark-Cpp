#include "api/manager.h"

/*  ==========================================================================  */
/*  =================  */
/*  ARK::API::Manager  */
/*  Constructor */
ARK::API::Manager::Manager()
{
  this->connect(ARK::Network());
};
/*  =================  */
/*  Constructor */
ARK::API::Manager::Manager(const ARK::Network& network)
{
  this->connect(network);
};
/*  =================  */
/*  Method */
void ARK::API::Manager::connect(const ARK::Network& network)
{
  this->netConnector = ARK::Utilities::Network::Connector(network);
};
/*  =================  */
/*  ==========================================================================  */
