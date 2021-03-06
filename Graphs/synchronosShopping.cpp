#include <bits/stdc++.h>
using namespace std; 

#define Any_of ano
#define All_of alo
#define All_of_Any_of aloano
#define Any_of_Any_of anoano
template <typename T>
bool Any_of(T f,vector<T> s){for(T i : s) if(i == f) return true;return false;}
template <typename T>
bool Any_of_Any_of(vector<T> f,vector<T> s){ for(T i : f) if(Any_of(i,s)) return true; return false;}
template <typename T>
bool All_of(vector<T> f,T s){for(T i : f) if(i != s) return false;return true;}
template <typename T>
bool All_of_Any_of(vector<T> f, vector<T> s){for(T i : f) if(!Any_of<T>(i,s)) return false;return true;}

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1); }
};
struct custom_hash {// http://xorshift.di.unimi.it/splitmix64.c
    static uint64_t splitmix64(uint64_t x) 
    {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}
    size_t operator()(uint64_t x) const 
    {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}
};

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(long long i=(a);i>=(b);i--)
#define maximum(a)            *max_element((a.begin()),(a.end()));
#define minimum(a)            *min_element((a.begin()),(a.end()));
#define _cin                  ios_base::sync_with_stdio(0);  cin.tie(0);
#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;typedef vector<ll> v;typedef vector<v> vv;typedef pair<long,long> ii;typedef vector<ii> vii;
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

unordered_map<ll,ll> memo;
ll min_ = numeric_limits<long long>::max();

void dfs(v& vis,vv& w,ll n,ll dest,ll k,ll time,v& t,ll& K){
    vis[n] = 1;cout <<n << endl;
    if(n == dest){
        cout << "Arrived dest " << k <<" "<< time << " " << (1 << (K+1))-1<< endl;
        memo[k] = time;
        for(auto i : memo)
            if((i.first | k) + 1== (1 << (K+1))-1) min_ = min(min_,max(i.second,time));
    }
    else
    for(int i = 1; i <= w[n].size();i++){
        if(vis[i] == 0 && w[n][i] != 0){
            dfs(vis,w,i,dest,k | t[i],time + w[n][i],t,K);
        }
    }
    vis[n] = 0;
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    ll n,m,k;cin>>n>>m>>k;
    v t(n+1);
    vv w(n+1,vector<ll>(n+1,0));
    REP(i,n+1){
        REP(j,n+1) cout << w[i][j] << " ";
        cout << endl;
    }REP(i,n){
        ll t1, t2,tt = 0;
        cin>>t1;
        REP(j,t1){cin>>t2; tt = tt | (1 << t2);};
        t[i+1] = tt;
    }REP(i,m){
        ll t1,t2,w1;
        cin>>t1>>t2>>w1;
        w[t1][t2] = w1;
        w[t2][t1] = w1;
    }
    v vis(n+1,0);
    dfs(vis,w,1,n,t[1],0,t,k);
    cout << min_ << endl;
    return 0;
}
