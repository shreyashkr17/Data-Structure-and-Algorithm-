#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

void lcs(string s,string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i =0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int i = 0;i<=m;i++){
        dp[0][i] = 0;
    }

    for(int ind1 = 1;ind1<=n;ind1++){
        for(int ind2 = 1;ind2 <= m;ind2++){
            if(s[ind1-1] == t[ind2-1]){
                dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
            }else{
                dp[ind1][ind2] = 0+max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    }

    int len = dp[n][m];

    int i = n,j =m;

    int index = len-1;
    string str = "";

    for(int k = 1;k<=len;k++){
        str+='$';
    }

    while (i > 0 && j > 0) {
        if(s[i-1] == t[j-1]){
            str[index] = s[i-1];
            i--;
            j--;
            index--;
        }else if(s[i-1] > t[j-1]){
            i--;
        }else{
            j--;
        }
    }

    cout<<str<<endl;

}
 
int main(){
    
    return 0;
}