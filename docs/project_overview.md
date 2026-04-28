 # 📚 Generalized Data Structure Library (GDSL)

---

## 1 Introduction

The **Generalized Data Structure Library (GDSL)** is a C++ template-based library that provides reusable, type-safe, and efficient implementations of commonly used data structures.
It is designed for students, developers, and competitive programmers who want a single, modular library for learning or integrating data structures into projects.

---

## 2 Features

The library includes the following data structures:

| Type              | Node Class        | Functionality Class | Description                                      |
|------------------|------------------|--------------------|--------------------------------------------------|
| Singly Linear     | SinglyLLLnode    | SinglyLLL          | Standard singly linked list                      |
| Singly Circular   | SinglyCLLnode    | SinglyCLL          | Circular singly linked list                      |
| Doubly Linear     | DoublyLLLnode    | DoublyLLL          | Doubly linked list (next & prev pointers)        |
| Doubly Circular   | DoublyCLLnode    | DoublyCLL          | Circular doubly linked list                      |
| Stack             | Stacknode        | Stack              | LIFO (Last In First Out) stack                   |
| Queue             | Queuenode        | Queue              | FIFO (First In First Out) queue                  |

---

## 3 Operations Supported

### 🔹 Linked Lists
- `InsertFirst(data)` – Insert at beginning  
- `InsertLast(data)` – Insert at end  
- `InsertAtPos(data, position)` – Insert at specific position  
- `DeleteFirst()` – Delete first node  
- `DeleteLast()` – Delete last node  
- `DeleteAtPos(position)` – Delete node at position  
- `Display()` – Display all elements  
- `Count()` – Return total nodes  

### 🔹 Stack
- `Push(data)` – Insert element  
- `Pop()` – Remove top element  
- `Peep()` – View top element  
- `Display()` – Display stack  
- `Count()` – Total elements  

### 🔹 Queue
- `Enqueue(data)` – Insert element  
- `Dequeue()` – Remove element  
- `Display()` – Display queue  
- `Count()` – Total elements  

---

## 4 Design Principles

- **Generic Templates**  
  Uses templates so the same code works with any data type.

- **Modular & Lightweight**  
  Entire library is implemented in a single file (`gdsl.cpp`) for simplicity.

- **Consistent Interfaces**  
  All data structures follow the same function naming, making them easy to use.

- **Efficient Memory Usage**  
  Designed to use memory efficiently with optimized operations.

- **Beginner-Friendly**  
  Code is simple, readable, and easy to understand for learning purposes. 

---

## 5 Example Usage
```
#include "../library/gdsl.cpp"

int main() {
    DoublyLLL<int> dobj;

    dobj.InsertFirst(11);
    dobj.InsertLast(21);
    dobj.InsertAtPos(16, 2);
    dobj.Display();   // Output: NULL<=> | 11 | <=> | 16 | <=> | 21 | <=> NULL

    dobj.DeleteAtPos(2);
    dobj.Display();   // Output: NULL<=> | 11 | <=> | 21 | <=> NULL

    cout << "Total nodes: " << dobj.Count() << endl;
    return 0;
}
```
