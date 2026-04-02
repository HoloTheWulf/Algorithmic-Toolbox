#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
    vector<int> minimum(m + 1, m + 1);
    vector<int> coin_values = {1, 3, 4};
    
    //base
    minimum[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int coin : coin_values) {
            if (i >= coin) {
                minimum[i] = min(minimum[i], minimum[i - coin] + 1);
            }
        }
    }
    
    return minimum[m];
}
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
