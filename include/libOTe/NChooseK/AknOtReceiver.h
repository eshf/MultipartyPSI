<<<<<<< HEAD
#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "Common/Defines.h"
#include "Network/Channel.h"
#include "Crypto/PRNG.h"
#include "TwoChooseOne/OTExtInterface.h"
#include "Common/BitVector.h"


namespace osuCrypto
{

class AknOtReceiver
{
public:
    AknOtReceiver();
    ~AknOtReceiver();

    void init(u64 totalOTCount, u64 numberOfOnes, double p,
        OtExtReceiver& ots, Channel& chl, PRNG& prng)
    {
        std::vector<Channel*> chls{ &chl };
        init(totalOTCount, numberOfOnes, p, ots, chls, prng);
    }


    void init(u64 totalOTCount, u64 numberOfOnes, double p,
        OtExtReceiver& ots, std::vector<Channel*>& chls, PRNG& prng);

    std::vector<u64> mOnes, mZeros;
    std::vector<block> mMessages;
    BitVector mChoices;
};

}
=======
#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "Common/Defines.h"
#include "Network/Channel.h"
#include "Crypto/PRNG.h"
#include "TwoChooseOne/OTExtInterface.h"
#include "Common/BitVector.h"


namespace osuCrypto
{

class AknOtReceiver
{
public:
    AknOtReceiver();
    ~AknOtReceiver();

    void init(u64 totalOTCount, u64 numberOfOnes, double p,
        OtExtReceiver& ots, Channel& chl, PRNG& prng)
    {
        std::vector<Channel*> chls{ &chl };
        init(totalOTCount, numberOfOnes, p, ots, chls, prng);
    }


    void init(u64 totalOTCount, u64 numberOfOnes, double p,
        OtExtReceiver& ots, std::vector<Channel*>& chls, PRNG& prng);

    std::vector<u64> mOnes, mZeros;
    std::vector<block> mMessages;
    BitVector mChoices;
};

}
>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
