#include <cmath>

int solution(int N) {
	int max_factor = sqrt(N);
	int factor_count = 0;

	for (int i = 1; i < max_factor + 1; i++) {
		if (N % i == 0) {
			if (sqrt(N) == i) factor_count++;
			else factor_count += 2;
		}
	}

	return factor_count;
}