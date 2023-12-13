#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int getMaxArea(vector<int>& arr,int n){
    stack<int> st;
    int n = arr.size();

    st.push(-1);
    int area = arr[0];

    int i = 0;

    vector<int> left(n,-1),right(n,n);

    while(i<n){
        while(!st.empty() && st.top()!=-1 && arr[st.top()] > arr[i]){
            right[st.top()] = i;
            st.pop();
        }

        if(i>0 && arr[i] == arr[i-1]){
            left[i] = left[i-1];
        }
        else{
            left[i] = st.top();
        }
        st.push(i);
        i++;
    }

    for(int j = 0;j<n;j++){
        area = max(area,arr[j]*(right[j]-left[j]-1));
    }

    return area;
}