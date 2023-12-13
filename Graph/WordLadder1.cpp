#include <iostream>
// #include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
#define ll long long

// Time Complexity: O(n* word* 26)
// Space COmplexity: O(n)

int wordLadderLength(string startWord,string targetWord,vector<string>& wordList){
    queue<pair<string,int>> q;
    q.push({startWord,1});

    unordered_set<string> st(wordList.begin(),wordList.end());

    st.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;

        q.pop();
        if(word == targetWord){
            return steps;
        }

        for(int i =0;i<word.size();i++){
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;

                // if word exist in the set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }
}
 
int main(){
    
    return 0;
}