// This is the implementation for the order book public API 
// The order book only cares about itself
// It will change things internally + screaming that it have changed
// It does not even need to worry about who is it screaming to


#pragma once
#include <cstdint>


namespace tickforge::engine {
    // Current: filling in the OrderBook
    class OrderBook {
        public:
            void createOrder() {
                auto id = createOrderID();
                checkOrderNotExistedInList(id);

            };
            
            void deleteOrder(std::uint64_t order_id) {
                checkOrderExistedInList(order_id);
                orders_list.erase(order_id);
            };

            // How to write overload ? 
            void editOrderPrice(std::uint64_t order_id, std::int64_t price) {
                checkOrderExistedInList(order_id);
                orders_list[order_id].price = price;
            };

            void editOrderQuantity(std::uint64_t order_id, std::int64_t quantity) {
                checkOrderExistedInList(order_id);
                orders_list[order_id].price = quantity;
            };
            

            void printOrderList() {
                for (auto &order: orders_list) {
                    // TODO: order needs internal .print util 
                    std::cout << "Order ID: " 
                    // Special order print
                    // Order.print
                    << order.first << '\n' 
                }
            };

        private:

            void checkOrderNotExistedInList(std::uint64_t id) {
                if (order_list.contains(std::uint64_t id )) {
                    // TODO: throw some meaningful error
                }
            }    
        
            void checkOrderExistedInList(std::uint64_t id) {
                if (!order_list.contains(std::uint64_t id )) {
                    // TODO: throw some meaningful error
                }
            }    

            std::uint64_t createOrderID() {};

            // TODO: how to cross import ? 
            // tickforge/engine/order/order.hpp
            std::unordered_map<std::uint64_t, Order> order_list;




    };


} // namespace tickforge::engine
