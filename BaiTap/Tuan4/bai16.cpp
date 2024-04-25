#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<vector<int>> Pascal(int n) {
    vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        triangle[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
    }
    return triangle;
}

void in(int n) {
    vector<vector<int>> triangle = Pascal(n);
    int max_length = to_string(triangle[n][n / 2]).length();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << setw(max_length) << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    in(n);
    return 0;
}

