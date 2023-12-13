#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int findWays(vector<int>& num,int tar){
    int n = num.size();
    vector<int> prev(tar+1,0),cur(tar+1,0);

    if(num[0] == 0){
        prev[0] = 2;
    }else{
        prev[0] = 1;
    }

    if(num[0] != 0 && num[0] <= tar){
        prev[num[0]] = 1;
    }

    for(int ind = 1;ind<n;ind++){
        for(int sum = 0;sum<=tar;sum++){
            int notTaken = prev[sum];
            int take = 0;
            if(num[ind] <= sum){
                take = prev[sum-num[ind]];
            }

            cur[sum] = (notTaken+take);
        }
        prev = cur;
    }

    return prev[tar];
}

int countPartition(int n,int d,vector<int>& arr){
    int totSum = 0;
    for(auto &it:arr){
        totSum+=it;
    }

    if(totSum-d < 0 || (totSum-d)%2 != 0){
        return 0;
    }

    return findWays(arr,(totSum-d)/2);
}

int target(int n,int target, vector<int>& arr){
    return countPartition(n,target,arr);
}
 
int main(){
    
    return 0;
}