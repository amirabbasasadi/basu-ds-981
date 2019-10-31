#include<iostream>
#include "LinkedList.hpp"
using namespace std;

int main(){
  LinkedList<float> myList;
  cout << "size of list : " << myList.size() << endl;
  // insert to list
  myList.addFront(3.14159);
  myList.addFront(2.71828);
  myList.addFront(1.61803);
  myList.addFront(0);
  myList.addFront(1);
  cout << "size of list : " << myList.size() << endl;
  cout << "head : " << myList.front() << endl;
  cout << "middle : " << myList.middle() << endl;
  myList.removeFront();
  cout << "head : " << myList.front() << endl;
  cout << boolalpha << "has cycle : " << myList.hasCycle() << endl;
  return 0;
}
