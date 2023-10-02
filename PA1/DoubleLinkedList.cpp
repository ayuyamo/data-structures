#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data Class : Holds all the data that goes inside the Node
class Data {
private:
  int value;
  string name;
public:
  Data(int value, string name) {
    this->value = value;
    this->name = name;
  }
  void print() {
    cout << value << " ";
    cout << name << " " << endl;
  }

  int getValue(){
    return this->value;
  }

  string getName(){
    return this->name;
  }
};

// Node Class : Node for the LinkedList
template <typename T> class Node {
private:
  T *value;
public:
  Node<T> *next;
  Node<T> *prev;
  Node(T *value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
  void print() { value->print(); }
  T *getValue(){
    return value;
  }

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

  DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
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
    cout << "Deleted node: " << endl;
    temp->print();
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
    cout << "Deleted node: " << endl;
    temp->print();
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

    cout << "Deleted node: " << endl;
    temp->print();
    delete temp;
    length--;
  }

  void sortList(){
    Node<T> *currNode = head->next;
    while(currNode){
      Node<T> *next1 = currNode->next;
      Node<T> *prev1 = currNode->prev;

    while(prev1 && prev1->getValue()->getValue() > currNode->getValue()->getValue())
      prev1 = prev1->prev;
    moveAfter(currNode, prev1);

      currNode = next1;
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
      nodeToMove->next = head;
      head->prev = nodeToMove;
      head = nodeToMove;
    }
  }
  void insertAfter(Node<T>* currNode, Node<T> *newNode) {
    if (currNode == tail){
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
      if (countMultiples(temp->getValue()) > 1){   
        removeMultiplesOf(temp->getValue()); 
        temp = head;
        continue;
      }
      temp = temp->next;
    }
    cout << "List after removing multiples: " << endl;
    printList();
  }

  void removeMultiplesOf(T* data){
    Node<T> *temp = head;
    while (temp){
      if (temp->getValue()->getValue() == data->getValue() && temp->getValue()->getName() == data->getName()) {
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
    Node<T> *temp = node;
    Node<T> *next1 = temp->next;

    if (next1)
      prev1->next = next1;
    if (prev1)
      next1->prev = prev1;
    delete temp;
    length--;
  }

  int countMultiples(T *data){
    int count = 0;
    Node<T> *temp = head;
    while(temp){
      if (temp->getValue()->getValue() == data->getValue() && temp->getValue()->getName() == data->getName()){
        ++count;
      }
      temp = temp->next;
    } 
    return count;
  }

  void evenOddSplit(){
    int index = 0;
    if (length == 0){
      cout << "Empty list -- not enough nodes to split" << endl;
      return;
    }

    DoubleLinkedList<T> *even = new DoubleLinkedList<T>();
    DoubleLinkedList<T> *odd = new DoubleLinkedList<T>();

    while (head){
        if (index % 2 == 0){
          even->append(head->getValue());
        } 
        else {
          odd->append(head->getValue());
        }
        deleteAtHead();
        ++index;
      }
    cout << "----------------------------" << endl;
    cout << "Even Linked List:" << endl;
    even->printList();
    cout << "----------------------------" << endl;
    cout << "Odd Linked List: " << endl;
    odd->printList();
  }

  void reverseList(){
    Node<T> *temp = head;

    Node<T> *curr = head;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    while(curr){
      next = curr->next;
      curr->next = prev;
      curr->prev = next;
      prev = curr;
      curr = next;
    }
    head = tail;
    tail = temp;
    printList();
  }

  void executeCommands(int option){
    string name;
    int val;
    int index;
    Data *data;
    switch(option){   
      case 1:
        return; 
      case 2:
        cout << "Enter data name: ";
        cin >> name;
        cout << "Enter data value (int): ";
        cin >> val;
        data = new Data(val, name);
        prepend(data);
        cout << "Updated list:" << endl;
        printList();
        break;
      case 3:
        cout << "Enter data name: ";
        cin >> name;
        cout << "Enter data value (int): ";
        cin >> val;
        data = new Data(val, name);
        append(data);
        cout << "Updated list:" << endl;
        printList();
        break;
      case 4:
        cout << "Enter data name: ";
        cin >> name;
        cout << "Enter data value (int): ";
        cin >> val;
        cout << "Type index to insert in: ";
        cin >> index;
        data = new Data(val, name);

        if (insert(index, data) == 0)
          cout << "Invalid index -- Unable to insert node" << endl;
        cout << "Updated list:" << endl;
        printList();
        break;
      case 5:
        deleteAtHead();
        cout << "Linked list after deleting the head: " << endl;
        printList();
        break;
      case 6:
        deleteAtTail();
        cout << "Linked list after deleting the tail: " << endl;
        printList();
        break;
      case 7:
        cout << "Pick node to delete by index: " << endl;
        cin >> index;
        deleteAtIndex(index);
        cout << "Linked list after deleting node at index " << index << ":" << endl;
        printList();
        break;
      case 8:
        cout << "Linked list after the list was reversed: " << endl;
        reverseList();
        break;
      case 9:
        cout << "Linked list after being sorted: " << endl;
        sortList();
        break;
      case 10:
        cout << "Enter data name: ";
        cin >> name;
        cout << "Enter data value (int): ";
        cin >> val;
        data = new Data(val, name);
        cout << "# of multiples of data with ";
        cout << "name " << name << " and ";
        cout << "value " << val << " is ";
        cout << countMultiples(data) << endl;
        break;
      case 11:
        removeMultiples();
        break;
      case 12:
        evenOddSplit();
        break;   
      case 13:
        cout << "Starting to exit program..." << endl;
        return;
    }
  }

};

// Main Program

  void printMenu(){
    cout << "============Menu============" << endl;
    cout << "     1.Delete a List       " << endl;
    cout << "     2.Insert at Head      " << endl;
    cout << "     3.Insert at Tail      " << endl;
    cout << "     4.Insert at Index     " << endl;
    cout << "     5.Delete at Head      " << endl;
    cout << "     6.Delete at Tail      " << endl;
    cout << "     7.Delete at Index     " << endl;
    cout << "     8.Reverse List        " << endl;
    cout << "       9.Sort List         " << endl;
    cout << "    10.Count Multiples     " << endl;
    cout << "   11.Delete Multiples     " << endl;
    cout << " 12. Split List Even Odd   " << endl;
    cout << "         13.Exit            " << endl;
    cout << "============================" << endl;
    cout << "Pick an option: ";
  }

int main() {

  int userInput = 1;
  DoubleLinkedList<Data> *dll = new DoubleLinkedList<Data>();

  while(userInput >= 1 && userInput <= 13){
    printMenu();
    cin >> userInput;
    cout << "----------------------------" << endl;
    if (userInput < 1 || userInput > 13) {
      cout << "Invalid option: " << userInput << endl;  
      while (userInput < 1 || userInput > 13) {
        cout << "Pick a number between 1 and 13: ";
        cin >> userInput;
      }
    }
    dll->executeCommands(userInput);

    if (userInput == 13)
      break;
    if (userInput == 1 || userInput == 12) {
      delete dll;
      cout << "Linked list successfully deleted" << endl;
      break;
    }
  }

  cout << "Program exited" << endl;

  return 0;
}