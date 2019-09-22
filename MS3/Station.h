// Station module header
// Station.h
// Chade Li
// 2019/07/30

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <deque>
#include <string>
#include <utility>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
    class Station {
        std::string m_stnName;
        std::deque<CustomerOrder> m_stnOrderQueue;
        ItemSet m_stnInventory;
    public:
        Station(const std::string& record);

        // disable copy and move operations
        //
        Station(const Station& src) = delete;
        Station& operator=(const Station& src) = delete;
        Station(Station&& src) = delete;
        Station& operator=(Station&& src) = delete;

        void display(std::ostream& os) const;
        void fill(std::ostream& os);
        const std::string& getName() const;
        bool hasAnOrderToRelease() const;
        Station& operator--();
        Station& operator+=(CustomerOrder&& order);
        bool pop(CustomerOrder& ready);
        void validate(std::ostream& os) const;
    };
}

#endif