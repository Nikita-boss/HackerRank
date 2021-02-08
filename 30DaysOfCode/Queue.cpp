#include <iostream>
using namespace std;

class Node {
  public:
    char _c;
    Node* next; 
};

class Queue {
  private: 
    Node* rear; // at which the values are added
    Node* front; // at whit the values are removed
  
  public:
    Queue() {front = nullptr; rear = nullptr;}
    ~Queue() {}
    void enqueue(char c);
    char dequeue();
}; 

void Queue:: enqueue(char c) {
  if (rear == nullptr) {
    rear = new Node();
    rear -> _c = c;
    rear -> next = nullptr;
    front = rear;
  } else {
    Node* temp = new Node();
    

  }

}

char Queue:: dequeue() {
  
}

int main() {
  return 0;
}