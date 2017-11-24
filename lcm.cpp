#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(long long a, long long b) {
	long long aprime;
	if (b == 0){
		return a;
	}else
	{aprime = a % b;
	return gcd_fast(b , aprime);}
}

long long lcm_fast(long long a, long long b) {
	long long temp = a * b;
	return (temp / gcd_fast(a, b));
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
