#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se;
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if(x == 1){
            se.insert(y);
        }
        else if(x == 2){
            if(se.find(y) != se.end()) se.erase(y);
        }
        else{
            if(se.find(y) != se.end()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}


