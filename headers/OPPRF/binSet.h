#pragma once

#include "Common/Defines.h"
#include "Network/Channel.h"
#include "NChooseOne/NcoOtExt.h"
#include "Hashing/CuckooHasher1.h"
#include "Hashing/SimpleHasher1.h"

namespace osuCrypto
{

	//struct BFParam
	//{
	//	double mBinScaler[2]; //first index is for init step, 2nd index for stash step
	//	uint64_t mNumHashes[2];
	//	uint64_t mSenderBinSize[2];
	//	/*
	//	double mBinStashScaler;
	//	uint64_t mNumStashHashes;
	//	uint64_t mSenderBinStashSize;*/
	//};

    class binSet
    {
    public:
		binSet();
        ~binSet();
		

        uint64_t mN, mParties, mMyIdx, mStatSecParam, mNcoInputBlkSize;// , mOtMsgBlkSize;
        block mHashingSeed;
		uint64_t mMaskSize;
		uint64_t mOpt;

		std::vector<std::vector<block>> mNcoInputBuff; //hash(x)

	//	OPPRFSender aaa;
		std::vector<block> mXsets;
		

		CuckooHasher1 mCuckooBins;
		SimpleHasher1 mSimpleBins;
      

		void init(uint64_t myIdx, uint64_t nParties, uint64_t setSize, uint64_t statSecParam, uint64_t opt);

		void hashing2Bins(std::vector<block>& inputs, int numThreads);
    };

}
