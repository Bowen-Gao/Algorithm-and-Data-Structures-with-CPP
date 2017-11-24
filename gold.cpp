#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int Optimal_W(int W, const vector<int> &w){
	int j = w.size();
	int **value = new int*[W+1];
	for (int i = 0; i < (W+1); ++i ){
		value[i] = new int[j+1];
	}
	for (int i = 0; i < (W+1); ++i){
		value[i][0] = 0;}
	for (int i = 0; i <(j+1); ++i){
		value[0][i] = 0;}

	for (int i = 1; i < (j+1); ++i){
		for (int u = 1; u < (W+1); ++u){
			value[u][i] = value[u][i-1];
			if (!(w[i-1] > u)){
				int val = value[u-w[i-1]][i-1] + w[i-1];
				if (val > value[u][i])
					value[u][i] = val;
			}
		}
	}
	int outcome = value[W][j];
	//for (int m = 0; m < (j+1); ++m){
	//	delete[] value[m];
	//}
	//delete[] value;
	return outcome;
}


int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << Optimal_W(W, w) << '\n';
  system("pause");
  return 0;
}
