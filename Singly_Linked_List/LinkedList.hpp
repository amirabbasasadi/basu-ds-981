#include<stdexcept>

template<typename T> class LinkedList;

template<typename T>
class Node{
public:
  Node():next(nullptr){
  }
private:
  T elem;
  Node<T>* next;
  friend class LinkedList<T>;
};

template<typename S>
class LinkedList{
private:
  Node<S>* head;
public:
  LinkedList();
  ~LinkedList();
  void addFront(const S&);
  void removeFront();
  bool empty() const;
  const S& front() const;
  unsigned size() const;
  const S& middle() const;
  bool hasCycle() const;
  void connectTailToSecond();
};

#include "LinkedList.cpp"
