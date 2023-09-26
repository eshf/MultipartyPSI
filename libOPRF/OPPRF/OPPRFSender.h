#pragma once
#include "Common/Defines.h"
#include "Network/Channel.h"
#include "NChooseOne/NcoOtExt.h"
#include "Hashing/SimpleHasher1.h"
#include "Hashing/CuckooHasher1.h"
#include "Hashing/BitPosition.h"
#include "OPPRF/binSet.h"
namespace osuCrypto
{


    class OPPRFSender
    {
    public:


        //static const uint64_t CodeWordSize = 7;
        //static const uint64_t hasherStepSize;

        OPPRFSender();
        ~OPPRFSender();

		uint64_t mN, mParties, mStatSecParam, mNcoInputBlkSize,  mOtMsgBlkSize;
        block mHashingSeed;
		//SimpleHasher1 mSimpleBins;
		//CuckooHasher1 mCuckooBins;

		uint64_t mNumBFhashs = 40;
		uint64_t mBfSize;
		std::vector<AES> mBFHasher;

        PRNG mPrng;
		Timer mTimer;
		double mPosBitsTime=0;

		//std::vector<std::vector<block>> mmOPRF; //mValOPRF[bIdx][Idx]
		//std::vector<BaseOPPRF> mmBits;//mBits[bIdx]


        std::vector<std::unique_ptr<NcoOtExtSender>> mOtSends;
		std::vector<std::unique_ptr<NcoOtExtReceiver>> mOtRecvs;
		//std::vector<std::vector<block>> mNcoInputBuff;

        void init(u32 opt, uint64_t numParties, uint64_t setSize,  uint64_t statSecParam, uint64_t inputBitSize,
            const std::vector<Channel*>& chls, uint64_t otCounts,
            NcoOtExtSender& ots, 
			NcoOtExtReceiver& otRecv,
            block seed, bool isOtherDirection=true);

        void init(u32 opt,uint64_t numParties, uint64_t setSize,uint64_t statSecParam, uint64_t inputBitSize,
            Channel & chl0, uint64_t otCounts,
            NcoOtExtSender& ots,
			NcoOtExtReceiver& otRecv,
            block seed, bool isOtherDirection=true);

		void getOPRFkeys(uint64_t IdxTheirParty, binSet& bins, Channel& chl, bool isOtherDirectionGetOPRF = true);
		

		void getOPRFkeys(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = false);

		void getOPRFkeysSeperatedandTable(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = false);

		void getOPRFkeysSeperated(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = false);
		
		void getOPRFkeysCombined(uint64_t IdxTheirParty, binSet& bins, const std::vector<Channel*>& chls, bool isOtherDirectionGetOPRF = false);

		void sendSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, Channel& chl);
		void recvSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, Channel& chl);
		void sendSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvSS(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);

		void sendSSTableBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts,  const std::vector<Channel*>& chls);
		void sendSSPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void sendFullPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void sendBFBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);


		void recvSSTableBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvSSPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvFullPolyBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);
		void recvBFBased(uint64_t IdxTheirParty, binSet& bins, std::vector<block>& plaintexts, const std::vector<Channel*>& chls);


    };

}