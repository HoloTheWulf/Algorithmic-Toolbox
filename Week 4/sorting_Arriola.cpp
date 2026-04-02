#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

std::pair<int, int> partition3(vector<int> &a, int left, int right) {
    int pivot = a[left];
    int left_1 = left;
    int right_1 = right; 
    int i = left;   

    while (i <= right_1) {
        if (a[i] < pivot) {
            swap(a[i], a[left_1]);
            left_1++;
            i++;
        } else if (a[i] > pivot) {
            swap(a[i], a[right_1]);
            right_1--; 

        } else {
            i++;
        }
    }
    
    // middle
    return {left_1, right_1};
}

void randomized_quick_sort(vector<int> &a, int left, int right) {
    if (left >= right) {
        return;
    }

    // random pivot
    int k = left + rand() % (right - left + 1);
    swap(a[left], a[k]);

    // slice array
    auto m = partition3(a, left, right);

    // Recursive sort
    randomized_quick_sort(a, left, m.first - 1);
    randomized_quick_sort(a, m.second + 1, right);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) { std::cin >> a[i]; }
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) { std::cout << a[i] << ' '; }
}
