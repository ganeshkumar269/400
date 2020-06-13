#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i = 0; i < n;++i)
typedef vector<int> v;
typedef vector<vector<int>> vv;
/*
    1.sort the edges wrt their weights
    2.Pick the edge with least weight and add it to the graph
    3.Make sure theedge doesnt form a cycle , if it does ignore the edge
    4.repeat step 2,3 for all edges

    To Detect a cycle:
        UnionFind By Rank
        struct subset = {parent,rank}
        make a subset array parent = i , rank = 0
        for every edge if find_parent(e.src) == find_parent(e.dest) cycle found
        else union(parent1,parent2)

*/
struct subset{
    int parent;
    int rank;
};

int find_parent(struct subset *s,int x){
    cout << "findparent " << x << endl;
    if(s[x].parent == x) return x;
    else return find_parent(s,s[x].parent);
}
void Union(struct subset *s,int a,int b){
    int p1 = find_parent(s,a);
    int p2 = find_parent(s,b);
    if(p1 != p2){
        if(s[p1].rank < s[p2].rank){
            s[p1].parent = p2;s[p2].rank++;
        }
        else if(s[p1].rank > s[p2].rank){
            s[p2].parent = p1;s[p1].rank++;
        }
        else {
            s[p1].parent = p2;s[p2].rank++;
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    cout << n << m << endl;
    vv adj(n+1);
    vv w(n+1,vector<int>(n+1));
    vv edgeSet;
    vv adjRes(n+1);
    cout << "init variable" << endl;
    rep(i,m){
        int t1,t2,w1;
        cin>>t1>>t2>>w1;
        edgeSet.push_back(vector<int>({t1,t2,w1}));
        // w[t1][t2] = (w[t2][t1] = w1);
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    cout << "sorted begin" << endl;
    // sort(edgeSet.begin(),edgeSet.end(),[](vector<int> i , vector<int> j ){ return i[2] < j[2];});
    cout << "sorted" << endl;
    struct subset *s = new subset[n+1];
    for(int i = 1; i <= n;i++){
    s[i].parent = i ; s[i].rank = 0;
    } 
    cout << "inited s" << endl;
    rep(i,m){
        //1.Iscycle?
        //2.Add to Graph
        cout << "came inside" << endl;
        int p1 = find_parent(s,edgeSet[i][0]);
        int p2 = find_parent(s,edgeSet[i][1]);
        cout <<edgeSet[i][0] << " " << edgeSet[i][1] <<" " << p1 <<" " << p2 << endl;
        if(p1 != p2){
            Union(s,p1,p2);
            adjRes[edgeSet[i][0]].push_back(edgeSet[i][1]);
            adjRes[edgeSet[i][1]].push_back(edgeSet[i][0]);
        }        
    }
    cout << "solution" << endl;
    rep(i,adjRes.size())   for(int j : adjRes[i]) cout << i << " " << j <<endl;
    return 0;
}
