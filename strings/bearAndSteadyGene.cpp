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

int solve(string gene) {
    int n=gene.size();
    int ca=-n/4,cc=-n/4,ct=-n/4,cg=-n/4;
    for(char i : gene){
        switch(i){
            case 'A': ca++;break;
            case 'C': cc++;break;
            case 'T': ct++;break;
            case 'G': cg++;break;
        }
    }
    vv m;
    v t(5,0);
    REP(i,n) m.push_back(t);
    REP(i,n){
        m[i] = t;
        switch(gene[i]){
            case 'A': m[i][0]++;break;
            case 'C': m[i][1]++;break;
            case 'T': m[i][2]++;break;
            case 'G': m[i][3]++;break;
        }
        t = m[i];
    }


    if(ca <= 0) ca = 0;  
    if(cc <= 0) cc = 0;  
    if(ct <= 0) ct = 0;  
    if(cg <= 0) cg = 0;  

    int min_ = numeric_limits<int>::max();
    int low = 0 , high = n-1;
    while(low < high){
        if(high[])
    }


    // for(int i =0;i<n;i++)
    // for(int j =i+1 ;j<n;j++){
    //     bool flag = true;
    //     if(ca > 0){
    //         if(i == 0){
    //             if(ca != m[j][0]) flag = false;
    //         }else {
    //             if(ca != m[j][0] - m[i-1][0])flag = false;
    //         }
    //     }
    //     if(cc > 0){
    //         if(i == 0){
    //             if(cc != m[j][1]) flag = false;
    //         }
    //         else {
    //             if(cc != m[j][1] - m[i-1][1])flag = false;
    //         }
    //     }if(ct > 0){
    //         if(i == 0){
    //             if(ct != m[j][2]) flag = false;
    //         }else {
    //             if(ct != m[j][2] - m[i-1][2])flag = false;
    //         }
    //     }if(cg > 0){
    //         if(i == 0){
    //             if(cg != m[j][3]) flag = false;
    //         }else {
    //             if(cg != m[j][3] - m[i-1][3])flag = false;
    //         }
    //     }
    //     if(flag)
    //         min_ = min(min_,j-i+1);
    // }
    return min_;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    ll n;
    cin>>n;
    string s;
    cin>>s;
    cout << solve(s) << endl;
    return 0;
}
