# Programming Assignment 2 

- **Author:** Halie Do (Quynh Anh)

## Project Structure
## Classes
### *TicketItem*
- **Fields (private):**
    - `string personName` : The variable holds `string` value of person's name 
    - `string reserveCode`: The variable holds `string` value of person's reserve code 
- **public:**
- **Constructor:** 
    - This constructor initializes the variables `personName` and `reserveCode` of `TicketItem` object with passed arguments `name` and `code`. 
```    
    TicketItem(string name, string code){
            this->personName = name;
            this->reserveCode = code;
        }
```
- **Destructor:**
    - This destructor is called when an object is about to be destroyed or goes out of scope. It prints the values of the current object (`personName` and `reserveCode`) by calling the `print()` function. This allows the user to see when the destructor is called, but does not perform any memory deallocation because the object will automatically be cleaned up by the default constructor when it goes out of scope. These print statements indicate that the destructor has been executed and the object's memory is released. 
```
    ~TicketItem(){
        print();
        cout << " -- Object deleted" << endl;
    }
```

- `string getPersonName()`: Fuction returns `string` value of `TicketItem` member variable `personName`.
- `string getReserveCode()`: Fuction returns `string` value of `TicketItem` member variable `reserveCode`.
- `void print()`: Upon being called this function prints the `personName` and `reserveCode` values of the  `TicketItem` object (that was used to call `print()`).
- `TicketItem* duplicateData()`: this function returns a new object with the same `personName` and `reserveCode` values as the current object (the one used by other classes to access this function). This function is used when switching items between different stacks in `StackQ` class because after `pop()` is called, the `data` object of the deleted node will be destroyed, hence trying to access and push it in a different stack generates a compiler error. How it works is this function is called to create an object with duplicate values and push it into the new stack while deleting the old object. 
### Node (template)
- **Fields:**
  - `T *data`: Contains node's data pointer of type `T` (template)
  - `Node<T> *nextNode`: This is holds the surrent node' s pointer to its next node (type `T`)
- **Constructor:** 
    - The following contructor initializes the `data` pointer with the passed argument `value`, which is a pointer to address of object `T`. `nextNode` is assigned with `nullptr` (which will be changed later in other classes that knows the next node the pointer points to). 
```  
    Node(T *value) {
        this->data = value;
        nextNode = nullptr;
    }
```
- **Destructor:**
    - If the `Node` object was destroyed or goes out of scope, the `~Node()` desctructor is called, which deletes the object `data` points to (hence the pointer will be invalidated after the `delete` operation) and set `nextNode`'s pointer to `nullptr`. This ensures that these pointers  inadvertently point to deallocated memory. 
```
    ~Node(){
        delete data;
        nextNode = nullptr;
    }
```
- `void print()`: This method uses `data` pointer to access its `T` class's `print()` value, which prints the information of the data of the node (`personName` and `reserveCode`). 

### *LLStack* (Template)
- **Fields (private):**
    - `Node<T> *top`: This variable holds the pointer to the top of the stack (most recently pushed item).
    - `int stackSize`: This variable holds an `int` value indicating the number of items currently stored in the stack.
    - `const int SMAXITEMS`: This variable holds a fixed `int` value specifying the max number of items the stack should hold. The idea is an attempt to push items into stack when `stackSize` is already equal to `SMAXITEMS` will cause an overflow. 
- **Constructor:** 
    - The constructor initializes `SMAXITEMS` to the passed parameter `maxNum` during the creation of the object because `SMAXITEMS` is `const` (changing a `const` value after the object was created might lead to compilation error). Otherwise, when a `LLStack` object was created, the stack is empty so its `top` pointer is set to `nullptr` and `stackSize` to `0` (because the stack currently has no items). 
```    
    LLStack(int maxNum) : SMAXITEMS(maxNum) {
        top = nullptr;
        stackSize = 0;
    }
```
- **Destructor:**
    - The following destructor is executed when the program ends (or when the class object is destroyed) and this process is to deallocate memory spaces of stack by having a while loop iterate through and delete each node in the stack. 
```
    ~LLStack() {
        Node<T> *temp = top;
        while (top) {
            top = top->nextNode;
            delete temp;
            temp = top;
        }
    }
```
- **Methods:**
    - `bool isFull()`: returns a `bool` value indicating whether the stack is full.

    - `bool isEmpty()`: returns a `bool` value indicating whether the stack is empty.

    - `void push(T *item)`: takes in a parameter that is pointer to an object of type `T`. This `push()` function creates a node pointer to this data and insert it to the top of the stack. Before pushing the item this function checks if the stack is full, if so then no push action will be done and inside the terminal a warning message will be displayed telling the user that the stack is full and no additional item can be inserted. `stackSize` then will be incremented by `1` because the stack has one more item.

    - `void pop()`: This function will delete the item atthe top of the stack. Before that it will update the new `top` to be the the current `top`'s `nextNode`. `stackSize` is then decremented by `1` because the stack just popped a value (has one less item). 

    - `T* peek()`: The function returns a `T` object pointer to the data of the `top` item (node) in the stack. That is, it tells user which item will be taken from the stack if `pop()` was called.

    - `void print()`: This function iterates through and print each node's data (`personName` and `reserveCode`) in the stack. 

### *StackQ* (Template)

- **Fields (private):**
    - `LLStack<T> *enQStack`: This variable holds pointer to the enqueue stack of `StackQ` class. When the program is being executed, if user tries to add item in the queue, the new item will pushed into this stack.

    - `LLStack<T> *deQStack`: This variable holds pointer to the dequeue stack of `StackQ` class. When the program is being executed, if user tries to delete an item (the last node) in the queue, this stack holds the list of items in order that it was pushed, and calls `pop()` to take out the first item that was inserted in the list. How it does this is holding a reversed `enQStack` (by popping each item from  `enQStack`and simultaneously inserting that item to `deQStack`) that correctly reflects the order of items to be deleted from the queue (FIFO) using stack operations (`pop()`).

    - `LLStack<T> *temp`: This is a temporary stack pointer that holds the extra items in `deQStack` when items were being deleted from `enQStack` and inserted into `deQStack`. This ensures that the order of items inserted into the queue is correct (Further explanation in `Problem definition` section). 

    - `int queueSize`: holds `int` value that tells the current number of items stored in the queue.
    - `const int QMAXITEMS`: This variable holds a fixed `int` value specifying the max number of items the queue should hold. The idea is an attempt to push items into queue when `queueSize` is already equal to `QMAXITEMS` will cause an overflow. 

- **Constructor:**
    - This constructor initializes an empty queue by creating `3` new empty stacks and assign them to `enQStack`, `deQStack` and `temp`. Since the queue is currently empty, `queueSize` is assigned `0` (no items in queue).
```
    //Contructors
    StackQ(){
        enQStack = new LLStack<T>(QMAXITEMS);
        deQStack = new LLStack<T>(QMAXITEMS);
        temp = new LLStack<T>(QMAXITEMS);
        queueSize = 0;
    }
```
- **Destructor:**
    - This destructor is called when `StackQ` object goes out of scope and it uses `delete` keyword to delete `enQStack` and `deQStack`. This will call the `~LLStack()` destructor for each object which loops through and delete every item (node) in the stack, and once a node is deleted its `data` object will also be destroyed, in this case `~TicketItem()` will be called, which prints the object's `personName` and `reserveCode` before it was destroyed. The `cout` commands are included in the destructor to keep track of the process (verify if each step is executed as expected).
```    
    //Destructor
    ~StackQ() {
        cout << "------------------------------------" << endl;
        delete enQStack;
        cout << "enQStack successfully deleted" << endl;
        cout << "------------------------------------" << endl;
        delete deQStack;
        cout << "deQStack successfully deleted" << endl;
        cout << "------------------------------------" << endl;
    }
```

- **Methods:**
    - `bool isEmpty()`: checks if the queue is empty. Returns `true` if it is, else returns `false`.

    - `bool isFull()`: checks if the queue is full. Returns `true` if it is, else returns `false`.

    - `int getSize()`: returns an `int` that represents the number of items are currently being stored inside the queue. 

    - `LLStack<T> *getEnQPointer()`: returns a pointer to memory address that holds object enqueue stack (`enQStack`).

    - `LLStack<T> *getDeQPointer()`: returns a pointer to memory address that holds object dequeue stack (`deQStack`).

    - `void enqueue(T* item)`:This function takes in a parameter of type `T*` that is pointer to a `T` object, then a new node will be created using this data and its pointer will be pushed into `enQStack`. There is a condition check to see if `queueSize` is full (if so then no new item will be pushed and an overflow warning message will be displayed in the terminal), and if not the new item will be inserted into the queue.  

    - `void makeReverseStack(LLStack<T> *current, LLStack<T> *inverse)`: This is a helper function that basically takes in two stack pointers as arguments, where each item will the popped from the `current` stack to the `inverse` stack (they're pointers, but just say stack because it's fewer words and the actual stacks are edited). The second stack pointer is called `inverse` because the (functionally defined) process of putting each item from `current` into `inverse` will make the stack hold a reversed list of items compared to the `current` stack. This is to make sure that when `dequeue()` is called the items that were inserted first will be taken out first (simulating the dequeuing process using only stack operations).

    - `void dequeue()`: The function will call `pop()` from `deQStack` (holding stack items in order of removal, so ones that will be removed first is the `top` of the stack) to remove the first inserted item, but if `deQStack` is empty, `makeReverseStack()` is called to take more items from `enqStack()` and reorganizes `deQStack` using `temp` so the list contains the correct order of items to be removed from the queue. 

    - `T* peek()`: returns a `T*` object pointer to the data object of the node to be deleted from the queue upon `dequeue()` being called. Hence this function looks at the `top` of `deQStack` and if it is empty, execute the line `makeReverseStack(enQStack, deQStack);` to push items from `enQStack` to `deQStack` before calling the `LLStack` object's `peek()` function (`return deQStack->peek();`).

    - `void print()`: iterates through and prints all items in the queue (the order that items were inserted, not the stack order). To do that, `deQStack` is printed (taking items from `enQStack` and using `temp` to organize the order of items) so that inside the terminal the queue is display from the first item inserted to the last item inserted. 

## Global functions & variables

- `void executeCommands(StackQ<TicketItem> *queue ,int option)`: This is a helper function that takes two parameters, one is an empty queue pointer (already initiated inside `main()`) and other is the `option` user picked from the menu. There is a switch-case statement inside the function that execute commands to perform operations according to the user's option (`add/delete` item, `peek`, `display queue` etc.), and access the needed functions from `QStack` class to perform those operations using the `QStack` object pointer (the first argument). 

- `void displayMenu()`: This is a helper function that uses `cout` commands to print the list of operations user can pick from to modify & read contents of the queue. 

- `string getName()`: This function is called in `executeCommands()` function `case 1` (user wants to add item into queue) which prints string prompting user input for person's first & last name and returns the full name. This returned `string` value will then be passed as `first parameter` in `TicketItem` class to set value for the class's member variable `personName`. 

- `random_device rd`: This line creates an instance of the random_device class named `rd`
- `mt19937 gen(rd())`: This line creates an instance of the `Mersenne Twister` pseudo-random number generator named `gen`. `mt19937` is a pseudo-random number generator that generates random 32-bit integers. `rd()` generates the seed for the `Mersenne Twister`. These variables are used by `genReserveCode()` function to generate random `int` converted to `string` values to be passed into `TicketItem` class's member variable `reserveCode`. 

- `string genReserveCode()`: This function returns a randomly generated 8-digit `string` value (generate a random `int`, then covert it to `string` and return the `string` value) representing the reserve code for `TicketItem` class. This function will also be called inside `executeCommands` function `case 1` and its return value will be passed as the `second parameter` to initialize the new `TicketItem` object's member variable `reserveCode`. 

## `main()`
- `int input`: This variable will hold an `int` value reprsenting number option the user picked from the queue menu. Initialized with `1` so that it enters the while loop.
- `bool validInput`: holds a `bool` value indicating if the user input was valid (if user input number that is out of scope or a key not in correct format, `validInput` will be `false`, otherwise `true).
- `StackQ<TicketItem> *ticketQueue = new StackQ<TicketItem>()`: This creates a `StackQ` object holding items whose data type is of `TicketItem` class and have `ticketQueue` points to that `StackQ` object's memory address. This will be the main queue that is going to modified during runtime. 

- `while()`: 
    - Executes as long as the user input was valid (between `1` and `7`).
    - Calls `displayMenu()` so that as long as the program still runs, and after the operations (according to user option) were completed, the menu will be displayed.
    - `do while()` loop is to take user input and handles any problems related to getting input. 
    - After getting a valid `input`, `main()` calls `executeCommands()` to handle operations according to user input (this along with the previously initialized `QStack` object pointer will be passed as arguments to `executeCommands()`).
    - `if()`: This statement checks if the user input was `7`, which is `Exit`, in which case main program will delete the `QStack` object pointer and `break` out of the while loop to exit the program. 

## Handling input error
This `do-while()` loop uses functions accessible with object `cin` to clear error flags (that would be generated if user provides incorrect input format) using `clear()` and discard invalid input using `ignore()`. The loop continues until the input was valid (`int` value between `1` and `7`), in which case `validInput` will be assigned `true`, thus exiting the loop.

```
    do {
        cout << "Pick an option: ";
        cin >> input;
        if (input < 1 || input > 7 || cin.fail()) {
            validInput = false;
            cout << "Invalid input. Please enter a valid integer (between 1 and 7):" << endl;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any invalid input
        } else {
            cout << "------------------------------------" << endl;
            validInput = true;
        }
    } while (!validInput);
```

## Problem Definition
- **Pictorial representation for the `StackQ` class:**

![pictorial representation of stacks](https://github.com/ayuyamo/data-structures-projects/blob/df750232bdec98fdfc9f1f62fdf1273d3688b973/PA2/img/PA2StackDiagram.png)


- **How `enQ()` and `deQ()` functions work with two stacks:**
    - When items are added to the queue, the `enqueue()` function calls `push()` to push items into `enQstack`. Hence the stack represents a list of items in descending order (`Last In First Out`).

    - To make it work like a queue, when `dequeue()` is called the first inserted item should be the first removed. the `deQStack` holds items in order that user inserted them. This was done by popping each item from `enQStack` and push it into `deQStack`. Doing it this way reverses the order of items when they're inserted in `deQStack`, hence it holds the correct order that items in a queue should be deleted (`First In First Out`). 

    - However this became a problem when `deQStack` is not empty. Supposing new items are pushed from `enQstack` into it without first removing exisiting items in `deQStack`, what resulted was wrong order of deleting items, since the newly inserted items will be stacked on top of the items that were supposed to be removed first. Hence if `dequeue()` is called, then the new items were popped when they should be the last items to be removed from the list. 

    - In other words, there's a need for a temporary stack (`temp`) that holds all the exisiting values of `deQStack` (popping items from `deQStack` to `temp`) while items from `enQStack` are inserted into the now empty `deQStack`. After all items from `enQStack` has been pushed into `deQStack`, `temp` will pop items and return them to `deQStack`. That way the queue can maintain the right order of deleting items. 
