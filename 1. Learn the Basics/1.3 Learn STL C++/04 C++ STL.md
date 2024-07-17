# C++ Standard Template Library (STL)

The C++ Standard Template Library (STL) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

## Components of STL

### 1. Containers

STL provides several container classes that implement various data structures:

- **Sequence Containers:**

  - `vector`: Dynamic array.
  - `deque`: Double-ended queue.
  - `list`: Doubly linked list.
  - `forward_list`: Singly linked list.
  - `array`: Static array.

- **Associative Containers:**

  - `set`: Container of unique keys, sorted by keys.
  - `multiset`: Container of keys, sorted by keys.
  - `map`: Container of key-value pairs, sorted by keys.
  - `multimap`: Container of key-value pairs, sorted by keys.

- **Unordered Containers:**

  - `unordered_set`: Container of unique keys, hashed for fast lookup.
  - `unordered_multiset`: Container of keys, hashed for fast lookup.
  - `unordered_map`: Container of key-value pairs, hashed for fast lookup.
  - `unordered_multimap`: Container of key-value pairs, hashed for fast lookup.

- **Container Adaptors:**
  - `stack`: LIFO stack.
  - `queue`: FIFO queue.
  - `priority_queue`: Priority queue.

### 2. Iterators

STL iterators provide a way to access elements in containers and sequences:

- **Iterator Categories:**
  - **Input Iterators:** Read-only access and single-pass algorithms.
  - **Output Iterators:** Write-only access and single-pass algorithms.
  - **Forward Iterators:** Read and write access, single-pass algorithms.
  - **Bidirectional Iterators:** Read and write access, multi-pass algorithms.
  - **Random Access Iterators:** Read and write access, supports arithmetic operations for efficient traversal.

### 3. Algorithms

STL provides numerous algorithms that operate on sequences defined by iterators:

- **Basic Algorithms:**

  - `sort`, `find`, `count`, `accumulate`, `transform`, etc.

- **Sorting Algorithms:**

  - `sort`, `stable_sort`, `partial_sort`, `nth_element`, etc.

- **Searching Algorithms:**

  - `find`, `find_if`, `binary_search`, `lower_bound`, `upper_bound`, etc.

- **Numeric Algorithms:**

  - `accumulate`, `inner_product`, `partial_sum`, `iota`, etc.

- **Mutating Algorithms:**
  - `copy`, `fill`, `replace`, `reverse`, `rotate`, `shuffle`, etc.

### 4. Function Objects (Functors)

STL allows defining function objects that can be called as if they were functions:

- **Purpose:** Functors are often used to customize the behavior of algorithms by providing predicates or custom operations.

### 5. Utilities

STL provides various utility components to support generic programming:

- **Pair:** Stores a pair of objects, such as a key-value pair.
- **Tuple:** Stores a tuple of objects, providing heterogeneous collections.
- **Optional:** Represents an optional value that may or may not contain a value.
- **Variant:** Represents a type-safe union of types.

## Summary

The C++ STL is a versatile and efficient library that provides a rich collection of data structures, algorithms, iterators, and utilities. It facilitates generic programming in C++ by promoting code reuse, maintainability, and performance optimization through its template-based design.
