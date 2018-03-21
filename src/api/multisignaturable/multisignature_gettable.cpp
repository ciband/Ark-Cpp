#include "api/multisignaturable/multisignature_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <cstring>

/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::MultiSignatureGettable::pending  */
/*  /api/multisignatures/pending?publicKey=  */
String ARK::API::MultiSignature::Gettable::pending(
    ARK::Utilities::Network::Connector& _netConnector, 
    const Publickey& _publicKey
)
{
    char uri[512] = { '\0' }; //TODO: check size

    strcpy(uri, ARK::API::Paths::MultiSignatures::pending_s);
    strcat(uri, "?publicKey=");
    strcat(uri, _publicKey.getValue());

    auto callback = _netConnector.cb(uri);

    return ARK::API::MultiSignature::Gettable::pendingfromJSON(callback);
};

/*
{
  "success":true,
  "transactions":[]
}
*/
String ARK::API::MultiSignature::Gettable::pendingfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);
  
  return jString->valueFor("transactions");
};
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
  /*  ==========================================  */
  /*  ARK::API::MultiSignature::Gettable::accounts  */
  // /*  /api/multisignatures/accounts?publicKey=  */
  // String ARK::API::MultiSignatureGettable::accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey) {
  //   String uri = ARK::API::Paths::MultiSignatures::accounts_s;
  //     uri += "?publicKey=";
  //     uri += _publicKey;
  //   String callback = _netConnector.cb(uri);
  //   return ARK::API::MultiSignature::Gettable::accountsfromJSON(callback);
  // };

  /*  Only on Mainnet?  */
  // String ARK::API::MultiSignature::Gettable::accountsfromJSON(String _jsonStr) {
  //   auto jString = ARK::Utilities::make_json_string(_jsonStr);
  //   return jString->valueFor("??");
  // };
  /*  ==========================================  */
/*  ==========================================================================  */
/*  ==========================================================================  */
