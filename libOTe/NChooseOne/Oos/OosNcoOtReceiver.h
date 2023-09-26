#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "NChooseOne/NcoOtExt.h"
#include "Network/Channel.h"
#include <vector>
#include "Tools/LinearCode.h"
//#include "NChooseOne/KkrtNcoOtReceiver.h"
#ifdef GetMessage
#undef GetMessage
#endif

namespace osuCrypto
{

    class OosNcoOtReceiver 
        : public NcoOtExtReceiver
        //: public KkrtNcoOtReceiver
    {
    public:


        OosNcoOtReceiver(LinearCode& code);

        bool hasBaseOts()const override
        {
            return mHasBase;
        }

        bool mHasBase;
        LinearCode mCode;

        std::vector<std::array<PRNG, 2>> mGens;
        MatrixView<block> mT0;
        MatrixView<block> mT1;
        MatrixView<block> mW;
        uint64_t mCorrectionIdx;

#ifndef NDEBUG
        std::vector<u8> mEncodeFlags;
#endif

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

        void check(Channel& chl) override;
    };

}
