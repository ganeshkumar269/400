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
    std::size_t operator() (const std::pair<T1, T2> &pair) const{
    return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1); 
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
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
typedef long long ll;
typedef vector<ll> v;
typedef vector<v> vv;
typedef pair<long,long> ii;
typedef vector<ii> vii;
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
int vis[1000][1000] = {{0}};

pair<int,bool> dfs(vector<string> arr,int N,int M,int n,int m, ii F,int& k){
    // cout <<"CurrentPos:" << n << " "<< m << endl;
    if(ano<int>(n,{-1,N}) || ano<int>(m,{-1,M})) return {0,false};
    if(vis[n][m]) return {0,false};
    if(arr[n][m] == 'X') return {0,false};
    vis[n][m] = 1;
    int ways = 0;
    if( n == F.first && m == F.second) return {1,true};
    auto m1 = dfs(arr,N,M,n+1,m,F,k);
    auto m2 = dfs(arr,N,M,n-1,m,F,k);
    auto m3 = dfs(arr,N,M,n,m+1,F,k);
    auto m4 = dfs(arr,N,M,n,m-1,F,k);

    if(m1.first == 1) ways++;
    if(m2.first == 1) ways++;
    if(m3.first == 1) ways++;
    if(m4.first == 1) ways++;

    if(anoano<bool>({m1.second,m2.second,m3.second,m4.second},{true})){
        if(ways > 1) {cout << n << " " << m << endl;k++;}
        return {1,true};
    }
    return {1,false};
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        vector<string> arr;
        cin>>n>>m;
        REP(i,n)REP(j,m)vis[i][j]=0;
        string tmp;
        REP(i,n) {cin>>tmp; arr.push_back(tmp);}
        cin>>k;
        // REP(i,n) cout << arr[i] << endl;
        ii star,M;
        REP(i,n)REP(j,m){
            if(arr[i][j] == '*') M = {i,j};
            if(arr[i][j] == 'M') star={i,j};
        }
        int k_ = 0;
        // cout << star.first << " " << star.second << " " << M.first << " " << M.second << endl;
        dfs(arr,n,m,star.first,star.second,M,k_);
        cout << ((k == k_) ? "Impressed" : "Oopss")<< endl;
    }
    return 0;
}
