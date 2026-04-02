#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int n, int W, const vector<int> &w) {
    vector<vector<int>> samplespace(n + 1, vector<int>(W + 1));
	int maximum = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            int left = 0;
            int right = 0;
            if (i == 0 || j == 0){
                samplespace[i][j] = 0;
                continue;            		
			}
            if(w[i - 1] <= j){
                left = samplespace[i - 1][j - w[i - 1]] + w[i - 1];
			}
            right = samplespace[i - 1][j];
			samplespace[i][j] = max(left, right);            	
        }
    }
    maximum = samplespace[n][W];
    return maximum;
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) { std::cin >> w[i]; }
	std::cout << optimal_weight(n, W, w) << '\n';
}