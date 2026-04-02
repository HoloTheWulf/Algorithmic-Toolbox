#include <iostream>
#include <vector>

using namespace std;


long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
    long long counter = 0;
    int mid = left + (right - left) / 2;
    
    // base
    if (right <= left + 1) {
        return 0;
    }

    counter += get_number_of_inversions(a, b, left, mid);
    counter += get_number_of_inversions(a, b, mid, right);

    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            counter += (mid - i);
        }
    }

    while (i < mid) {
        b[k++] = a[i++];
    }
    while (j < right) {
        b[k++] = a[j++];
    }

    for (int index = left; index < right; index++) {
        a[index] = b[index];
    }

    return counter;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) { std::cin >> a[i]; }
	vector<int> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
