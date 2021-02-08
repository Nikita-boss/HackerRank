#include <iostream>
using namespace std;

class Node {
  public:
    char _c;
    Node* next;
};

class Solution {
  public:
    Solution() { rear = nullptr; front = nullptr; top = nullptr; }
    void pushCharacter(char c);
    void enqueueCharacter(char c);
    char popCharacter();
    char dequeueCharacter();
  private:
    Node* rear;
    Node* front;
    Node* top;
};

void Solution:: pushCharacter(char c) {
    Node *temp = new Node();
    temp -> _c = c;
    temp -> next = top;
    top = temp;
}

char Solution:: popCharacter() {
    char value = top -> _c;
    Node* temp = top;
    top = top -> next;
    delete temp;
    return value;  
}

void Solution:: enqueueCharacter(char c) {
  if (rear == nullptr) {
    rear = new Node();
    rear -> _c = c;
    rear -> next = nullptr;
    front = rear;
  } else {
    Node* temp = new Node();
    rear -> next = temp;
    temp -> _c = c;
    temp -> next = nullptr;
    rear = temp;
  }
}

char Solution:: dequeueCharacter() {
  Node* temp = front;
  if (temp == nullptr) {
    cout << "Underflows" << '\n';
    return -1;
  } else if (temp -> next != nullptr) {
    char return_value = temp -> _c;
    front = front -> next;
    free(temp);
    return return_value;
  } else {
    char return_value = temp -> _c;
    free(temp);
    rear = nullptr;
    front = nullptr;
    return return_value;
  }
}

int main() {
    // read the string s.
    string s;
    getline(cin, s);
  	// create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
  
    return 0;
}