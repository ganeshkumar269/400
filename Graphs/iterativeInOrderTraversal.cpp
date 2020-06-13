#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i = 0; i < n;++i)
typedef vector<int> v;
typedef vector<vector<int>> vv;

struct node {
    int val;
    node* left;
    node* right;
};

int main(){
    freopen("in.txt","r",stdin);
    int n;cin>>n;
    v arr;
    cout << n << " ";
    rep(i,n) {
        cout << i << " ";
        int t;
        cin>>t;
        arr.push_back(t);
    }
    // cerr << "this cerr " ;
    // cout << "before loop1" <<" " ;
    stack<int> s;
    s.push(0);
    // cout << "before loop2" <<" " ;
    int curr = 0;
    // cout << "before loop" <<" " ;
    while(!s.empty() && curr < n){
        curr = s.top();
        s.pop();
        cerr<<"size: " << s.size() << " " ;
        while(curr < n) {
            s.push(curr);
            // cerr << curr << " ";
            curr = 2*curr+1;
        }
        curr = s.top();
        s.pop();
        cerr << curr << ": ";
        cerr << arr[curr] << " ";
        if(2*curr + 2 < n)
            s.push(2*curr + 2 );
    }
}