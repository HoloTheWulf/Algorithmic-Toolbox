#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> optimal_sequence(int n) {
    vector<int> dp(n + 1);
    vector<int> sequence; 
    
    for (int i = 2; i <= n; i++) {
        // Base
        dp[i] = dp[i - 1] + 1;
        

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    while (n > 1) {
        sequence.push_back(n);
        
        if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) {
            n /= 3;
        } else if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) {
            n /= 2;
        } else {
            n -= 1;
        }
    }
    sequence.push_back(1);
    reverse(sequence.begin(), sequence.end());
    
    return sequence;
}

int main() {
	int n;
	std::cin >> n;
	// cout << optimal_sequence(n) << endl;

	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}
