#include "models/transaction.h"

#include <cstring>
#include <cstdio>

namespace ARK {

Transaction::Transaction(
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
) :
    id_(),
    blockid_(),
    height_(),
    type_(t),
    timestamp_(),
    amount_(a),
    fee_(f),
    vendorField_(),
    senderId_(si),
    recipientId_(ri),
    senderPublicKey_(spk),
    signature_(),
    confirmations_()
{
    strncpy(id_, i, sizeof(id_) / sizeof(id_[0]));
    strncpy(blockid_, b, sizeof(blockid_) / sizeof(blockid_[0]));
    strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
    strncpy(timestamp_, ts, sizeof(timestamp_) / sizeof(timestamp_[0]));
    strncpy(vendorField_, vf, sizeof(vendorField_) / sizeof(vendorField_[0]));
    strncpy(signature_, s, sizeof(signature_) / sizeof(signature_[0]));
    strncpy(confirmations_, c, sizeof(confirmations_) / sizeof(confirmations_[0]));
}


size_t Transaction::printTo(Print& p) const
{
	size_t size = 0;
		size += p.print("\nid: ");
		size += p.print(this->id_);

		size += p.print("\nblockid: ");
		size += p.print(this->blockid_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\ntype: ");
		size += p.print(this->type_);

		size += p.print("\ntimestamp: ");
		size += p.print(this->timestamp_);

		size += p.print("\namount: ");
		size += p.print(this->amount_.ark());

		size += p.print("\nfee: ");
		size += p.print(this->fee_.ark());

		size += p.print("\nvendorField: ");
		size += p.print(this->vendorField_);

		size += p.print("\nsenderId: ");
		size += p.print(this->senderId_.getValue());

		size += p.print("\nrecipientId: ");
		size += p.print(this->recipientId_.getValue());

		size += p.print("\nsenderPublicKey: ");
		size += p.print(this->senderPublicKey_.getValue());

		size += p.print("\nsignature: ");
		size += p.print(this->signature_);

		size += p.print("\nconfirmations: ");
		size += p.print(this->confirmations_);
	return size;
}

}
