#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time complexity : O(n)

void subsequences(int index, vector<int> &ds,int arr[],int n){
    if(index == n){
        for(auto it:ds){
            cout<<it<<" ";
        }

        if(ds.size() == 0){
            cout<<"{}";
        }

        cout<<endl;
        return;
    }

    //not pick, or not take condition, this element is not added to the subsequence
    subsequences(index+1,ds,arr,n);

    //take or pick the particular index into the particular subsequence
    ds.push_back(arr[index]);
    subsequences(index+1,ds,arr,n);
    ds.pop_back();

}

int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> ds;

    subsequences(0,ds,arr,n);
    return 0;
}