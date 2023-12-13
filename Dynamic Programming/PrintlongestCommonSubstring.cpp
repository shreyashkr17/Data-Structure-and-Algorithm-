#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

string LongestCommonSubstring(string str1,string str2){
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    int maxLength = 0;
    int endIndex = 0;

    for(int i = 1;i <= m;i++){
        for(int j = 1;j<=n;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                
                if(dp[i][j] > maxLength){
                    maxLength = dp[i][j];
                    endIndex = i-1;
                }
            }
        }
    }

    for(auto it:dp){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }

    string longest_common_substring = str1.substr(endIndex - maxLength + 1, maxLength);
    return longest_common_substring;
}
 
int main(){
    // string str1, str2;
    // cout << "Enter the first string: ";
    // cin >> str1;
    // cout << "Enter the second string: ";
    // cin >> str2;

    string result = LongestCommonSubstring("babaab", "babbba");
    cout << "Longest Common Substring: " << result << endl;
    
    return 0;
}