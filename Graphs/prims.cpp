#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
#define rep(i,n) for(int i = 0; i < n;++i)
#define pb push_back
typedef vector<int> v;
typedef vector<vector<int>> vv;


int main(){
    int n,m;
    vector<vector<pair<int,int>>> adj(n+1);
    cin>>n>>m;
    rep(i,m){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        adj[t1].pb({t2,t3});
        adj[t2].pb({t1,t3});
    }
    vector<pair<int,int>> dist;
    rep(i,n+1) dist.pb({numeric_limits<int>::max(),i});
    int start;cin>>start;
    dist[start] = {0,start};
    make_heap(dist.begin(),dist.end());
    int nodes=0;
    v vis(n+1,0);
    while(nodes < n){
        int t = dist[0].second;
        pop_heap(dist.begin(),dist.end());
        dist.pop_back();
        if(vis[t] == 0)
        for(auto i : adj[t]){
            
        }
    }
    return 0;
}