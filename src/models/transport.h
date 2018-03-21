

#ifndef transport_h
#define transport_h

namespace ARK
{
  /*************************************************
  *	ARK::TransportPeerHeader
  **************************************************/
  struct TransportPeerHeader
  {
    public:
      char id[32];
      char height[32];
      int version;
      Balance totalAmount;
      Balance totalFee;
      Balance reward;
      Hash payloadHash;
      int payloadLength;
      char timestamp[32];
      int numberOfTransactions;
      char previousBlock[32];
      Publickey generatorPublicKey;
      Signature blockSignature;
  }; 
  /*************************************************/

};

#endif
