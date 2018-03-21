#include "api/delegatable/delegate_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "api/helpers.h"

/*  ==========================================================================  */
/*  ===================================  */
/*  ARK::API::Delegate::Gettable::count  */
/*  /api/delegates/count  */
int ARK::API::Delegate::Gettable::count(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Delegate::count_s);

  return ARK::API::Delegate::Gettable::countfromJSON(callback);
};

/*
{ 
  "success":true,
  "count":166
}
*/
int ARK::API::Delegate::Gettable::countfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return convert_to_int(jString->valueFor("count"));
};
/*  ===================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Delegate::Gettable::search  */
/*  /api/delegates/search?q=sleepdeficit  */
ARK::API::Delegate::Respondable::Search ARK::API::Delegate::Gettable::search(
    ARK::Utilities::Network::Connector& _netConnector,
    const char* const _username)
{
    char uri[64] = { '\0' }; //TODO review size
    strcpy(uri, ARK::API::Paths::Delegate::search_s);
    strcat(uri, "?q=");
    strcat(uri, _username);

    auto callback = _netConnector.cb(uri);

  return ARK::API::Delegate::Gettable::searchfromJSON(callback);
};

/*
{ 
  "success":true,
  "delegates":[
    { 
      "username":"_username",
      "address":"_arkAddress",
      "publicKey":"_pubkey",
      "vote":"0000000000000",
      "producedblocks":0,
      "missedblocks":0
    }
  ]
}
*/
ARK::API::Delegate::Respondable::Search ARK::API::Delegate::Gettable::searchfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return ARK::API::Delegate::Respondable::Search(
        jString->subarrayValueIn("delegates", 0, "username").c_str(),
        jString->subarrayValueIn("delegates", 0, "address").c_str(),
        jString->subarrayValueIn("delegates", 0, "publicKey").c_str(),
        jString->subarrayValueIn("delegates", 0, "vote").c_str(),
        convert_to_int(jString->subarrayValueIn("delegates", 0, "producedblocks")),
        convert_to_int(jString->subarrayValueIn("delegates", 0, "missedblocks"))
    );
};
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Delegate::Gettable::voters  */
/*  /api/delegates/voters?publicKey=_pubKey  */
ARK::API::Delegate::Respondable::Voters ARK::API::Delegate::Gettable::voters(
    ARK::Utilities::Network::Connector& _netConnector,
    const Publickey& _publicKey)
{
    char uri[64] = { '\0' }; //TODO review size
    strcpy(uri, ARK::API::Paths::Delegate::voters_s);
    strcat(uri, "?publicKey=");
    strcat(uri, _publicKey.getValue());

    auto callback = _netConnector.cb(uri);

  return ARK::API::Delegate::Gettable::votersfromJSON(callback);
};

/*
{ "success":true,
  "accounts":[
    { "username": "String",
      "address":  "Balance",
      "publicKey":  "Publickey",
      "balance":  "Balance"
    },
    { "username": "String",
      "address":  "Address",
      "publicKey":  "Publickey",
      "balance":  "Balance"
    }
  ]
}
*/
ARK::API::Delegate::Respondable::Voters ARK::API::Delegate::Gettable::votersfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    const auto voterCount = ARK::API::Helpers::substringCount(_jsonStr, "username");

    ARK::API::Delegate::Respondable::Voters voters(voterCount);

    for (auto i = 0; i < voterCount; ++i)
    {
        voters[i] = ARK::Voter(
            jString->subarrayValueIn("accounts", i, "username").c_str(),
            jString->subarrayValueIn("accounts", i, "address").c_str(),
            jString->subarrayValueIn("accounts", i, "publicKey").c_str(),
            jString->subarrayValueIn("accounts", i, "balance").c_str()
        );
    };

    return voters;
};
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Delegate::Gettable::delegate  */
/* 
  /api/delegates/get?username=sleepdeficit
  /api/delegates/get?publicKey=_pubKey
*/
ARK::Delegate ARK::API::Delegate::Gettable::delegate(
    ARK::Utilities::Network::Connector& _netConnector,
    const char* const _parameter)
{
    char uri[512] = { '\0' }; //TODO: review sizes
    strcpy(uri, ARK::API::Paths::Delegate::get_s);

  if (strlen(_parameter) > 20)  //TODO:  refactor this to take a string or a PublicKey object to overload function
  {
      strcat(uri, "?publicKey=");
  }
  else
  {
      strcat(uri, "?username=");
  };

  strcat(uri, _parameter);

  auto callback = _netConnector.cb(uri);

  return ARK::API::Delegate::Gettable::delegatefromJSON(callback);
};

/*
{ 
  "success":true,
  "delegate":{
    "username": "sleepdeficit",
    "address":  "Address",
    "publicKey":  "Publickey",
    "vote": "Balance",
    "producedblocks": String,
    "missedblocks": String,
    "rate": int,
    "approval":d  ouble,
    "productivity": double
  }
}
*/
ARK::Delegate ARK::API::Delegate::Gettable::delegatefromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return ARK::Delegate(
        jString->subvalueIn("delegate", "username").c_str(),
        jString->subvalueIn("delegate", "address").c_str(),
        jString->subvalueIn("delegate", "publicKey").c_str(),
        jString->subvalueIn("delegate", "vote").c_str(),
        convert_to_int(jString->subvalueIn("delegate", "producedblocks")),
        convert_to_int(jString->subvalueIn("delegate", "missedblocks")),
        convert_to_int(jString->subvalueIn("delegate", "rate")),
        convert_to_float(jString->subvalueIn("delegate", "approval")),
        convert_to_float(jString->subvalueIn("delegate", "productivity"))
    );
}
/*  ======================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
/*  =====================================  */
/*  ARK::API::Delegate::Gettable::delegates  */
// /*  /api/delegates  */
// String ARK::API::Delegate::Gettable::delegates(ARK::Utilities::Network::Connector _netConnector) {
//   String uri = ARK::API::Paths::Delegate::delegates_s;
//   String callback = _netConnector.cb(uri);
//   return ARK::API::Delegate::Gettable::delegatesfromJSON(callback);
// };
/*
{ "success":true,
  "delegates":[
    { "username":"d_chris",
      "address":"DQUjMT6fhJWbwhaYL5pPdX9v5qPiRcAzRb",
      "publicKey":"02bcfa0951a92e7876db1fb71996a853b57f996972ed059a950d910f7d541706c9",
      "vote":"11511729062473143",
      "producedblocks":38129,
      "missedblocks":11252,
      "rate":1,
      "approval":88.81,
      "productivity":77.21
    },
    ...
    { "username":"phildark",
      "address":"D6mtwEK2cyT2BRaUZtmgaWYg3XTpEML8s8",
      "publicKey":"03f734e0baae2207eb1a225cf435e75c79b935a806c79edf5733e402cad8852dd8",
      "vote":"2431020000000",
      "producedblocks":7157,
      "missedblocks":4685,
      "rate":51,"approval":0.02,
      "productivity":60.44
    }
  ],
  "totalCount":166
}
*/
// String ARK::API::Delegate::Gettable::delegatesfromJSON(String _jsonStr) {
//   Serial.println("========== delegatesfromJSON ==========");
//   // Serial.println("_jsonStr");
//   // Serial.println(_jsonStr);
//   // Serial.println();
//   auto jString = ARK::Utilities::make_json_string(_jsonStr);
//   int top51Count = 51;
//   // ARK::Delegate delegate[5];
//   ARK::DelegatesResponse delegatesResponse(5);
//   for (int i = 0; i < 5; i++) {
//     ARK::Delegate delegate = {
//       jString->subarrayValueIn("delegates", i, "username"),
//       jString->subarrayValueIn("delegates", i, "address"),
//       jString->subarrayValueIn("delegates", i, "publicKey"),
//       jString->subarrayValueIn("delegates", i, "vote"),
//       jString->subarrayValueIn("delegates", i, "producedblocks").toInt(),
//       jString->subarrayValueIn("delegates", i, "missedblocks").toInt(),
//       jString->subarrayValueIn("delegates", i, "rate").toInt(),
//       jString->subarrayValueIn("delegates", i, "approval").toFloat(),
//       jString->subarrayValueIn("delegates", i, "productivity").toFloat()
//     };
//     delegatesResponse.list[i] = delegate;
//   };
//   String resp;
//   for ( int i = 0; i < 5; i++ ) {
//     resp += "delegate ";  resp += i + 1;	resp += ":\n	";
//       resp += delegatesResponse.list[i].description();
//   };
//   resp += "totalCount:\n";
//     resp += jString->valueFor("totalCount");
//   return resp;
// };
/*  =====================================  */
/*  ==========================================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =================================  */
/*  ARK::API::Delegate::Gettable::fee  */
/*  /api/delegates/fee  */
Balance ARK::API::Delegate::Gettable::fee(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Delegate::fee_s);

  return ARK::API::Delegate::Gettable::feefromJSON(callback);
};

/*
{
  "success":true,
  "fee":  Balance
}
*/
Balance ARK::API::Delegate::Gettable::feefromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Balance(jString->valueFor("fee").c_str());
};
/*  =================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =============================================  */
/*  ARK::API::Delegate::Gettable::forgedByAccount  */
/*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
ARK::API::Delegate::Respondable::ForgedByAccount ARK::API::Delegate::Gettable::forgedByAccount(
    ARK::Utilities::Network::Connector& _netConnector,
    const Publickey& _generatorPublicKey)
{
    char uri[512] = { '\0' }; //TODO: review sizes
    strcpy(uri, ARK::API::Paths::Delegate::getForgedByAccount_s);
    strcat(uri, "?generatorPublicKey=");
    strcat(uri, _generatorPublicKey.getValue());

    auto callback = _netConnector.cb(uri);

    return ARK::API::Delegate::Gettable::forgedByAccountfromJSON(callback);
};

/*
{
  "success":true,
  "fees": "Balance",
  "rewards":  "Balance",
  "forged": "Balance"
}
*/
ARK::API::Delegate::Respondable::ForgedByAccount ARK::API::Delegate::Gettable::forgedByAccountfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return ARK::API::Delegate::Respondable::ForgedByAccount(
        jString->valueFor("fees").c_str(),
        jString->valueFor("rewards").c_str(),
        jString->valueFor("forged").c_str()
    );
}
/*  =============================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::Delegate::Gettable::nextForgers  */
/*  /api/delegates/forging/getNextForgers  */
ARK::API::Delegate::Respondable::NextForgers ARK::API::Delegate::Gettable::nextForgers(
    ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Delegate::getNextForgers_s);

  return ARK::API::Delegate::Gettable::nextForgersfromJSON(callback);
};

/*
{ "success":true,
  "currentBlock":2307497,
  "currentSlot":3189409,
  "delegates":[
    "035ce69858a12a5ac31575c35c7c87a84a1b6a0455697d7015ea756a880aef05c0",
    "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
    "028f0a25321cd9d3bf051b34a835cd5eee0125120c17654bc95790f8f2d970dc46",
    "027d607ba6226b302357aa9b4bb75d0e44761780492f0b38b267d2962d242e6a52",
    "02b7b740973db16cd9c6f0f6f2bc160d27cd2a855e172d887833141bec234eb80c",
    "0212ba6565ea6900ecf1fc5eee172f74aff8b22963be5d0d60e7f773db0055cbd2",
    "02524ea2e2e9bad0ecbe521756388bf65e0b09dd2877d96495fe60200a97b35ddb",
    "02dc13fcb190bcfbe9e7ecfc6269635ed2c497a75bab471f2b15c1a99897da97b3",
    "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
    "031f3dffe4d10f78d85806d6b46f9c9a116e1aa56e8c538da2e02a416ff654b1db"
  ]
}
*/
ARK::API::Delegate::Respondable::NextForgers ARK::API::Delegate::Gettable::nextForgersfromJSON(
    const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    Publickey delegates[10];

    for (int i = 0; i < 10; i++)
    {
        delegates[i] = Publickey(jString->subvalueFor("delegates", i).c_str());
    };

    return ARK::API::Delegate::Respondable::NextForgers(
        jString->valueFor("currentBlock").c_str(),
        jString->valueFor("currentSlot").c_str(),
        delegates
    );
}
  /*  =========================================  */
/*  ==========================================================================  */

