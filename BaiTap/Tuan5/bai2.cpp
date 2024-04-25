#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int x, a, b;
    cin >> x >> a >> b;
    v.erase(v.begin()+x);
    v.erase(v.begin()+a-1, v.begin()+b-1);
    cout << v.size() << endl;
    for(int x : v) cout << x << " ";
    return 0;
}

