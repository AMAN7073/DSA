#include <bits/stdc++.h>
using namespace std;
    
#define PB push_back
#define MP make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define eb emplace_back

    
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MX = 100001;

class Node{
public:
  int val;
  Node *left;
  Node *right;

  Node(int value){
    this->val = value;
    this->left = this->right = NULL;
  }
};

class BST{
private:
  Node *root;

  Node *insert(Node *node ,int value){
    if(node == NULL)
      return new Node(value);

    if(node->val < value)
      node->right = insert(node->right,value);
    else
      node->left = insert(node->left,value);
    return node;
  }

  Node *search(Node *node ,int value){
    if(node == NULL || node->val == value)
      return node;

    if(node->val <= value)
      return search(node->right,value);
    else
      return search(node->left,value);
  }

  void Inorder(Node *node){
    if(node == NULL)
      return;
    Inorder(node->left);
    cout<<node->val<<" ";
    Inorder(node->right);
    return;
  }

  void Preorder(Node *node){
    if(node == NULL)
      return;
    cout<<node->val<<" ";
    Preorder(node->left);
    Preorder(node->right);
    return;
  }

  void Postorder(Node *node){
    if(node == NULL)
      return;
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->val<<" ";
    return;
  }

public:
  BST(){
    this->root = NULL;
    cout<<"Created"<<endl;
  }

  void insert(int value){
    root = insert(root,value);

  }

  Node *search(int value){
    return search(root,value);
  }

  void inorder(){
    cout<<"Inorder is:- ";
    Inorder(root);
    cout<<endl;
  }

  void preorder(){
    cout<<"Preorder is:- ";
    Preorder(root);
    cout<<endl;
  }

  void postorder(){
    cout<<"Postorder is:- ";
    Postorder(root);
    cout<<endl;
  }

};

static void search(BST test, int n){
  if(test.search(n) == NULL){
    cout<<n<<" Found\n";
  }
  else
    cout<<n<<" Not-Found\n";
}

int main() {
  BST First;
  First.insert(10);
  First.insert(15);
  First.insert(5);
  First.insert(8);
  First.insert(18);
  First.insert(12);
  First.insert(10);

  First.preorder();
  First.inorder();
  First.postorder();

  search(First,10);
  search(First,9);
}
