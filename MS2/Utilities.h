// Utilites module header
// Utilities.h
// Chade Li
// 2019/07/08

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <iostream>
#include <string>

namespace sict {

    class Utilities {
        static char m_delimiter;
        static std::size_t m_fieldWidth;
    public:
        Utilities();
        const std::string extractToken(const std::string& str, std::size_t& next_pos);
        const char getDelimiter() const;
        std::size_t getFieldWidth() const;
        static void setDelimiter(const char d);
        void setFieldWidth(std::size_t fw);
    };
}

#endif