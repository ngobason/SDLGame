#include <iostream>
#include <vector>

using namespace std;

void MagicSquare(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));

    int num = 1;
    int row = 0, col = n / 2;

    while (num <= n * n) {
        v[row][col] = num;

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (v[nextRow][nextCol] == 0) {
            row = nextRow;
            col = nextCol;
        }
        else {
            row = (row + 1) % n;
        }

        num++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    MagicSquare(N);

    return 0;
}

