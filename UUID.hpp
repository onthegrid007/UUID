/*
*   BSD 3-Clause License, see file labled 'LICENSE' for the full License.
*   Copyright (c) 2023, Peter Ferranti
*   All rights reserved.
*/

#ifndef UUID_HPP_
#define UUID_HPP_

#include <cstdint>
// #include <sstream>
#include <random>

static std::random_device __RandomDevice{};//([](){ std::stringstream ss; ss << (uint64_t)time(0); return ss.str(); })());
static std::mt19937_64 __RandomEngine(__RandomDevice());

template<class T = uint64_t>
class _UUID {
    private:
    static std::uniform_int_distribution<T> __UniformDistribution;
    
    public:
    typedef T Type;
    T m_uuid;
    _UUID() : m_uuid(__UniformDistribution(__RandomEngine)) {}
    constexpr _UUID(const _UUID& other) : m_uuid(other.m_uuid) {}//})= default;
};

typedef _UUID<> UUID;

#endif