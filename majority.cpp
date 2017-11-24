#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int> &B, vector<int> &C){
	vector<int> D;
	vector<int>::iterator b = B.begin();
	vector<int>::iterator c = C.begin();
	vector<int>::iterator d = D.begin();;
	while (b != B.end() && c != C.end()){
		if (*b <= *c){
			D.push_back(*b);
			b++;
		}else{
			D.push_back(*c);
			c++;
		}
	}
	while (b != B.end()){
		D.push_back(*b);
		b++;
	}
	while (c != C.end()){
		D.push_back(*c);
		c++;
	}
	return D;
}

vector<int> MergeSort(vector<int> &A){
	if (A.size() == 1)
		return A;
	int m = (int)A.size() / 2;
	vector<int> A1;
	for (int i = 0; i < m; ++i){
		A1.push_back(A[i]);}
	vector<int> B = MergeSort(A1);
	vector<int> A2;
	for (int i = m; i < A.size(); ++i){
		A2.push_back(A[i]);}
	vector<int> C = MergeSort(A2);
	vector<int> APrime = Merge(B, C);
	return APrime;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return 1;
  //write your code here
  vector<int> SortedA = MergeSort(a);
  double majority = (double)a.size()/2;
  int tmp = SortedA[0];
  int max = 1;
  int times = 1;
  for (int i = 1; i < SortedA.size(); ++i){
	  if (SortedA[i] == tmp){
		  times = times + 1;
	  }else{
		  tmp = SortedA[i];
		  if (times > max)
			  max = times;
		  times = 1;}
  }
  if (times > max)
	  max = times;
  if (max > majority){
	  return 1;
  }else{
	  return -1;}
}


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  //vector<int> x = MergeSort(a);
  //for (int i = 0; i < a.size(); ++i){
	  //cout << x[i]<<" ";}
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  system("pause");
  return 0;
}
