#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "Common/Defines.h"
#include "Common/ArrayView.h"
#include <string>
namespace osuCrypto
{

    class PRNG;
    class LinearCode
    {
    public:
        LinearCode();
        ~LinearCode();
        LinearCode(const LinearCode& cp);


        void loadTxtFile(const std::string& fileName);
        void loadTxtFile(std::istream& in);



        void loadBinFile(const std::string& fileName);
        void loadBinFile(std::istream& in);

        void writeBinFile(const std::string& fileName);
        void writeBinFile(std::ostream& out);

        void random(PRNG& prng, uint64_t inputSize, uint64_t outputSize);

        void generateMod8Table();

        uint64_t mCodewordBitSize;
        std::vector<block> mG;
        std::vector<block> mG8;

        uint64_t plaintextBlkSize()const;
        uint64_t codewordBlkSize()const;

        uint64_t plaintextBitSize()const;
        uint64_t codewordBitSize()const;


        void encode(ArrayView<block> plaintext, ArrayView<block> codeword);

    };

}
