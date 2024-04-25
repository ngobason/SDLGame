#include <iostream>
#include <cstring>

using namespace std;

void trim_left(char a[]) {
    int len = strlen(a);
    int start = 0;
    while (a[start] != '\0' && isspace(a[start])) {
        start++;
    }
    for (int i = start; i <= len; ++i) {
        a[i - start] = a[i];
    }
}

int main() {
    char a[] = "  Hello, World!";
    trim_left(a);
    cout << a << endl;

    return 0;
}

