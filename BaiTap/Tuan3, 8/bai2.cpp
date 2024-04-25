#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Rect {
    int x;
    int y;
    int w;
    int h;

    bool contains(const Point& p) const {
        return (p.x >= x && p.x <= x + w && p.y >= y && p.y <= y + h);
    }
};

int main() {
    Rect rect = {2, 2, 5, 5};
    Point point_inside = {4, 4};
    Point point_outside = {8, 8};

    cout << boolalpha << rect.contains(point_inside) << endl;
    cout << boolalpha << rect.contains(point_outside) << endl;

    return 0;
}

