// Linked List Implementation
template<typename T>
LinkedList<T>::LinkedList(){
  head = nullptr;
}

// Linked List AddFront
template<typename T>
void LinkedList<T>::addFront(const T& data){
  // allocate a new node
  Node<T>* new_node = new Node<T>();
  new_node->elem = data;
  new_node->next = head;
  head = new_node;
}

template<typename T>
bool LinkedList<T>::empty() const{
  return !head;
}

// get front
template<typename T>
const T& LinkedList<T>::front() const{
  if(empty())
    throw std::runtime_error("There is no element in list!!!");
  return head->elem;
}

// Linked List RemoveFront
template<typename T>
void LinkedList<T>::removeFront(){
  if(empty())
    throw std::runtime_error("There is no element in list!!!");
  Node<T>* temp = head;
  head = head->next;
  delete temp;
}

template<typename T>
unsigned LinkedList<T>::size() const{
  Node<T>* temp = head;
  unsigned counter = 0;
  while(temp){
    temp = temp->next;
    counter++;
  }
  return counter;
}

template<typename T>
const T& LinkedList<T>::middle() const{
  if(empty())
    throw std::runtime_error("There is no element in list!!!");
  Node<T>* fast=head;
  Node<T>* slow=head;
  while(fast->next){
    slow = slow->next;
    fast = fast->next;
    if(!(fast->next))
      break;
    fast = fast->next;
  }
  return slow->elem;
}

template<typename T>
bool LinkedList<T>::hasCycle() const{
  Node<T>* slow = head;
  Node<T>* fast = head;
  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
    if(!(fast->next))
      break;
    fast = fast->next;
    if(fast == slow)
      return true;
  }
  return false;
}

template<typename T>
void LinkedList<T>::connectTailToSecond(){
  if(size() <= 3)
    throw std::runtime_error("can not make a bad list");
  Node<T>* second = head->next;
  Node<T>* tail = second;
  while(!(tail->next))
    tail = tail->next;
  tail->next = second;
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
  while(!empty())
    removeFront();
}
