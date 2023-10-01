# Introduction

**This repository will be used to store all of my programming assignments (separated into folders and numbered in the order that the assignment was given) from SDSU CS210 Data Structures class**

## Programming Assignment 1 ("PA1" folder)
### Overview
- This is the first programming assignment in the class where I was given the template for list of predefined functions in `DoubleLinkedList` class (such as `prepend()`, `append()`, `insert()` etc.) and constructor for `Data` class (containing fields `string name` and `int value`) that will be the data type of the nodes I will work with for the purpose of this assignment.

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