// Utilites module implementation
// Utilities.cpp
// Chade Li
// 2019/07/30

#include "Utilities.h"
using namespace std;

namespace sict {
    // initialize class variables
    //
    char Utilities::m_delimiter {'*'};
    size_t Utilities::m_fieldWidth {0};
    
    // default constructor: set safe empty state
    //
    Utilities::Utilities() {}

    // modifier: extract and return the next token in the string
    // starting at next_pos and end before delimiter
    //
    const string Utilities::extractToken(const string& str, size_t& next_pos) {
        string token;
        size_t token_length {0};

        // find next delimiter position
        size_t next_delimiter_pos = str.find(m_delimiter, next_pos + 1);
        
        // get the length of next token and extract the token
        size_t start_pos = 0;

        // add !next_pos condition to extract the first token in a record
        if (!next_pos) {
            token_length = next_delimiter_pos;
            start_pos = 0;
        } else {
            token_length = next_delimiter_pos - (next_pos + 1);
            start_pos = next_pos + 1;
        }
        token = str.substr(start_pos, token_length);
        next_pos = next_delimiter_pos;
        
        return token;
    }
    
    // query: return the delimiter character
    //
    const char Utilities::getDelimiter() const {
        return m_delimiter;
    }
    
    // query: return the filed width for the current object
    //
    size_t Utilities::getFieldWidth() const {
        return m_fieldWidth;
    }

    // modifier: set the delimiter character for all object of this class
    //
    void Utilities::setDelimiter(const char d) {
        m_delimiter = d;
    }

    // modifier: set the filed width for the current object
    //
    void Utilities::setFieldWidth(size_t fw) {
        m_fieldWidth = fw;
    }
}