#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int sumSub(int index,vector<int> &ds,int s, int sum, int arr[], int n)
{   
    if(s>sum){
        return 0;
    }
    
    if(index == n){
        if(s==sum){
            return 1;
        }
        else return 0;
    }

    // ds.push_back(arr[index]);
    s+=arr[index];
    int l = sumSub(index+1,ds,s,sum,arr,n);

    s-=arr[index];
    // ds.pop_back();

    int r = sumSub(index+1,ds,s,sum,arr,n);
}

int main(){
    int arr[] = {1,2,1};
    int n  = 3;
    int sum = 2;
    vector<int> ds;

    cout<<sumSub(0,ds,0,sum,arr,n)<<endl;
    return 0;
}