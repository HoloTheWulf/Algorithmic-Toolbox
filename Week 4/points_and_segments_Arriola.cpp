#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Cleanliness is nice
enum flag_Type {
    START = 0,
    SELECTION = 1,
    END = 2
};

struct Event {
    int coordinate;
    flag_Type type;

    bool operator<(const Event& other) const {
        if (coordinate == other.coordinate) {
            return type < other.type; 
        }
        return coordinate < other.coordinate;
    }
};


vector<int> fast_count_segments(const vector<pair<int, int>>& ranges, const vector<int>& points) {
    vector<int> cnt(points.size());
    vector<Event> events;
    unordered_map<int, int> counter;
	
    events.reserve(ranges.size() * 2 + points.size());

    for (const auto& range : ranges) {
        events.push_back({range.first, START});
        events.push_back({range.second, END});
    }
    for (int p : points) {
        events.push_back({p, SELECTION});
    }

	// sort
    sort(events.begin(), events.end());

    // count
    int current_segments = 0;
    for (const auto& event : events) {
        if (event.type == START) {
            current_segments++;
        } else if (event.type == END) {
            current_segments--;
        } else if (event.type == SELECTION) {
            counter[event.coordinate] = current_segments;
        }
    }

    for (size_t i = 0; i < points.size(); i++) {
        cnt[i] = counter[points[i]];
    }

    return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	vector<std::pair<int, int>> ranges;
	ranges.reserve(n);
	int start, end;
	for (size_t i = 0; i < n; i++) {
		std::cin >> start >> end;
		if (start <= end) ranges.push_back(make_pair(start, end));
	}

	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) { std::cin >> points[i]; }

	auto cnt1 = fast_count_segments(ranges, points);

	for (size_t i = 0; i < cnt1.size(); i++) { cout << cnt1[i] << " "; }
}
