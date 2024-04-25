#include <iostream>
#include <vector>

using namespace std;

void xoanOc(int x, int y) {
    vector<vector<int>> matrix(x, vector<int>(y));

    int num = 1;
    int top = 0, bottom = x - 1, left = 0, right = y - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    xoanOc(x, y);

    return 0;
}
