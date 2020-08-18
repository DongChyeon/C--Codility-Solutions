#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
	int max_sum = A[0];
	int current_sum = A[0];

	for (int i = 1; i < A.size(); i++) {
		current_sum = max(current_sum + A[i], A[i]);
		max_sum = max(max_sum, current_sum);
	}
	
	return max_sum;
}