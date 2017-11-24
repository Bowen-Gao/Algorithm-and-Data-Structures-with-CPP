#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vector<int> optimal_sequence(int n) {
//  std::vector<int> sequence;
//  while (n >= 1) {
//    sequence.push_back(n);
//    if (n % 3 == 0) {
//      n /= 3;
//    } else if (n % 2 == 0) {
//      n /= 2;
//    } else {
//      n = n - 1;
//    }
//  }
//  reverse(sequence.begin(), sequence.end());
//  return sequence;
//}

vector<int> Optimal_sequence(int n){
	vector<int> sequence;
	int * MinNum = new int [n+1];
	MinNum[0] = -1;
	MinNum[1] = 0;
	for (int m = 2; m < (n+1); ++m){
		MinNum[m] = 2147483647;
		if (m % 3 == 0){
			int Num3 = MinNum[m/3] + 1;
		    if (Num3 < MinNum[m])
				MinNum[m] = Num3;
		}
		if (m % 2 == 0){
			int Num2 = MinNum[m/2] + 1;
			if (Num2 < MinNum[m])
				MinNum[m] = Num2;
		}
		if ( m - 1 >= 0 ) {
			int Num1 = MinNum[m-1] + 1;
			if (Num1 < MinNum[m])
				MinNum[m] = Num1;
		}
	}

	int MinStep = MinNum[n];
	sequence.push_back(n);
	MinStep = MinStep - 1;
	int i = n - 1;
	while (MinStep >= 0) {
		if (MinNum[i] == MinStep){
			sequence.push_back(i);
			MinStep -= 1;
		}
		i -= 1;
	}
	reverse(sequence.begin(), sequence.end());
    return sequence;
}


int main() {
  int n;
  cin >> n;
  vector<int> sequence = Optimal_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (int i = 0; i < sequence.size(); ++i) {
	  cout << sequence[i] << " ";
  }
	system("pause");
	return 0;
}
