#include <iostream>
#include <vector>

using namespace std;


int counter(const vector<long>& a, int left, int right, long target) {
    int count = 0;
    for (int i = left; i <= right; ++i) {
        if (a[i] == target) {
            count++;
        }
    }
    return count;
}

long get_majority_element(const vector<long> &a, int left, int right) {
    int n = right - left + 1;
    int mid = left + (right - left) / 2;
	
    // base
    if (left == right) {
        return a[left];
    }

    // div
    long left_big = get_majority_element(a, left, mid);
    long right_big = get_majority_element(a, mid + 1, right);

    // same
    if (left_big == right_big) {
        return left_big;
    }

    // not
    int left_count = counter(a, left, right, left_big);
    int right_count = counter(a, left, right, right_big);

    if (left_count > n / 2) return left_big;
    if (right_count > n / 2) return right_big;

  
    return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<long> a(n);
	for (size_t i = 0; i < a.size(); ++i) { std::cin >> a[i]; }
	std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
