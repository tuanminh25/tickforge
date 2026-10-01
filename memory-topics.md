# tickforge — Memory Topics

Every memory topic covered by tickforge, and the component where it is learned.

## Fundamentals

| Topic | Where in tickforge |
|---|---|
| Stack vs heap, object lifetime | Everywhere |
| RAII, ownership | Connections, files, sockets |
| Smart pointers (`unique_ptr`, `shared_ptr`, `weak_ptr`) and the cost of atomic ref counting | Client session objects |
| Move semantics, copy elision | Passing messages between stages |
| Undefined behavior: dangling pointers, use-after-free, overflows | Caught by AddressSanitizer and UBSan |

## Layout

| Topic | Where in tickforge |
|---|---|
| `sizeof`, alignment, padding, struct packing | Order struct, wire messages |
| `alignas`, cache-line alignment | Lock-free queues |
| Endianness, serialization | Binary wire protocol |

## Allocation

| Topic | Where in tickforge |
|---|---|
| How `new` / `malloc` work and what they cost | Benchmark |
| Placement `new` | Object pool |
| Object pools, preallocation | Orders stored in the book |
| Arena allocators, `std::pmr` | Per-message parsing in the gateway |
| Zero-allocation hot path | Rule for the engine and gateway |

## Hardware and cache

| Topic | Where in tickforge |
|---|---|
| Cache hierarchy (L1/L2/L3), locality | Choosing the book's data structure (array vs tree) |
| Data-oriented design, array-of-structs vs struct-of-arrays | Price-level storage |
| Branch prediction, prefetching | Hot-path tuning |
| Zero-copy buffers | Network → engine |
| Memory-mapped files (`mmap`) | Journal |
| TLB, huge pages | *Bonus:* engine memory |
| NUMA | *Bonus:* with CPU pinning |

## Tools

| Topic | Where in tickforge |
|---|---|
| AddressSanitizer, UBSan, Valgrind / heaptrack | Measurement and tooling |
| `perf` cache-miss profiling | Benchmarks |

---

