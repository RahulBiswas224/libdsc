# libdsc — A Data Structures Library in C

A ground-up implementation of core data structures written strictly in standard C (`stdio.h`, `stdlib.h`, `string.h` only — no external dependencies). Built to demonstrate systems-level programming: manual memory management, pointer manipulation, and algorithmic complexity analysis. Every structure is Valgrind-clean — zero memory leaks, zero invalid reads/writes.

---

## Contents

- [Implemented Data Structures](#implemented-data-structures)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Memory Management Approach](#memory-management-approach)
- [Complexity Reference](#complexity-reference)
- [Sample Output](#sample-output)

---

## Implemented Data Structures

| Structure | Operations | What it demonstrates |
|---|---|---|
| **Singly Linked List** | insert (head/tail), delete, search, traverse | Dynamic allocation, pointer traversal, edge-case handling on head/tail removal |
| **Doubly Linked List** | insert, delete, search, traverse (both directions) | Tail-pointer optimization for O(1) insertion, bidirectional traversal, safe node unlinking |
| **Stack (array-based)** | push, pop, peek, resize | Fixed/dynamic capacity management, contiguous memory, overflow/underflow handling |
| **Stack (linked-list-based)** | push, pop, peek | O(1) push/pop via head manipulation, unbounded growth |
| **Queue (circular array)** | enqueue, dequeue, front, resize | Modulo-based wraparound to avoid wasted space, O(1) operations |
| **Queue (linked-list-based)** | enqueue, dequeue, front | Dual-pointer (front/rear) management for O(1) operations at both ends |
| **Binary Search Tree** | insert, search, delete, inorder/preorder/postorder traversal | Recursion, tree balancing edge cases, inorder-successor logic for two-child deletion |
| **Hash Table (chaining)** | insert, get, remove, dynamic resize | Custom string hashing, collision handling via chaining, load-factor-triggered rehashing |

---

## Getting Started

### Prerequisites
- GCC
- GNU Make
- Valgrind (optional — used to verify zero memory leaks)

### Build and run

```bash
# Clone the repository
git clone https://github.com/<your-username>/libdsc.git
cd libdsc

# Compile the project
make

# Run the test harness — exercises every data structure and prints results
./bin/libdsc_test

# Verify there are no memory leaks
make valgrind
```

### Clean build artifacts

```bash
make clean
```

---

## Project Structure

```
libdsc/
├── Makefile
├── README.md
├── include/            # Header files — struct definitions and public API declarations
│   ├── sll.h
│   ├── dll.h
│   ├── stack_array.h
│   ├── stack_list.h
│   ├── queue_array.h
│   ├── queue_list.h
│   ├── bst.h
│   └── hash_table.h
├── src/                # Implementations, with inline time/space complexity notes
│   ├── sll.c
│   ├── dll.c
│   ├── stack_array.c
│   ├── stack_list.c
│   ├── queue_array.c
│   ├── queue_list.c
│   ├── bst.c
│   └── hash_table.c
└── test/
    └── main.c          # Test harness exercising all operations on every structure
```

---

## Memory Management Approach

Correctness in a systems-level project is measured by memory safety, not just working output.

- **Dedicated free functions per structure** — `sll_free()`, `dll_free()`, `bst_free()`, `hash_table_free()`, etc. — so ownership of every allocation is explicit and traceable.
- **Postorder frees for trees** — the BST is torn down bottom-up (free left subtree, free right subtree, free node) so no pointer is ever dereferenced after the memory behind it is released.
- **Deep copies for hash table keys** — string keys are duplicated with `malloc` + `strcpy` rather than stored by reference, so the table isn't left holding a dangling pointer if the caller's original string goes out of scope.
- **Valgrind as a gate, not an afterthought** — `make valgrind` runs the full test suite under Valgrind's leak checker; the goal is `0 bytes definitely lost` before any commit is considered done.

---

## Complexity Reference

| Structure | Operation | Time | Space |
|---|---|---|---|
| Singly Linked List | insert at head | O(1) | O(1) |
| Singly Linked List | insert at tail / search | O(n) | O(1) |
| Doubly Linked List | insert at head/tail | O(1) | O(1) |
| Stack (array/list) | push / pop / peek | O(1) | O(1) amortized |
| Queue (circular array/list) | enqueue / dequeue | O(1) | O(1) amortized |
| BST | insert / search / delete (avg) | O(log n) | O(1) |
| BST | insert / search / delete (worst, unbalanced) | O(n) | O(1) |
| Hash Table | insert / get / remove (avg) | O(1) | O(1) |
| Hash Table | insert / get / remove (worst, collisions) | O(n) | O(1) |

Full derivations and reasoning are documented as comments above each function in `src/`.

---

## Sample Output

```
$ ./bin/libdsc_test

== Singly Linked List ==
Inserted: 10 -> 20 -> 30
After delete(20): 10 -> 30

== Binary Search Tree ==
Inorder traversal: 10 20 30 40 50
Deleted 30 (two children) -> Inorder: 10 20 40 50

== Hash Table ==
insert("name", "Rahul") -> OK
get("name") -> "Rahul"
Collision test: 3 keys hashed to bucket 4, chain length 3
```

*(Full output is generated by `test/main.c` at runtime — this is a representative excerpt.)*

---

## Author

Built by [Rahul Biswas](https://github.com/RahulBiswas224) as a systems-programming exercise ahead of technical interviews focused on C and data structures.