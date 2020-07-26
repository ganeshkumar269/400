#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <limits>
#include <algorithm>
//https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/
//When given a string and a list of patterns  , to find the all the occurances of the patterns in the string this algorithm is used
using namespace std;
#define ll long long
#define rep(i,n) for(ll i =0;i < n;i++)
const ll maxa = 26;
const  ll maxs = 200002;
vector<unordered_set<ll>> out;
vector<ll> f;
vector<vector<ll>> Goto;

ll buildAutomaton(vector<string>& p){
    //build goto array
    ll total=0 ;
    for(ll i =0 ;i < p.size();i++) total += p[i].size();
    out.resize(total);
    f.resize(total);
    fill_n(f.begin(),total,-1);
    f[0] = 0;
    Goto.resize(total);
    fill_n(Goto.begin(),total,vector<ll>(26,-1));
    ll states = 0;
    cerr << "Goto Array Start" << endl;
    rep(i,p.size()){
        ll currentState = 0;
        string& word = p[i];
        for(char j : word){
            // cerr << currentState << " ";
            if(Goto[currentState][j-'a'] == -1)
                Goto[currentState][j-'a'] = ++states;
            currentState = Goto[currentState][j-'a'];
        }
        out[currentState].insert(i);
    }    
    cerr << "Goto Array Over" << endl;
    //building failure array
    rep(i,26)
        if(Goto[0][i] == -1) Goto[0][i]=0;
    queue<ll> q;
    rep(i,26)
        if(Goto[0][i] != 0){
            f[Goto[0][i]]= 0;
            q.push(Goto[0][i]);
        }
    cerr << "Starting Failure Function" << endl;
    while(!q.empty()){
        ll state = q.front(); 
        q.pop();
        rep(j,26){
            if(Goto[state][j] != -1){
                ll failure = f[state];
                while(Goto[failure][j] == -1)failure = f[failure];
                failure = Goto[failure][j];
                f[Goto[state][j]] = failure;
                for(ll k : out[failure])
                    out[Goto[state][j]].insert(k);
                q.push(Goto[state][j]);
            }
        }
    }
    return states;
}

ll findNextState(ll currState,char ch){
    // cerr << "findNextState " << currState << " " << ch << endl;
    ll ans = currState;
    ll i = ch-'a';
    while(Goto[ans][i] == -1) ans = f[ans];
    return Goto[ans][i];
}

int main(){
    freopen("in.txt","r",stdin);
    ll n;cin>>n;
    vector<ll> h(n);
    vector<string> p(n);
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>h[i];
    ll d;cin>>d;
    ll states = buildAutomaton(p);
    cerr  << "Build Complete, states " << states << endl;
    ll max_ = -1;
    ll min_ = numeric_limits<ll>::max();
    while(d--){
        ll l,r;cin>>l>>r;
        string strand; cin>>strand;
        // cerr << l << " " << r << " "<< strand << endl;
        ll val = 0;
        ll it =0;ll currState = 0;
        while(it < strand.size()){
            it++;
            currState = findNextState(currState,strand[it-1]);
            if(out[currState].size() == 0) continue;
            for(ll j : out[currState]){
                if(j >= l && j <= r)
                val += h[j];
                // cout << p[j] << " found at " << it-p[j].size() << endl;
            }
        }
        min_=min(min_,val);
        max_ = max(max_,val);
    }
    cout << min_  << " " << max_ << endl;
    // cout << "Build finish" << endl;
    // rep(i,states){
    //     rep(j,26)
    //         cout << Goto[i][j] << " ";
    //     cout << endl;
    // }
    // cout << "failure array" << endl;
    // rep(i,states+1)cout << f[i] << " ";
    // cout << endl;
    
    return 0;
}