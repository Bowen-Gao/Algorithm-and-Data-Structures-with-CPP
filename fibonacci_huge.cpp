#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    vector<long long> vec;
	vec.push_back(0);
	long long previous = 0;
    long long current  = 1;
	int i = 0;

    while (i < 2){
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
		
		if (previous == 0 && current == 1)
			break;
		else
			vec.push_back(previous);
	}
	long long index = n % vec.size();
    return vec[index];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
	return 0;
}
