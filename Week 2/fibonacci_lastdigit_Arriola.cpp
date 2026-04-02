#include <iostream>
#include <cassert>

using namespace std;

int fibonacci_lastdigit(int n) {

    long a = 1;
    long b = 0;
    long buffer = 0;

    if (n <= 1){
    	return n;	
	}

    for (int i = 0; i < (n - 1); i++) {
        buffer = b;
        b = a;
        a = (buffer + a)%10;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci_lastdigit(n);
}

