#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M (ll)10e9+7

/*
   https://www.geeksforgeeks.org/multiply-large-integers-under-large-modulo/
   a^b = a + a + a +  ... b times
 while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
  
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
  
        b >>= 1; // b = b / 2
    }
*/

ll solve(ll a, ll b){
    ll res = 0;
    while(b != 0){
        ll t = 0;
        if(b&1) res = (res+a)%M;
        a = (a*2)%M;
        b >>= 1;
    }
    return res;
}

int main(){
    cout << solve(78,12) << endl;
}
