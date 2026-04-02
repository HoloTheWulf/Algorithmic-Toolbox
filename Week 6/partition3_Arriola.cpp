#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int balanced(int target, vector<long long>& items) {
    int n = items.size();
    vector<vector<long long>> samplespace(n + 1, vector<long long>(target + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= target; w++) {
            samplespace[i][w] = samplespace[i - 1][w]; // Default: don't include the item
            
            if (items[i - 1] <= w) {
                samplespace[i][w] = max(samplespace[i][w], samplespace[i - 1][w - items[i - 1]] + items[i - 1]);
            }
        }
    }

    int result = samplespace[n][target];

    if (result != target) {
        return result;
    }

    vector<bool> tested(n, false);
    int current_w = target;
    
    for (int i = n; i > 0 && current_w > 0; i--) {
        if (samplespace[i][current_w] != samplespace[i - 1][current_w]) {
            tested[i - 1] = true;
            current_w -= items[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (tested[i]) {
            items.erase(items.begin() + i);
        }
    }

    return result;
}

bool partition3(vector<long long>& A) {
    long long total_sum = accumulate(A.begin(), A.end(), 0LL);

    if (total_sum % 3 != 0 || A.size() < 3) {
        return false;
    }

    long long target = total_sum / 3;
    
    if (*max_element(A.begin(), A.end()) > target) {
        return false;
    }

    bool set_a = (balanced(target, A) == target);
    bool set_b = (balanced(target, A) == target);
    return set_a && set_b;
}

int main() {
	int n;
	std::cin >> n;
	vector<long long> A(n);
	for (size_t i = 0; i < A.size(); ++i) { std::cin >> A[i]; }
	std::cout << partition3(A) << '\n';
	return 0;
}
