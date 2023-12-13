#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<TreeNode*> constructNode(int start, int end){
    vector<TreeNode*> list;

    if(start > end){
        list.push_back(NULL);
        return list;
    }

    for(int i = start;i<=end;i++){
        vector<TreeNode*> leftSubTree = constructNode(start, i-1);
        vector<TreeNode*> rightSubTree = constructNode(i+1, end);

        for(int j = 0;j<leftSubTree.size();j++){
            TreeNode* left = leftSubTree[j];

            for(int k = 0; k <rightSubTree.size(); k++){
                TreeNode* right = rightSubTree[k];
                TreeNode* node = new TreeNode(i);

                node->left = left;
                node->right = right;

                list.push_back(node);
            }
        }
    }

    return list;
} 

int main(){
    vector<TreeNode*> totalTreesFrom1toN = constructNode(1,3);
    cout<<"Preorder traversal of all constructed BSTs are :\n";
    for(int i = 0;i< totalTreesFrom1toN.size();i++){
        preorder(totalTreesFrom1toN[i]);
        cout<<endl;
    } 
    return 0;
}