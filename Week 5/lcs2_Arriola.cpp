#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lcs2(const vector<int> &a, const vector<int> &b) {
    int x = a.size();
    int y = b.size();
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));


    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (a[i - 1] == b[j - 1]) {
                //match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                //not
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[x][y];
}

int main() {
	size_t y;
	std::cin >> y;
	vector<int> a(y);
	for (size_t i = 0; i < y; i++) { std::cin >> a[i]; }

	size_t x;
	std::cin >> x;
	vector<int> b(x);
	for (size_t i = 0; i < x; i++) { std::cin >> b[i]; }

	std::cout << lcs2(a, b) << std::endl;
}
