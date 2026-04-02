#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int closest_stop(int max_distance, vector<int> & stops) {
	int closest = 0;
	for (int i=0; i<stops.size(); i++){
		if (stops[i] <= max_distance){
			closest = stops[i];		
		}
	}
	return closest;
}

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    
// ORGANIZES STOPS BY DISTANCE (in case distances not in order)	
//	for (int i=0; i<stops.size(); i++){
//    	for(int j=0; j<stops.size(); j++){
//    		if (stops[i] < stops[j]){
//    			swap(stops[i], stops[j]);
//			}
//		}
//	}
	
//	for (int i=0; i<stops.size(); i++){
//		cout << stops[i] << " ";	
//	}
	int refuel = 0;
	int max_distance = tank;

	if(max_distance > dist){
		return refuel;
	}
	
	for (int i=0; i<stops.size(); i++){
		int closest = closest_stop(max_distance, stops);
		if (closest > 0 && max_distance < dist){
			max_distance = closest + tank;
			refuel += 1;
			if (max_distance >= dist){
				return refuel;
			}
		}
	}

    return -1;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
