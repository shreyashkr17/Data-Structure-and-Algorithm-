#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool sumSub(int ind,vector<int>& ds,int s,int sum,int arr[],int n){
    if(ind == n){
        if(s == sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(sumSub(ind+1,ds,s,sum,arr,n) == true){
        return true;
    }

    s-=arr[ind];
    ds.pop_back();

    if(sumSub(ind+1,ds,s,sum,arr,n) == true){
        return true;
    }

    return false;
}
 
int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    vector<int> ds;

    sumSub(0,ds,0,sum,arr,n);
    return 0;
}