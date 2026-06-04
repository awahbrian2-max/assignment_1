#include <iostream>
#include <queue>
using namespace std;
// Define a Node in the Binary Search Tree
struct Node{
int data;
Node *left;
Node *right;
// Constructor to initialize Node with a value
Node(int val){
data = val;
left = nullptr;
right = nullptr;
}
};
// Define the Binary Search Tree class
class BST{
Node *root;
// Helper function to insert a value into the tree
Node* insert(Node *curr, int val){
// Base case: if current node is null create a new node
if (curr == nullptr)
return new Node(val);
// If value is less than nodes data go left
if (val < curr->data)
curr->left = insert(curr->left, val);
// If value is greater than nodes data go right
else if (val > curr->data)
curr->right = insert(curr->right, val);
// Return the current node
return curr;
}
// Helper function to perform inorder traversal
void inorder(Node *curr){
// Base case: if current node is null return
if (curr == nullptr)
return;
// Recur for subtree
inorder(curr->left);
// Print nodes data
cout<<curr->data <<" ";
// Recur for right subtree
inorder(curr->right);
}
// function to perform preorder traversal
void preorder(Node *curr){
// Base case: if current node is null return
if (curr == nullptr)
return;
// Print nodes data
cout<<curr->data << " ";
// Recur for subtree
preorder(curr->left);
// Recur for subtree
preorder(curr->right);
}
// function to perform postorder traversal
void postorder(Node *curr)
{
// Base case: if current node is null return
if (curr == nullptr)
return;
// Recur for subtree
postorder(curr->left);
// Recur for subtree
postorder(curr->right);
// Print nodes data
cout << curr->data << " ";
}
// function to search for a value in the tree
Node* search(Node *curr, int key){
// Base case: if current node is null or key is found, return current node
if (curr == nullptr || curr->data == key)
return curr;
// If key is less than nodes data search in left subtree
if (key < curr->data)
return search(curr->left, key);
// If key's greater than current nodes data search in right subtree
return search(curr->right, key);
}
// function to find the minimum value in the tree
Node* findMin(Node *curr){
// Keep going left until we find the value
while (curr && curr->left != nullptr)
curr = curr->left;
return curr;
}
// Helper function to find the value in the tree
Node* findMax(Node *curr){
// Keep going right until we find the value
while (curr && curr->right != nullptr)
curr = curr->right;
return curr;
}
// Helper function to delete a node from the tree
Node* deleteNode(Node *curr, int key){
// Base case: if current node is null return null
if (curr == nullptr)
return curr;
// Traverse to find the node to be deleted
if (key < curr->data)
  curr->left = deleteNode(curr->left, key);
else if (key > curr->data)
  curr->right = deleteNode(curr->right, key);
else {
  // Node found. Handle different cases
 // Case 1: no child
  if (curr->left == nullptr){
    Node *temp = curr->right;
    delete curr;
    return temp;
}
// Case 2: no child
else if (curr->right == nullptr)
{
  Node *temp = curr->left;
  delete curr;
  return temp;
}
// Case 3: two children. Find inorder successor ( node in right subtree)
Node *temp = findMin(curr->right);
// Copy successors value to node
curr->data = temp->data;
// Delete the successor
curr->right = deleteNode(curr->right, temp->data);
}
return curr;
}
// Helper function to print the tree
void printTree(Node *curr, string prefix, bool isLeft){
// Base case: if current node is null return
if (curr == nullptr)
return;
// Print nodes data
cout<<prefix;
cout<<(isLeft ? "|-- " : "`-- ");
cout<<curr->data << "\n";
// Recur for children
if (curr->left != nullptr || curr->right != nullptr){
if (curr->left != nullptr)
  printTree(curr->left, prefix + (isLeft ? "|   " : "    "), true);
if (curr->right != nullptr)
  printTree(curr->right, prefix + (isLeft ? "|   " : "    "), false);
}
}
public:
// Constructor to initialize the Binary Search Tree
BST(){
root = nullptr;
}
// Function to insert a value into the tree
void insert(int val){
  root = insert(root, val);
}
// Function to perform inorder traversal
void inorder(){
inorder(root);
}
// Function to perform preorder traversal
void preorder(){
preorder(root);
}
// Function to perform postorder traversal
void postorder(){
postorder(root);
}
// Function to search for a value in the tree
void search(int key){
  Node *res = search(root, key);
  if (res)
      cout << "Found!" << endl;
  else
    cout << "Not found." << endl;
}
// Function to find the value in the tree
void findMinimum(){
Node *temp = findMin(root);
if (temp)
cout << "Min: " << temp->data << endl;
}
// Function to find the maximum value in the tree
void findMaximum(){
Node *temp = findMax(root);
if (temp)
cout << "Max: " << temp->data << endl;
}
// Function to delete a node from the tree
void deleteValue(int key){
root = deleteNode(root, key);
}
// Function to display the tree
void display(){
if (root == nullptr){
cout << "Tree is empty.\n";
return;
}
printTree(root, "", false);
}
};

int main(){
// Create a Binary Search Tree
BST tree;
int choice, val;
// Display menu
cout<<"\n--- Binary search Tree Menu ---\n";
cout<<"1. Insert\n";
cout<<"2. Preorder\n";
cout<<"3. Postorder\n";
cout<<"4. Search\n";
cout <<"5. Inorder\n";
cout << "6. Find Min\n";
cout << "7. Find Max\n";
cout << "8. Delete\n";
cout << "9. Print Tree\n";
cout << "10. Exit\n";
cout << "Choice: ";
cin >> choice;
switch (choice){
case 1:
cout<<"Insert value: ";
cin >> val;
tree.insert(val);
cout<<"Added. \n";
cout<< endl;
break;
case 2:
cout<<"Preorder: ";
tree.preorder();
cout<<endl;
break;
case 3:
cout<<"Postorder: ";
tree.postorder();
cout<<endl;
break;
case 4:
cout<<"Search, for: ";
cin>>val;
tree.search(val);
break;
case 5:
cout<<"Inorder: ";
tree.inorder();
break;
case 6:
tree.findMinimum();
break;
case 7:
tree.findMaximum();
break;
case 8:
cout<<" value: ";
cin>>val;
tree.deleteValue(val);
cout<<"Removed.\n";
break;
case 9:
cout << "\n";
tree.display();
break;
case 10:
break;
default:
cout<<"Invalid.\n";
}
return 0;
}