// Assembly Line Project - Milestone 2
// CustomerOrder.h
// Chade Li
// 2019/07/17
#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

#include <iostream>
#include <string>
#include <utility>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
    class CustomerOrder {
        // nested struct
        //
        struct ItemInfo {
            std::string mm_name;
            unsigned int mm_serialNo;
            bool mm_filled;

            ItemInfo()
                : mm_name {""}
                , mm_serialNo {0}
                , mm_filled {false} {}
        };

        ItemInfo* m_itemInfo;
        std::string m_custName;
        std::string m_prodName;
        size_t m_noItems;
        static unsigned m_fw;
    public:
        CustomerOrder();
        CustomerOrder(const std::string& record);
        // disable copy operations
        //
        CustomerOrder(const CustomerOrder& src) = delete;
        CustomerOrder& operator=(const CustomerOrder& src) = delete;
        CustomerOrder(CustomerOrder&& src);
        CustomerOrder& operator=(CustomerOrder&& src);
        ~CustomerOrder();
        void fillItem(ItemSet& item, std::ostream& os);
        bool isFilled() const;
        bool isItemFilled(const std::string& item);
        std::string getNameProduct() const;
        void display(std::ostream& os, bool showDetail = false) const; 
    };
}

#endif