

#ifndef NETWORKS_H
#define NETWORKS_H

#include "utilities/platform.h"
#include "models/network.h"

namespace ARK
{
namespace Constants
{
namespace Networks
{

namespace Devnet
{

	/*
			ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
			ARK::API::Manager mngr(devnet);
					Serial.println(mngr.network.nethash);
					Serial.println(mngr.network.token);
					Serial.println(mngr.network.symbol);
					Serial.println(mngr.network.explorer);
					Serial.println(mngr.network.version);

			Outputs: =====
				578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
				DARK
				DѦ
				https://dexplorer.ark.io/
				30
			==============
	*/

	extern const char* nethash;

	extern const char* const seeds[6];

	extern const int port;

    extern const NetworkType type;

	/*	String randomPeer = ARK::Constants::Networks::Devnet::randomPeer();	*/
	inline const char* randomPeer()
	{
		return seeds[random(0, 5)];
	};

	extern const ARK::Network model;
}



namespace Mainnet
{

	/*	TEST
		ARK::Network mainnet = ARK::Constants::Networks::Mainnet::model;
		ARK::API::Manager mngr(mainnet);
		Serial.println(mngr.network.nethash);
		Serial.println(mngr.network.token);
		Serial.println(mngr.network.symbol);
		Serial.println(mngr.network.explorer);
		Serial.println(mngr.network.version);

		Outputs: =====
			6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988
			ARK
			Ѧ
			https://explorer.ark.io/
			23
		==============
	*/

	extern const char* nethash;
	extern const char* const seeds[46];

	extern const int port;

    extern const NetworkType type;

	/*	String randomPeer = ARK::Constants::Networks::Mainnet::randomPeer();	*/
	inline const char* randomPeer()
	{
		return seeds[random(0, 45)];
	};

	extern const ARK::Network model;
}

namespace Network_ADV
{

	extern const ARK::Network_ADV::network_t devnet;

	extern const ARK::Network_ADV::network_t main;

	extern const ARK::Network_ADV::network_t testnet;

	extern const ARK::Network_ADV::network_t bitcoin;
};

};
}
}
#endif
