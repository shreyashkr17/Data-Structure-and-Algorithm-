#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    private:
        void findPath(int i,int j,vector<vector<int>>& m,int n,vector<string>& ans,string s,vector<vector<int>>& vis,int diri[],int dirj[]){
            if(i==n-1 && j==n-1){
                ans.push_back(s);
                return;
            }

            string direction = "DLRU";

            for(int ind = 0;ind<4;ind++){
                int nexti = i+diri[ind];
                int  nextj = j+dirj[ind];
                if(nexti >= 0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && m[nexti][nextj] == 1){
                    vis[i][j] = 1;
                    s+=direction[ind];
                    findPath(nexti,nextj,m,n,ans,s,vis,diri,dirj);
                    vis[i][j] = 0;
                }
            }
        }
    public:
        vector<string> solve(vector<vector<int>>& m,int n){
            vector<string> ans;
            vector<vector<int>> vis(n,vector<int> (n,0));
            int diri[] = {1,0,0,-1};
            int dirj[] = {0,1,-1,0};
            string s="";

            if(m[0][0] == 1){
                findPath(0,0,m,n,ans,s,vis,diri,dirj);
            }

            return ans;
        }
};

int main() {
  int n = 4;

 vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
   
  Solution obj;
  vector < string > result = obj.solve(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}