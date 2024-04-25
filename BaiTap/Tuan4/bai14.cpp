#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int minVal = INT_MAX, maxVal = INT_MIN, sumEven = 0, cntOdd = 0;
    for(int i = 0; i < n; i++){
        minVal = min(a[i], minVal);
        maxVal = max(a[i], maxVal);
        if(a[i] % 2 == 0) sumEven += a[i];
        else cntOdd++;
    }
    cout << minVal << endl << maxVal << endl << sumEven << endl << cntOdd;
    return 0;
}
