#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    public:
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};


node* buildTree(node* root){
    int data;
    cout<<"Enter Data:";
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the left child of data "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the right child of data "<<data<<endl;
    root->right=buildTree(root->right);
   return root;
}


node* buildLevelTree(node* root){
    queue<node*> q;
    cout<<"Enter root data:";
    int data;
    cin>>data;
    
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"enter data for left node of "<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
   
        temp->left=new node(data);
        q.push(temp->left);
        }

        cout<<"enter data for right node of "<<temp->data<<endl;
        cin>>data;

    if(data!=-1){
        temp->right=new node(data);
        q.push(temp->right);
    }
        
    }
    return root;

    
}
void preOrderTraversal(node* root){
    if(root==NULL||root->data==-1)
    return;
    int data=root->data;
    cout<<data<<" ";
    preOrderTraversal(root->left);
   preOrderTraversal(root->right);
}
void inOrderTraversal(node* root){
    if(root==NULL||root->data==-1)
    return;
    int data=root->data;
    
    inOrderTraversal(root->left);
    cout<<data<<" ";
    inOrderTraversal(root->right);


}

void postOrderTraversal(node* root){
    if(root==NULL||root->data==-1)
    return;
    int data=root->data;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<data<<" ";

}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp!=NULL){
        cout<<temp->data<<" ";
         if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
        else{
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
        }
      // getch();
        
       
    }
}
int main(){
node* root=NULL;
//4 5 7 -1 -1 8 -1 -1 6 9 -1 -1 10 -1 -1
buildTree(root);
//1 3 5 7 11 10 -1 -1 -1 -1 -1 -1 
//root =buildLevelTree(root);

cout<<endl<<"PREORDER TRAVERSAL:"<<endl;
getch();
 preOrderTraversal(root);
cout<<endl<<"PREORDER TRAVERSAL:"<<endl;
 inOrderTraversal(root);
cout<<endl<<"PREORDER TRAVERSAL:"<<endl;
postOrderTraversal(root);
cout<<endl<<"LEVEL ORDER TRAVERSAL"<<endl;
levelOrderTraversal(root);

return 0;
}