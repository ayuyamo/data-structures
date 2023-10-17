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
    const int SMAXITEMS;
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
    bool isFull(){
        return stackSize == SMAXITEMS;
    }
    bool isEmpty(){
        return stackSize == 0;
    }
    void push(T *item){
        Node<T> *newNode = new Node<T>(item);
        if (stackSize == 0) {
        top = newNode;
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
};

template <typename T> class StackQ {
private:
    LLStack<T> *enQStack;
    LLStack<T> *deQStack;
    int queueSize;
    const int QMAXITEMS;

    //Contructors
    StackQ(){
        enQStack = nullptr;
        deQStack = nullptr;
        queueSize = 0;
    }
    StackQ(LLStack<T> *stack){//FIXME
        enQStack = stack;
        deQStack = stack;
        queueSize = 1;
    }
public:
    bool isEmpty(){
        return queueSize == 0;
    }
    bool isFull(){
        return queueSize == QMAXITEMS;
    }
    void enqueue(T* item){
        enQStack->push(item);
    }
    void dequeue(){
        deQStack->pop();
    }
    T* peek(){
        return deQStack->peek();
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
    return 0;
}
