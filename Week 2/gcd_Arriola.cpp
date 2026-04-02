#include <iostream>
#include <algorithm>
using namespace std;

int gcd(long long first, long long second) {
	long long high = max(first, second);
	long long low = min(first, second);
	if (low == 0){
		return high;    	
	}else{
		return gcd(low, high % low);		
	}
}
int main(){
	int first, second;
	cin >> first;
	cin >> second;
	cout << gcd(first, second);
}