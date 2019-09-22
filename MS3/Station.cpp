// Station module implementation
// Station.cpp
// Chade Li
// 2019/07/30

#include "Station.h"
using namespace std;

namespace sict {
    // one-argument constructor: pass the reference to a string
    // to the ItemSet sub-object of the current object
    //
    Station::Station(const string& record)
        : m_stnInventory(record) {
            m_stnName = m_stnInventory.getName();
    }
    
    // query: display the data for its ItemSet on os
    //
    void Station::display(ostream& os) const {
        m_stnInventory.display(os);
    }

    void Station::fill(ostream& os) {
        if (!m_stnOrderQueue.empty()) {
            (m_stnOrderQueue.front()).fillItem(m_stnInventory, os);
        }
    }

    // query: return a reference to the name of ItemSet sub-object
    //
    const string& Station::getName() const {
        return m_stnInventory.getName();
    }

    // query: return the release state of current object
    // returns true if the station has filled item requests for the customer order at the front of the queue
    // or if the station has no items left
    //
    bool Station::hasAnOrderToRelease() const {
        bool result = false;
        if (!m_stnOrderQueue.empty() && (m_stnOrderQueue.front().isItemFilled(m_stnName) || m_stnInventory.getQuantity() == 0)) {
            result = true;
        }
        return result;
    }

    Station& Station::operator--() {
        --m_stnInventory;
        return *this;
    }

    // modifier: receive a rvalue reference to a customer order and
    // add the order to the back of the station queue and return a reference to the current object
    //
    Station& Station::operator+=(CustomerOrder&& order) {
        m_stnOrderQueue.push_back(move(order));
        return *this;
    }

    // modifier: receive an lvalue reference to a customer order
    // remove the order at the front of queue and pass it to the calling function through parameter
    // return true if the station filled its part of order
    //
    bool Station::pop(CustomerOrder& ready) {
        bool result = false;
		if (!m_stnOrderQueue.empty()) {
            // check if the front order in the queue is filled
			result = m_stnOrderQueue.front().isItemFilled(m_stnName);
			ready = move(m_stnOrderQueue.front());
			m_stnOrderQueue.pop_front();
		}
		return result;
	}


    // query: report the state of the ItemSet object in a format
    //
    void Station::validate(ostream& os) const {
        os << " getName(): " << m_stnInventory.getName() << endl;
		os << " getSerialNumber(): " << m_stnInventory.getSerialNumber() << endl;
		os << " getQuantity(): " << m_stnInventory.getQuantity() << endl;
    }
}