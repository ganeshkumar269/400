#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


template<class T>
struct TrieNode {
    unordered_map<T,TrieNode*> m;
    bool endOfWord;
    TrieNode():endOfWord(false){}
};


template<class T>
class TrieStructure{
    TrieNode<T> *root;
    public:
        TrieStructure(){
            root = new TrieNode<T>();
        }

        void insert(string s){
            TrieNode<T>* temp = root;
            for(int i =0 ; i < s.size();i++){
                if((temp->m).find(s[i]) == (temp->m).end()){
                    TrieNode<T>* t = new TrieNode<T>();
                    (temp->m).insert({s[i],t});
                    temp = t;
                }else{
                    temp = (temp->m)[s[i]];
                }
            }
            temp->endOfWord = true;
        }

        bool search(const string& s, bool prefix_search = false){
            TrieNode<T>* temp = root;
            int i = 0;
            while(i < s.size()){
                if((temp->m).find(s[i]) == (temp->m).end()) return false;
                temp = (temp->m)[s[i]];i++;
            }
            if(!prefix_search){
                if(temp->endOfWord == true) return true;
                else return false;
            }else return true;
        }

        bool prefix_search(const string& s){return search(s,true);}

        // void erase(string s){
        //     if(!search(s))return;
        //     TrieNode<T>* temp = root;
        //     for(int i =0;i < s.size();i++){
        //         TrieNode<T>* t = (temp->m)[s[i]];
        //         (temp->m).erase(s[i]);
        //         if((temp->m).size() == 0) delete temp;
        //         temp = t;
        //     }
        // }

};


int main(){
    freopen("in.txt","r",stdin);
    int n;cin>>n;
    vector<string> s(n);
    TrieStructure<char> trie;
    for(int i =0 ; i <n;i++)cin>>s[i];
    for(string i : s) trie.insert(i);
    for(string i : s) cout << trie.search(i) << " ";
    cout << trie.search(string("ab")) << endl;
    cout << trie.search(string("abce")) << endl;
    return 0;
}