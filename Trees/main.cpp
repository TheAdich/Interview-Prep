#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int n)
  {
    data= n;
    left = NULL;
    right = NULL;
  }
};

Node* makeBinary() {
  int n;
  cin>>n;

  if(n==-1)   return NULL;

  Node* root = new Node(n);
  root->left = makeBinary();
  root->right = makeBinary();
  return root;
}

void printBinary(Node* root) {
  if(root==NULL)
  {
    return;
  }

  cout<<" "<<root->data;
  printBinary(root->left);
  printBinary(root->right);
  return;

}

int heightBinary(Node* root) {
  if(root == NULL)  {
    return -1;
  }

  int lh,rh;
  lh = heightBinary(root->left) +  1;
  rh = heightBinary(root->right) + 1;

  return std::max(lh,rh);
}

void printKLevel(Node* root, int k) {
  if(root == NULL)    return;

  if(k==0)
  {
    cout<<" "<<root->data;
    return;
  }
  printKLevel(root->left,k-1);
  printKLevel(root->right,k-1);

}

void printAllLevels(Node* root) {
  int height = heightBinary(root);

  for(int i = 0 ; i <= 3 ; i++)
  {
    printKLevel(root,i);
    cout<<endl;
  }
}

void printBFT(Node* root) {
  queue<Node*> q;
  q.push(root);
  Node* temp = NULL;
  while(!q.empty())
  {
    temp = q.front();
    q.pop();
    if(temp)
    {
      cout<<temp->data<<" ";
      q.push(temp->left);
      q.push(temp->right);
    }
  }

}

int diameterTree(Node* root)
{
  if(root==NULL)   return 0;

  int h1 = heightBinary(root->left);
  int h2 = heightBinary(root->right);
  int h3 = h1 + h2;
  return std::max(h1,std::max(h2,h3));
}

int main()
{
  Node* root = makeBinary();
  cout<<"Pre-Order Print : ";
  printBinary(root);
  cout<<"\nHeight of tree : ";
  cout<<heightBinary(root);
  cout<<"\nPrint Kth Level :";
  printKLevel(root,3);
  cout<<"\nPrint all levels :\n";
  printAllLevels(root);
  cout<<"\nPrint BFT : ";
  printBFT(root);
  cout<<endl;
}
