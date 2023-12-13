#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string FirstNonRepeating(string A){
    map<char,int> mp;
    string ans = "";
    queue<int> q;

    for(int i = 0;i<A.length();i++){
        char ch = A[i];

        q.push(ch);
        mp[ch]++;

        while(!q.empty()){
            if(mp[q.front()] > 1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }

    return ans;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string A;
        cin>>A;
        while(tc--){
            string A;
            cin>>A;

            string ans = FirstNonRepeating(A);
            cout<<ans<<endl;
        }
        return 0;
    }
    return 0;
}