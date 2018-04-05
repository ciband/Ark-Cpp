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

  return ARK::Utilities::get_json_interface().delegates_count_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Delegate::Gettable::search  */
/*  /api/delegates/search?q=sleepdeficit  */
std::unique_ptr<ARK::API::Delegate::Respondable::Search[]> ARK::API::Delegate::Gettable::search(
    ARK::Utilities::Network::Connector& _netConnector,
    const char* const _username)
{
    char uri[64] = { '\0' }; //TODO review size
    strcpy(uri, ARK::API::Paths::Delegate::search_s);
    strcat(uri, "?q=");
    strcat(uri, _username);

    auto callback = _netConnector.cb(uri);

  return ARK::Utilities::get_json_interface().delegates_search_fromJSON(callback.c_str());
}

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

  return ARK::Utilities::get_json_interface().delegates_voters_fromJSON(callback.c_str());
}

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
	} else {
      strcat(uri, "?username=");
	}

	strcat(uri, _parameter);

	auto callback = _netConnector.cb(uri);

	return ARK::Utilities::get_json_interface().delegates_get_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
/*  =====================================  */
/*  ARK::API::Delegate::Gettable::delegates  */
// /*  /api/delegates  */
std::unique_ptr<ARK::Delegate[]> ARK::API::Delegate::Gettable::delegates(ARK::Utilities::Network::Connector& _netConnector) {
	auto callback = _netConnector.cb(ARK::API::Paths::Delegate::delegates_s);
	return ARK::Utilities::get_json_interface().delegates_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  =================================  */
/*  ARK::API::Delegate::Gettable::fee  */
/*  /api/delegates/fee  */
Balance ARK::API::Delegate::Gettable::fee(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Delegate::fee_s);

  return ARK::Utilities::get_json_interface().delegates_fee_fromJSON(callback.c_str());
}

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

    return ARK::Utilities::get_json_interface().delegates_forging_getForgedByAccount_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::Delegate::Gettable::nextForgers  */
/*  /api/delegates/forging/getNextForgers  */
ARK::API::Delegate::Respondable::NextForgers ARK::API::Delegate::Gettable::nextForgers(
    ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Delegate::getNextForgers_s);

  return ARK::Utilities::get_json_interface().delegates_getNextForgers_fromJSON(callback.c_str());
}

