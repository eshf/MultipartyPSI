#pragma once
// This file and the associated implementation has been placed in the public domain, waiving all copyright. No restrictions are placed on its use. 
#include "Common/Defines.hpp"

#ifndef H_SHA1_H
#endif
#define H_SHA1_H

#include <string>

extern void sha1_compress(uint32_t state[5], const uint8_t block[64]);

namespace osuCrypto {
    class SHA1
    {
    public:
        static const uint64_t HashSize = 20;
        SHA1();

        void Reset();
        void Update(const u8* dataIn, uint64_t length);
        void Update(const block& blk);

        void Final(u8* DataOut);
        const SHA1& operator=(const SHA1& src);

    private:
        //CryptoPP::SHA1 mSha;
        std::array<uint32_t,5> state;
        std::array<uint8_t, 64> buffer;
        uint64_t idx;
    };
    
    //uint64_t    SHA1::HashSize(20);

    //void blk_SHA1_Init(blk_SHA_CTX *ctx);
    //void blk_SHA1_Update(blk_SHA_CTX *ctx, const void *dataIn, unsigned long len);
    //void blk_SHA1_Final(unsigned char hashout[20], blk_SHA_CTX *ctx);
    //
    //#define git_SHA_CTX    blk_SHA_CTX
    //#define git_SHA1_Init    blk_SHA1_Init
    //#define git_SHA1_Update    blk_SHA1_Update
    //#define git_SHA1_Final    blk_SHA1_Final
    //class SHA2
    //{
    //public:
    //    static const uint64_t HashSize = 512;
    //    SHA2() { Reset(); }

    //    //uint64_t mSize;
    //    //u32 mH[5];
    //    //u32 mW[16];

    //    inline void Reset()
    //    {
    //        mSha.Restart();
    //    }
    //    inline void Update(const u8* dataIn, uint64_t length)
    //    {
    //        mSha.Update(dataIn, length);
    //    }
    //    inline void Update(const block& blk)
    //    {
    //        Update(ByteArray(blk), sizeof(block));
    //    }
    //    inline void Final(u8* DataOut)
    //    {
    //        mSha.Final(DataOut);
    //    }

    //private:
    //    //void Block(const u32* data);
    //    CryptoPP::SHA512 mSha;

    //};

}
