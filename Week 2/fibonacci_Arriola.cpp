#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_fast(int n) {
	if (n <=1){
		return n;
	}
    
    vector<long> nth(n + 1);
    nth[0] = 0; nth[1] = 1;

    for (int i = 2; i <= n; i++) {
        nth[i] = nth[i - 1] + nth[i - 2];
    }
    return nth[n];
}


int main() {
    long n = 0;
    cin >> n;

    cout << fibonacci_fast(n);

}
