#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
	if (A.size() < 2) return 0;
	
	int min_value = A[0];
	int max_profit = 0;

	for (int i = 0; i < A.size(); i++) {
		min_value = min(min_value, A[i]);
		max_profit = max(max_profit, A[i] - min_value);
	}

	return max_profit;
}