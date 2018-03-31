#include "api/peerable/peer_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <cstring>
#include <cstdio>

/*  ==========================================================================  */
/*  ============================  */
/*  ARK::API::Peer::Gettable::peer  */
/*  /api/delegates/fee  */
ARK::Peer ARK::API::Peer::Gettable::peer(
    ARK::Utilities::Network::Connector& _netConnector,
    const char* const _ip,
    int _port)
{
    char uri[64] = { '\0' };  //TODO: review sizes
    strcpy(uri, ARK::API::Paths::Peer::get_s);
    strcat(uri, "?ip=");
    strcat(uri, _ip);
    strcat(uri, "&port=");
    const auto len = strlen(uri);
    sprintf(uri + len, "%d", _port);

    auto callback = _netConnector.cb(uri);

    return ARK::Utilities::get_json_interface().peers_get_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~11,000 bytes  */
/*  =============================  */
/*  ARK::API::PeerGettable::peers  */
/*  /api/peers  */
std::unique_ptr<ARK::Peer[]> ARK::API::Peer::Gettable::peers(ARK::Utilities::Network::Connector& _netConnector) {
   auto callback = _netConnector.cb(ARK::API::Paths::Peer::peers_s);
   return ARK::Utilities::get_json_interface().peers_fromJSON(callback.c_str());
 }

/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::PeerGettable::version  */
/*  /api/peers/version  */
ARK::API::Peer::Respondable::Version ARK::API::Peer::Gettable::version(
    ARK::Utilities::Network::Connector& _netConnector
)
{
    auto callback = _netConnector.cb(ARK::API::Paths::Peer::version_s);

    return ARK::Utilities::get_json_interface().peers_version_fromJSON(callback.c_str());
}

