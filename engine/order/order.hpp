// Order definition

#pragma once
#include <cstdint>


namespace tickforge::engine {
    enum class Side : std::uint8_t { Buy, Sell };
    enum class OrderType : std::uint8_t { Limit, Market };

    struct Order {
        std::int64_t price; // in tick, ignored for market order
        std::int64_t remaining_qty;
        std::uint64_t id;
        std::uint32_t account_id;
        Side side;
        OrderType order_type;    

    };

    static_assert(sizeof(Order) == 32);

} // namespace tickforge::engine
