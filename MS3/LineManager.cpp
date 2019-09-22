// LineManager module implementation
// LineManager.cpp
// Chade Li
// 2019/07/30

#include "LineManager.h"

using namespace std;

namespace sict {
    // 5-argument constructor: move the customer orders to the front of a queue holding the orders waiting to be filled
    // and determine the index of last station in the line
    //
    LineManager::LineManager(vector<Station*>& pStns, vector<size_t>& indexNextStn, vector<CustomerOrder>& orders, size_t indexFirstStn, ostream& os) {
        m_pStns = pStns;
        m_indexFirstStn = indexFirstStn;
        m_indexNextStn = indexNextStn;
        
        // move customer orders into vector ordersToFill
        for (auto& e: orders) {
            m_ordersToFill.push_back(move(e));
        }

        // determine the index of last station in the line
        vector<size_t> stnLine;
        size_t currentIndex = m_indexFirstStn;
        stnLine.push_back(currentIndex);
        for (size_t i = 0; i < m_indexNextStn.size(); i++) {
            stnLine.push_back(m_indexNextStn[currentIndex]);
            currentIndex = m_indexNextStn[currentIndex];
        }
        m_indexLastStn = stnLine.back();

        m_orderSize = orders.size();
    }
    
    // query: display the complete and incomplete orders at the end of the line
    //
    void LineManager::display(ostream& os) const {
        os << "COMPLETED ORDERS\n";
        for (auto& e: m_completeOrders) {
            e.display(os, true);
        }
        os << endl;

        os << "INCOMPLETE ORDERS\n";
        for (auto& e: m_incompleteOrders) {
            e.display(os, true);
        }
    }

    // modifier: if a customer order is on the back of the queue to be filled, move it to the starting station
    // execute fill steps at each station on the line
    //
    bool LineManager::run(ostream& os) {
        bool result;
        CustomerOrder currentOrder;

        if (!m_ordersToFill.empty()) {
            *m_pStns[m_indexFirstStn] += move(m_ordersToFill.front());
            m_ordersToFill.pop_front();
        }

        //try{
            for (size_t i = 0; i < m_indexNextStn.size(); i++) {
                m_pStns[i]->fill(os);
            }

            for (size_t i = 0; i < m_pStns.size(); i++) {
                bool anyOrderToRelease = m_pStns[i]->hasAnOrderToRelease();
                bool isTheLastStn = (m_indexLastStn == m_indexNextStn[i]);

                if (anyOrderToRelease) {
                    m_pStns[i]->pop(currentOrder);

                    if (!isTheLastStn) {
                        os << " --> " << currentOrder.getNameProduct() << " moved from " << m_pStns[i]->getName() << " to " << m_pStns[m_indexNextStn[i]]->getName() << endl;
                        *m_pStns[m_indexNextStn[i]] += move(currentOrder);
                    } else {
                        if (currentOrder.isFilled()) {
                            os << " --> " << currentOrder.getNameProduct() << " moved from " << m_pStns[i]->getName() << " to Completed Set" << endl;
                            m_completeOrders.push_back(move(currentOrder));
                            m_orderSize--;
                        } else {
                            os << " --> " << currentOrder.getNameProduct() << " moved from " << m_pStns[i]->getName() << " to Incompleted Set" << endl;
                            m_incompleteOrders.push_back(move(currentOrder));
                            m_orderSize--;
                        }
                    }
                }
            }
        //} catch (const exception& e) {
          //  e.what();
        //}
        
        if (m_orderSize == 0) {
            result = true;
        } else {
            result = false;
        }

        return result;
    }
}
