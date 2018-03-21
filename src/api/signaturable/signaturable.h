#ifndef SIGNATURABLE_H
#define SIGNATURABLE_H

#include "api/signaturable/signature_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Signaturable
*   	public Signature::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Signature Loader Model
* 
**************************************************/
class Signaturable :
  	public Signature::Gettable,
  	virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*		/api/signatures/fee
		*
		*		@uri:	/api/signatures/fee
		*		@returnType:	Balance
		*
		*   @method:	signaturesFee()
		*
		*   @outs:	ARK::API::Signature::Gettable::fee(this->netConnector)
		*
		*   @description:
		*			Gets cost of Signature from a Node via API.
		* 
		**************************************************/
    
    Balance signaturesFee()
    {
      return ARK::API::Signature::Gettable::fee(this->netConnector);
    };
    /*************************************************/

};

// namespace signature_cb {
//   struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};
// };

};
};


#endif
