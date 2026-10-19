Debt for this part: 

- order_type in the resting struct. Every order sitting in the book is a limit order, so this field is only meaningful on arrival. That points at two shapes: an incoming request and a resting order. It currently costs zero bytes because of padding, so leave it. Revisit when the book exists.

- static_assert(std::is_trivially_copyable_v<Order>). This matters once the journal or wire format starts copying orders as raw bytes. Add it when that happens.

- Explicit enum values (Buy = 0, Sell = 1). These matter once enums go over the wire or into the journal, where the numbers become a contract. Not now.

- Strong types (Price, Qty) instead of raw int64_t. This is the “real” fix for the swap bug. Probably not worth it yet.