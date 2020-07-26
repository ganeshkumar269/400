#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1); }
};
unordered_map<pair<int,int>,int,pair_hash> memo;
//recursive
int lps(int l,int r,string& s){
    int res;
    cerr << l << " " << r << endl;
    if(memo.find({l,r}) != memo.end()) return memo[{l,r}];
    if(l == r) res=1;
    else if(s[l] == s[r]){
        if(r-l == 1) res = 2;
        else res = lps(l+1,r-1,s)+2;
    }
    else res = max(lps(l+1,r,s),lps(l,r-1,s)); 
    memo[{l,r}] = res;
    return res;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stderr);
    string s;
    cin>>s;int n = s.size();
    //recursive
    // lps(0,s.size()-1,s);
    // int max_ = -1;
    // for(int i = 0; i <s.size()-1;i++)
    //     max_ = max(max_,lps(0,i,s)*lps(i+1,s.size()-1,s));
    // cout << max_ << endl;
    vector<vector<int,int>> m(n+1,vector<int>(n+1));
    for(int i = 0;i < n;i++)
    for(int j = i;j < n;j++){
        int res;
        if(i == j) res = 1;
        else if(s[i] == s[j]){
            if(j-i == 1) res = 2;
            else res = m[i-1][j-1];
        }else res = max(m[i])
    }
    return 0;
}