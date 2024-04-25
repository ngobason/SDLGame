#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (a[i] * (n-i-1));
    }
    cout << sum;
    return 0;
}
