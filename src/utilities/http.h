

#ifndef HTTP_H
#define HTTP_H

#include "platform.h"

//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>

namespace ARK
{
namespace Utilities
{
namespace Network
{

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
  class HTTPConnectable;
/*  ==========================================================================  */




/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::HTTP 
*   Currently using ESP8266 libs
*
* The purpose of this class is to serve as an
*   entry point for integrating the HTTPClient
*   library for different boards/chipsets
**************************************************/
  class HTTP {
    public: 
     // bool isReachable = false;

      HTTP(){};

     String get(const String& peer, int port, const String& request);
  };
/*  ==========================================================================  */


};
};
};



/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
class ARK::Utilities::Network::HTTPConnectable
{
public:

  ARK::Utilities::Network::HTTP http;
};
/*  ==========================================================================  */





/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::HTTP 
**************************************************/
String ARK::Utilities::Network::HTTP::get(const String& peer, int port, const String& request)
{
#if 0
  HTTPClient http;

 // if (this->isReachable == false)
//  {
 //   http.setReuse(true);
    http.setTimeout(1000);
	Serial.println("Opening HTTP connection to " + peer + ":" + String(port));
    http.begin(peer, port, request);
 //   this->isReachable = true;
 // }
 // else
 // {
 //   http.begin(request);
 // };

  int httpCode = http.GET();

  while (!http.connected())
  {
    delay(1000);
    Serial.println("waiting for HTTP connection for " + request);
  };

  //this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());

  //if (this->isReachable)
  if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
  {
    String streamStr = String(http.getStreamPtr()->readString());

    http.end();

    return streamStr;
  }
  else
  {
    http.end();

    return "Error: Connection to Peer could not be established";
  };
#else 
return "";
#endif
};
/*  ==========================================================================  */


#endif