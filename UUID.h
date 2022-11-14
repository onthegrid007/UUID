/*
*   BSD 3-Clause License, see file labled 'LICENSE' for the full License.
*   Copyright (c) 2022, Peter Ferranti
*   All rights reserved.
*/

#ifndef UUID_H_
#define UUID_H_

#include <string>

class UUID {
    protected:
    uint64_t m_UUID;

    public:
    UUID();
    UUID(const uint64_t uuid);
    UUID(const UUID& other) = default;
    operator uint64_t() const;
    operator const std::string() const;
    UUID& operator=(const UUID& other) = default;
    template<typename S>
    const S& operator<<(const S& s) {
        return s << this->operator const std::string();
    }
};
#endif