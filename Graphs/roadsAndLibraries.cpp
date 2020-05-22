#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i =0;i < n;i++)
typedef vector<vector<int>> vv;
typedef vector<int> v;

void dfs(vv adj,v& vis,int n){
    vis[n] = 1;
    REP(i,adj[n].size())
        if(!vis[adj[n][i]])
            dfs(adj,vis,adj[n][i]);
}


int main(){
    freopen("in.txt","r",stdin);
    int q;
    cin>>q;
    while(q--){
        int n, m,cr,cl;
        cin>>n>>m>>cl>>cr;
        vv adj(n+1);
        REP(i,m){
            int t1,t2;
            cin>>t1>>t2;
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);
        }
        int cnt = 0;
        v vis(n+1,0);
        REP(i,n){
            if(!vis[i+1]){
                dfs(adj,vis,i+1);cnt++;
            }
        }cerr << cnt << endl;
        cout << min(n*cl,(n-cnt)*cr + cnt*cl) << endl;
    }
}