#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>

using namespace std;

struct finder {
    long long x;
    long long y;
};

double dist(const finder& a, const finder& b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Compare x, y
bool comp_x(const finder& a, const finder& b) {
    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}

bool comp_y(const finder& a, const finder& b) {
    return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
}

// Merge sorted halves
void merger(vector<finder>& points, int low, int mid, int high) {
    vector<finder> merged;
    merged.reserve(high - low + 1);
    
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (comp_y(points[i], points[j])) {
            merged.push_back(points[i++]);
        } else {
            merged.push_back(points[j++]);
        }
    }

    while (i <= mid) merged.push_back(points[i++]);
    while (j <= high) merged.push_back(points[j++]);

    for (int k = 0; k < merged.size(); ++k) {
        points[low + k] = merged[k];
    }
}

double minimal_distance(vector<finder>& points, int low, int high) {
    // zero
    if (low >= high) {
        return numeric_limits<double>::max();
    }
    
    // base
    if (high - low == 1) {
        if (!comp_y(points[low], points[high])) {
            swap(points[low], points[high]);
        }
        return dist(points[low], points[high]);
    }

    int mid = low + (high - low) / 2;
    finder mid_point = points[mid];

    double d1 = minimal_distance(points, low, mid);
    double d2 = minimal_distance(points, mid + 1, high);
    double min_d = min(d1, d2);

    merger(points, low, mid, high);

    vector<finder> strip;
    for (int i = low; i <= high; ++i) {
        if (abs(points[i].x - mid_point.x) <= min_d) {
            strip.push_back(points[i]);
        }
    }

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (j - i < 8); ++j) {
            min_d = min(min_d, dist(strip[i], strip[j]));
        }
    }

    return min_d;
}

int main() {
    size_t n;
    if (!(cin >> n)) return 0; 
    
    vector<finder> points(n);
    long long x, y;
    for (size_t i = 0; i < n; i++) {
        cin >> x >> y;
        points[i] = {x, y};
    }
    
    sort(points.begin(), points.end(), comp_x);

    cout << fixed;
    cout << setprecision(9) << minimal_distance(points, 0, static_cast<int>(points.size()) - 1) << endl;
    
    return 0;
}