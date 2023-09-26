#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use.  
#include "NChooseOne/NcoOtExt.h"
#include "NChooseOne/KkrtNcoOtSender.h"
#include "Common/BitVector.h"
#include "Common/MatrixView.h"
#include "Base/naor-pinkas.h"
#include "Tools/LinearCode.h"
#include "Network/Channel.h"

#include <array>
#include <vector>
#ifdef GetMessage
#undef GetMessage
#endif


namespace osuCrypto {

    class OosNcoOtSender 
        : public NcoOtExtSender
        //: public KkrtNcoOtSender
    {
    public: 

        OosNcoOtSender(LinearCode& code)
            : mCode(code)
        {}
        ~OosNcoOtSender();

        LinearCode mCode;

        std::vector<PRNG> mGens;
        BitVector mBaseChoiceBits;
        std::vector<block> mChoiceBlks;
        MatrixView<block> mT, mCorrectionVals;
        uint64_t mCorrectionIdx;




        bool hasBaseOts() const override
        {
            return mBaseChoiceBits.size() > 0;
        }

        void setBaseOts(
            ArrayView<block> baseRecvOts,
            const BitVector& choices) override;

        std::unique_ptr<NcoOtExtSender> split() override;


        void init(uint64_t numOtExt) override;


        void encode(
            uint64_t otIdx,
            const ArrayView<block> codeWord,
            block& val) override;

        void getParams(
            bool maliciousSecure,
            uint64_t compSecParm, uint64_t statSecParam, uint64_t inputBitCount, uint64_t inputCount,
            uint64_t& inputBlkSize, uint64_t& baseOtCount) override;

        void recvCorrection(Channel& chl, uint64_t recvCount) override;

        void check(Channel& chl) override;
    };
}

