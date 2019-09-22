// ItemSet module implementation
// ItemSet.cpp
// Chade Li
// 2019/07/08

#include <iostream>
#include <string>
#include <iomanip>
#include "ItemSet.h"
#include "Utilities.h"
using namespace std;

namespace sict {
    // constructor: receive a reference to the string and extract 4 tokens
    //
    ItemSet::ItemSet(const string& line) {
        size_t next_pos = line.find(m_utility.getDelimiter());
        m_name = line.substr(0, next_pos);
        m_serialNo = stoul(m_utility.extractToken(line, next_pos));
        m_qty = stoi(m_utility.extractToken(line, next_pos));
        m_desc = m_utility.extractToken(line, next_pos);

        if (m_name.length() > m_utility.getFieldWidth())
			m_utility.setFieldWidth(m_name.length());
    }

    // move constructor
    //
    ItemSet::ItemSet(ItemSet&& src) {
        if (this != &src) {
            m_name = src.m_name;
            m_desc = src.m_desc;
            m_serialNo = src.m_serialNo;
            m_qty = src.m_qty;

            src.m_name = "";
            src.m_desc = "";
            src.m_serialNo = 0;
            src.m_qty = 0;
        }
    }

    // query: return a reference to the name of the item
    //
    const string& ItemSet::getName() const {
        return m_name;
    }

    // query: return the serial number
    //
    const unsigned int ItemSet::getSerialNumber() const {
        return m_serialNo;
    }

    // query: return the remaining number of items
    //
    const unsigned int ItemSet::getQuantity() const {
        return m_qty;
    }

    // prefix decrement operator: reduce the number of items in stock by one,
    // increase the serial number by one and returns a reference to the current object
    //
    ItemSet& ItemSet::operator--() {
        m_qty--;
        m_serialNo++;
        
        return *this;
    }

    // query: insert the data of the current object into stream os
    //
    void ItemSet::display(ostream& os, bool full) const {
        size_t name_sz = m_utility.getFieldWidth();

		if (full) {
			os << left << setw(name_sz) << m_name;
            os << " [" << setw(5) << setfill('0') << m_serialNo << setfill(' ');
            os << "] Quantity " << setw(3) << m_qty;
            os << " Description: " << m_desc << endl;
        }
	}
}