#include <iostream>
using namespace std;

class Node {
  public:
    Node* left;
    Node* right;
    int data;
    Node(int data): left{nullptr}, right{nullptr}, data{data} {}
    Node(): left{nullptr}, right{nullptr} {}
};

class Solution {
  public:
    Node* insert(Node* root, int data) {
      if (root == nullptr) {
        return new Node(data);
      }

      Node* N = new Node();
      if (data <= root -> data) {
        N = insert(root -> left, data);
        root -> left = N;
      } else {
        N = insert(root -> right, data);
        root -> right = N;
      }
      return root;
    } 

    int getHeight(Node* root){
      if(!root) {
        return -1;
      }
      int leftDepth = getHeight(root->left);
      int rightDepth = getHeight(root->right);

      return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};

int main() {
  Solution myTree;
  Node* root = nullptr;

  int t;
  int data;
  cin >> t;
  while(t-- > 0){
      cin >> data;
      root = myTree.insert(root, data);
  }
  int height = myTree.getHeight(root);
  cout << height << '\n';
  return 0;
}