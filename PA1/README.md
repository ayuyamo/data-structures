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
- `deleteAtHead()` : **O(1)** (Because every command in the function runs constant time)
- `deleteAtTail()` : **O(1)** (Because every command in the function runs constant time)
- `deleteAtIndex()`: **O(n)** (When getting the previous node of the node to delete, the command `Node<T> *prev1 = get(index - 1);` calls to `get()` method that runs to the **O(n)** complexity)
- `sortList()` : **O(n)** 
    ``` while(prev1 && prev1->value->value > currNode->value->value)
            prev1 = prev1->prev;
    ```
    - The above command makes the worst run time complexity for this method O(n) by taking into account the possibility that `currNode` (when being the last node in the list) while be compared to every other (previous) node in the list to find the smallest `prev1` node value to insert `currNode` after (or `currNode` itself might be the node with smallest values and be prepended to the list)
- `removeMultiples()` : **O(n^2)** 
    - This is because `removemultiples()` has a while loop (O(n)) that loops through each node in the given list, and everytime `countMultiples()` will be called (to check if each node has duplicates), which runs to O(n), and the function will call to `removeMultiplesOf()` if the `if` statement was true also runs to O(n) (but since these function call operations aren't nested within each other, the overall runtime is still O(n)). Given the while loops in `removeMultiples()`, which has O(n) complexity, and `countMultiples()` inside it that also runs to O(n), the overall complexity (due to nested loops) is **O(n)**.

- `evenOddSplit()` : **O(n)**
    - The operation inisde this method that takes the worst time complexity is 
    ``` while (head){
            if (index % 2 == 0){
                even->append(head->value);
            } 
            else {
                odd->append(head->value);
            }
            deleteAtHead();
            ++index;
        }
    ```
    - Hence the runtime complexity for `evenOddSplit()` is O(n).
- `reverseList()` : O(n)
    - Similar to `evenOddSplit()`, the below while loop inside the function causes the time complexity of O(n):
    ```
    while(curr){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    ```
    - Since this command loops through every node in the list and reassign its pointers, the time complexity of this while loop is O(n).

***Helper Functions***:

- `printMenu()` : **O(1)**, since every command in the function is print line that only takes constant run time
- `createList()`: **O(1)**, because even though inside the function the `printList()` method was called to print the contents of the new list (which loops through and print names and values of each node in the list), there always only one node that the new list was intialized with, hence the while loop inside `printList()` for that particular case only runs once, and `createList()` itself will only be used once for initializing the list at the beginnning of the program, so I'd say it runs to O(1) instead of O(n).
- `executeCommands()`: **O(n^2)**, since in the worst case scenario, the user will choose the input `11` to remove duplicate nodes in the list, which jumps to `case 11` of the switch-case statement inside the `executeCommands()` function, and inside `case 11`, `removeMultiples()` is called. Since `removeMultiples()` runs to O(n^2) and is inside `executeCommands()`, this function runs to O(n^2).
- `deleteNode()`: **O(1)**; every statement inside the function runs to constant time.
- `removeMultiplesOf()`: **O(n)**; the function has a while loop to test every node in the linked list that has matching data as the given `T* data` argument, which runs to O(n).
- `insertAfter()`: **O(1)**; every statement inside the function runs to constant time.
- `moveAfter()`: **O(1)**;  every statement inside the function runs to constant time.
