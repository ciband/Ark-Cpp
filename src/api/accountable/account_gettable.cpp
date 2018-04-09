#include "api/accountable/account_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "utilities/connector.h"

/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Account::Gettable::balance  */
/*  /api/accounts/getBalance?address=arkAddress */
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balance(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO: check size
    strcpy(uri, ARK::API::Paths::Account::getBalance_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());
  
    auto callback = netManager.cb(uri);

    return ARK::Utilities::get_json_interface().accounts_getBalance_fromJSON(callback.c_str());
};

/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::publickey  */
/*  /api/accounts/getPublickey?address=arkAddress */
Publickey ARK::API::Account::Gettable::publickey(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);
    return ARK::Utilities::get_json_interface().accounts_getPublickey_fromJSON(callback.c_str());
};



/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::Account::Gettable::delegatesFee  */
/*  /api/accounts/delegates/fee?address=arkAddress  */
Balance ARK::API::Account::Gettable::delegatesFee(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{

    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);

    return ARK::Utilities::get_json_interface().accounts_delegates_fee_fromJSON(callback.c_str());
};





/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Account::Gettable::delegates  */
/*  /api/accounts/delegates?address=arkAddress  */
std::unique_ptr<ARK::Delegate[]> ARK::API::Account::Gettable::delegates(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegates_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);

    return ARK::Utilities::get_json_interface().accounts_delegates_fromJSON(callback.c_str());
}


/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::account  */
/*  /api/accounts?address=arkAddress  */
ARK::Account ARK::API::Account::Gettable::account(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::accounts_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);

    return ARK::Utilities::get_json_interface().accounts_fromJSON(callback.c_str());
}
