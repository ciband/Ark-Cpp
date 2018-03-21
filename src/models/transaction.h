

#ifndef transaction_h
#define transaction_h

#include "types/balance.h"
#include "types/address.h"
#include "types/publickey.h"
#include "utilities/platform.h"

namespace ARK {

//static const auto TRANSACTION_MAX_SIZE = 600;
    
/*  ==========================================================================  */
  /*  ================  */
  /*  ARK::Transaction  */
  class Transaction : public Printable {

    private:
      char id_[65];  //TODO: review array sizes
      char blockid_[65];
      char height_[65];
      int type_;
      char timestamp_[65];
      Balance amount_;
      Balance fee_;
      char vendorField_[65];
      Address senderId_;
      Address recipientId_;
      Publickey senderPublicKey_;
      char signature_[144];
      char confirmations_[65];

  public:
	  Transaction() = default;

	  Transaction(
		  const char* const i,
		  const char* const b,
		  const char* const h,
		  int t,
		  const char* const ts,
		  const char* const a,
		  const char* const f,
		  const char* const vf,
		  const char* const si,
		  const char* const ri,
		  const char* const spk,
		  const char* const s,
		  const char* const c
	  );

	  const char* id() const noexcept { return id_; }
	  const char* block_id() const noexcept { return blockid_; }
	  const char* height() const noexcept { return height_; }
	  int type() const noexcept { return type_; }
	  const char* timestamp() const noexcept { return timestamp_; }
	  const Balance& amount() const noexcept { return amount_; }
	  const Balance& fee() const noexcept { return fee_; }
	  const char* vendor_field() const noexcept { return vendorField_; }
	  const Address& sender_id() const noexcept { return senderId_; }
	  const Address& recipient_id() const noexcept { return recipientId_; }
	  const Publickey& sender_publickey() const noexcept { return senderPublicKey_; }
	  const char* signature() const noexcept { return signature_; }
	  const char* confirmations() const noexcept { return confirmations_; }

      size_t printTo(Print& p) const override;
  };
  /*  ================  */
/*  ==========================================================================  */

};

#endif
 