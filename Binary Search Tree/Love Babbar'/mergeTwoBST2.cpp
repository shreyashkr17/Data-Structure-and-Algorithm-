#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void convertIntoSortedDLL(TreeNOde<int> *root,TreeNode<int>* &head){
    if(root == NULL){
        return NULL;
    }

    convertIntoSortedDLL(root->right,head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left,head);
}

TreeNOde<int> mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2){
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data <head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1= head1->right
            }
        }else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head1 = head2->right;
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head1!=NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head;
        head1 = head1->right;
    }
}

int countNode(TreeNode<int> *head){
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedLLtoBST(TreeNode<int>* &head,int n){
    //base case
    if(n <= 0 || root ==NULL){
        return NULL;
    }

    TreeNode<int> *left = sortedLLtoBST(head,n/2);
    TreeNode<int> *root = head;
    root->left = left;
    head = head->next;

    root->right = sortedLLToBST(head,n-n/2-1);

    return root;
}


TreeNode<int> *mergeBST(TReeNode<int> *root1, TreeNode<int> *root2){
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    TreeNode<int> *head = mergeLinkedList(head1,head2);

    return sortedLLToBST(head,countNodes(head));
}

int main(){
    
    return 0;
}