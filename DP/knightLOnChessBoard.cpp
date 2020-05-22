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

vv arr;


int dfs(int N, int n,int m,int k,int a,int b){
    if(a == 1 and b == 2)cout <<n <<" " <<m<< endl;
    if(n >= N || n < 0 || m >= N || m < 0) return -1;
    if(alo<int>({n,m},N-1)) return k;
    if(arr[n][m]) return -1;
    arr[n][m] = 1;
    int m1 = dfs(N,n+a,m+b,k+1,a,b);
    int m2 = dfs(N,n+a,m-b,k+1,a,b);
    int m3 = dfs(N,n-a,m+b,k+1,a,b);
    int m4 = dfs(N,n-a,m-b,k+1,a,b);
    if(alo<int>({m1,m2,m3,m4},-1)) return -1;
    int min_ = INF;
    for(int i : {m1,m2,m3,m4})
        if(i != -1) min_ = min(i,min_);
    return min_;
}
void init(int n){
    v t(n,0);
    arr.clear();
    REP(i,n) arr.push_back(t);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    cout << n << endl;
    for(int i =1 ;i < n;i++){
        for(int j =1; j < n;j++){
            init(n);
            cout << dfs(n,0,0,0,i,j) << " ";
        }
        cout << endl;
    }
    return 0;
}
