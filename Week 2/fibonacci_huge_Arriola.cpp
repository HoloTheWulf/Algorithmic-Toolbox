#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge(long long n, long long m) {
    vector<long long> samplespace{0, 1};
    if (n <= 1) return n;

    while (true) {

        int size = samplespace.size();
        long long next = (samplespace[size - 1] + samplespace[size - 2]) % m;
        samplespace.push_back(next);

        if (samplespace[samplespace.size() - 2] == 0 && samplespace[samplespace.size() - 1] == 1) {
            samplespace.pop_back();
            samplespace.pop_back();
            break;
        }
    }

    return samplespace[n % samplespace.size()];
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	// std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge(n, m) << '\n';
}
