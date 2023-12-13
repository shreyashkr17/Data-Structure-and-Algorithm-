#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity: O(n*n!);
//Space Complexity:O(n^2);

class Solution{
    public:
        bool isSafe(int row,int col,vector<string>& boards,int n){
            //check upper element
            int duplicaterow = row;
            int duplicatecol = col;

            while(row >= 0 && col>=0){
                if(boards[row][col] == 'Q'){
                    return false;
                }
                row--;
                col--;
            }

            row = duplicaterow;
            col = duplicatecol;

            while(col>=0){
                if(boards[row][col] == 'Q'){
                    return false;
                }
                col--;
            }

            row = duplicaterow;
            col = duplicatecol;

            while(row<n && col>=0){
                if(boards[row][col] == 'Q'){
                    return false;
                }
                row++;
                col--;
            }

            return true;
        }
    public:
        void solve(int col,vector<string>& boards,vector<vector<string>>& ans,int n){
            if(col == n){
                ans.push_back(boards);
                return;
            }

            for(int row =0;row<n;row++){
                if(isSafe(row,col,boards,n)){
                    boards[row][col] = 'Q';
                    solve(col+1,boards,ans,n);
                    boards[row][col] = '.';
                }
            }
        }
    public:
        vector<vector<string>> solveNQueens(int n){
            vector<vector<string>> ans;
            vector<string> boards(n);
            string s(n,'.');
            for(int i=0;i<n;i++){
                boards[i] = s;
            }

            solve(0,boards, ans, n);
            return ans;
        }
};
 
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}