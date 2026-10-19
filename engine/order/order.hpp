// Order definition

#pragma once
#include <cstdint>


namespace tickforge::engine {
    enum class Side : std::uint8_t { Buy, Sell };
    enum class OrderType : std::uint8_t { Limit, Market };

    struct Order {
        std::int64_t price = 0; // in ticks, ignored for market order
        std::int64_t remaining_qty = 0; 
        std::uint64_t id = 0;
        std::uint32_t account_id = 0;
        Side side = Side::Buy;
        OrderType order_type = OrderType::Limit; // Limit or Market
    };

    static_assert(sizeof(Order) == 32);

} // namespace tickforge::engine
