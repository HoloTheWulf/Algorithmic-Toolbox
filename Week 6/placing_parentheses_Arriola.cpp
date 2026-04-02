#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

long long signs(long long a, long long b, char op) {
    if (op == '*') return a * b;
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    assert(0);
}

long long get_maximum_value(const string &exp) {
    vector<long long> nums;
    vector<char> ops;
    for (size_t i = 0; i < exp.size(); i++) {
        if (i % 2 == 0) nums.push_back(exp[i] - '0');
        else ops.push_back(exp[i]);
    }

    int n = nums.size();


    vector<vector<long long>> min_size(n, vector<long long>(n, 0));
    vector<vector<long long>> max_size(n, vector<long long>(n, 0));


    for (int i = 0; i < n; i++) {
        min_size[i][i] = nums[i];
        max_size[i][i] = nums[i];
    }

    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            
            long long min_val = numeric_limits<long long>::max();
            long long max_val = numeric_limits<long long>::min();

            for (int k = i; k < j; k++) {  
                
                long long a = signs(max_size[i][k], max_size[k + 1][j], ops[k]);
                long long b = signs(max_size[i][k], min_size[k + 1][j], ops[k]);
                long long c = signs(min_size[i][k], max_size[k + 1][j], ops[k]);
                long long d = signs(min_size[i][k], min_size[k + 1][j], ops[k]);

                // Update our temporary min and max
                min_val = min({min_val, a, b, c, d});
                max_val = max({max_val, a, b, c, d});
            }
            
            min_size[i][j] = min_val;
            max_size[i][j] = max_val;
        }
    }


    return max_size[0][n - 1];
}

int main() {
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}
