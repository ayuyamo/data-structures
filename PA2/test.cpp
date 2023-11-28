#include <iostream>
#include <string>
#include <algorithm>
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
        print();
        cout << " -- Object deleted" << endl;
    }
    string getPersonName(){ return this->personName;}
    string getReserveCode(){ return this->reserveCode;}
    void print() {
        cout << "Person's name: " << this->personName << " - ";
        cout << "Reserve code: " << this->reserveCode << " " << endl;
    }

    TicketItem* duplicateData(){
      return new TicketItem(this->getPersonName(), this->getReserveCode());
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
      //   data = nullptr;
        delete data;
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
        cout << "Stack successfully deleted" << endl;
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
      //   if (enQStack != nullptr) {
      //       enQStack->deleteAll();
      //       delete enQStack;
      //   }

         delete enQStack;
        cout << "enQStack successfully deleted" << endl;
      //   if (deQStack != nullptr) {
      //       deQStack->deleteAll();
      //       delete deQStack;
      //   }
         delete deQStack;
        cout << "deQStack successfully deleted" << endl;
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
    void makeReverseStack(LLStack<T> *current, LLStack<T> *inverse){
        while(!current->isEmpty()){
            inverse->push(current->peek());
            current->pop();
        }
    }
    void dequeue(){
        if (deQStack->isEmpty()) {
            makeReverseStack(enQStack, deQStack);
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
            makeReverseStack(enQStack, deQStack);
        return deQStack->peek();
    }
    void print(){
        while (!deQStack->isEmpty()){
            temp->push(deQStack->peek());
            deQStack->pop();
        }
        makeReverseStack(enQStack, deQStack);
        makeReverseStack(temp, deQStack);
        deQStack->print();
    }
};

int main() {
   // cout << endl;
   // cout << "Welcome " << getInput() << "!" << endl;
//    cout << "May I call you " << firstName << "?" << endl;
   TicketItem *baby = new TicketItem("love", "peace");
   TicketItem *baby1 = new TicketItem("love1", "peace1");
   TicketItem *baby2 = new TicketItem("love2", "peace2");
   TicketItem *baby3 = new TicketItem("love3", "peace3");
   TicketItem *baby4 = new TicketItem("love4", "peace4");
   TicketItem *baby5 = new TicketItem("love5", "peace5");

   Node<TicketItem> *node = new Node<TicketItem>(baby);
   LLStack<TicketItem> *haha = new LLStack<TicketItem>(baby);
   haha->push(baby1);
   haha->push(baby2);
   haha->push(baby3);
   haha->push(baby4);
   haha->push(baby5);

   StackQ<TicketItem> *mama = new StackQ<TicketItem>();
   mama->enqueue(baby);
   mama->enqueue(baby1);
   mama->enqueue(baby2);
   mama->enqueue(baby3);
   mama->enqueue(baby4);
   mama->enqueue(baby5);


   // delete node;
   // delete haha;
   delete mama;
   return 0;
}