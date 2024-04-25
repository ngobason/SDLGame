#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if(a == 0 || b == 0) return a+b;
    else return gcd(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    if(gcd(a, b) == 1) cout << "Yes";
    else cout << "No";
    return 0;
}
