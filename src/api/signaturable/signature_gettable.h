

#ifndef SIGNATURE_GETTABLE_H
#define SIGNATURE_GETTABLE_H

#include "types/balance.h"
#include "utilities/connector.h"

namespace ARK {
namespace API {
namespace Signature {

/*************************************************
*  PROTECTED: ARK::API::Signature::Gettable
**************************************************/
class Gettable {
protected:
/*************************************************
    * ARK::API::SignatureGettable::fee
    *   /api/signatures/fee
    **************************************************/
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);


    /*************************************************/

};


}
}
}

#endif