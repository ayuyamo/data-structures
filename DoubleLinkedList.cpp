#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data Class : Holds all the data that goes inside the Node
class Data {
public:
  int value;
  string name;
  Data(int value, string name) {
    this->value = value;
    this->name = name;
  }
  void print() {

    cout << value << " " << endl;
    cout << name << " " << endl;
  }
};

// Node Class : Node for the LinkedList
template <typename T> class Node {
public:
  T *value;
  Node<T> *next;
  Node<T> *prev;
  Node(T *value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
  void print() { value->print(); }
};

// LinkedList Class : Container for Nodes
template <typename T> class DoubleLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  int length;

public:
  // Constructor
  DoubleLinkedList(T *value) {
    Node<T> *newNode = new Node<T>(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  // Destructor
  ~DoubleLinkedList() {
    Node<T> *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      temp->print();
      temp = temp->next;
    }
  }

  // get and set
  Node<T> *getHead() {
    if (head == nullptr) {
      cout << "Head: nullptr" << endl;
    } else {
      cout << "Head: " << head->value << endl;
    }
    return head;
  }

  Node<T> *getTail() {
    if (tail == nullptr) {
      cout << "Tail: nullptr" << endl;
    } else {
      cout << "Tail: " << tail->value << endl;
    }
    return tail;
  }

  int getLength() {
    cout << "Length: " << length << endl;
    return length;
  }

  Node<T> *get(int index) {
    if (index < 0 || index >= length)
      return nullptr;
    Node<T> *temp = head;
    for (int i = 0; i < index; ++i) {
      temp = temp->next;
    }
    return temp;
  }

  bool set(int index, T *value) {
    Node<T> *temp = get(index);
    if (temp) {
      temp->value = value;
      return true;
    }
    return false;
  }

  // All insert methods
  // Insert at end
  void append(T *value) {
    Node<T> *newNode = new Node<T>(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  // Insert at beginning

  void prepend(T *value) {
    Node<T> *newNode = new Node<T>(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    length++;
  }

    void prepend(Node<T> *newNode) {
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    length++;
  }


  // Insert at Index

  bool insert(int index, T *value) {
    if (index < 0 || index > length)
      return false;
    if (index == 0) {
      prepend(value);
      return true;
    }
    if (index == length) {
      append(value);
      return true;
    }
    Node<T> *newNode = new Node<T>(value);
    Node<T> *prev1 = get(index - 1);
    Node<T> *next1 = prev1->next;
    newNode->prev = prev1;
    newNode->next = next1;
    prev1->next = newNode;
    next1->prev = newNode;
    length++;
    return true;
  }

  // All delete Methods
  // Write DeleteHead, DeleteTail & DeleteAtIndex here
  void deleteAtHead(){
    if (length == 0)
      return;
    Node<T> *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
    }
    delete temp;
    length--;
  }

  void deleteAtTail(){
    if (length == 0)
      return;
    Node<T> *temp = tail;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail = tail->prev;
      tail->next = nullptr;
    }
    delete temp;
    length--;
  }
  
  void deleteAtIndex(int index){
    if (index < 0 || index >= length)
      return;
    if (index == 0) {
      deleteAtHead();
      return;
    }
    if (index == length - 1) {
      deleteAtTail();
      return;
    }
    Node<T> *prev1 = get(index - 1);
    Node<T> *temp = prev1->next;
    Node<T> *next1 = temp->next;

    prev1->next = temp->next;
    next1->prev = prev1;
    delete temp;
    length--;
  }

  void sortList(){
    Node<T> *currNode = head->next;
    while(currNode){
      Node<T> *prev1 = currNode->prev;

      while(prev1 && prev1->value->value > currNode->value->value)
        prev1 = prev1->prev;
      moveAfter(currNode, prev1);

      currNode = currNode->next;
    }

    printList();
  }

  void moveAfter(Node<T> *nodeToMove, Node<T> *nodeBefore){
    Node<T> *succNode = nodeToMove->next;
    Node<T> *predNode = nodeToMove->prev;

    if (succNode)
      succNode->prev = predNode;
    if (predNode)
      predNode->next = succNode;
    
    if (nodeToMove == head)
      head = succNode;
    if (nodeToMove == tail)
      tail = predNode;

    nodeToMove->next = nullptr;
    nodeToMove->prev = nullptr;

    if (nodeBefore) {
      insertAfter(nodeBefore, nodeToMove);
    } else {
      prepend(nodeToMove); 
    }
  }
  void insertAfter(Node<T>* currNode, Node<T> *newNode) {
    if (head == nullptr){
      head = newNode;
      tail = newNode;
    } else if (currNode == tail){
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    } else{
      Node<T> *sucNode = currNode->next;
      newNode->next = sucNode;
      newNode->prev = currNode;
      currNode->next = newNode;
      sucNode->prev = newNode;
    }
  }

  void removeMultiples(){
    Node<T>* temp = head; 
    while(temp){
      if (countMultiples(temp->value) > 1){   
        removeMultiplesOf(temp->value->value); 
        temp = head;
        continue;
      }
      temp = temp->next;
    }
    printList();
  }

  void removeMultiplesOf(int val){
    Node<T> *temp = head;
    while (temp){
      if (temp->value->value == val) {
        Node<T> *nextNode = temp->next;
        deleteNode(temp);
        temp = nextNode;
        continue;
      }
      temp = temp->next;
    }
  }

  void deleteNode(Node<T> *node){
    if (node == nullptr)
      return;
    if (node == head) {
      deleteAtHead();
      return;
    }
    if (node == tail) {
      deleteAtTail();
      return;
    }
    Node<T> *prev1 = node->prev;
    Node<T> *temp = prev1->next;
    Node<T> *next1 = temp->next;

    prev1->next = temp->next;
    next1->prev = prev1;
    delete temp;
    length--;
  }

  int countMultiples(T *data){
    int count = 0;
    Node<T> *temp = head;
    while(temp){
      if (temp->value->value == data->value){
        ++count;
      }
      temp = temp->next;
    } 
    return count;
  }

  void evenOddSplit(){
    int index;
    DoubleLinkedList<T> *even = new DoubleLinkedList<T>(head->value);
    DoubleLinkedList<T> *odd = new DoubleLinkedList<T>(head->next->value);

    index = 2;
    head = head->next->next;

    while (head){
      if (index % 2 == 0){
        even->append(head->value);
      } 
      else {
        odd->append(head->value);
      }
      head = head->next;
      ++index;
    }
    cout << "Even Linked List: " << endl;
    even->printList();
    cout << "Odd Linked List: " << endl;
    odd->printList();
  }

  void reverseList(){

  }

};

// Main Program

int main() {
  // creating data object
  Data *d1 = new Data(10, "a");
  Data *d2 = new Data(11, "b");
  Data *d3 = new Data(12, "c");
  Data *d4 = new Data(13, "d");
  Data *d5 = new Data(14, "e");
  Data *d6 = new Data(15, "f");
  // Data *d7 = new Data(16, "g");
  // Data *d8 = new Data(12, "a");
  // Data *d9 = new Data(10, "a");
  // Data *d10 = new Data(11, "a");
  Data *d11 = new Data(15, "a");



 // Creating Linked List
 DoubleLinkedList<Data> *ll1 = new DoubleLinkedList<Data>(d1);
  ll1->append(d2);
  ll1->append(d3);
  ll1->append(d4);
  ll1->append(d5);
  ll1->append(d6);
  // ll1->append(d7);
  // ll1->append(d8);
  // ll1->append(d9);
  // ll1->append(d10);
  ll1->append(d11);

  // ll1->deleteAtHead();
  // ll1->deleteAtTail();
  // ll1->deleteAtIndex(4);
  // ll1->deleteNode(ll1->get(4));
  // ll1->removeMultiples(ll1->get(0)->value->value);
  // ll1->sortList();
  // Calling operations on Linked List
  // ll1->printList();

  // cout << ll1->countMultiples(d10) << endl;
  cout << "Original list: " << endl;
  ll1->printList();
  cout << "After removing nodes with matching data: " << endl;
  ll1->removeMultiples();
  // ll1->evenOddSplit();

  return 0;
}