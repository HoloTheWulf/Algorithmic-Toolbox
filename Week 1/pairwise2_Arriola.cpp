#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	long double test = 0;
	long double first = 0;
	long double second = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> test;
		
		if (test > second){
			if (test > first){
				second = first;
				first = test;
			}
			else {
				second = test;
			}
		}
	}

	cout << fixed << setprecision(0) << first*second;
}