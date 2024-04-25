#include <iostream>

using namespace std;

int cnt[10];

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 0; i < 10; i++){
        cout << i << " " << cnt[i] << endl;
    }
    return 0;
}

