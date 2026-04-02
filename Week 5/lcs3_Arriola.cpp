#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lcs3(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    int x = a.size();
    int y = b.size();
    int z = c.size();
    vector<vector<vector<int>>> samplespace(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, 0)));

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    // match
                    samplespace[i][j][k] = samplespace[i - 1][j - 1][k - 1] + 1;
                } else {
                    // not
                    samplespace[i][j][k] = max({samplespace[i - 1][j][k],samplespace[i][j - 1][k],samplespace[i][j][k - 1]});
                }
            }
        }
    }

    return samplespace[x][y][z];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) { std::cin >> a[i]; }
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) { std::cin >> b[i]; }
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) { std::cin >> c[i]; }
	std::cout << lcs3(a, b, c) << std::endl;
}
