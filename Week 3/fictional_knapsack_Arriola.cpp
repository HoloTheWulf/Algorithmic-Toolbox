#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	long remaining = capacity;
	
	for (int i=0; i<values.size();i++){
		for (int j=0; j<values.size();j++){
			if (values[i]/weights[i] > values[j]/weights[j]){
				swap(values[i], values[j]);
				swap(weights[i], weights[j]);
			}
		}
	}
	//DEBUG SORT BY VALUE PER WEIGHT
//	for (int i=0; i<values.size();i++){
//		cout << values[i] << " " << weights[i] << endl;
//	}
	for (int i=0; i<values.size();i++){
		if(remaining > 0){
			if(weights[i] < remaining){
				remaining -= weights[i];
				value += values[i];
				//cout << "IF CLAUSE. " << "New value: " << value << " Remaining weight: " << remaining <<endl;
			}else{
				//double fractional = static_cast<double>(remaining/weights[i]);
				//cout << "FRACTIONAL " << fractional << endl;
				value += static_cast<double>(values[i]*remaining)/weights[i];
				//cout << "ADDED VALUE " << static_cast<double>(values[i]*fractional) << endl;
				remaining = 0;
				//cout << "ELSE CLAUSE. " << "New value: " << value << " Remaining weight: " << remaining << endl;
			}
		}else{
			return value;
		}
	}	
	
	
	return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}