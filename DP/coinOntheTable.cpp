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
vector<vector<pair<int,int>>> mem;
vector<vector<int>> vis;

pair<int,int> dfs(vector<string> board,int N,int M,int k,int n,int m){
    if(n < 0 || n >= N || m < 0 || m >= M) return {-1,-1};
    cerr << n << " " << m << endl;
    if(board[n][m] =='*'){
        vis[n][m] = 1;
        return {0,0};
    }
    if(vis[n][m])
        return  mem[n][m];
    vis[n][m] = 1;
    auto m1 = dfs(board,N,M,k,n-1,m);
    auto m2 = dfs(board,N,M,k,n+1,m);
    auto m3 = dfs(board,N,M,k,n,m-1);
    auto m4 = dfs(board,N,M,k,n,m+1);
    // cerr <<n <<" " << m << " " << m1 << " " << m2 << " " << m3 << " " <<m4 << endl;

   


    if(m1.first == -1 && m2.first == -1 && m3.first == -1 && m4.first == -1 )
        return mem[n][m] = {-1,-1};

    int min_ = numeric_limits<int>::max();
    int d = -1;
    if(m1.first != -1 && board[n][m] != 'U') m1.first++;
    if(m2.first != -1 && board[n][m] != 'D') m2.first++;
    if(m3.first != -1 && board[n][m] != 'L') m3.first++;
    if(m4.first != -1 && board[n][m] != 'R') m4.first++;
    for(auto i : {m1,m2,m3,m4})
        if(i.first != - 1 && i.first < min_ && i.second < k){
            min_ = i.first;
            d = i.second;
        }
    return mem[n][m] = {min_,d+1};
}


int coinOnTheTable(int m, int k, vector<string> board) {
    int n = board.size();
    vector<int> t(m,0);
    vector<pair<int,int>> t2(m,{-1,-1});
    for(int i = 0; i < n;i++){
        mem.push_back(t2);
        vis.push_back(t);
    }
    dfs(board,board.size(),m,k,0,0);
    for(int i =0 ; i < n;i++){
        for(int j = 0; j < m;j++)
            cerr << mem[i][j].first << " ";
        cerr << endl;
    }
    for(int i =0 ; i < n;i++){
        for(int j = 0; j < m;j++)
            cerr << vis[i][j] << " ";
        cerr << endl;
    }
    return mem[0][0].first;
}




int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int n,m,k;cin>>n>>m >> k;
    vector<string> arr;
    REP(i,n){
        string t;
        cin>>t;
        arr.push_back(t);
    }
    cout << coinOnTheTable(m,k,arr) << endl;
    return 0;
}
