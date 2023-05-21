#include <iostream>
#include <climits>

using namespace std;

// Structure to represent a point on the plane
struct Point {
    int x, y;
};

// Function to calculate the squared distance between two points
long long calcDistance(const Point& p1, const Point& p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

// Function to find the closest pair of points
long long closestPair(Point coordinates[], int n) {
    long long minDist = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dist = calcDistance(coordinates[i], coordinates[j]);
            minDist = min(minDist, dist);
        }
    }

    return minDist;
}

// Driver code
int main() {
    // Points on a plane P[i] = {x, y}
    Point P[] = {{1, 2}, {2, 3}, {3, 4}, {5, 6}, {2, 1}};
    int n = sizeof(P) / sizeof(P[0]);

    // Function call
    cout << "The smallest distance is " << closestPair(P, n);

    return 0;
}
