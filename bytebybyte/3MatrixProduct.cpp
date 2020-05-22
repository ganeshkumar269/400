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

unordered_map<ii,long,pair_hash> mem;

ll solve(vv arr,int n,int m){
    if(mem.find({n,m}) != mem.end()) return mem[{n,m}];
    if(n == 0 and m == 0) return mem[{0,0}] = arr[0][0];
    ll t1 = n == 0 ? -1 : arr[n][m]*solve(arr,n-1,m);
    ll t2 = m == 0 ? -1 : arr[n][m]*solve(arr,n,m-1);
    ll res = n == 0 ? t2 : max(t1,t2);
    if(n == 0) res = t2;
    else if(m == 0) res = t1;
    else res = max(t1,t2);
    return mem[{n,m}] = res;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int m,n,t;
    cin>>n>>m;
    vv arr(n);
    REP(i,n) REP(j,m) cin>>t , arr[i].push_back(t); 
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++)        
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << solve(arr,n-1,m-1) << endl;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++)        
            cout << mem[{i,j}] << " ";
        cout << endl;
    }
    return 0;
}
