#include "api/blockable/block_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "utilities/connector.h"

/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Block::Gettable::block  */
/*  /api/blocks/get?id=_blockID */
ARK::Block ARK::API::Block::Gettable::block(
    ARK::Utilities::Network::Connector& netConnector,
    const char* const blockId)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Block::get_s);
    strcat(uri, "?id=");
    strcat(uri, blockId);

    auto callback = netConnector.cb(uri);
    return ARK::Utilities::get_json_interface().blocks_get_fromJSON(callback.c_str());
}


/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks   */
/*   blocks callback is ~63,712 bytes   */
/*  ===============================  */
/*  ARK::API::Block::Gettable::blocks  */
// /*  /api/blocks */
 std::unique_ptr<ARK::Block[]> ARK::API::Block::Gettable::blocks(ARK::Utilities::Network::Connector _netConnector) {
   auto callback = _netConnector.cb(ARK::API::Paths::Block::blocks_s);
   return ARK::Utilities::get_json_interface().blocks_fromJSON(callback.c_str());
 }


/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Block::Gettable::epoch  */
/*  /api/blocks/getEpoch  */
String ARK::API::Block::Gettable::epoch(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getEpoch_s);

  return ARK::Utilities::get_json_interface().blocks_getEpoch_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::height  */
/*  /api/blocks/getHeight  */
ARK::API::Block::Respondable::Height ARK::API::Block::Gettable::height(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getHeight_s);

  return ARK::Utilities::get_json_interface().blocks_getHeight_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::Block::Gettable::nethash  */
/*  /api/blocks/getNethash  */
Hash ARK::API::Block::Gettable::nethash(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getNethash_s);

  return ARK::Utilities::get_json_interface().blocks_getNethash_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ============================  */
/*  ARK::API::Block::Gettable::fee  */
/*  /api/blocks/getFee  */
Balance ARK::API::Block::Gettable::fee(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getFee_s);

  return ARK::Utilities::get_json_interface().blocks_getFee_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  =============================  */
/*  ARK::API::Block::Gettable::fees  */
/*  /api/blocks/getFees  */
ARK::Fees ARK::API::Block::Gettable::fees(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getFees_s);

  return ARK::Utilities::get_json_interface().blocks_getFees_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Block::Gettable::milestone  */
/*  /api/blocks/getMilestone  */
String ARK::API::Block::Gettable::milestone(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getMilestone_s);

  return ARK::Utilities::get_json_interface().blocks_getMilestone_fromJSON(callback.c_str());
};

/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::reward  */
/*  /api/blocks/getReward  */
Balance ARK::API::Block::Gettable::reward(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getReward_s);

  return ARK::Utilities::get_json_interface().blocks_getReward_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::supply  */
/*  /api/blocks/getSupply  */
Balance ARK::API::Block::Gettable::supply(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getSupply_s);

  return ARK::Utilities::get_json_interface().blocks_getSupply_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::status  */
/*  /api/blocks/getStatus  */
ARK::API::Block::Respondable::Status ARK::API::Block::Gettable::status(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getStatus_s);

  return ARK::Utilities::get_json_interface().blocks_getStatus_fromJSON(callback.c_str());
};

