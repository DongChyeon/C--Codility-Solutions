#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
	vector<int> left_slice_sum;
	vector<int> right_slice_sum;

	left_slice_sum.assign(A.size(), 0);
	right_slice_sum.assign(A.size(), 0);

	for (int i = 1; i < A.size() - 2; i++) {
		left_slice_sum[i] = max(left_slice_sum[i - 1] + A[i], 0);
	}	// 순방향으로 구간합 계산

	for (int i = A.size() - 2; i > 1; i--) {
		right_slice_sum[i] = max(right_slice_sum[i + 1] + A[i], 0);
	}	// 역방향으로 구간합 계산

	int slice_sum = left_slice_sum[0] + right_slice_sum[2];
	for (int i = 1; i < A.size() - 1; i++) {
		slice_sum = max(slice_sum, left_slice_sum[i - 1] + right_slice_sum[i + 1]);
	}	// 가운데를 제외하고 위의 두 구간합을 더한 값이 가장 클 때가 최댓값

	return slice_sum;
}