#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i =0;i < n;i++)
typedef vector<vector<int>> vv;
typedef vector<int> v;
struct subset{
    long parent;
    long rank;
};

long find(vector<subset>& s,long x){
    if(s[x].parent == -1) return x;
    return s[x].parent = find(s,s[x].parent);
}

void Union(vector<subset>& s,long x,long y){
    long p1 = find(s,x);
    long p2 = find(s,y);
    if(p1 != p2){
    if(s[p1].rank < s[p2].rank){
        s[p1].parent = p2;
        s[p2].rank ++;
    }
    else if(s[p1].rank > s[p2].rank){
        s[p2].parent = p1;
        s[p1].rank ++;
    }else{
        s[p1].parent = p2;
        s[p2].rank ++;
    }}
}
struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1); }
};


int main(){
    freopen("in.txt","r",stdin);
    long n,p;cin>>n>>p;
    unordered_set<pair<long,long>,pair_hash> ed;
    rep(i,p){
        long t1,t2;
        cin>>t1>>t2;
        if(ed.find({t1,t2}) == ed.end() &&ed.find({t1,t2}) == ed.end())
            ed.insert({t1,t2});
    }
    vector<subset> s(n+10);
    rep(i,n){s[i].parent = -1;s[i].rank=0;}
    for(auto i : ed){
        Union(s,i.first,i.second);
    }
    long res = 0;
    v arr(n,0);
    for(long i = 0; i < n;i++) arr[find(s,i)]++;
    long sq = 0,sum=0;
    rep(i,n){
        sq += arr[i]*arr[i];
        sum+=arr[i];
    }
    res = (sum*sum-sq)/2;
    cout << res << endl;
    return 0;
}