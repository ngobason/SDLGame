#include <iostream>

using namespace std;

bool palindrome(string s){
    int l = 0, r = s.length()-1;
    while(l < r){
        if(s[l] != s[r]) return false;
        else{
            l++;
            r--;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(palindrome(s)) cout << "YES";
    else cout << "NO";
    return 0;
}

