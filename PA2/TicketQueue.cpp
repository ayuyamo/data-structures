#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TicketItem {
private:
    string personName;
    string reserveCode;
public:
    TicketItem(string name, string code){
        this->personName = name;
        this->reserveCode = code;
    }
    string getPersonName(){
        return this->personName;
    }
    string getReserveCode(){
        return this->reserveCode;
    }
    void print() {
        cout << this->personName << " ";
        cout << this->reserveCode << " " << endl;
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
    bool isFull(){
        return stackSize == SMAXITEMS;
    }
    bool isEmpty(){
        return stackSize == 0;
    }
    int getSize(){
        return stackSize;
    }
    void push(T *item) {
        Node<T> *newNode = new Node<T>(item);
        if (stackSize == 0) {
            top = newNode;
        } else if (stackSize == SMAXITEMS){
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
    bool isEmpty() { return queueSize == 0; }
    bool isFull() { return queueSize == QMAXITEMS; }
    void enqueue(T* item){
        enQStack->push(item);
        queueSize++;
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
        deQStack->pop();     
        queueSize--;
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
    void executeCommands(int option){
        string name;
        string code;
        TicketItem *data;
        switch(option){
            case 1:
                cout << "Enter person name: ";
                cin >> name;
                cout << "Enter reserve code: ";
                cin >> code;
                data = new TicketItem(name, code);
                enqueue(data);
                cout << "Updated ticket queue:" << endl;
                print();
                break;
            case 2:
                dequeue();
                cout << "------------------------------------" << endl;
                cout << "Updated ticket queue:" << endl;
                print();
                break;
            case 3:
                cout << "First item in queue: ";
                data = peek();
                data->print();
                break;
            case 4:
                cout << "Ticket queue:" << endl;
                print();
                break;
            case 5:
                cout << "Ticket queue size: " << queueSize << endl;
                break;
            case 6:
                cout << "enQStack:" << endl;
                enQStack->print();
                cout << "------------------------------------" << endl;
                cout << "deQStack:" << endl;
                deQStack->print();
                break;
            case 7:
                cout << "Starting to exit program..." << endl;
                return;
        }
    }
};

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
    cout << "Pick an option: "; 
}

int main(){
    int input = 1;
    StackQ<TicketItem> *ticketQueue = new StackQ<TicketItem>();
    while(input >= 1 && input <= 7){
        displayMenu();
        cin >> input;
        cout << "------------------------------------" << endl;
        if (input < 1 || input > 7) {
            cout << "Invalid option: " << input << endl;  
            while (input < 1 || input > 7) {
                cout << "Pick a number between 1 and 7: ";
                cin >> input;
            }
        }
        ticketQueue->executeCommands(input);
        if (input == 7) {
            delete ticketQueue;
            cout << "Queue successfully deleted" << endl;
            break;
        }
    }

    cout << "Program exited" << endl;
    return 0;
}