#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a;
    cout << a << " ";
    if(a<0){
        return 0;
    }
    int tmp = a;
    do{
        cin >> b;
        if(b!=tmp){
            cout << b << " ";
        }
        tmp = b;
    }while(b>=0);
}
