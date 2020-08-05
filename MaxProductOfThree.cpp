#include <algorithm>

int solution(vector<int>& A) {
	int max = A[0] * A[1] * A[2];

	sort(A.begin(), A.end());

	if (A[0] < 0 && A[1] < 0) {
		if ((A[0] * A[1] * A[A.size() - 1]) > max) {
			max = A[0] * A[1] * A[A.size() - 1];
		}
	}   // 음수 * 음수 * 양수가 최댓값인 경우
	if ((A[A.size() - 3] * A[A.size() - 2] * A[A.size() - 1]) > max) {
		max = A[A.size() - 3] * A[A.size() - 2] * A[A.size() - 1];
	}

	return max;
}