#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment>& segments) {
    vector<int> points;
    if (segments.empty()) return points;
	//sorting
    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.end < b.end;
    });

    int current = segments[0].end;
    points.push_back(current);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (current < segments[i].start) {
            current = segments[i].end;
            points.push_back(current);
        }
    }

    return points;
}
int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
