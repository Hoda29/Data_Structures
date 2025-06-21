# Data Structures Implementation in C

A comprehensive implementation of fundamental data structures built from scratch in C, including dynamic arrays (lists), queues, and stacks. This project demonstrates core computer science concepts with clean, well-documented code suitable for learning and reference.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Data Structures Implemented](#data-structures-implemented)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Examples](#examples)
- [Memory Management](#memory-management)
- [Performance Analysis](#performance-analysis)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This project provides clean, educational implementations of essential data structures in C. Each data structure is implemented with dynamic memory allocation, proper error handling, and comprehensive documentation. The code follows best practices for C programming and includes extensive comments explaining the logic and design decisions.

## ✨ Features

- **Memory Safe**: All implementations include proper memory management with allocation, reallocation, and deallocation
- **Generic Design**: Structures can hold any data type through void pointers
- **Error Handling**: Comprehensive error checking with meaningful return codes
- **Well Documented**: Extensive comments and documentation for educational purposes
- **Performance Optimized**: Efficient algorithms with analysis of time and space complexity
- **Test Coverage**: Complete test suite with edge cases and performance benchmarks

## 📚 Data Structures Implemented

### 1. Dynamic Array (List)
- **File**: `list.c`, `list.h`
- **Description**: Resizable array implementation with automatic memory management
- **Operations**: Insert, delete, search, resize, sort
- **Time Complexity**: O(1) amortized insertion, O(n) deletion/search
- **Space Complexity**: O(n)

### 2. Stack (LIFO)
- **File**: `stack.c`, `stack.h`
- **Description**: Last-In-First-Out data structure with dynamic sizing
- **Operations**: Push, pop, peek, isEmpty, size
- **Time Complexity**: O(1) for all operations
- **Space Complexity**: O(n)

### 3. Queue (FIFO)
- **File**: `queue.c`, `queue.h`
- **Description**: First-In-First-Out data structure with circular buffer implementation
- **Operations**: Enqueue, dequeue, front, rear, isEmpty, size
- **Time Complexity**: O(1) for all operations
- **Space Complexity**: O(n)

## 📁 Project Structure

```
data-structures-c/
├── src/
│   ├── list.c              # Dynamic array implementation
│   ├── stack.c             # Stack implementation
│   ├── queue.c             # Queue implementation
│   └── utils.c             # Utility functions
├── include/
│   ├── list.h              # List header file
│   ├── stack.h             # Stack header file
│   ├── queue.h             # Queue header file
│   └── utils.h             # Utility header file
├── tests/
│   ├── test_list.c         # List unit tests
│   ├── test_stack.c        # Stack unit tests
│   ├── test_queue.c        # Queue unit tests
│   └── test_runner.c       # Test suite runner
├── examples/
│   ├── list_example.c      # List usage examples
│   ├── stack_example.c     # Stack usage examples
│   └── queue_example.c     # Queue usage examples
├── docs/
│   ├── API.md              # Detailed API documentation
│   └── COMPLEXITY.md       # Time/space complexity analysis
├── Makefile                # Build configuration
└── README.md               # This file
```

## 🚀 Installation

### Prerequisites
- GCC compiler (version 4.9 or higher)
- Make utility
- Standard C library

### Build Instructions

1. **Clone the repository**:
```bash
git clone https://github.com/yourusername/data-structures-c.git
cd data-structures-c
```

2. **Compile the project**:
```bash
make all
```

3. **Run tests**:
```bash
make test
```

4. **Run examples**:
```bash
make examples
```

5. **Clean build files**:
```bash
make clean
```

### Compilation Options

- **Debug build**: `make debug` - Includes debugging symbols and extra warnings
- **Release build**: `make release` - Optimized for performance
- **Memory check**: `make valgrind` - Run with Valgrind for memory leak detection

## 💡 Usage

### Basic Example

```c
#include "list.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>

int main() {
    // Create a dynamic list
    List* list = list_create(sizeof(int));
    
    // Add elements
    int values[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        list_push_back(list, &values[i]);
    }
    
    // Print list contents
    printf("List contents: ");
    for (size_t i = 0; i < list_size(list); i++) {
        int* value = (int*)list_get(list, i);
        printf("%d ", *value);
    }
    printf("\n");
    
    // Cleanup
    list_destroy(list);
    
    return 0;
}
```

## 📖 API Reference

### Dynamic List API

```c
// Creation and destruction
List* list_create(size_t element_size);
void list_destroy(List* list);

// Element operations
int list_push_back(List* list, const void* data);
int list_push_front(List* list, const void* data);
int list_insert(List* list, size_t index, const void* data);
int list_pop_back(List* list);
int list_pop_front(List* list);
int list_remove(List* list, size_t index);

// Access operations
void* list_get(const List* list, size_t index);
int list_set(List* list, size_t index, const void* data);
void* list_front(const List* list);
void* list_back(const List* list);

// Utility operations
size_t list_size(const List* list);
size_t list_capacity(const List* list);
bool list_empty(const List* list);
void list_clear(List* list);
int list_reserve(List* list, size_t capacity);
```

### Stack API

```c
// Creation and destruction
Stack* stack_create(size_t element_size);
void stack_destroy(Stack* stack);

// Core operations
int stack_push(Stack* stack, const void* data);
int stack_pop(Stack* stack);
void* stack_top(const Stack* stack);

// Utility operations
size_t stack_size(const Stack* stack);
bool stack_empty(const Stack* stack);
void stack_clear(Stack* stack);
```

### Queue API

```c
// Creation and destruction
Queue* queue_create(size_t element_size);
void queue_destroy(Queue* queue);

// Core operations
int queue_enqueue(Queue* queue, const void* data);
int queue_dequeue(Queue* queue);
void* queue_front(const Queue* queue);
void* queue_rear(const Queue* queue);

// Utility operations
size_t queue_size(const Queue* queue);
bool queue_empty(const Queue* queue);
void queue_clear(Queue* queue);
```

## 🔧 Examples

### Stack Example: Balanced Parentheses Checker

```c
#include "stack.h"
#include <stdio.h>
#include <string.h>

bool is_balanced(const char* expression) {
    Stack* stack = stack_create(sizeof(char));
    
    for (int i = 0; expression[i]; i++) {
        char ch = expression[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            stack_push(stack, &ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack_empty(stack)) {
                stack_destroy(stack);
                return false;
            }
            
            char* top = (char*)stack_top(stack);
            if ((ch == ')' && *top != '(') ||
                (ch == ']' && *top != '[') ||
                (ch == '}' && *top != '{')) {
                stack_destroy(stack);
                return false;
            }
            stack_pop(stack);
        }
    }
    
    bool balanced = stack_empty(stack);
    stack_destroy(stack);
    return balanced;
}
```

### Queue Example: Breadth-First Search

```c
#include "queue.h"
#include <stdio.h>

void bfs_traverse(int graph[][MAX_VERTICES], int vertices, int start) {
    Queue* queue = queue_create(sizeof(int));
    bool visited[MAX_VERTICES] = {false};
    
    queue_enqueue(queue, &start);
    visited[start] = true;
    
    printf("BFS Traversal: ");
    
    while (!queue_empty(queue)) {
        int* current = (int*)queue_front(queue);
        printf("%d ", *current);
        queue_dequeue(queue);
        
        for (int i = 0; i < vertices; i++) {
            if (graph[*current][i] && !visited[i]) {
                queue_enqueue(queue, &i);
                visited[i] = true;
            }
        }
    }
    
    printf("\n");
    queue_destroy(queue);
}
```

## 🧠 Memory Management

All data structures implement proper memory management:

- **Automatic Resizing**: Dynamic arrays automatically resize when capacity is exceeded
- **Memory Pooling**: Efficient memory allocation strategies to minimize fragmentation
- **Leak Prevention**: All allocated memory is properly tracked and freed
- **Error Handling**: Graceful handling of allocation failures

### Memory Safety Guidelines

1. Always call the corresponding `destroy` function for each `create` call
2. Check return values for allocation failures
3. Don't access freed memory or invalid indices
4. Use provided utility functions rather than direct memory manipulation

## ⚡ Performance Analysis

### Time Complexity Summary

| Operation | List | Stack | Queue |
|-----------|------|-------|-------|
| Insert/Push | O(1) amortized | O(1) | O(1) |
| Delete/Pop | O(n) worst case | O(1) | O(1) |
| Access | O(1) | O(1) | O(1) |
| Search | O(n) | O(n) | O(n) |

### Space Complexity
- **List**: O(n) where n is the number of elements
- **Stack**: O(n) where n is the number of elements  
- **Queue**: O(n) where n is the number of elements

### Benchmarking

Run performance benchmarks:
```bash
make benchmark
./benchmark
```

## 🧪 Testing

The project includes comprehensive test suites for each data structure:

### Running Tests

```bash
# Run all tests
make test

# Run specific test
./tests/test_list
./tests/test_stack  
./tests/test_queue

# Run with memory checking
make test-valgrind
```

### Test Coverage

- **Unit Tests**: Test individual functions with various inputs
- **Integration Tests**: Test interactions between different operations
- **Edge Cases**: Test boundary conditions and error scenarios
- **Memory Tests**: Verify proper memory management
- **Performance Tests**: Benchmark operations with large datasets

## 🤝 Contributing

Contributions are welcome! Please follow these guidelines:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/new-feature`
3. **Follow coding standards**: Use consistent formatting and naming conventions
4. **Add tests**: Include tests for new functionality
5. **Update documentation**: Update README and API docs as needed
6. **Submit a pull request**: Provide a clear description of changes

### Coding Standards

- Use meaningful variable and function names
- Follow K&R C style for bracing and indentation
- Include comprehensive comments
- Handle all error conditions
- Maintain consistent error return codes

**Happy coding! 🚀**
