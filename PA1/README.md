# Programming Assignment 1 Methods Explained

**Project Name**: Programming Assignment 1
**Author**: Quynh Anh N Do (Halie Do)
**File Structure of the project submitted**: 
- A zip file named "Halie_Do.zip" containing:
    **→** DoubleLinkedList.cpp
    **→** README.pdf
## Software that was used for this assignment: VSCode
## How to get started?
- When the program first runs, it needs to create a list, hence requiring the user to choose data and value for the first node, which it will use to initialize the new list with. After the process was complete it will print the new list (which then only contains the first node created)
- After that, a menu of options for manipulating the list will be displayed, prompting user to type an `int` number between `1` and `13` to pick an option. A warning will be displayed to require typing another number if the input was not in range `1-13`.
- **Options**: 
    - If `1` or `13` was picked, the list will be deleted and program will exit.
    - If `2` was picked, the terminal will prompt user input for (`string`) name and (`int`) value of the node to be inserted at the head of the list. This input will create a new data and pointer to that data address and invoke the `prepend()` method, which will perform the action of inserting the new node at the beginning of the list. After the method was executed, inside the terminal, the list with new node will be displayed. 
    - If `3` was picked, the terminal will prompt user input for (`string`) name and (`int`) value of the node to be inserted at the tail of the list. This input will create a new data and pointer to that data address and invoke the `append()` method, which will perform the action of inserting the new node at the end of the list. After the method was executed, inside the terminal, the list with new node will be displayed. 
    - If `4` was picked, the terminal will display  the terminal will prompt user input for (`string`) name, (`int`) value as well as the index at which the new node will be inserted into the list. This input will create a new data and pointer to that data address and invoke the `insert()` method, which inserts the new node at the specified index in the list. After the method was executed, inside the terminal, the list with new node will be displayed. If the index wasn't valid, a warning message will be displayed to notify user of insertion failure, and the displayed list will be unchanged. 
    - If `5` was picked, the head node will be deleted (using the `deleteAtHead()` method) and displayed in terminal, following the updated list after the deletion process.
    - If `6` was picked, the tail node will be deleted (using the `deleteAtTail()` method) and displayed in terminal, following the updated list after the deletion process.
    - If `7` was picked, the program will prompt user to input index value of the node they want to delete, then display the list after the node was deleted (if the received index input was out of scope, the  displayed list will be exactly the same as before).
    - If `8` was picked, the `reverseList()` method will be called, and every node will be listed in reverse order when displayed in terminal.
    - If `9` was picked, the list will be sorted in ascending order (in terms of `int` value, from smallest to largest) and displayed after the sorting process was completed (using `sortList()` method).
    - If `10` was picked, the terminal will require user to type in data (`string` name, `int` value) and use given input to compare & display the number of nodes with matching data.
    - If `11` was picked, the terminal will display the new list after every node with matching data (its name and value) was removed.
    - If `12` was picked, in terminal each deleted node will be displayed, following the contents inside `even` and `odd` lists created after the original list was splited. Afterward the original list will be destroyed (using   the `delete` keyword) and the program exits. 
    b. Describe what function is called by each input and briefly describe each function.
### Runtime Complexity of each function
