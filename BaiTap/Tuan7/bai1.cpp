#include <iostream>
#include <string>

using namespace std;

void reverse(char a[]) {
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    char *start = a;
    char *endd = a + length - 1;
    while (start < endd) {
        char temp = *start;
        *start = *endd;
        *endd = temp;
        start++;
        endd--;
    }
}

void delete_char(char a[], char c) {
    int i = 0, j = 0;
    while (a[i]) {
        if (a[i] != c) {
            a[j] = a[i];
            j++;
        }
        i++;
    }
    a[j] = '\0';
}

void pad_right(char a[], int n) {
    int len = strlen(a);
    if (len >= n) {
        return;
    }
    int spaces = n - len;
    for (int i = 0; i < spaces; ++i) {
        a[len + i] = ' ';
    }
    a[len + spaces] = '\0';
}

int main() {
    char arr[] = "Hello";
    reverse(arr);
    cout << arr << endl;

    char a[] = "jdfjdsnvjndvn";
    char c;
    cin >> c;
    delete_char(a, c);
    cout << a << endl;

    int n = 10;
    pad_right(arr, n);
    cout << arr << endl;
    return 0;
}

