// LineManager module header
// LineManager.h
// Chade Li
// 2019/07/28
#pragma once

#ifndef SICT_LINE_MANAGER_H
#define SICT_LINE_MANAGER_H

#include <iostream>
#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sict {
    class LineManager {
        std::vector<Station*> m_pStns;
        std::vector<size_t> m_indexNextStn;
        size_t m_indexFirstStn;
        size_t m_indexLastStn;
        size_t m_orderSize;
        std::deque<CustomerOrder> m_ordersToFill;
        std::deque<CustomerOrder> m_completeOrders;
        std::deque<CustomerOrder> m_incompleteOrders;

    public:
        LineManager(std::vector<Station*>& pStns, std::vector<size_t>& indexNextStn, std::vector<CustomerOrder>& orders, size_t indexFirstStn, std::ostream& os);
        void display(std::ostream& os) const;
        bool run(std::ostream& os);
    };
}

#endif