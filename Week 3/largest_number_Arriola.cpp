#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string largest_number(vector<string> a) {
	string largest;
	stringstream ret;
	sort(a.begin(), a.end(), [](const string& str1, const string& str2) {
        return (str1 + str2) > (str2 + str1); 
    }
	);

    for (const string& str : a) {
        ret << str;
    }

	ret >> largest;
	return largest;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) { std::cin >> a[i]; }
	std::cout << largest_number(a);
}
