#include <iostream>
#include <cstring>

using namespace std;

char* concat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char* res = new char[len1 + len2 + 1];

    strcpy(res, str1);

    strcat(res, str2);

    return res;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "World";

    char* res = concat(str1, str2);
    cout << res << endl;
    delete[] res;

    return 0;
}

