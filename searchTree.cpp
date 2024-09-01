#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "/Users/Shmuli/c++library/que.cpp"
using std::string, std::vector, std::map, std::set, std::queue, std::pair;
using std::cin, std::cout, std::endl, std::stringstream;
using std::max, std::min;
using std::make_pair, std::make_shared;
using std::priority_queue;
using std::shared_ptr;


/**
 * in order to make sure there are no memory leaks
*/
set<void*> allPointers;



template <typename T>
struct searchNode{
    map<char, searchNode*> children;
    bool isWord = false;
    string word;
    T data;


     inline void display(const int depth = 0)const{
        cout << "depth: " << depth << endl;
        for (auto &[chr, node]: children){
            node->display(depth+1);
        }

        cout << word << " " << data << endl;


     }


    void insert(const string word, T data){
        searchNode* temp = this;

        char c;
        for(int i = 0; i < word.size(); i++){
            c = word[i];
            if(temp->children[c] == nullptr){
                temp->children[c] = new searchNode();
            }
            temp = temp->children[c];
        }
        temp->isWord = true;
        temp->data = data;
        temp->word = word;
        
    }

    bool hasWord(const string word){
        searchNode* temp = this;
        char c;
        for(int i = 0; i < word.size(); i++){
            c = word[i];
            if(temp->children[c] == nullptr){
                return false;
            }
            temp = temp->children[c];
        }
        return temp->isWord;
    }
    bool containes(const string word){
        searchNode* temp = this;
        char c;
        for(int i = 0; i < word.size(); i++){
            c = word[i];
            if(temp->children[c] == nullptr){
                return false;
            }
            temp = temp->children[c];
        }
        return true;
    }


    searchNode* operator[](const string word){
        searchNode* temp = this;
        char c;
        for(int i = 0; i < word.size(); i++){
            c = word[i];
            if(temp->children[c] == nullptr){
                return nullptr;
            }
            temp = temp->children[c];
        }
        return temp;
    }

    vector<string> bfs(){
        que<searchNode*> que;
        que.push(this);

        vector<string> words;
        searchNode* currentNode;
        string word;
        while(que.size){
            currentNode = que--;
            if(currentNode->isWord){
                word = currentNode->word;
                words.push_back(word);
            }
            for (std::pair<char, searchNode*> itr: currentNode->children){
                que.push(itr.second);
            }
        }
        return words;
    }

    searchNode(){
        allPointers.insert((void *)this);
    }


    ~searchNode(){
        for(auto &[chr, node]: children){
            allPointers.erase((void *)node);
            delete node;
        }
    }
};


std::ostream& operator<<(std::ostream& out, vector<string> words){
    for(int i = 0; i < words.size(); i++){
        out << words[i] << endl;
    }
    return out;
}


std::ostream& operator<<(std::ostream& out, searchNode<int> tree){
    return out;
}




void test(){
    searchNode<int> tree;
    tree.insert("height", 1);
    tree.insert("hilt", 90);
    tree.insert("hepye", 3);


    assert(tree.hasWord("hilt"));
    assert(!tree.hasWord("doof"));
    assert(tree.containes("hil"));
}



int main(){

    // test();
    searchNode<int> tree;

    tree.insert("height", 1);   
    tree.insert("hilt", 90);   
    tree.insert("hepye", 3);   
    tree.insert("holy", 4);   
    tree.insert("holy", 5);

    cout << tree["h"]->bfs() << endl;
    return 0;
}



