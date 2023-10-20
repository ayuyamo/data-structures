#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class TicketItem {
private:
    string personName;
    string reserveCode;
public:
    //Constructor
    TicketItem(string name, string code){
        this->personName = name;
        this->reserveCode = code;
    }
    //Destructor
    ~TicketItem(){
    }
    string getPersonName(){ return this->personName;}
    string getReserveCode(){ return this->reserveCode;}
    void print() {
        cout << "Person's name: " << this->personName << " - ";
        cout << "Reserve code: " << this->reserveCode << " " << endl;
    }
};

// Node Class : Node for the Stack Linked List
template <typename T> class Node {
public:
    T *data;
    Node<T> *nextNode;

    Node(T *value) {
        this->data = value;
        nextNode = nullptr;
    }
    ~Node(){
        data = nullptr;
        nextNode = nullptr;
    }
    void print() { data->print(); }
};

template <typename T> class LLStack {
private:
    Node<T> *top;
    int stackSize;
    const int SMAXITEMS = 20;

public:
    //Contrustor
    LLStack(){
        top = nullptr;
        stackSize = 0;
    }
    LLStack(T *data){
        Node<T> *newNode = new Node<T>(data);
        top = newNode;
        stackSize = 1;
    }
    //Destructor
    ~LLStack() {
        Node<T> *temp = top;
        while (top) {
            top = top->nextNode;
            delete temp;
            temp = top;
        }
    }
    bool isFull(){ return stackSize == SMAXITEMS;}
    bool isEmpty(){ return stackSize == 0;}
    void push(T *item) {
        Node<T> *newNode = new Node<T>(item);
        if (isEmpty()) {
            top = newNode;
        } else if (isFull()){
            cout << "Stack full: Cannot insert items" << endl;
            return;
        } else {
            newNode->nextNode = top;
            top = newNode;
        }
        stackSize++;
    }
    void pop(){
        if (stackSize == 0)
            return;
        Node<T> *temp = top;
        if (stackSize == 1) {
            top = nullptr;
        } else {
            top = top->nextNode;
        }
        delete temp;
        stackSize--;
    }
    T* peek(){
        return top->data;
    }
    void deleteAll(){
        while (top) {
            pop();
        } 
    }
    void print(){
        Node<T> *temp = top;
        while (temp != nullptr) {
            temp->print();
            temp = temp->nextNode;
        }
    }
};

template <typename T> class StackQ {
private:
    LLStack<T> *enQStack;
    LLStack<T> *deQStack;
    LLStack<T> *temp;
    int queueSize;
    const int QMAXITEMS = 20;
public:
    //Contructors
    StackQ(){
        enQStack = new LLStack<T>();
        deQStack = new LLStack<T>();
        temp = new LLStack<T>();
        queueSize = 0;
    }
    //Destructor
    ~StackQ() {
        enQStack->deleteAll();
        deQStack->deleteAll();
    }
    bool isEmpty() { return queueSize == 0;}
    bool isFull() { return queueSize == QMAXITEMS;}
    int getSize() { return queueSize;}
    LLStack<T> *getEnQPointer() { return enQStack;}
    LLStack<T> *getDeQPointer() { return deQStack;}
    void enqueue(T* item){
        if (!isFull()){
             enQStack->push(item);
            queueSize++;
        } else {
            cout << "------------------------------------" << endl;
            cout << "Warnings: Queue FULL -- Cannot insert more items" << endl;
            cout << "------------------------------------" << endl;
            cout << "Item not inserted: " << item->getPersonName() << endl;
        }
    }
    void makeDeQStack(LLStack<T> *current, LLStack<T> *inverse){
        while(!current->isEmpty()){
            inverse->push(current->peek());
            current->pop();
        }
    }
    void dequeue(){
        if (deQStack->isEmpty()) {
            makeDeQStack(enQStack, deQStack);
        }
        if (deQStack->isEmpty()) {
            cout << "Warnings: Queue EMPTY -- Cannot delete items" << endl;
        } else {
            T *temp = deQStack->peek(); 
            deQStack->pop();  
            cout << "Item deleted: ";
            temp->print();
            queueSize--;
        }
    }
    T* peek(){
        if (deQStack->isEmpty())
            makeDeQStack(enQStack, deQStack);
        return deQStack->peek();
    }
    void print(){
        while (!deQStack->isEmpty()){
            temp->push(deQStack->peek());
            deQStack->pop();
        }
        makeDeQStack(enQStack, deQStack);
        makeDeQStack(temp, deQStack);
        deQStack->print();
    }
};


random_device rd;
mt19937 gen(rd());

string genReserveCode(){
    uniform_int_distribution<int> dis(10000000, 99999999);
    int random_number = dis(gen);

    return to_string(random_number);
}

string getName(){
    string firstName;
    string lastName;

    cout << "Enter person's first name: ";
    cin >> firstName;
    cout << "Enter person's last name: ";
    cin >> lastName;

    return firstName + " " + lastName;
}

void executeCommands(StackQ<TicketItem> *queue ,int option){
    TicketItem *data;
    string fullName;
    string code;
    switch(option){
        case 1:
            fullName = getName();
            code = genReserveCode();
            data = new TicketItem(fullName, code);
            queue->enqueue(data);
            // cout << "Updated ticket queue:" << endl;
            // queue->print();
            break;
        case 2:
            queue->dequeue();
            // cout << "------------------------------------" << endl;
            // cout << "Updated ticket queue:" << endl;
            // queue->print();
            break;
        case 3:
            cout << "First item in queue: ";
            data = queue->peek();
            data->print();
            break;
        case 4:
            cout << "Ticket queue:" << endl;
            queue->print();
            break;
        case 5:
            cout << "Ticket queue size: " << queue->getSize() << endl;
            break;
        case 6:
            cout << "enQStack:" << endl;
            queue->getEnQPointer()->print();
            cout << "------------------------------------" << endl;
            cout << "deQStack:" << endl;
            queue->getDeQPointer()->print();
            break;
        case 7:
            cout << "Starting to exit program..." << endl;
            return;
    }
}

void displayMenu(){
    cout << "================Menu================" << endl;
    cout << "     1.Add Item to ticket queue     " << endl;
    cout << "     2.Delete from ticket queue     " << endl;
    cout << "    3.Peek from the ticket queue    " << endl;
    cout << "     4.Display the ticket queue     " << endl;
    cout << "     5.Display ticket queue size    " << endl;
    cout << "    6.Display enQStack & deQStack   " << endl;
    cout << "              7.Exit                " << endl;
    cout << "====================================" << endl;
}

int main(){
    int input = 1;
    bool validInput;
    StackQ<TicketItem> *ticketQueue = new StackQ<TicketItem>();
    while(input >= 1 && input <= 7){
        displayMenu();
        do {
            cout << "Pick an option: ";
            cin >> input;
            if (input < 1 || input > 7 || cin.fail()) {
                validInput = false;
                cout << "Invalid input. Please enter a valid integer (between 1 and 7):" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cout << "------------------------------------" << endl;
                validInput = true;
            }
        } while (!validInput);

        executeCommands(ticketQueue, input);
        if (input == 7) {
            delete ticketQueue;
            cout << "Queue successfully deleted" << endl;
            break;
        }
    }

    cout << "Program exited" << endl;
    return 0;
}