#ifndef BOOST_CORE_DETAIL_SPLITMIX64_HPP_INCLUDED
#define BOOST_CORE_DETAIL_SPLITMIX64_HPP_INCLUDED

// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
//
// An implementation of splitmix64 for testing purposes,
// derived from Sebastiano Vigna's public domain implementation
// http://xorshift.di.unimi.it/splitmix64.c

#include <boost/cstdint.hpp>

namespace boost
{
namespace detail
{

class splitmix64
{
private:

    boost::u64 x_;

public:

    splitmix64(): x_( 0 )
    {
    }

    explicit splitmix64( boost::u64 seed ): x_( seed )
    {
    }

    boost::u64 operator()()
    {
        x_ += ( boost::u64(0x9e3779b9u) << 32 ) + 0x7f4a7c15u;

        boost::u64 z = x_;

        z ^= z >> 30;
        z *= ( boost::u64(0xbf58476du) << 32 ) + 0x1ce4e5b9u;
        z ^= z >> 27;
        z *= ( boost::u64(0x94d049bbu) << 32 ) + 0x133111ebu;
        z ^= z >> 31;

        return z;
    }
};

} // namespace detail
} // namespace boost

#endif // #ifndef BOOST_CORE_DETAIL_SPLITMIX64_HPP_INCLUDED
