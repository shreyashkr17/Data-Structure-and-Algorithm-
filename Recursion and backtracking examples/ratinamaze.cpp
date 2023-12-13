#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity: O(4^(m*n)),      because on every cell we need to try 4 different directions.

//Space Complexity:  O(m*n),       Maximum Depth of the recursion tree(auxiliary space).

class Solution{
    private:
        void findPath(int i,int j,vector<vector<int>>& m,int n,vector<string>& ans,string s,vector<vector<int>>& vis){
            if(i==n-1 && j==n-1){
                ans.push_back(s);
                return;
            }

            //for odwanward visit check
            if(i+1<n && !vis[i+1][j] && m[i+1][j] == 1){
                vis[i][j] = 1;
                s+="D";
                findPath(i+1,j,m,n,ans,s,vis);
                vis[i][j] = 0;
            }

            //for left visit check
            if(j-1>=0 && !vis[i][j-1] && m[i][j-1] == 1){
                vis[i][j] = 1;
                s+="L";
                findPath(i,j-1,m,n,ans,s,vis);
                vis[i][j] = 0;
            }

            //for right visit check
            if(j+1<n && !vis[i][j+1] && m[i][j+1] == 1){
                vis[i][j] = 1;
                s+="R";
                findPath(i,j+1,m,n,ans,s,vis);
                vis[i][j] = 0;
            }

            //for upward visit check
            if(i-1>=0 && !vis[i-1][j] && m[i-1][j] == 1){
                vis[i][j] = 1;
                s+="U";
                findPath(i-1,j,m,n,ans,s,vis);
                vis[i][j] = 0;
            }
        }
    public:
        vector<string> findPath(vector<vector<int>>& m,int n){
            vector<string> ans;
            vector<vector<int>> vis(n,vector<int> (n,0));
            string s = "";

            if(m[0][0] == 1){
                findPath(0,0,m,n,ans,s,vis);
            }

            return ans;
        }
};

int main() {
  int n = 4;

  vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}