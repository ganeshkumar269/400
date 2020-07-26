//https://www.geeksforgeeks.org/find-k-cores-graph/
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i =0;i<n;i++)
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);    
    vector<int> deg(n+1,0);
    rep(i,n){
        int s,d;cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
        deg[d]++;deg[s]++;
    }
    for(int i =2;i <n;i++){
        vector<int> temp(deg);
        
    }
    return 0;
}