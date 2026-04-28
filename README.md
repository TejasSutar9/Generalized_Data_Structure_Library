# 📚 Generalized Data Structure Library (GDSL)

A C++ template-based library that provides reusable, type-safe, and efficient implementations of commonly used data structures.

---

## 🚀 Introduction

The **Generalized Data Structure Library (GDSL)** is designed for students, developers, and competitive programmers who want a modular and scalable way to learn and implement data structures.

It focuses on:
- Reusability
- Type safety (using templates)
- Clean and consistent design

---

## ✨ Features

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

## ⚙️ Operations Supported

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

## 🧠 Design Principles

- **Generic Templates** → Type-safe and reusable  
- **Modular & Lightweight** → Entire library in a single file (`gdsl.cpp`)  
- **Consistent Interfaces** → Same method naming across all structures  
- **Efficient Memory Usage** → Optimized operations  
- **Beginner-Friendly** → Easy to understand and use  

---

## 📌 Example Usage

```cpp
#include "../library/gdsl.cpp"

int main() {
    DoublyLLL<int> dll;

    dll.InsertFirst(10);
    dll.InsertLast(20);
    dll.InsertAtPos(15, 2);
    dll.Display();

    dll.DeleteAtPos(2);
    dll.Display();

    cout << "Total nodes: " << dll.Count() << endl;
    return 0;
}

---

## 📁 Folder Structure
```
Generalized_Data_Structure_Library/
│── docs/
│── examples/
│── include/
│── README.md
```

---

## ▶️ How to Run
1. Clone Repository
```
git clone <repo-url>
```
2. Navigate to Folder
```
cd Generalized_Data_Structure_Library
```
3. Compile
```
g++ main.cpp -o output
```
4. Run
```
Linux / Mac:
./output
```
Windows:
```
output.exe
```
