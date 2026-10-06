# tickforge — Concurrency Topics

Every concurrency topic covered by tickforge, and the component where it is learned.

## Basics

| Topic | Where in tickforge |
|---|---|
| Threads, `std::jthread`, stop tokens (clean shutdown) | Gateway and publisher threads |
| Thread-local storage | Per-thread latency stats |
| Race conditions vs data races | Everywhere, caught by ThreadSanitizer |

## Locking

| Topic | Where in tickforge |
|---|---|
| `mutex`, `lock_guard`, `unique_lock`, `scoped_lock` | Queue version 1 |
| Condition variables, spurious wakeups | Queue version 1 |
| Reader-writer locks (`shared_mutex`) | Book snapshot service |
| Lock granularity and contention | Account manager: one global lock vs per-account locks |
| Deadlock and lock ordering | Account manager locking several accounts at once |
| Livelock, starvation, priority inversion | Slow-consumer handling, wait strategies |
| Spinlocks (built from `atomic_flag`) | Benchmarked against a mutex |

## Atomics and the memory model

| Topic | Where in tickforge |
|---|---|
| `std::atomic`, compare-and-swap | Sequence counter, stats counters |
| Memory orderings (`seq_cst`, acquire/release, relaxed) | Lock-free queues |
| Happens-before, synchronizes-with | Lock-free queues |
| Memory fences | Lock-free queues (optional variant) |
| `atomic::wait` / `notify` (C++20) | Queue version 1.5 |

## Lock-free programming

| Topic | Where in tickforge |
|---|---|
| SPSC ring buffer | Engine → publisher |
| MPSC queue | Several gateway threads → sequencer |
| False sharing, cache-line padding | Queue benchmarks |
| Wait strategies (spin, yield, back off, block) | Consumer threads |
| Lock-free vs wait-free guarantees | Learned through the queue versions |
| MPMC queue, ABA problem, memory reclamation | *Bonus stage* |

## Higher-level tools and patterns

| Topic | Where in tickforge |
|---|---|
| Thread pools, task queues | Background services |
| Futures, promises, `packaged_task`, `async` | Thread pool results |
| Work stealing | Thread pool version 2 |
| Latches, barriers, semaphores (C++20) | Load tester: synchronized bot start, connection cap |
| Parallel algorithms (`std::execution::par`) | Offline analysis of the journal |
| Producer-consumer pipelines, backpressure | The whole system |
| Share-nothing / single-owner design | The matching engine itself |
| C++20 coroutines | *Bonus:* gateway version 3 |

## Concurrent I/O

| Topic | Where in tickforge |
|---|---|
| Non-blocking sockets, `epoll` event loop | Gateway |
| `io_uring` | *Bonus:* gateway variant |

## Across processes and machines

| Topic | Where in tickforge |
|---|---|
| Shared-memory IPC between processes | Engine and publisher as separate processes linked by a shared-memory ring buffer |
| Signals, graceful shutdown | Every process |
| Clocks and timestamps (monotonic vs wall clock) | Latency measurement |
| Replication, heartbeats, failover, split-brain | Backup engine |

## Testing and tools

| Topic | Where in tickforge |
|---|---|
| ThreadSanitizer, stress tests, deterministic tests | Measurement and tooling |

---

**Self-check:** by the end, nearly every chapter of *C++ Concurrency in Action* (Anthony Williams) should map to something built here.
