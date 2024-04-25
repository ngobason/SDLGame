#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i+j <= n+1) cout << i + j - 1 << " ";
            else{
                cout << j-n+i-1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

