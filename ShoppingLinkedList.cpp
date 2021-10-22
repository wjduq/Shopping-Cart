#include <iostream>
#include <cmath>
#include <string>
#include "ShoppingLinkedList.h"
#include "ItemNode.h"
using namespace std;

//constructors and deconstructors
ShoppingLinkedList::ShoppingLinkedList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}

ShoppingLinkedList::~ShoppingLinkedList(){
  while(head != nullptr){
    ItemNode* next = head->next;
    delete head;
    head = next;
  }
  size = 0;
  tail = nullptr;

}


ShoppingLinkedList::ShoppingLinkedList(ShoppingLinkedList& originalList){
  if(originalList.head == nullptr){
    head = nullptr;
    tail = nullptr;
  }
  else{
    size = originalList.size;
    if(this != &originalList){
      head = new ItemNode(originalList.head->name, originalList.head->quantity);
      ItemNode* current = head;
      ItemNode* originalObj = originalList.head;
      while (originalObj->next != nullptr) {
        current->next = new ItemNode(originalObj->next->name, originalObj->next->quantity);
        originalObj = originalObj->next;
        current = current->next;
        tail = current;
      }
    }
  }

}





//mutators
void ShoppingLinkedList::addItem(string name, int quantity){

  if(size > 0){
    ItemNode* thing;
    ItemNode* temp;
    thing = head;

    if(name < thing->name){
      ItemNode* newItem = new ItemNode(name, quantity);
      newItem->next = thing;
      head = newItem;
      size++;
    }

    else if(name > thing->name){
      while(name > thing->name){
        temp = thing;
        thing = thing->next;


        if(thing == nullptr){
          break;
        }

      }


      ItemNode* newItem = new ItemNode(name, quantity);
      temp->next = newItem;
      newItem->next = thing;
      size++;

      if(newItem->name > tail->name){
        tail = newItem;
      }

    }
  }
  else {
    ItemNode* newItem = new ItemNode(name, quantity);
    head = newItem;
    tail = newItem;
    size++;
  }
}

void ShoppingLinkedList::removeItem(int index){
  ItemNode* tmp;
  ItemNode* current = head;
  int count = 0;
  if (index == 0) {
    head = current->next;
    delete current;
    size--;
  }
  else {
    while(current != tail) {
      tmp = current;
      current = current->next;
      count++;
      if(count == index){
        tmp->next = current->next;
        delete current;
        size--;
        break;
      }
    }
  }

}

void ShoppingLinkedList::printList(){
  ItemNode* tmp = head;
  if(size != 0){

    for (int i = 0; i < size; ++i){
      cout << tmp->name << ": " << tmp->quantity << endl;
      tmp = tmp->next;
    }
    cout << endl;
  }
  else{
    cout << "Shopping cart is empty" << endl;
  }
}

void ShoppingLinkedList::updateQuantity(int index, int quantity) {
  ItemNode* tmp;
  ItemNode* current = head;
  int count = 0;
  if (index == 0) {
    current->quantity = quantity;
  }
  else {
    while(current != tail) {
      current = current->next;
      count++;
      if(count == index){
        current->quantity = quantity;
        break;
      }
    }
  }
}

void ShoppingLinkedList::clearShoppingList(){
  for (int i = 0; i < size; i++) {
    removeItem(i);
  }
  size = 0;
  head = nullptr;
  tail = nullptr;
}


bool ShoppingLinkedList::addAll(ShoppingLinkedList anotherList){
  bool notinThere = true;
  bool change;


  ItemNode* needtoAdd = anotherList.head;


  while(needtoAdd != nullptr){
    ItemNode* originalTemp = head;
    notinThere = true;

    while(originalTemp != nullptr){
      if(needtoAdd->name == originalTemp->name){
        originalTemp->quantity = originalTemp->quantity + needtoAdd->quantity;
        notinThere = false;
        change = true;
      }

      originalTemp = originalTemp->next;

    }

    if(notinThere){
      addItem(needtoAdd->name, needtoAdd->quantity);
      change = true;
    }

    needtoAdd = needtoAdd->next;
  }

  return change;
}

bool ShoppingLinkedList::removeReduceAll(ShoppingLinkedList anotherList) {
  bool notinThere = true;
  bool change;
  ItemNode* needtoTake = anotherList.head;


  while(needtoTake != nullptr){
    ItemNode* originalTemp = head;
    notinThere = true;
    int index = 0;

    while(originalTemp != nullptr){
      if(needtoTake->name == originalTemp->name){
        originalTemp->quantity = originalTemp->quantity - needtoTake->quantity;
        if (originalTemp->quantity <= 0) {
          this->removeItem(index);
        }
        notinThere = false;
        change = true;
      }

      originalTemp = originalTemp->next;
      index++;

    }

    needtoTake = needtoTake->next;
  }

  return change;
}




//accessors
ItemNode* ShoppingLinkedList::getHead(){
  return head;
}

ItemNode* ShoppingLinkedList::getTail(){
  return tail;
}

int ShoppingLinkedList::getSize() {
  return size;
}

string ShoppingLinkedList::getName(int index) {
  ItemNode* current = head;
  int count = 0;
  if (index == 0) {
    return head->name;
  }
  else {
    while(current != tail) {
      current = current->next;
      count++;
      if(count == index){
        return current->name;
      }
    }
  }
}

int ShoppingLinkedList::getQuantity(int index){
  ItemNode* current = head;
  int count = 0;
  if (index == 0) {
    return head->quantity;
  }
  else {
    while(current != tail) {
      current = current->next;
      count++;
      if(count == index){
        return current->quantity;
      }
    }
  }
}


//member operator overloading


ShoppingLinkedList ShoppingLinkedList::operator=(const ShoppingLinkedList& listToCopy){

  while(head != nullptr){
    ItemNode* next = head->next;
    delete head;
    head = next;
  }
  size = 0;
  tail = nullptr;


  if(listToCopy.head == nullptr){
    head = nullptr;
    tail = nullptr;
  }
  else{
    size = listToCopy.size;
    if(this != &listToCopy){
      head = new ItemNode(listToCopy.head->name, listToCopy.head->quantity);
      ItemNode* current = head;
      ItemNode* originalObj = listToCopy.head;
      while (originalObj->next != nullptr) {
        current->next = new ItemNode(originalObj->next->name, originalObj->next->quantity);
        originalObj = originalObj->next;
        current = current->next;
        tail = current;
      }
    }
  }

  return *this;
}




//non-member operator overloading
ostream& operator<<(ostream& out, ShoppingLinkedList& s1) {


  ItemNode* tmp = s1.getHead();
  int size = s1.getSize();
  if(size != 0){

    for (int i = 0; i < size; ++i){
      out << tmp->name << ": " << tmp->quantity << endl;
      tmp = tmp->next;
    }
  }
  else{
    out << "Shopping cart is empty" << endl;
  }

  return out;
}
