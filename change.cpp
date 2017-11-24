#include <iostream>

int get_change(int m) {
  //write your code here
	int n = 0;
	int left;
	n = n + (m / 10);
	left = m % 10;
	n = n + (left / 5);
	left = left % 5;
	n = n + (left / 1);
	left = 0;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  return 0;
}
