#include <iostream>
#include <stdexcept>
#include <string>
#include "ShoppingLinkedList.h"

using namespace std;


int main()
{
  ShoppingLinkedList listA;

  // Add elements to the list
  listA.addItem("Strawberry",2);
  listA.addItem("Tuna",5);
  listA.addItem("Celery",3);
  listA.addItem("Salmon",4);
  listA.addItem("Bread",10);
  listA.addItem("Milk",1);
  listA.addItem("Apple",20);
  listA.addItem("Lettuce",8);
  listA.addItem("Kiwi",16);
  listA.addItem("Kale",6);
  cout << "\n(1) Print listA: " <<endl;
  cout<<listA<<endl;

  listA.removeItem(3);
  cout << "\n(2) after remove item at index 3" << endl;
  cout<<listA<<endl;

  listA.updateQuantity(5,13);
  cout << "\n(3) Update the 6th item in list quantity as 13: " << endl;
  cout<<listA<<endl;

  ShoppingLinkedList listB;
  listB.addItem("Strawberry",1);
  listB.addItem("Blueberry",2);
  listB.addItem("Celery",1);
  listB.addItem("Salmon",2);
  listB.addItem("Bread",3);
  listB.addItem("Banana",10);
  listB.addItem("Apple",10);
  listB.addItem("Lettuce",8);
  listB.addItem("Cheese",4);
  listB.addItem("Kale",6);

  cout << "\n(4) Print listB: " << endl;
  cout<<listB<<endl;

  if (listA.addAll(listB))
  {
    cout << "\n(5) Print listA after adding listB: " << endl;
    cout<<listA<<endl;
  }


  listB.clearShoppingList();
  cout << "\n(6) Print cleared listB: " <<endl;
  cout<<listB<<endl;

  ShoppingLinkedList listC;
  listC.addItem("Strawberry",1);
  listC.addItem("Tuna",2);
  listC.addItem("Celery",4);
  listC.addItem("Salmon",2);
  listC.addItem("Bread",3);
  listC.addItem("Milk",15);
  listC.addItem("Apple",10);
  listC.addItem("Lettuce",8);
  listC.addItem("Kiwi",4);
  listC.addItem("Kale",6);
  listC.addItem("Yogurt",3);

  cout << "\n(7) Print listC: " << endl;
  cout<<listC<<endl;

  if (listA.removeReduceAll(listC))
  {
    cout << "\n(8) Print listA after reducing by listC: " <<endl;
    cout<<listA<<endl;
  }

  listC=listA;
  listC.removeItem(0);
  cout << "\n(9) Print listC after deep copy of listA: " <<endl;
  cout<<listC<<endl;
  cout<<"\n(10) Print listA" <<endl;
  cout<<listA<<endl;

  return 0;
}
