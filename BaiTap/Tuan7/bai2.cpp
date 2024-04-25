#include <iostream>
#include <cstring>

using namespace std;

void truncate(char a[], int n) {
    int len = strlen(a);
    if (len <= n) {
        return;
    }
    a[n] = '\0';
}

int main() {
    char arr[] = "Hello, World!";
    int n = 5;
    truncate(arr, n);
    cout << arr << endl;

    return 0;
}

