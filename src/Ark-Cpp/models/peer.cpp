<<<<<<< HEAD
#include "peer.h"

#include <cstring>
#include <cstdio>

ARK::Peer::Peer(
	const char* const i,
	int p,
	const char* const v,
	int e,
	const char* const o,
	const char* const h,
	const char* const s,
	int d
) : ip_(), port_(p), version_(), errors_(e), os_(), height_(), status_(), delay_(d) {
	strncpy(ip_, i, sizeof(ip_) / sizeof(ip_[0]));
	strncpy(version_, v, sizeof(version_) / sizeof(version_[0]));
	strncpy(os_, o, sizeof(os_) / sizeof(os_[0]));
	strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
	strncpy(status_, s, sizeof(status_) / sizeof(status_[0]));
}

size_t ARK::Peer::printTo(Print& p) const
=======


#include "models.h"

ARK::Peer::Peer(
		const char *const newIP,
		int 							newPort,
		const char *const newVersion,
		int 							newErrors,
		const char *const newOS,
		const char *const newHeight,
		const char *const newStatus,
		int 							newDelay
)
{
	strncpy(ip, newIP, sizeof(ip) / sizeof(ip[0]));
	port = newPort;
	strncpy(version, newVersion, sizeof(version) / sizeof(version[0]));
	errors = newErrors;
	strncpy(os, newOS, sizeof(os) / sizeof(os[0]));
	strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
	strncpy(status, newStatus, sizeof(status) / sizeof(status[0]));
	delay = newDelay;
};

/*************************************************
*
**************************************************/
size_t ARK::Peer::printTo(Print &p) const
>>>>>>> master
{
	size_t size = 0;

	size += p.print("ip: ");
<<<<<<< HEAD
	size += p.print(this->ip_);

	size += p.print("\nport: ");
	size += p.print(this->port_);

	size += p.print("\nversion: ");
	size += p.print(this->version_);

	size += p.print("\nerrors: ");
	size += p.print(this->errors_);

	size += p.print("\nos: ");
	size += p.print(this->os_);

	size += p.print("\nheight: ");
	size += p.print(this->height_);

	size += p.print("\nstatus: ");
	size += p.print(this->status_);

	size += p.print("\ndelay: ");
	size += p.print(this->delay_);

	return size;
}

=======
	size += p.print(this->ip);

	size += p.print("\nport: ");
	size += p.print(this->port);

	size += p.print("\nversion: ");
	size += p.print(this->version);

	size += p.print("\nerrors: ");
	size += p.print(this->errors);

	size += p.print("\nos: ");
	size += p.print(this->os);

	size += p.print("\nheight: ");
	size += p.print(this->height);

	size += p.print("\nstatus: ");
	size += p.print(this->status);

	size += p.print("\ndelay: ");
	size += p.print(this->delay);

	return size;
}
/*************************************************/
>>>>>>> master
