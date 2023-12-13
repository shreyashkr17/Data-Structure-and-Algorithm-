#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// BUild the binary tree and inserted the data of the node
node* buildTree(node* root){
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}


// Level Order Traversal in Binary Tree
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// Reverse Level Order traversal
void reverseLevelOrderTraversal(node* root){
    stack<node*> s;
    queue<node*> q;

    s.push(root);


    while(q.empty() == false){
        root = q.front();
        q.pop();
        s.push(root);

        if(root->right){
            q.push(root->right);
        }

        if(root->left){
            q.push(root->left);
        }
    }

    while(s.empty() == false){
        root = s.top();
        cout<<root->data<<" ";
        s.pop();
    }
}

// Inorder Traversal
// LNR --> Left -> Node -> right 

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}

// PreOrder Traversal 
// NLR --> node left right
void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// PostOrder Traversal
// LRN --> left right node
void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}




int main(){
    node* root = NULL;

    root = buildTree(root);
    cout<<"Prinitng the level order traversal output: "<<endl;
    levelOrderTraversal(root);

    return 0;
}