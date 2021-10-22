output: MyShoppingList.o ShoppingLinkedList.o
	g++ MyShoppingList.o ShoppingLinkedList.o -o output

MyShoppingList.o: MyShoppingList.cpp ShoppingLinkedList.h ItemNode.h
	g++ -c MyShoppingList.cpp

ShoppingLinkedList.o: ShoppingLinkedList.cpp ShoppingLinkedList.h ItemNode.h
	g++ -c ShoppingLinkedList.cpp

clean:
	rm* .o
