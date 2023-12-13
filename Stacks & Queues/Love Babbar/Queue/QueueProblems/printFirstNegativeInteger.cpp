#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Naive Approach : 
// Time Complexity: O((n-k+1)*k);
// Space  complexity: O(1);

// Time Complexity: O(n)
// Time Complexity: O(k)

vector<ll> printFirstNegativeInteger(ll int arr[],ll int n,ll int k){
    deque<ll int>dq;
    vector<ll> ans;

    int negative = -1;

    for(int i = 0;i<k;i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }else{
        ans.push_back(0);
    }


    // now processing for the remaining portion

    for(int i = k;i<n;i++){
        if(!dq.empty() && (i-dq.front())>=k){
            dq.pop_front();
        }

        if(arr[i] < 0){
            dq.push_back(i);
        }

        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }

    return ans;
}
 
int main(){
    ll int t,i;
    cin>>t;

    while(t--){
        ll int n;
        ll int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }

        ll int k;
        cin>>k;

        vector<ll> ans = printFirstNegativeInteger(arr,n,k);

        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}