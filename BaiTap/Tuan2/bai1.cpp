#include <bits/stdc++.h>

using namespace std;

int Prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return n > 1;
}

int main(){
    int n;
    cin >> n;
    if(Prime(n)) cout << "yes";
    else cout << "no";
    return 0;
}
