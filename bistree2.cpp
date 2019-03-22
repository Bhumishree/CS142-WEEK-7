#include<iostream>
using namespace std;

class Node{
  public:
   int data;
   Node*left;
   Node*right;
   Node*parent;
  
   Node(int val) {
     left=NULL;
     right=NULL;
     parent=NULL;
     data=val;
    }
  };

class bist {
   public:
  Node*root;
  
  bist(){
   root=NULL;
   }


void insert(int val){
    insertHelper(root,val);
  }

void insertHelper(Node*current,int val){
     if(current==NULL){
        if(root==NULL){
          current=new Node(val);
          root=current;
         }
       }
      else if(val>current->data){
          if (current->right==NULL){
            current->right=new Node(val);
            (current->right)->parent=current;
              }
          else  {
            insertHelper(current->right,val);
            }
         }
      else  {
         if(current->left==NULL){
            current->left=new Node(val);
            (current->left)->parent=current;
            }
         else {
          insertHelper(current->left,val);
            }
          }
       }

void display(){
  display2(root);
   }

void display2(Node*current){
   if(current->left!=NULL){
      display2(current->left);
    }
     cout<<current->data<<",";
   if(current->right!=NULL){
      display2(current->right);
    }
  }

Node*find_min(Node*current){
  while(current->left!=NULL){
    current=current->left;
   }
  return current;
 }

void deletenode(int val) {
  deletehelper(root,val);
  }

Node*deletehelper(Node*current,int val){
   if (current==NULL){
      return current;
    }
   if (val<current->data) {
     current->left = deletehelper(current->left,val);
   }
   else if(val>current->data) {
      current->right = deletehelper(current->right,val);
   }
  else {
     if(current->left==NULL) {
        Node*temp = current->right;
        delete current;
        return temp;
       }
     else if(current->right==NULL){
        Node*temp = current->left;
        delete current;
        return temp;
       }
     else {
         Node* temp= find_min(current);
         current->data=temp->data;
         current->right = deletehelper(current->right,temp->data);
      }
     return current;
  }
}
 };
int main(){

bist s1;
s1.insert(23);
s1.insert(20);
s1.insert(19);
s1.insert(25);
s1.insert(33);
s1.insert(15);
s1.insert(45);
s1.insert(16);
s1.display();
s1.deletenode(20);
cout<<endl;
s1.display();

 

return 0;
}
