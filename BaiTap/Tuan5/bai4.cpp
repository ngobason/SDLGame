#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        int *pos = lower_bound(a, a+n, x);
        if(a[pos-a] == x) cout << "Yes " << pos - a + 1<< endl;
        else cout << "No " << pos - a + 1<< endl;
    }
    return 0;
}



