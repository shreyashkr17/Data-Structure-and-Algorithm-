#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity: O( (2^n) *k*(n/2) )
//          Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.


//Space Complexity : Space Complexity: O(k * x)
//          Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

class Solution{
    private:
        void partition(int index,string s,vector<string>& path,vector<vector<string>>& res){
            if(index == s.length()){
                res.push_back(path);
                return;
            }

            for(int i = index;i<s.size();i++){
                if(isPalin(s,index,i)){
                    path.push_back(s.substr(index,i-index+1));
                    partition(i+1,s,path,res);
                    path.pop_back();
                }
            }
        }

        bool isPalin(string s,int start,int end){
            while(start<=end){
                if(s[start++]!=s[end--]){
                    return false;
                }
            }
            return true;
        }
    public:
        vector<vector<string>> partiotion(string s){
            vector<vector<string>> res;
            vector<string> path;
            partition(0,s,path,res);

            return res;
        }
};

// int main() {
//   string s = "aabb";
//   Solution obj;
//   vector < vector < string >> ans = obj.partition(s);
//   int n = ans.size();
//   cout << "The Palindromic partitions are :-" << endl;
//   cout << " [ ";
//   for (auto i: ans) {
//     cout << "[ ";
//     for (auto j: i) {
//       cout << j << " ";
//     }
//     cout << "] ";
//   }
//   cout << "]";

//   return 0;
// }