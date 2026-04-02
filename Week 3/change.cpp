#include <iostream>
using namespace std;


int get_change(long long m) {
  int coins = 0;

	if(m >= 10){
  		coins += m/10;
  		m = m%10;
	}

  	if(m >= 5){
  		coins += m/5;
  		m = m%5;
	}

	coins += m;
	return coins;
}

int main() {
  long long m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
