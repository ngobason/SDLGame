#include <iostream>

using namespace std;

bool palindrome(int n){
    int x = 0, y = n;
    while(n){
        x = x*10+n%10;
        n /= 10;
    }
    if(y == x) return true;
    else return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for(int i = a; i <= b; i++){
            if(palindrome(i)) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}


