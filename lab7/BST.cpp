#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left = NULL, *right = NULL;
};

//find small value of a subtree
node* small(node* root){
  if (root->left == NULL){
    return root;
  }
  else {
    small(root->left);
  }
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root->left == NULL && root->right == NULL){
    cout << root->key << " ";
    return;
  }
  if (root->left != NULL){
    traverseInOrder(root->left);
  }
  cout << root->key << " ";
  if (root->right != NULL) {
    traverseInOrder(root->right);
  }
  

}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL){
    root = new node;
    root->key = key;
    return root;
  }
  else if (key <= root->key){
    root->left = insertNode(root->left, key);
  }
  else {
    root->right = insertNode(root->right, key);
  }
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root->key == key) {
    if (root->left == NULL && root->right == NULL){
      delete root;
      return NULL;
    }
    else if (root->left != NULL && root->right != NULL){
      node* sm = small(root->right);
      root->key = sm->key;
      root->right = deleteNode(root->right, sm->key);
    }
    else{
      if (root->left != NULL){
        return root->left;
      }
      else{
        return root->right;
      }
    }
    
  }
  else{
    if (key <= root->key){
      root->left = deleteNode(root->left, key);
    }
    else{
      root->right = deleteNode(root->right, key);
    }
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}