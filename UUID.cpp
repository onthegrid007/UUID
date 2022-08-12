/*
*   BSD 3-Clause License, see file labled 'LICENSE' for the full License.
*   Copyright (c) 2022, Peter Ferranti
*   All rights reserved.
*/

#include "UUID.h"
#include <ctime>
#include <random>
#include <sstream>

static const std::string __SEEDRNGSTR_() { std::stringstream ss; ss << (uint64_t)time(0); return ss.str(); }

static std::random_device __RandomDevice(__SEEDRNGSTR_());
static std::mt19937_64 __RandomEngine(__RandomDevice());
static std::uniform_int_distribution<uint64_t> __UniformDistribution;

UUID::UUID() :
    m_UUID(__UniformDistribution(__RandomEngine)) { }

UUID::UUID(const uint64_t uuid) :
    m_UUID(uuid) { }

UUID::operator uint64_t() const { return m_UUID; }

UUID::operator const std::string() const { std::stringstream ss; ss << m_UUID; return ss.str(); }