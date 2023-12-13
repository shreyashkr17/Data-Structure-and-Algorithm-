#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sortedInsert(stack<int>& st,int num){
    if(st.empty() || (!st.empty() && st.top() < num)){
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st,num);

    st.push(n);
}
 
void sortedStack(stack<int>& st){
    if(st.empty()){
        return;
    }

    int num = st.top();

    st.pop();

    sortedStack(st);

    sortedInsert(st,num);
}