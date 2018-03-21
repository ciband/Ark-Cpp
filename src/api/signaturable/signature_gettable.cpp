#include "api/signaturable/signature_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::SignatureGettable::fee  */
/*  /api/signatures/fee  */
Balance ARK::API::Signature::Gettable::fee(ARK::Utilities::Network::Connector& _netConnector)
{
    auto callback = _netConnector.cb(ARK::API::Paths::Signatures::fee_s);

    return ARK::API::Signature::Gettable::feefromJSON(callback);
}

/*
{
  "success":true,
  "fee":  Balance
}
*/
Balance ARK::API::Signature::Gettable::feefromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Balance(jString->valueFor("fee").c_str());
}
/*  ================================  */
/*  ==========================================================================  */
