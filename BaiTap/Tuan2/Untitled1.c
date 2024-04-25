#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ChiaDu(ll n){
    if(n==2 || n==8) return 1;
    else{
        ll f1 = 2, f2 = 8, fn;
        ll mod = 1000000007;
        for(int i = 3; i <= n; i++){
            f1%=mod;
            f2%=mod;
            fn = (2*f1)%mod + (8*f2)%mod;
            fn%=mod;
            f2 = f1;
            f1 = fn;
        }
        return fn;
    }
}

int main(){
    ll n;
    cin >> n;
    cout << ChiaDu(n);
    return 0;
}
