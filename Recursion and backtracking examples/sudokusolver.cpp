#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time complexity : O(9^n^2);
//Space complexity: O(1);

bool isPossible(vector<vector<char>>& boards,int row,int col,char ch){
    for(int i = 0;i<9;i++){
        if(boards[i][col] == ch){
            return false;
        }

        if(boards[row][i] == ch){
            return false;
        }

        if(boards[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
            return false;
        }
    }

    return true;
}

bool sudokusolver(vector<vector<char>>& boards){
    for(int i = 0;i<boards.size();i++){
        for(int j = 0;j<boards[0].size();j++){
            if(boards[i][j] == '.'){
                for(char c = '1';c<='9';c++){
                    if(isPossible(boards,i,j,c)){
                        boards[i][j] = c;

                        if(sudokusolver(boards)){
                            return true;
                        }else{
                            boards[i][j] = '.';
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    sudokusolver(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}