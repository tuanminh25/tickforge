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

Day one — starting with building the server ! - Well because client without server, it has nobody else to send orders, to communicate to...

Okay note note: tomorrow, I need you to do this: 

- The paper exercise: Process about ten orders by hand on an empty book and write down the book after each one.This later on becomes our code spec

- Design the order book:
    
    + What is an order? 
    
    + How to store prices level ?

    + Find best price fast? 

- Code with tests: a plain single threaded C++ engine with the paper


