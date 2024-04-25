#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void dec_to_bin(int n){
    if(n < 2) cout << n%2;
    else{
        dec_to_bin(n/2);
        cout << n%2;
    }
}

int bin_to_dec(string s){
    int n = 0;
    for(int i = s.length()-1; i >= 0; i--){
        int x = s[i] - '0';
        n += x * pow(2, s.length()-i-1);
    }
    return n;
}

int main(){
    string s;
    cin >> s;
    cout << bin_to_dec(s) << endl;
    int n;
    cin >> n;
    dec_to_bin(n);
    return 0;
}
