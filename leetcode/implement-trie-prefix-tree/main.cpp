#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    char ch;
    bool isEnd;
    TrieNode * next[26];
public:
    TrieNode() {
        isEnd = false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * pNode = root;
        int len = word.length();
        for(int i=0;i<len;i++){
            int pos = word[i]-'a';

            if(!pNode->next[pos]){
                pNode->next[pos] = new TrieNode();
            }
            pNode = pNode->next[pos];
        }
        pNode->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * pNode = root;
        int len = word.length();
        for(int i=0;i<len;i++){
            int pos = word[i]-'a';
            if(!pNode || !pNode->next[pos]) return false;
            pNode = pNode->next[pos];
        }
        if(!pNode->isEnd) return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * pNode = root;
        int len = prefix.length();
        for(int i=0;i<len;i++){
            int pos = prefix[i]-'a';
            if(!pNode || !pNode->next[pos]) return false;
            pNode = pNode->next[pos];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main(){
    Trie trie;
    trie.insert("a");
    bool flag = trie.search("a");
    string out = flag==true?"YES":"NO";
    cout<<out<<endl;
    return 0;
}
