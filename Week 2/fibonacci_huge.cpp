#include <iostream>
#include <cassert>

using namespace std;

int fibonacci_huge(int n, int m) {

    long a = 1;
    long b = 0;
    long buffer = 0;

    if (n <= 1){
    	return n;	
	}

    for (int i = 0; i < (n - 1); i++) {
        buffer = b;
        b = a;
        a = (buffer + a)%m;
    }
    return a;
}

int main() {
    int n, m = 0;
    cin >> n;
    cin >> m;
    cout << fibonacci_huge(n,m);
}

