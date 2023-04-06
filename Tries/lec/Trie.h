#include "TrieNode.h"
class tries{
    TrieNode *root;
    public:
    tries(){
        root=new TrieNode('\0');
    }
    // first function i.e insert word function
    void insertword(TrieNode *root,string word){
        // Base case
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        // small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child=root->children[index];
        }else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        // Recursive calls
        insertword(child,word.substr(1));
    }
    // for the user 
    void insertwordhelper(string word){
        insertword(root,word);
    }

    bool search_helper(TrieNode *root,string word){
        // Base case
        if(word.size()==0){
            return root->isTerminal; // if isTriminal---true-->return True   else return false;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            // word is present in the tries node
            child=root->children[index];
        }else{
            // since word is not present we directly return false here
            return false;
        }
        // Recursive calls
        search_helper(child,word.substr(1));
    }
    bool search_helper(string word){
        return search_helper(this->root,word);
    }
};