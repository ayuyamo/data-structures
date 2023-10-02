# Programming Assignment 1 Methods Explained

**Project Name**: Programming Assignment 1
**Author**: Quynh Anh N Do (Halie Do)
**File Structure of the project submitted**: 
- A zip file named "Halie_Do.zip" containing:
    - DoubleLinkedList.cpp
    - README.pdf
## Software that was used for this assignment:
- **VSCode:** This makes it easy for me to push/pull changes from my private repository for programming assignments from this class on github 
- **How to use:** I just follow tutorials for using **VSCode** on youtube (there are plenty and most of them will help) and they show how to install the software & compilers for different programming languages you choose to write in, how to sign into github account from **VSCode** and switch between branches to push/pull changes from github. Aside from ease of access to github and syncing changes (and its personal preference) I think it owrks the same way as any other IDE. 
## How to get started?
- When the program first runs, it will create a new list (`DoubleLinkedList<Data> *dll = new DoubleLinkedList<Data>();`). After that, a menu of options for manipulating the list will be displayed, prompting user to type an `int` number between `1` and `13` to pick an option. A warning will be displayed to require typing another number if the input was not in range `1-13`. 

    ***Options***:
    - **If `1` was picked,** the **list will be deleted** and program will exit. 
    - **If `2` was picked,** the terminal will prompt user input for (`string`) name and (`int`) value of the node to be inserted at the head of the list. This input will create a new data and pointer to that data address and invoke the `prepend()` method, which will perform the action of **inserting the new node at the beginning of the list**. After the method was executed, inside the terminal, the list with new node will be displayed. 
    - **If `3` was picked,** the terminal will prompt user input for (`string`) name and (`int`) value of the node to be inserted at the tail of the list. This input will create a new data and pointer to that data address and invoke the `append()` method, which will perform the action of **inserting the new node at the end of the list**. After the method was executed, inside the terminal, the list with new node will be displayed. 
    - **If `4` was picked,** the terminal will display  the terminal will prompt user input for (`string`) name, (`int`) value as well as the index at which the new node will be inserted into the list. This input will create a new data and pointer to that data address and invoke the `insert()` method, which **inserts the new node at the specified index in the list**. After the method was executed, inside the terminal, the list with new node will be displayed. If the index wasn't valid, a warning message will be displayed to notify user of insertion failure, and the displayed list will be unchanged. 
    - **If `5` was picked,** the **head node will be deleted** (using the `deleteAtHead()` method) and displayed in terminal, following the updated list after the deletion process.
    - **If `6` was picked,** the **tail node will be deleted** (using the `deleteAtTail()` method) and displayed in terminal, following the updated list after the deletion process.
    - **If `7` was picked,** the program will prompt user to input **index value of the node they want to delete**, then display the list after the node was deleted (if the received index input was out of scope, the  displayed list will be exactly the same as before).
    - **If `8` was picked,** the `reverseList()` method will be called, and **every node will be listed in reverse order** when displayed in terminal.
    - **If `9` was picked,** the **list will be sorted in ascending order** (in terms of `int` value, from smallest to largest) and displayed after the sorting process was completed (using `sortList()` method).
    - **If `10` was picked,** the terminal will require user to type in data (`string` name, `int` value) and use given input to **compare & display the number of nodes with matching data**.
    - **If `11` was picked,** the terminal will **display the new list after every node with matching data (its name and value) was removed**.
    - **If `12` was picked,** in terminal each deleted node will be displayed, following the contents inside **`even` and `odd` lists** created after the original list was splited. Afterward the original list will be destroyed (using   the `delete` keyword) and the program exits(because inside the `main()` program, the while loop always checks if `userInput` was `1`, `12` or `13`, where in the first two cases the linked list will be deleted before `break;` was executed to exit the loop, which ends the program). 
    - **If `13` was picked,** the program will call `executeCommands()` with input `13`, which simply returns back to the `main()` program, check if `userInput` was `13`, in which case the `break;` command will be called to exit the while loop, hence ending the program. 

    ***Desctiption of the functions***:
    - `DoubleLinkedList()`: This constructor without parameters was added to enable creating an empty list.
    ```
        DoubleLinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
    ```
    - `executeCommands()`: A helper function that was called based on the user input inside the while loop in the main program. It uses switch-case statement to executes different sets of commands based on the case number.

    - `deleteAtHead()`: checks if the `length` is `0`, in which case no further action is needed because there is no node to delete. If not, the list's `head` pointer will be assigned to variable `temp`. Next it will check if the `length` is `1`, if so then the `head` and `tail` pointers will be updated to `nullptr` and `temp` will be deleted (previous head node was deleted). Otherwise, the `else{}` statement will be executed, where `head` will point to the successor of the previous `head` node, hte `prev` pointer now pointing to `nullptr`. After `else{}` was done, the previous `head` node (currently assigned to `temp`) will be deleted. `length` was decremented because now there's one less node in the list. **Note: `temp` will be printed so user knows which node will be deleted before it was actually deleted.** 

    - `deleteAtTail()`: Using the same logic as `deleteAtHead()`, the function will first check if `length` equals `0` (if so then `return;` will be called and nothing will be deleted). if `length` euqals `1`, the `head` and `tail` pointers will be `nullptr`, otherwise the new `tail` will be the node before the previous tail and its `next` pointer will now be `nullptr`. At the end, `temp` is printed and then deleted. `length` was decremented because now there's one less node in the list.

    - `deleteAtIndex()`: checks if index is valid (between `0` and `length - 1`), otherwise it simply executes `return;` and does not delete any node. If `index` is `0`, it calls `deleteAtHead()`, if `index` is `length - 1` then it calls `deleteAtTail()`. Otherwise, three new node pointers `prev1`, `temp` and `next1` will be created and assigned pointers to the node before the index, the node at the index, and the node right after the index, respectively. `prev1`'s `next` pointer will point to `next1`, and `next1`'s `prev` pointer points to `prev1`, which updates all the necessary pointers before deleting the node at the specified index. `temp` is printed and then deleted at the end. `length` is decremented since a node was deleted from the list.
    - `sortList()`: create three pointers `currNode` as `head->next`, `prev1` as `head` and `next1`as `currNode->next`. Then the following while loop finds the **first** node in the list whose `value` is smaller than `currNode`'s:
    ```
        while(prev1 && prev1->getValue()->getValue() > currNode->getValue()->getValue())
            prev1 = prev1->prev;
    ```
    Once the "smallest" `prev1` node was found, `moveAfter()` was called to insert `currNode` behind the respective `prev1` node. After the insertion was completed, the sorting process begins again with the node after the `currNode` (`next1`) and repeats until every node is sorted. At the end, the new sorted list is printed. 

    - `moveAfter()`: the helper function used in `sortList()` to sort the nodes. First the node to move (aka `nodeToMove`) will be removed (but not deleted) from the list, hence `nodeToMove`'s `next` and `prev` node pointers were updated to not include it. Then, the following `if{}` statement checks if there's a smaller node before that `nodeToMove` could be inserted after (aka `nodeBefore`), otherwise that means `nodeToMove` has the smallest `value` in the list and will be prepended to the list. If instead `nodeBefore` was found (aka not `NULL`) then `insertAfter()` was called to insert `nodeToMove` after `nodeBefore`. 

    - `removeMultiples()`: this function checks and removes all duplicate nodes (nodes with matching data values, aka `name` and `value`). First it creates new pointer `temp` and assigns it the pointer to the `head` node. It then loops through every node in the list and check for duplicates (using `if (countMultiples(temp->value) > 1)` statement) to remove (if the duplicate is found then we assign the node address to `removeMultiplesOf()` to delete all nodes with matching data as the passed argument). At the end the list after removing duplicates was printed to the terminal. 
    
    - `removeMultiplesOf()`: called in `removeNumtiples()` to remove each node with a certain matching data (this function is called on multiple times for different data). Once a node with matching data is found, `deleteNode()` is called to remove that node. This repeats until every node with matching data is deleted from the list.

    - `countMultiples()`: takes in `Data` type parameter and compare its `name` and `value` to every node in the list. The function returns the number of nodes with matching data. 

    - `evenOddSplit()`: function that separates nodes from the original list into `even` and `odd` lists based on index, then prints the 2 new lists and destroy the original one. At the beginning, `int` type variable called `index` was delcared and initialized with `0` to keep track of the index of the nodes in the list. If the original list's `length` is `0` then no splitting operation is made because the list is empty. Else, `even` and `odd` lists will be created empty, following a while loop that appends nodes from original list (by index) into its respective (new) list, while destroy the same node in the original list. The while loop ends when the original list is empty, and the two new lists will be printed. *Note: The original list is not deleted until the program finishes executing `evenOddSplit()` and returns control to `main()`, where it checks if `userInput` value was `12` (if user chose the option of sorting the list) and deletes the original list as well as exiting the program if the condition was `true`*.

    - `reverseList()`: loops through every node and updates its node pointers. Each node's `next` pointer will point to its previous node, and its `prev` pointer points to the node after it. At the end the the following statements are executed to assign the `tail` pointer to `head`, and the new `tail` pointer will be the previous `head` node:
    ```
        head = tail;
        tail = temp; //temp was the previous head node before the reversing process was executed
    ```
    

### Runtime Complexity of each function
- `deleteAtHead()` : **O(1)** (Because every command in the function runs constant time)
- `deleteAtTail()` : **O(1)** (Because every command in the function runs constant time)
- `deleteAtIndex()`: **O(n)** (When getting the previous node of the node to delete, the command `Node<T> *prev1 = get(index - 1);` calls to `get()` method that runs to the **O(n)** complexity)
- `sortList()` : **O(n)** 
    ``` 
        while(prev1 && prev1->getValue()->getValue() > currNode->getValue()->getValue())
            prev1 = prev1->prev;
    ```
    - The above command makes the worst run time complexity for this method O(n) by taking into account the possibility that `currNode` (when being the last node in the list) while be compared to every other (previous) node in the list to find the smallest `prev1` node value to insert `currNode` after (or `currNode` itself might be the node with smallest values and be prepended to the list)
- `removeMultiples()` : **O(n^2)** 
    - This is because `removemultiples()` has a while loop (O(n)) that loops through each node in the given list, and everytime `countMultiples()` will be called (to check if each node has duplicates), which runs to O(n), and the function will call to `removeMultiplesOf()` if the `if` statement was true also runs to O(n) (but since these function call operations aren't nested within each other, the overall runtime is still O(n)). Given the while loops in `removeMultiples()`, which has O(n) complexity, and `countMultiples()` inside it that also runs to O(n), the overall complexity (due to nested loops) is **O(n)**.

- `evenOddSplit()` : **O(n)**
    - The operation inisde this method that takes the worst time complexity is 
    ``` 
        while (head){
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
- `executeCommands()`: **O(n^2)**, since in the worst case scenario, the user will choose the input `11` to remove duplicate nodes in the list, which jumps to `case 11` of the switch-case statement inside the `executeCommands()` function, and inside `case 11`, `removeMultiples()` is called. Since `removeMultiples()` runs to O(n^2) and is inside `executeCommands()`, this function runs to O(n^2).
- `deleteNode()`: **O(1)**; every statement inside the function runs to constant time.
- `removeMultiplesOf()`: **O(n)**; the function has a while loop to test every node in the linked list that has matching data as the given `T* data` argument, which runs to O(n).
- `insertAfter()`: **O(1)**; every statement inside the function runs to constant time.
- `moveAfter()`: **O(1)**;  every statement inside the function runs to constant time.
*Access Functions*:
- `getValue()` (in `Node` class): Since the value address the `node` pointer points to is a `private` member, this `get()` function provides the node access to other `get()` methods inside the class of the node's `value` object. 
- `getValue()` (in `Data` class): returns the `int value` of the `Data` object (since `value` field is a `private` member and direct access is not allowed)
- `getName()` (in `Data` class): returns the `string name` of the `Data` object (since `name` field is a `private` member and direct access is not allowed)

