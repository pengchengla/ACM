/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-03
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

struct TrieNode{
    char ch;
    bool isWord;
    TrieNode * next[26];
    TrieNode(){}
    TrieNode(char c){
        ch=c;
        isWord=false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
};

class WordDictionary {
public:
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * pNode = root;
        for(int i=0;i<word.length();i++){
            if(pNode->next[word[i]]) pNode = pNode->next[word[i]];
            else{
                pNode->next[word[i]] = new TrieNode(word[i]);
                pNode = pNode->next[word[i]];
            }
        }
        pNode->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return subsearch(root,word,0);
    }
private:
    bool subsearch(TrieNode * root,string word,int p){
        if(p==word.length() && root->isWord) return true;
        if(word[p]!='.'){
            if(!root->next[word[p]]) return false;
            root = root->next[word[p]];
            p++;
        }else{
            bool flag = false;
            p++;
            for(int i=0;i<26;i++){
                flag = subsearch(root->next[i],word,p);
                if(flag) return true;
            }
            return false;
        }
    }
private:
    TrieNode * root;
};

int main(){
    return 0;
}
