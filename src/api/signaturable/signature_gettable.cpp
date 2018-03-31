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

    return ARK::Utilities::get_json_interface().signatures_Fee_fromJSON(callback.c_str());
}

