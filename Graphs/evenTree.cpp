#include "All.h"
// #include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n;++i)
typedef vector<int> v;
typedef vector<vector<int>> vv;

int main(){
    int n,m;
    cin>>n>>m;
    vv adj(n+1);
    bool parent[n+1];
    rep(i,m){
        int t1,t2;
        cin>>t1>>t2;
        adj[t1].push_back(t2); 
        adj[t2].push_back(t1); 
    } 
    
    return 0;
}