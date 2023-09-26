#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "NChooseOne/NcoOtExt.h"
#include "Network/Channel.h"
#include <vector>

#ifdef GetMessage
#undef GetMessage
#endif

namespace osuCrypto
{

    class KkrtNcoOtReceiver : public NcoOtExtReceiver
    {
    public:


        KkrtNcoOtReceiver()
            :mHasBase(false)
        {}

        bool hasBaseOts() const override
        {
            return mHasBase;
        }

        bool mHasBase;
        std::vector<std::array<PRNG,2>> mGens;
        MatrixView<block> mT0;
        MatrixView<block> mT1;
        uint64_t mCorrectionIdx;

        void setBaseOts(
            ArrayView<std::array<block, 2>> baseRecvOts) override;
        

        void init(uint64_t numOtExt) override;


        std::unique_ptr<NcoOtExtReceiver> split() override;

        void encode(
            uint64_t otIdx,
            const ArrayView<block> inputword,
            block& val) override;

        void zeroEncode(uint64_t otIdx) override;

        void getParams(
            bool maliciousSecure,
            uint64_t compSecParm, uint64_t statSecParam, uint64_t inputBitCount, uint64_t inputCount,
            uint64_t& inputBlkSize, uint64_t& baseOtCount) override;


        void sendCorrection(Channel& chl, uint64_t sendCount) override;

        void check(Channel& chl) override {}
    };

}
