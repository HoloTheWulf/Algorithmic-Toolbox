#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int left, int right, int x) {
    int mid = left + (right - left) / 2;
    
    // base
    if (left > right) {
        return -1;
    }

    if (a[mid] == x) {
        return mid;
    } else if (a[mid] > x) {
        // left
        return binary_search(a, left, mid - 1, x);
    } else {
        // right
        return binary_search(a, mid + 1, right, x);
    }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout <<  binary_search(a, 0, a.size() - 1, b[i]) << ' ';
  }
}
