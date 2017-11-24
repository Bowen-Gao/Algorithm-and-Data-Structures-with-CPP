#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double> vw(n);

  for (int i = 0; i < n; ++i){
	  vw[i] = (double) values[i] / weights[i];}

  for (int i = 0; i < n; ++i){
	  if (capacity == 0)
		  break;
	  double max = 0.0;
	  int index = -1;
	  for (int i = 0; i < n; ++i){
		  if (weights[i] > 0 && vw[i] > max){
			  max = vw[i];
		      index = i;}
	  }
	  int add = min(weights[index], capacity);
	  value += add * max;
	  weights[index] -= add;
	  capacity -= add;
  }
  return value;
}

int main() {
  static int n;
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
