#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool is_palindrome(char a[]) {
    int len = strlen(a);
    int i = 0;
    int j = len - 1;
    while (i < j) {
        while (!isalpha(a[i]) && i < j) {
            i++;
        }
        while (!isalpha(a[j]) && i < j) {
            j--;
        }
        char char_i = tolower(a[i]);
        char char_j = tolower(a[j]);

        if (char_i != char_j) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char a[] = "Hello, World!";
    cout << boolalpha << is_palindrome(a) << endl;
    return 0;
}

