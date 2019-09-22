// Assembly Line Project - Milestone 2
// CustomerOrder.cpp
// Chade Li
// 2019/07/17

#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
using namespace std;

namespace sict {

    unsigned CustomerOrder::m_fw = 0;

    // default constructor: set the empty state
    //
    CustomerOrder::CustomerOrder() 
        : m_itemInfo {nullptr}
        , m_custName {""}
        , m_prodName {""}
        , m_noItems {0}
        {}

    // one-argument constructor: extract tokens in a string and hold data,
    // allocate memory for each item and determine the field width
    //
    CustomerOrder::CustomerOrder(const string& record) {
        Utilities utility;

        size_t delimiter_pos = record.find(utility.getDelimiter());
        m_custName = record.substr(0, delimiter_pos);
        m_prodName = utility.extractToken(record, delimiter_pos);
        m_noItems = count(record.begin(), record.end(), utility.getDelimiter()) - 1;

        m_fw = (m_fw < m_custName.size()) ? m_custName.size() : m_fw;
        
        m_itemInfo = new ItemInfo[m_noItems];

        if (m_noItems >= 1) {
            for (size_t i = 0; i < m_noItems; i++) {
                m_itemInfo[i].mm_name = utility.extractToken(record, delimiter_pos);
            }
        } else {
            throw std::string("error: item(s) not found");
        }
    }

    // move constructor
    //
    CustomerOrder::CustomerOrder(CustomerOrder&& src) {
        *this = std::move(src);
    }

    // move assignment operator
    //
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
        m_itemInfo = src.m_itemInfo;
        m_custName = src.m_custName;
        m_prodName = src.m_prodName;
        m_noItems = src.m_noItems;

        src.m_itemInfo = nullptr;
        src.m_custName = "";
        src.m_prodName = "";
        src.m_noItems = 0;

        return *this;
    }

    // destructor: deallocates any memory that the object has allocated
    //
    CustomerOrder::~CustomerOrder() {
        delete [] m_itemInfo;
        m_itemInfo = nullptr;
    }

    // modifier: check item request, fill the requested item if available and report the filling
    //
    void CustomerOrder::fillItem(ItemSet& item, ostream& os) {
        for (size_t i = 0; i < m_noItems; i++) {
            if (m_itemInfo[i].mm_name == item.getName()) {
                // item is out of stock
                if (item.getQuantity() == 0) {
                    os << " Unable to fill " << m_custName << " [" << m_prodName <<"][" << m_itemInfo[i].mm_name << "][" << m_itemInfo[i].mm_serialNo << "] out of stock" << endl;
                // item has already been filled
                } else if (m_itemInfo[i].mm_filled) {
                    os << " Unable to fill " << m_custName << " [" << m_prodName <<"][" << m_itemInfo[i].mm_name << "][" << m_itemInfo[i].mm_serialNo << "] already filled" << endl;
                // item has not been filled
                // report the filling and deduct the number of the item by 1
                } else {
                    m_itemInfo[i].mm_serialNo = item.getSerialNumber();
                    os << " Filled " << m_custName << " [" << m_prodName <<"][" << m_itemInfo[i].mm_name << "][" << m_itemInfo[i].mm_serialNo << "]" << endl;
                    m_itemInfo[i].mm_filled = true;
                    item.operator--();
                }
            }
        }
    }

    // query: search the list of items request and return true if all have been filled
    //
    bool CustomerOrder::isFilled() const {
        bool allFilled = true;
        for (size_t i = 0; i < m_noItems && allFilled; i++) {
            if (!m_itemInfo[i].mm_filled) allFilled = false;
        }
        return allFilled;
    }

    // query: search the item request list for that item and return true if all have been filled
    //
    bool CustomerOrder::isItemFilled(const string& item) {
        bool filled = true;
        for (size_t i = 0; i < m_noItems && filled; i++) {
            if (m_itemInfo[i].mm_name == item) {
                if (!m_itemInfo[i].mm_filled) {
                    filled = false;
                }
            }
        }
        return filled;
    }

    // query: returns the name of customer and their product in format
    //
    string CustomerOrder::getNameProduct() const {
        return m_custName + "[" + m_prodName + "]";
    }

    // query: insert the data for the current object into stream os
    //
    void CustomerOrder::display(ostream& os, bool showDetail) const {
        os << left << setw(m_fw) << m_custName << " [" << m_prodName << "]" << endl;
        if (showDetail) {
            for (size_t i = 0; i < m_noItems; i++) {
                os << setw(m_fw + 1) << " " << "[" << m_itemInfo[i].mm_serialNo << "] " << m_itemInfo[i].mm_name << " – ";
                if (m_itemInfo[i].mm_filled)
                    os << "FILLED" << endl;
                else
                    os << "MISSING" << endl;
            }
        } else {
            for (size_t i = 0; i < m_noItems; i++) {
                os << setw(m_fw + 1) << " " << m_itemInfo[i].mm_name << endl;
            } 
        }
    }
}