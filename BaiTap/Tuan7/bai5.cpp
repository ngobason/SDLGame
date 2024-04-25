#include <iostream>
#include <cstring>

using namespace std;

void trim_right(char a[]) {
    int len = strlen(a);
    int end = len - 1;
    while (end >= 0 && isspace(a[end])) {
        end--;
    }
    a[end + 1] = '\0';
}

int main() {
    char a[] = "Hello, World!   ";
    trim_right(a);
    cout << a << "/" << endl;

    return 0;
}

