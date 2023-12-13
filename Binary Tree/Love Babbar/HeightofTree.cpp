#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity: O(n)
// Space Complexity: O(height)

int heightOfTree(struct Node* node){
    if(node == NULL){
        return 0;
    }

    int left = heightOfTree(node->left);
    int right = heightOfTree(node->right);

    int ans = max(left,right)+1;

    return ans;
}

