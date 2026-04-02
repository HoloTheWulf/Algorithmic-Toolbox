#include <iostream>
using namespace std;

long long lcm_naive(long long a, long long b) {
	long long lcm = 0;

    for (long long i = 1; i < a+1 && i < b+1; i++) {
        if (a % i == 0 && b % i == 0)
            lcm = (a*b)/i;
    }
	return lcm;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
