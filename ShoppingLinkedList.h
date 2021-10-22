#ifndef SHOPPINGLINKEDLIST_H
#define SHOPPINGLINKEDLIST_H
#include <stdexcept>
#include "ItemNode.h"
using namespace std;

class ShoppingLinkedList {
  private:
    int size;
    ItemNode* head;
    ItemNode* tail;

  public:
  //Constructors and deconstructors
    ShoppingLinkedList();
    ShoppingLinkedList(ShoppingLinkedList& s1);
    ~ShoppingLinkedList();

    //mutators
    void addItem(string name, int quantity);
    void removeItem(int index);
    void updateQuantity(int index, int quantity);
    void printList();
    void clearShoppingList();
    bool addAll(ShoppingLinkedList anotherList);
    bool removeReduceAll(ShoppingLinkedList anotherList);
    //accesors
    ItemNode* getHead();
    ItemNode* getTail();
    int getSize();
    string getName(int index);
    int getQuantity(int index);

    //member overloading
    ShoppingLinkedList operator=(const ShoppingLinkedList& listToCopy);



};

ostream& operator<<(ostream&, ShoppingLinkedList& s1);


#endif
