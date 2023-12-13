#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;
#define ll long long

vector<vector<string>> findSequences(string beginWord,string endWord,vector<string>& wordList){
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;

    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        // erase all words that has been
        // used in the previous level to transform
        if(vec.size() > level){
            level++;
            for(auto it:usedOnLevel){
                st.erase(it);

            }   
        }

        string word = vec.back();
        if(word ==  endWord){
            if(ans.size()==0){
                ans.push_back(vec);
            }else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }

        for(int i = 0;i<word.size();i++){
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();

                }
            }
            word[i] = original;
        }
    }

    return ans;
}
 
int main(){
    
    return 0;
}