#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long double> samplespace(n);
	for (int i = 0; i < n; ++i) {
		cin >> samplespace[i];
	}
	
	double maximum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (maximum < (samplespace[i] * samplespace[j])){
				maximum = samplespace[i] * samplespace[j];
			}
		}
	}
	cout << fixed << setprecision(0) << maximum;
}