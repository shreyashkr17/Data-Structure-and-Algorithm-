#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }
        void insertUtil(TrieNode* root,string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            // Assumption words will be in capital
            int index = word[0]-'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                //absent
                child = new TrieNode(word[0]);
                root->children[index] = child; 
            }

            // Recursion
            insertUtil(child,word.substr(1));
        }




        bool searchUtil(TrieNode* root,string word){
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0]-'A';

            TrieNode* child;

            if(root -> children[index] != NULL){
                child = root->children[index];
            }else{
                return false;
            }

            return searchUtil(child,word.substr(1));
        }

        bool search(string word){
            return searchUtil(root,word);
        }
}; 

int main(){
    
    return 0;
}