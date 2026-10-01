#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

Node*createTree(){
    int value;
    cout<<"Enter root value (-1 for empty): ";
    cin>>value;

    if(value==-1)
        return NULL;

    Node*root=new Node{value,NULL,NULL};
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node*current=q.front();
        q.pop();

        cout<<"Enter left child of "<<current->data<<" (-1 for none): ";
        cin>>value;

        if(value!=-1){
            current->left=new Node{value,NULL,NULL};
            q.push(current->left);
        }

        cout<<"Enter right child of "<<current->data<<" (-1 for none): ";
        cin>>value;

        if(value!=-1){
            current->right=new Node{value,NULL,NULL};
            q.push(current->right);
        }
    }

    return root;
}

void inorder(Node*root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node*root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node*root){
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node*root){
    if(root==NULL)
        return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node*current=q.front();
        q.pop();

        cout<<current->data<<" ";

        if(current->left!=NULL)
            q.push(current->left);

        if(current->right!=NULL)
            q.push(current->right);
    }
}

int main(){
    Node*root=createTree();

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPreorder: ";
    preorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    cout<<"\nLevel Order: ";
    levelOrder(root);

    return 0;
}
