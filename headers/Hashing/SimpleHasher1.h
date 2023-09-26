#pragma once
#include "Common/Defines.h"
#include "Common/BitVector.h"
#include "Common/ArrayView.h"
#include "Hashing/BitPosition.h"
namespace osuCrypto
{
	//// a list of {{set size, bit size}}
	//std::vector<std::array<uint64_t, 2>> binSizes
	//{
	//    {1<<12, 18},
	//    {1<<16, 19},
	//    {1<<20, 20},
	//    {1<<24, 21}
	//};



	struct SimpleParam1
	{

		double mBinScaler[2];
		uint64_t mNumHashes[2];

		uint64_t mMaxBinSize[2];
		uint64_t mNumBits[2];
		/*
		double mBinStashScaler;
		uint64_t mNumStashHashes;
		uint64_t mSenderBinStashSize;*/
	};

	class SimpleHasher1
	{
	public:
		SimpleHasher1();
		~SimpleHasher1();

		
		//typedef std::vector<uint64_t,block> MtBin;
		//typedef std::vector<std::pair<uint64_t, block>> MtBin;
		struct Bin
		{
			std::vector<uint64_t> mIdx; //have many items in the bin
								   //hash index used for mIdx. Only use when combined hints
								   //one can think mIdx and hIdx as a pair <mIdx,hIdx>....
			std::vector<uint64_t> hIdx;
			std::vector<BitPosition> mBits;//mBits[IdxParty]
			std::vector<std::vector<block>> mValOPRF; //mValOPRF[IdxParty][mIdx]
		};
		uint64_t  mRepSize, mInputBitSize, mN;
		uint64_t mBinCount[2], mMaxBinSize[2], mNumHashes[2], mNumBits[2];

		//mOpprfs[IdxParty][inputIdx][hIdx]
		std::vector<std::vector<std::vector<block>>> mOprfs;
		uint64_t testMaxBinSize;
		std::vector<uint64_t> realBinSizeCount1;
		std::vector<uint64_t> realBinSizeCount2;

		std::unique_ptr<std::mutex[]> mMtx;
		std::vector<Bin> mBins;
		block mHashSeed;
		SimpleParam1 mParams;
		void print(uint64_t idxParty, bool isIdx, bool isOPRF, bool isMap, bool isPos, uint64_t opt = 0) const;

		uint64_t maxRealBinSize();

		void init(uint64_t n, uint64_t opt);

		void insertBatch(
			ArrayView<uint64_t> inputIdxs,
			MatrixView<uint64_t> hashs);

		//void preHashedInsertItems(ArrayView<block> items, uint64_t itemIdx);
		//void insertItemsWithPhasing(ArrayView<block> items, uint64_t itemIdx);
	};

}
