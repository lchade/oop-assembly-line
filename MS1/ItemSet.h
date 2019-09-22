// ItemSet module header
// ItemSet.h
// Chade Li
// 2019/07/08

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include <iostream>
#include <string>
#include "Utilities.h"

namespace sict {
    class ItemSet {
        Utilities m_utility;
        std::string m_name;
        unsigned m_serialNo;
        unsigned m_qty;
        std::string m_desc;
    public:
        ItemSet(const std::string& str);
        // disable copy constructor and copy/move assignment operator
        //
        ItemSet(const ItemSet& src) = delete;
        ItemSet& operator=(const ItemSet& src) = delete;
        ItemSet& operator=(ItemSet&& src) = delete;

        ItemSet(ItemSet&& src);

        const std::string& getName() const;
        const unsigned int getSerialNumber() const;
        const unsigned int getQuantity() const;
        ItemSet& operator--();
        void display(std::ostream& os, bool full) const;
    };
}

#endif