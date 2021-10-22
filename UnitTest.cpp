#include <iostream>
#include <cassert>
#include "ShoppingLinkedList.h"
using namespace std;

int main() {
  //test empty linked list
  ShoppingLinkedList listA;
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);

/*
  //test removeItem with empty list
  listA.removeItem(0);
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);
  assert(listA.getTail() == listA.getHead());

  //test updateQuantity with empty list
  listA.updateQuantity(0,100);
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);
  assert(listA.getTail() == listA.getHead());
  */

  //test clearShoppingList with empty list
  listA.clearShoppingList();
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);
  assert(listA.getTail() == listA.getHead());

  //test overloaded = with empty list
  ShoppingLinkedList listB;
  listB = listA;
  assert(listB.getSize() == 0);
  assert(listB.getHead() == nullptr);
  assert(listB.getTail() == nullptr);

  //test addAll with empty list
  ShoppingLinkedList listC;
  listA.addAll(listC);
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);

  //test removeReduceAll with empty list
  listA.removeReduceAll(listC);
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);


  //test additem to empty list
  listA.addItem("apple", 7);
  assert(listA.getName(0) == "apple");
  assert(listA.getQuantity(0) == 7);
  assert(listA.getSize() == 1);
  assert(listA.getHead() != nullptr);
  assert(listA.getTail() != nullptr);
  assert(listA.getTail() == listA.getHead());

  //test additem to non-empty list
  listA.addItem("sushi", 20);
  assert(listA.getName(1) == "sushi");
  assert(listA.getQuantity(1) == 20);
  assert(listA.getSize() == 2);
  assert(listA.getHead() != nullptr);
  assert(listA.getTail() != nullptr);
  assert(listA.getTail() != listA.getHead());

  //test additem with two elements, which test whether it is placed alphabetically
  listA.addItem("celery", 9);
  assert(listA.getName(1) == "celery");
  assert(listA.getQuantity(1) == 9);
  assert(listA.getSize() == 3);
  assert(listA.getHead() != nullptr);
  assert(listA.getTail() != nullptr);
  assert(listA.getTail() != listA.getHead());

  //test removeItem with non-emptylist
  listA.removeItem(2);
  assert(listA.getName(1) == "celery");
  assert(listA.getQuantity(1) == 9);
  assert(listA.getSize() == 2);
  assert(listA.getHead() != nullptr);
  assert(listA.getTail() != nullptr);
  assert(listA.getTail() != listA.getHead());

  //test updateQuantity with non-empty list
  listA.updateQuantity(1, 46);
  assert(listA.getName(1) == "celery");
  assert(listA.getQuantity(1) == 46);
  assert(listA.getSize() == 2);
  assert(listA.getHead() != nullptr);
  assert(listA.getTail() != nullptr);
  assert(listA.getTail() != listA.getHead());

  //test overloaded = with nonempty list
  listB = listA;
  assert(listB.getName(0) == "apple");
  assert(listB.getQuantity(0) == 7);
  assert(listB.getSize() == 2);
  assert(listB.getHead() != nullptr);
  assert(listB.getTail() != nullptr);
  assert(listB.getTail() != listA.getHead());

  //test addAll with non-empty list
  listC.addItem("trout", 18);
  listC.addItem("tuna", 76);
  listA.addAll(listC);
  assert(listA.getName(3) == "tuna");
  assert(listA.getQuantity(3) == 76);
  assert(listA.getSize() == 4);
  assert(listB.getHead() != nullptr);
  assert(listB.getTail() != nullptr);
  assert(listB.getTail() != listA.getHead());

  //test removeReduceAll with non-empty list
  ShoppingLinkedList listD;
  listD.addItem("apple", 14);
  listD.addItem("celery", 20);
  listA.removeReduceAll(listD);
  assert(listA.getName(0) == "celery");
  assert(listA.getQuantity(0) == 26);
  assert(listA.getName(2) == "tuna");
  assert(listA.getQuantity(2) == 76);
  assert(listA.getSize() == 3);
  assert(listA.getHead() != nullptr);
  assert(listA.getTail() != nullptr);
  assert(listA.getTail() != listA.getHead());

  //test clearShoppingList with non-empty list
  //List A
  listA.clearShoppingList();
  assert(listA.getSize() == 0);
  assert(listA.getHead() == nullptr);
  assert(listA.getTail() == nullptr);
  assert(listA.getTail() == listA.getHead());

  //List B
  listB.clearShoppingList();
  assert(listB.getSize() == 0);
  assert(listB.getHead() == nullptr);
  assert(listB.getTail() == nullptr);
  assert(listB.getTail() == listB.getHead());

  //List B
  listC.clearShoppingList();
  assert(listC.getSize() == 0);
  assert(listC.getHead() == nullptr);
  assert(listC.getTail() == nullptr);
  assert(listC.getTail() == listC.getHead());

  //List D
  listD.clearShoppingList();
  assert(listD.getSize() == 0);
  assert(listD.getHead() == nullptr);
  assert(listD.getTail() == nullptr);
  assert(listD.getTail() == listD.getHead());

  return 0;
}
