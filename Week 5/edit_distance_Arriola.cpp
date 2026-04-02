#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int a = str1.size();
    int b = str2.size();
    vector<vector<int>> distance(a + 1, vector<int>(b + 1));
    
    for (int i = 0; i <= a; ++i) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= b; ++j) {
        distance[0][j] = j;
    }

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = min({
                    distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + 1});
            }
        }
    }

    return distance[a][b];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
