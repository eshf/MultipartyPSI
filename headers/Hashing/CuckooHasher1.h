#pragma once
#include "Common/Defines.h"
#include "Common/Log.h"
#include "Common/BitVector.h"
#include "Common/ArrayView.h"
#include "Common/MatrixView.h"
#include "Hashing/BitPosition.h"
//#include <mutex>
#include <atomic>

//#define THREAD_SAFE_CUCKOO

namespace osuCrypto
{
    struct CuckooParam1
    {
        double mBinScaler[2]; //first index is for init step, 2nd index for stash step
		uint64_t mNumHashes[2];
		uint64_t mSenderBinSize[2];
/*
		double mBinStashScaler;
		uint64_t mNumStashHashes;
		uint64_t mSenderBinStashSize;*/
    };



    class CuckooHasher1
    {
    public:
        CuckooHasher1();
        ~CuckooHasher1();

        struct Bin
        {
            Bin() :mVal(-1) {}
            Bin(uint64_t idx, uint64_t hashIdx) : mVal(idx | (hashIdx << 56)) {}

            bool isEmpty() const;
            uint64_t idx() const;
            uint64_t hashIdx() const;

            void swap(uint64_t& idx, uint64_t& hashIdx);
#ifdef THREAD_SAFE_CUCKOO
            Bin(const Bin& b) : mVal(b.mVal.load(std::memory_order_relaxed)) {}
            Bin(Bin&& b) : mVal(b.mVal.load(std::memory_order_relaxed)) {}
            std::atomic<uint64_t> mVal;
#else
            Bin(const Bin& b) : mVal(b.mVal) {}
            Bin(Bin&& b) : mVal(b.mVal) {}
            uint64_t mVal;
			std::vector<block> mValOPRF;
			std::vector<u8> mValMap;

			std::vector<std::vector<block>> mCoeffs;//mBits[IdxParty][mIdx]
#endif
        };
        struct Workspace
        {
            Workspace(uint64_t n)
                : curAddrs(n)
                , curHashIdxs(n)
                , oldVals(n)
                //, findAddr(n)
                , findVal(n)
            {}

            std::vector<uint64_t>
                curAddrs,// (inputIdxs.size(), 0),
                curHashIdxs,// (inputIdxs.size(), 0),
                oldVals;// (inputIdxs.size());

            std::vector<std::array<uint64_t, 2>> /*findAddr,*/ findVal;
        };


		std::mutex mInsertBin;
        uint64_t mTotalTries;

        bool operator==(const CuckooHasher1& cmp)const;
        bool operator!=(const CuckooHasher1& cmp)const;

        //std::mutex mStashx;

        CuckooParam1 mParams;
		block mHashSeed;
		uint64_t  mRepSize, mInputBitSize, mN;
		uint64_t mBinCount[2];//mBinCount[0] for init step, mBinCount[1] for Stash step
        void print(uint64_t IdxParty, bool isIdx, bool isOPRF, bool isMap) const;
		void init(uint64_t n,uint64_t opt);
        void insert(uint64_t IdxItem, ArrayView<uint64_t> hashes);
        void insertHelper(uint64_t IdxItem, uint64_t hashIdx, uint64_t numTries);
		void insertStashHelper(uint64_t IdxItem, uint64_t hashIdx, uint64_t numTries);

        void insertBatch(ArrayView<uint64_t> itemIdxs, MatrixView<uint64_t> hashs, Workspace& workspace);

		
			void insertStashBatch(ArrayView<uint64_t> itemIdxs, MatrixView<uint64_t> hashs, Workspace& workspace);


        uint64_t find(ArrayView<uint64_t> hashes);
        uint64_t findBatch(MatrixView<uint64_t> hashes, 
            ArrayView<uint64_t> idxs,
            Workspace& wordkspace);

   // private:

        std::vector<uint64_t> mHashes;
        MatrixView<uint64_t> mHashesView;

		std::vector<uint64_t> mStashHashes;
		MatrixView<uint64_t> mStashHashesView;

        std::vector<Bin> mBins;
        std::vector<Bin> mStashBins;
		std::vector<uint64_t> mStashIdxs;

        //std::vector<Bin> mBins;
        //std::vector<Bin> mStash;


        //void insertItems(std::array<std::vector<block>,4>& hashs);
    };

}
