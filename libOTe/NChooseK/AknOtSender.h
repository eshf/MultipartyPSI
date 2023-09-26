#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "Common/Defines.h"
#include "Network/Channel.h"
#include "Crypto/PRNG.h"
#include "TwoChooseOne/OTExtInterface.h"
#include "Common/BitVector.h"

namespace osuCrypto
{

    class AknOtSender
    {
    public:
        AknOtSender();
        ~AknOtSender();


        //void computeBounds(uint64_t n, uint64_t k, uint64_t statSecPara);


        void init(uint64_t totalOTCount, uint64_t cutAndChooseThreshold, double p,
            OtExtSender& ots, Channel& chl, PRNG& prng)
        {
            std::vector<Channel*> chls{ &chl };
            init(totalOTCount, cutAndChooseThreshold, p, ots, chls, prng);
        }

        void init(uint64_t totalOTCount, uint64_t cutAndChooseThreshold, double p,
            OtExtSender& ots, std::vector<Channel*>& chls, PRNG& prng);

        //std::vector<BitVector> mTheirPermutes;

        std::vector<std::array<block, 2>> mMessages;

        BitVector mSampled;
        //uint64_t mTotalOTCount, mCutAndChooseThreshold;
        //double mCutAndChooseProb;
    };

}
