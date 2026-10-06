# Tickforge

A low-latency mini exchange and trading ecosystem in C++.

Built from scratch as a learning project in concurrency, lock-free design, and performance engineering.

Well this pretty much contains both Client Side and Server Side in a trading trading context

It looks like this

tickforge client A <-> tickforge server <-> tickforge client B

## Planned components

- **Matching engine** — price-time priority, limit / market / cancel / modify, single-threaded, zero-allocation hot path
- **Sequencer + journal** — sequence numbers, write-ahead log, crash recovery and replay
- **Order gateway** — `epoll` event loop, binary protocol, mutex → lock-free queues (SPSC / MPSC)
- **Account manager** — positions, risk limits, deadlock-free multi-account locking
- **Market data publisher** — UDP multicast fan-out, gap detection, snapshot recovery, slow-consumer policy
- **Trading bots** — feed handler, local book rebuild, simple strategy, load generator
- **Background services** — custom thread pool (futures, work stealing), async logging
- **Replication** — backup engine, heartbeats, failover
- **Measurement** — latency histograms (p50 / p99 / p99.9), CPU pinning, sanitizers, benchmarks for every version

## Status

Day two — on our way building the server - understand then mechanism-ish first and anyone who is involved ! - Well because client without server, it has nobody else to send orders, to communicate to...

We are making the exchange floor first (HOSE - Hochiminh stock exchange)

I just discovered about which part must be sequential, which can be parallel:

- The trade board, only one person one employee can touch it at at time

- Sublock it right now does not worth it, while performance can improve a little, but it can introduce deadlock: employee A locking B waiting on C - emplyoyee Z locking C waiting on B

- I can make the taking in order part multithreaded or paralelly: having many employee standing at booths

- However, the whole board itself must still be sequential - only one employee touches at a time (yes this is an intended duplicate line from above to remind me)

Later on we gonna cosplay the client - Optiver

Okay note note: tomorrow, I need you to do this: 

- The paper exercise: Process about ten orders by hand on an empty book and write down the book after each one.This later on becomes our code spec

- Design the order book:
    
    + What is an order? 
    
    + How to store prices level ?

    + Find best price fast? 

- Code with tests: a plain single threaded C++ engine with the paper

- Ok a hint is  that this can be our format for now :

Ex1:
Board (sellers):  Alice  SELL 30 @ 10.00
                  Bob    SELL 50 @ 10.02
                  Dan    SELL 40 @ 10.08

Raymond arrives:  BUY 100 @ 10.05


Ex2: with more detail
id=1  trader=Alice  side=BUY  price=10.05  qty=100  type=LIMIT

# Order book rules:
- Only non-MARKET order will stay in the order book 
- Every orders in the book are of type LIMIT
- Buyer comes and buy lowest firsts

# Data Flow:

Private board being source of truth of everything
-> All adjustment is being done on the "private" board

Whenever there is a change inside the private board, it will annouces to a publisher, and that publisher will change things on the public side


# Project layout
notes/
engine/
  engine.hpp
  engine.cpp
  order/
   order.hpp             # what an order book api + what it is 
  order_book/
   order_book.hpp        # the book public api: what it holds, what you can ask it to do, what is it 
   order_book.cpp        # the order book implementation
  tests/
    engine/
     test_engine.cpp
    order_book/
     test_order_book.cpp # today's 4-order exercise, as a test
