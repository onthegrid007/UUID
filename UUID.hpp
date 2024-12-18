/*
*   BSD 3-Clause License, see file labled 'LICENSE' for the full License.
*   Copyright (c) 2023, Peter Ferranti
*   All rights reserved.
*/

#ifndef UUID_HPP_
#define UUID_HPP_

#include <cstdint>
#include <random>

inline static std::random_device __RandomDevice{};
inline static std::mt19937_64 __RandomEngine(__RandomDevice());

template<class T = std::uint64_t>
class _UUID {
    private:
    inline static std::uniform_int_distribution<T> __UniformDistribution{};
    
    public:
    typedef T Type;
    T m_uuid;
    _UUID() : m_uuid(__UniformDistribution(__RandomEngine)) {}
    constexpr _UUID(const _UUID& other) : m_uuid(other.m_uuid) {}//})= default;
    constexpr bool operator!=(const _UUID& other) { return m_uuid != other.m_uuid; }
    constexpr bool operator==(const _UUID& other) { return m_uuid == other.m_uuid; }
    operator const std::string() {
        std::stringstream ss;
        ss << m_uuid;
        return ss.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const _UUID& uuid) {
        os << uuid.m_uuid;
        return os;
    }
};

typedef _UUID<> UUID_T;

#endif