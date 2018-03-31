#include "api/transactionable/transaction_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "types/hash.h"
#include "utilities/connector.h"
#include "helpers/subcount.h"

#include <cstring>
#include <memory>

/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Transaction::Gettable::transaction  */
/*  /api/transactions/get?id=  */
ARK::Transaction ARK::API::Transaction::Gettable::transaction(
    ARK::Utilities::Network::Connector& netConnector, 
    const Hash& id
) {
    char uri[512] = { '\0' }; //TODO review sizes

    strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
    strcat(uri, "?id=");
    strcat(uri, id.getValue());

    auto callback = netConnector.cb(uri);
    return ARK::Utilities::get_json_interface().transactions_get_fromJSON(callback.c_str());
}


/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
/*  ===========================================  */
/*  ARK::API::Transaction::Gettable::transactions  */
// /*  /api/transactions */
 std::unique_ptr<ARK::Transaction[]> ARK::API::Transaction::Gettable::transactions(ARK::Utilities::Network::Connector& netConnector) {
   auto callback = netConnector.cb(ARK::API::Paths::Transaction::transactions_s);
   return ARK::Utilities::get_json_interface().transactions_fromJSON(callback.c_str());
 }

/*  ==========================================================================  */
/*  =====================================================  */
/*  ARK::API::Transaction::Gettable::transactionUnconfirmed  */
/*  /api/transactions/unconfirmed/get?id=  */
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionUnconfirmed(
    ARK::Utilities::Network::Connector& netConnector, 
    const Hash& id
) {
    char uri[1024] = { '\0' }; //TODO review sizes

    strcpy(uri, ARK::API::Paths::Transaction::getSingleUnconfirmed_s);
    strcat(uri, "?id=");
    strcat(uri, id.getValue());

    auto callback = netConnector.cb(uri);
    return ARK::Utilities::get_json_interface().transactions_unconfirmed_get_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ======================================================  */
/*  ARK::API::Transaction::Gettable::transactionsUnconfirmed  */
/*  /api/transactions/unconfirmed  */
std::unique_ptr<ARK::API::Transaction::Respondable::Unconfirmed[]> ARK::API::Transaction::Gettable::transactionsUnconfirmed(
    ARK::Utilities::Network::Connector& netConnector
) {
    auto callback = netConnector.cb(ARK::API::Paths::Transaction::unconfirmed_s);

    return ARK::Utilities::get_json_interface().transactions_unconfirmed_fromJSON(callback.c_str());
}
