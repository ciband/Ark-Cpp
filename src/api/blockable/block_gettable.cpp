#include "api/blockable/block_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "utilities/connector.h"

/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Block::Gettable::block  */
/*  /api/blocks/get?id=_blockID */
ARK::Block ARK::API::Block::Gettable::block(
    ARK::Utilities::Network::Connector& _netConnector,
    const char* const _blockId)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Block::get_s);
    strcat(uri, "?id=");
    strcat(uri, _blockId);

    auto callback = _netConnector.cb(uri);
    return ARK::API::Block::Gettable::blockfromJSON(callback);
};

/*
{ "success":true,
  "block":{
    "id": "String",
    "version":  int,
    "timestamp":  String,
    "height": String,
    "previousBlock":  "Striing",
    "numberOfTransactions": String,
    "totalAmount":  Balance,
    "totalFee": Balance,
    "reward": Balance,
    "payloadLength":  String,
    "payloadHash":  "Hash",
    "generatorPublicKey": "Publickey",
    "generatorId":  "Address",
    "blockSignature": "Signature",
    "confirmations":  String,
    "totalForged":" Balance"
  }
}
*/
ARK::Block ARK::API::Block::Gettable::blockfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return ARK::Block(
        jString->valueIn("block", "id").c_str(),
        convert_to_int(jString->valueIn("block", "version")),
        jString->valueIn("block", "timestamp").c_str(),
        jString->valueIn("block", "height").c_str(),
        jString->valueIn("block", "previousBlock").c_str(),
        jString->valueIn("block", "numberOfTransactions").c_str(),
        jString->valueIn("block", "totalAmount").c_str(),
        jString->valueIn("block", "totalFee").c_str(),
        jString->valueIn("block", "reward").c_str(),
        jString->valueIn("block", "payloadLength").c_str(),
        jString->valueIn("block", "payloadHash").c_str(),
        jString->valueIn("block", "generatorPublicKey").c_str(),
        jString->valueIn("block", "generatorId").c_str(),
        jString->valueIn("block", "blockSignature").c_str(),
        jString->valueIn("block", "confirmations").c_str(),
        jString->valueIn("block", "totalForged").c_str()
    );
}
/*  ==============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks   */
/*   blocks callback is ~63,712 bytes   */
/*  ===============================  */
/*  ARK::API::Block::Gettable::blocks  */
// /*  /api/blocks */
// String blocks(ARK::Utilities::Network::Connector _netConnector) {
//   String uri = ARK::API::Paths::Block::blocks_s;
//   String callback = _netConnector.cb(uri);
//   if (callback.indexOf("false") >= 0) { return callback; };
//   return ARK::API::Block::Gettable::blocksfromJSON(callback);
// };

// /*
// {
//   "success":true,
//   "blocks":[
//     {
//       "id":"_blockID",
//       "version":_version,
//       "timestamp":_timestamp,
//       "height":_height,
//       "previousBlock":"_previousBlock",
//       "numberOfTransactions":_numberOfTransactions,
//       "totalAmount":_totalAmount,
//       "totalFee":_totalFee,
//       "reward":_reward,
//       "payloadLength":_payloadLength,
//       "payloadHash":"_payloadHash",
//       "generatorPublicKey":"_generatorPubkey",
//       "generatorId":"_generatorId",
//       "blockSignature":"_blockSig",
//       "confirmations":_confirmations,
//       "totalForged":"_totalForged"
//     },
//     ...
//     {
//       "id":"_blockID",
//       "version":_version,
//       "timestamp":_timestamp,
//       "height":_height,
//       "previousBlock":"_previousBlock",
//       "numberOfTransactions":_numberOfTransactions,
//       "totalAmount":_totalAmount,
//       "totalFee":_totalFee,
//       "reward":_reward,
//       "payloadLength":_payloadLength,
//       "payloadHash":"_payloadHash",
//       "generatorPublicKey":"_generatorPubkey",
//       "generatorId":"_generatorId",
//       "blockSignature":"_blockSig",
//       "confirmations":_confirmations,
//       "totalForged":"_totalForged"
//     }
//   ],
//   "count":2313747
// }
// */
// String blocksfromJSON(String _jsonStr) {
//   auto jString = ARK::Utilities::make_json_string(_jsonStr);
//   // ARK::Block block = {
//   //   jString->valueFor("id").toInt(),
//   //   jString->valueFor("version").toFloat(),
//   //   jString->valueFor("timestamp").toInt(),
//   //   jString->valueFor("height").toInt(),
//   //   jString->valueFor("previousBlock").toInt(),
//   //   jString->valueFor("numberOfTransactions").toInt(),
//   //   jString->valueFor("totalAmount").toFloat(),
//   //   jString->valueFor("totalFee").toFloat(),
//   //   jString->valueFor("reward").toInt(),
//   //   jString->valueFor("payloadLength").toInt(),
//   //   jString->valueFor("payloadHash"),
//   //   jString->valueFor("generatorPublicKey"),
//   //   jString->valueFor("generatorId"),
//   //   jString->valueFor("blockSignature"),
//   //   jString->valueFor("confirmations").toInt(),
//   //   jString->valueFor("totalForged").toInt()
//   // };
//   return "";//block.description();
// };
/*  ===============================  */
/*  ==========================================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Block::Gettable::epoch  */
/*  /api/blocks/getEpoch  */
String ARK::API::Block::Gettable::epoch(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getEpoch_s);

  return ARK::API::Block::Gettable::epochfromJSON(callback);
};

/*
{
  "success":true,
  "epoch":  "String"
}
*/
String ARK::API::Block::Gettable::epochfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return jString->valueFor("epoch");
};
/*  ==============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::height  */
/*  /api/blocks/getHeight  */
ARK::API::Block::Respondable::Height ARK::API::Block::Gettable::height(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getHeight_s);

  return ARK::API::Block::Gettable::heightfromJSON(callback);
};

/*
{
  "success":true,
  "height": String,
  "id": "String"
}
*/
ARK::API::Block::Respondable::Height ARK::API::Block::Gettable::heightfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return ARK::API::Block::Respondable::Height(jString->valueFor("height").c_str(), jString->valueFor("id").c_str());
};
/*  ===============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::Block::Gettable::nethash  */
/*  /api/blocks/getNethash  */
Hash ARK::API::Block::Gettable::nethash(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getNethash_s);

  return ARK::API::Block::Gettable::nethashfromJSON(callback);
};

/*
{
  "success":true,
  "nethash":  "Hash"
}
*/
Hash ARK::API::Block::Gettable::nethashfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Hash(jString->valueFor("nethash").c_str());
};
/*  ================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ============================  */
/*  ARK::API::Block::Gettable::fee  */
/*  /api/blocks/getFee  */
Balance ARK::API::Block::Gettable::fee(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getFee_s);

  return ARK::API::Block::Gettable::feefromJSON(callback);
};

/*
{ "success":true,
  "fee":  Balance
}
*/
Balance ARK::API::Block::Gettable::feefromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Balance(jString->valueFor("fee").c_str());
};
/*  ============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =============================  */
/*  ARK::API::Block::Gettable::fees  */
/*  /api/blocks/getFees  */
ARK::Fees ARK::API::Block::Gettable::fees(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getFees_s);

  return ARK::API::Block::Gettable::feesfromJSON(callback);
};

/*
{ "success":true,
  "fees":{
    "send": Balance,
    "vote": Balance,
    "secondsignature": Balance,
    "delegate": Balance,
    "multisignature": Balance
  }
}
*/
ARK::Fees ARK::API::Block::Gettable::feesfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return Fees(
        jString->valueIn("fees", "send").c_str(),
        jString->valueIn("fees", "vote").c_str(),
        jString->valueIn("fees", "secondsignature").c_str(),
        jString->valueIn("fees", "delegate").c_str(),
        jString->valueIn("fees", "multisignature").c_str()
    );
};
/*  =============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Block::Gettable::milestone  */
/*  /api/blocks/getMilestone  */
String ARK::API::Block::Gettable::milestone(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getMilestone_s);

  return ARK::API::Block::Gettable::milestonefromJSON(callback);
};

/*
{
  "success":true,
  "milestone": String
}
*/
String ARK::API::Block::Gettable::milestonefromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return jString->valueFor("milestone");
};
/*  ==================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::reward  */
/*  /api/blocks/getReward  */
Balance ARK::API::Block::Gettable::reward(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getReward_s);

  return ARK::API::Block::Gettable::rewardfromJSON(callback);
};

/*
{ "success":true,
  "reward": Balance
}
*/
Balance ARK::API::Block::Gettable::rewardfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Balance(jString->valueFor("reward").c_str());
};
/*  ===============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::supply  */
/*  /api/blocks/getSupply  */
Balance ARK::API::Block::Gettable::supply(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getSupply_s);

  return ARK::API::Block::Gettable::supplyfromJSON(callback);
};

/*
{
  "success":true,
  "supply": Balance
}
*/
Balance ARK::API::Block::Gettable::supplyfromJSON(const char* _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Balance(jString->valueFor("supply").c_str());
};
/*  ===============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::status  */
/*  /api/blocks/getStatus  */
ARK::API::Block::Respondable::Status ARK::API::Block::Gettable::status(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Block::getStatus_s);

  return ARK::API::Block::Gettable::statusfromJSON(callback);
};

/*
{ "success":true,
  "epoch":  "String",
  "height": String,
  "fee":  Balance,
  "milestone":  String,
  "nethash":" Hash",
  "reward":_reward,
  "supply":_supply
}
*/
ARK::API::Block::Respondable::Status ARK::API::Block::Gettable::statusfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);
  
    return ARK::API::Block::Respondable::Status(
        jString->valueFor("epoch").c_str(),
        jString->valueFor("height").c_str(),
        jString->valueFor("fee").c_str(),
        convert_to_int(jString->valueFor("milestone")),
        jString->valueFor("nethash").c_str(),
        jString->valueFor("reward").c_str(),
        jString->valueFor("supply").c_str()
    );
};
/*  ===============================  */
/*  ==========================================================================  */
