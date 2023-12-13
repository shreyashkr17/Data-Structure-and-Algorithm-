#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int maximumProfit(vector<int>& arr){
    int maxProfit = 0;
    int mini = arr[0];
    for(int i = 1;i<=arr.size();i++){
        maxProfit = max(maxProfit,arr[i]-mini);
        mini = min(mini,arr[i]);
    } 

    return maxProfit;
}
 
int main(){
    
    return 0;
}