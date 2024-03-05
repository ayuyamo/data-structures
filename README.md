# Introduction

**This repository contains a collection of programming projects completed during the SDSU CS210 Data Structures class. Each project is organized into separate folders and numbered according to completion order.**

## Project 1 ("PA1" folder)
### Overview
- This programming assignment entails utilizing a provided template for the `DoubleLinkedList` class, which includes a list of predefined functions such as `prepend()`, `append()`, `insert()`, etc. Additionally, a constructor for the `Data` class is provided, containing fields `string name` and `int value`, which serve as the data type for the nodes involved in this assignment.

### Details of the Assignment
The programming assignment is built on implementing the LIST ADT using a Doubly Linked List.
Use the `DLLTemplate` provided along with this project as a starting point.

### Adding methods
**Add & implement the following methods, according to the given definitions, to the `DoubleLinkedList` Class:**
1. Add all **Delete** Methods:
-  `void deleteAtHead()`: prints then deletes the head of the list.
-  `void deleteAtTail()`: prints then deletes the tail of the list.
-  `void deleteAtIndex(int index)`: prints then deletes the node at given index.
2. `void sortList()`: Sort all nodes in the list in ascending order of int value. Print the List.
3. `void removeMultiples()`: This removes all nodes that have matching data. This method must
delete these nodes and free up memory. Print the updated list.
4. `int countMultiples(T* value)`: This method counts how many nodes have the value matching to T
value passed in the argument.
- This method might require modifications being made to the Data class, to write a custom compareData()
method, which is also an acceptable solution.
5. `void evenOddSplit()`: This method splits the given linked list into two separate linked lists A and
B.
- List A will have all the even nodes from the original list
- List B will have all the odd nodes from the original list.
- As the nodes are being moved from the original list to the split lists, they need to be deleted
from the original list and the original list needs to be deleted after the split lists are created.
- Print both lists.
6. `void reverseList()`: Reverse the doubly Linked List. Print reversed list.

### Inside the main program
The Main Program should execute as follows:
1. Display a Menu for the user that loops infinitely till the exit, Split List or Delete List Option is
Chosen. User chooses a menu option. The “how” is your choice.
2. Menu is as follows; each option calls the corresponding function of the list.
    - Create a List (optional; I created an empty list before presenting the Menu to users)
    - Delete a List
    - Insert at Head
    - Insert at Tail
    - Insert at Index
    - Delete at Head
    - Delete at Tail
    - Delete at Index
    - Reverse List
    - Sort List
    - Count Multiples
    - Delete Multiples
    - Split List Even Odd
    - Exit

To run the program, first compile the c++ file:
```
g++ -o doubly_linked_list doubly_linked_list.cpp
```
Once the compilation is successful, you can run the generated binary/executable:
```
./doubly_linked_list
```
## Project 2 ("PA2" folder)
## Overview 
- The programming assignment is built on implementing the `STACK & QUEUE ADT` using a `Singly Linked List`.
- Implementing a Ticket Queue using two `Stacks` (which are in turn implemented as a `Single Linked List`).

## Class Descriptions & Constraints
### **Constraints:**
- Container classes must not be datatype dependent. Maintain the integrity of the template.
- All Classes must have a constructor that accepts arguments to initialize variables. You may
overload constructors.
- All classes must have a valid destructor.
- Mandatory variables listed must be added to each class. Additional variables may be declared.
- Mandatory method for every class is `void print()`. Additional methods may be defined.
- Do not change the names or data types of classes, variables or methods given below.

### **Descriptions:** 
1. **The Data class:**
    `Name: TicketItem`
    - This class will contain the details of the items in the queue:
    - **Mandatory Variables:**
        - `string personName`
        - `string reserveCode`
2. **The Node: (Uses Template)**
    `Name: Node`
    - This class is the node for the linked list.
    - **Mandatory variables:**
        - `T* data`
        - `Node* nextNode`
3. **The Stack Container: (Uses Template)**
    `Name: LLStack`
    - This class IMPLEMENTS `Stack ADT` methods. Stack is implemented using `Singly Linked List`.
    - **Mandatory variables:**
        - `Node<T>* top`
        - `int stackSize`
        - `const int SMAXITEMS`
    - **Mandatory Methods:**
        - `bool IsFull()`
        - `bool IsEmpty()`
        - `void push(T* item)`
        - `void pop()`
        - `T* peek ()`
4. **The Implementation: (Uses Template)**
    `Name: StackQ`
    - This class IMPLEMENTS the `Queue ADT Methods`.
    - The Queue is implemented using 2 `LLStack` objects. The underlying data structure is a combination of
    `push` and `pop` methods over the two stack objects.

    - **Mandatory variables:**
        - `LLStack* enQStack`
        - `LLStack* deQStack`
        - `int queueSize`
        - `const int QMAXITEMS`

    - **Mandatory Methods:**
        - `bool IsFull()`
        - `bool IsEmpty()`
        - `void enqueue (T* item)`
        - `void dequeue()`
        - `T* peek()`

- **Implementation Strategy:**
    - As you can notice, there are two Stacks (`enQStack` and `deQStack`) declared as member variables in the `StackQ` class. You need to use these two Stacks for implementing the functionalities of a queue.
    - How to perform `deQ()` - the dequeue method
        - pop the topmost element from the `deQStack`.
        - If the `deQStack` is empty, pop all the elements from the enQStack and push them
        one by one into the `deQStack` then pop from `deQStack` to perform `deQ()`.
        How to perform `enQ()` - the enqueue method
        - Add the new node to the top of the enQStack.
        - Empty condition for the enQStack is only to maintain the top reference.

- **main method:**
    - Create an object of the `StackQ` class to demonstrate all the functions of the
    `Queue` implemented as two stacks.
    - Display a Menu (like `PA1`) to perform the following options:
        1. Add Item to ticket queue
        2. Delete from ticket queue
        3. Peek from the ticket queue
        4. Display the ticket queue
        5. Display ticket queue size
        6. Display enQStack and deQStack
        7. Exit