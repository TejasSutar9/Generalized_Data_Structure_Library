### 📚 Generalized Data Structure Library (GDSL)
---
1. Introduction
The Generalized Data Structure Library (GDSL) is a C++ template-based library that provides reusable, type-safe, and efficient implementations of commonly used data structures.
It is designed for students, developers, and competitive programmers who require a modular and scalable library for learning or integrating data structures into projects.
---

2. Features
The library provides generic implementations of the following data structures:

Type	Node Class	Functionality Class	Description
Singly Linear	SinglyLLLnode	SinglyLLL	Standard singly linked list
Singly Circular	SinglyCLLnode	SinglyCLL	Circular version of singly linked list
Doubly Linear	DoublyLLLnode	DoublyLLL	Doubly linked list with next & prev pointers
Doubly Circular	DoublyCLLnode	DoublyCLL	Doubly linked list with circular connection
Stack	Stacknode	Stack	LIFO stack with push/pop/peek
Queue	Queuenode	Queue	FIFO queue with enqueue/dequeue

---
3. Operations Supported

Linked Lists
InsertFirst(data) – Inserts at the beginning
InsertLast(data) – Inserts at the end
InsertAtPos(data, position) – Inserts at a specific position
DeleteFirst() – Deletes the first node
DeleteLast() – Deletes the last node
DeleteAtPos(position) – Deletes a node from a specific position
Display() – Prints all elements
Count() – Returns the number of elements

Stack
Push(data) – Adds element to the top
Pop() – Removes and returns the top element
Peep() – Returns the top element without removing it
Display() – Prints all stack elements
Count() – Returns total elements

Queue
Enqueue(data) – Adds element to the rear
Dequeue() – Removes and returns the front element
Display() – Prints all queue elements
Count() – Returns total elements

5. Design Principles
Generic Templates – Ensures type safety and reusability
Modular & Lightweight – Entire library in gdsl.cpp
Consistent Interfaces – Same method naming across structures
Efficient Memory Usage – Optimized operations
Beginner-Friendly – Easy to understand and use


7. Example Usage
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

📁 Folder Structure
docs/
examples/
include/
README.md

---
▶️ How to Run
Clone Repository
git clone <repo-url>
Navigate to Folder
cd Generalized_Data_Structure_Library
Compile
g++ main.cpp -o output
Run
./output

Windows:
output.exe

