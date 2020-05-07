#include <bits/stdc++.h>
using namespace std; 
struct pair_hash
{
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
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
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

void countSort(vector<vector<string>> arr) {
    for(long i =0 ;i < arr.size()/2;i++) arr[i][1] = "-";
    long max_ = -1;
    for(long i = 0; i < arr.size();i++) max_ = max(max_,stol(arr[i][0]));
    vector<long> t(max_+1,0);
    for(long i =0;i<arr.size();i++) t[stol(arr[i][0])]++;
    for(long i =1;i<t.size();i++) t[i] += t[i-1];
    REP(i,t.size()) cerr << t[i] << " ";
    cout << endl;
    vector<string> res(arr.size()+10);
    for(long i=0;i<arr.size();i++){
        res[t[stol(arr[i][0])-1]++] = arr[i][1];
    }
    for(long i =0 ;i < arr.size();i++)cout << res[i] << " ";
    cout << endl;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    long n;
    cin>>n;
    vector<vector<string>> t;
    REP(i,n){
        string t1,t2;
        cin>>t1>>t2;
        t.push_back({t1,t2});
    }
    countSort(t);
    return 0;
}
