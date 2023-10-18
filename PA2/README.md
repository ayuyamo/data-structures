# Programming Assignment 2 

- **Author:** Halie Do (Quynh Anh)

## Project Structure
- For each class in the project:
    - list and describe the function / usage of every variable, constructor and method.

## Classes
### TicketItem
- **Fields (private):**
    - `string personName`
    - `string reserveCode`
- **public:**
- **Constructor:** 
```    
    TicketItem(string name, string code){
            this->personName = name;
            this->reserveCode = code;
        }
```
- `string getPersonName()`
- `string getReserveCode()`
- `void print()`
### Node (template)
- **Fields:**
  - `T *data`
  - `Node<T> *nextNode`
- **Constructor:** 
```  
    Node(T *value) {
        this->data = value;
        nextNode = nullptr;
    }
```
- `void print()`
### LLStack
- **Fields (private):**
    - `Node<T> *top`
    - `int stackSize`
    - `const int SMAXITEMS`
- **Constructor:** 
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
- `bool isFull()`
- `bool isEmpty()`
- `void push(T *item)`
- `void pop()`
- `T* peek()`
- `void deleteAll()`
- `void print()`

### StackQ (Template)

- **Fields (private):**
    - `LLStack<T> *enQStack`
    - `LLStack<T> *deQStack`
    - `LLStack<T> *temp`
    - `int queueSize`
    - `const int QMAXITEMS`

- **Constructor:**
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
```    
    ~StackQ() {
            enQStack->deleteAll();
            deQStack->deleteAll();
        }
```

- **Methods:**
    - `bool isEmpty()`
    - `bool isFull()`
    - `int getSize()`
    - `LLStack<T> *getEnQPointer()`
    - `LLStack<T> *getDeQPointer()`
    - `void enqueue(T* item)`
    - `void makeDeQStack(LLStack<T> *current, LLStack<T> *inverse)`
    - `void dequeue()`
    - `T* peek()`
    - `void print()`

## Non-member functions

- `void executeCommands(StackQ<TicketItem> *queue ,int option)`
- `void displayMenu()`

## Handling input error
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