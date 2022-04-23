/*
*   BSD 3-Clause License, see file labled 'LICENSE' for the full License.
*   Copyright (c) 2022, Peter Ferranti
*   All rights reserved.
*   Other Contributers:
*/

#include "UUID.h"
#include <sstream>
#include <ctime>

const std::string seedTimetoStr() {
    std::stringstream ss; ss << (uint64_t)time(0); return ss.str();
}

std::random_device UUID::RandomDevice(seedTimetoStr());
std::mt19937_64 UUID::RandomEngine(UUID::RandomDevice());
std::uniform_int_distribution<uint64_t> UUID::UniformDistribution;

UUID::UUID() :
    m_UUID(UUID::UniformDistribution(UUID::RandomEngine)) { }

UUID::UUID(const uint64_t& uuid) :
    m_UUID(uuid) { }

UUID::operator uint64_t() const { return m_UUID; }

UUID::operator const std::string() const { std::stringstream ss; ss << m_UUID; return ss.str(); }