#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    bool found = false;
    for(pair<int, int> p : mp){
        if(p.second >= 2){
            cout << "YES";
            found = true;
            break;
        }
    }
    if(!found) cout << "NO";
    return 0;
}
