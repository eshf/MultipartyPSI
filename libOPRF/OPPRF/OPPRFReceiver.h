#pragma once

#include "Common/Defines.h"
#include "Network/Channel.h"
#include "NChooseOne/NcoOtExt.h"
#include "Hashing/CuckooHasher1.h"
#include "Hashing/SimpleHasher1.h"
#include "OPPRF/binSet.h"

namespace osuCrypto
{

    class OPPRFReceiver
    {
    public:
        OPPRFReceiver();
        ~OPPRFReceiver();
        
        //static const uint64_t CodeWordSize = 7;
        //static const uint64_t hasherStepSize;

		
        uint64_t mN, mParties, mStatSecParam, mNcoInputBlkSize;// , mOtMsgBlkSize;
        block mHashingSeed;
        std::vector<uint64_t> mIntersection;

		//std::vector<std::vector<block>> mNcoInputBuff;

		std::vector<std::unique_ptr<NcoOtExtSender>> mOtSends;
        std::vector<std::unique_ptr<NcoOtExtReceiver>> mOtRecvs;
		//CuckooHasher1 mCuckooBins;
		//SimpleHasher1 mSimpleBins;
        PRNG mPrng;

		uint64_t mNumBFhashs = 40;
		uint64_t mBfSize;
		std::vector<AES> mBFHasher;
		
		void init(u32 opt, uint64_t numParties, uint64_t n, uint64_t statSecParam, uint64_t inputBitSize, Channel& chl0, uint64_t otCounts, NcoOtExtReceiver& otRecv, NcoOtExtSender& otSend, block seed, bool isOtherDirection=true);
		void init(u32 opt, uint64_t numParties, uint64_t n, uint64_t statSecParam, uint64_t inputBitSize, const std::vector<Channel*>& chls, uint64_t otCounts, NcoOtExtReceiver& ots, NcoOtExtSender& otSend, block seed, bool isOtherDirection=true);

	

		//void copy2Bins(CuckooHasher1& cuckooBins);

		void getOPRFkeys( uint64_t IdxTheirParty, binSet& bins, Channel& chl, bool isOtherDirectionGetOPRF=true);
		void getOPRFkeys(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = true);

		void getOPRFkeysSeperatedandTable(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = true);

		void getOPRFkeysSeperated(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = true);

		void getOPRFkeysCombined(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = true);
		

		void recvSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, Channel& chl);
		void sendSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, Channel& chl);
		void sendSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);


		void recvSSTableBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvSSPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvFullPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvBFBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);



		void sendSSTableBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void sendSSPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void sendFullPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void sendBFBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);



    };




}
