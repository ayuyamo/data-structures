# Programming Assignment 2 

- **Author:** Halie Do (Quynh Anh)

## Project Structure
- For each class in the project:
    - list and describe the function / usage of every variable, constructor and method.

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
    - not sure what this does yet. 
```
    ~TicketItem(){
        personName = nullptr;
        reserveCode = nullptr;
    }
```

- `string getPersonName()`: Fuction returns `string` value of `TicketItem` member variable `personName`.
- `string getReserveCode()`: Fuction returns `string` value of `TicketItem` member variable `reserveCode`.
- `void print()`: Upon being called this function prints the `personName` and `reserveCode` values of the  `TicketItem` object (that was used to call `print()`).
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
    - Not sure what this does yet
```
    ~Node(){
        data = nullptr;
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
    - If no arguments were passed, the no-parameter constructor is called, initializing an empty stack with `top` pointer to `nullptr` (because there is no item in the stack yet) and the `stackSize` to `0`. 
    - If a `T` object pointer was passed (address to a data object of type `T`), the one-parameter constructor is called, which creates a new `Node<T>` pointer called `newNode` that will be initialized with the passed value pointer (`data`). By this point the stack already has one  `Node<T>` pointer as a stack element, hence the new item will be the top of the stack (`top = newNode`) and `stackSize` will be assigned `1`. 
```    
    LLStack(){
        top = nullptr;
        stackSize = 0;
    }
    LLStack(T *data){
        Node<T> *newNode = new Node<T>(data);
        top = newNode;
        stackSize = 1;
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

- `void deleteAll()`: This function iterates through and delete each node in the stack.

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
    public:
        //Contructors
        StackQ(){
            enQStack = new LLStack<T>();
            deQStack = new LLStack<T>();
            temp = new LLStack<T>();
            queueSize = 0;
        }
```
- **Destructor:**
    - This destructor calls `deleteAll()` to iterate and delete all nodes stored inside `enQStack` and `deQStack`. `temp` is always empty because the stack is only used to temporary store items in `deQStack` and at the end be cleared out after `makeDeQStack()` was executed.
```    
    ~StackQ() {
            enQStack->deleteAll();
            deQStack->deleteAll();
        }
```

- **Methods:**
    - `bool isEmpty()`: checks if the queue is empty. Returns `true` if it is, else returns `false`.

    - `bool isFull()`: checks if the queue is full. Returns `true` if it is, else returns `false`.

    - `int getSize()`: returns an `int` that represents the number of items are currently being stored inside the queue. 

    - `LLStack<T> *getEnQPointer()`: returns a pointer to memory address that holds object enqueue stack (`enQStack`).

    - `LLStack<T> *getDeQPointer()`: returns a pointer to memory address that holds object dequeue stack (`deQStack`).

    - `void enqueue(T* item)`:This function takes in a parameter of type `T*` that is pointer to a `T` object, then a new node will be created using this data and its pointer will be pushed into `enQStack`. There is a condition check to see if `queueSize` is full (if so then no new item will be pushed and an overflow warning message will be displayed in the terminal), and if not the new item will be inserted into the queue.  

    - `void makeDeQStack(LLStack<T> *current, LLStack<T> *inverse)`: This is a helper function that basically takes in two stack pointers as arguments, where each item will the popped from the `current` stack to the `inverse` stack (they're pointers, but just say stack because it's fewer words and the actual stacks are edited). The second stack pointer is called `inverse` because the (functionally defined) process of putting each item from `current` into `inverse` will make the stack hold a reversed list of items compared to the `current` stack. This is to make sure that when `dequeue()` is called the items that were inserted first will be taken out first (simulating the dequeuing process using only stack operations).

    - `void dequeue()`: The function will call `pop()` from `deQStack` (holding stack items in order of removal, so ones that will be removed first is the `top` of the stack) to remove the first inserted item, but if `deQStack` is empty, `makeDeQStack()` is called to take more items from `enqStack()` and reorganizes `deQStack` using `temp` so the list contains the correct order of items to be removed from the queue. 
    - `T* peek()`: returns a `T*` object pointer to the data object of the node to be deleted from the queue upon `dequeue()` being called.
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
- For the `StackQ` class:
    - draw (pictorial representation of stacks) 
    - explain with an example how `enQ()` and `deQ()` functions work with two stacks.