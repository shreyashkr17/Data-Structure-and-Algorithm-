#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isValid(string s){
    stack<char> st;
    for(auto it:s){
        if(it == '(' || it == '[' || it=='{'){
            st.push(it);
        }
        else{
            if(st.size() == 0){
                return false;
            }
            char ch = st.top();
            if((it == ')' && ch == '(') || ((it == ']') && ch == '[') || (it == '}' && it == '{')){
                continue;
            }else{
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    
    return 0;
}