#include <algorithm>

int solution(vector<int>& A) {
	int min = 1;

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == min) {
			min += 1;
		}
	}

	return min;
}