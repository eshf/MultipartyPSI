<<<<<<< HEAD
#include "BitIterator.h"

namespace osuCrypto
{

    BitReference::operator u8() const
    {
        return (*mByte & mMask) >> mShift;
    }

=======
#include "BitIterator.h"

namespace osuCrypto
{

    BitReference::operator u8() const
    {
        return (*mByte & mMask) >> mShift;
    }

>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
}