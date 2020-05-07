#include <bits/stdc++.h>
using namespace std; 
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
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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

string organizingContainers(vector<vector<long long>>& container) {
    if(container.size() == 0) return string("Possible");
    unordered_map<ll ,ll> row_sum;ll sum = 0;
    for(auto i : container) sum = accumulate(i.begin(),i.end(),(ll)0) ,row_sum[sum]++;
    // for(auto i : row_sum) cout << i.first <<" "<< i.second << endl;
    for(int i =0 ;i < container[0].size(); i++){
        long long sum =0 ;
        for(int j = 0; j < container.size(); j++){
            sum+=container[j][i];
        }
        if(row_sum[sum] > 0 ) row_sum[sum]--;
        else return string("Impossible");
    }
    // for(auto i : row_sum) cout << i.first <<" "<< i.second << endl;
    return string("Possible");
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int q;
    cin>>q;
    while(q--){
        long n;
        cin>>n;
        vv m;
        REP(i,n){
            v t;
            long a;
            REP(i,n)cin>>a , t.push_back(a);
            m.push_back(t);
        }
        cout << organizingContainers(m) << endl;
    }
    return 0;
}