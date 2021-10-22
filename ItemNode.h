#ifndef ITEMNODE_H
#define ITEMNODE_H
#include <stdexcept>
using namespace std;


class ItemNode{
  public:
    //data members
    string name;
    int quantity;
    ItemNode* next;

    //Constructors
    ItemNode(){
      name = "no name given";
      quantity = 0;
      next = nullptr;
    }

    ItemNode(string name, int quantity){
      this->name = name;
      this->quantity = quantity;
      next = nullptr;
    }
};

#endif
