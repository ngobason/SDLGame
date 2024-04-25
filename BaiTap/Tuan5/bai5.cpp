#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(){
    map<string, int> mp;
    int q;
    cin >> q;
    while(q--){
        int x;
        string s;
        cin >> x >> s;
        if(x == 1){
            int y;
            cin >> y;
            mp[s] += y;
        }
        else if(x == 2){
            mp[s] = 0;
        }
        else{
            cout << mp[s] << endl;
        }
    }
    return 0;
}




