#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
	sort(A.begin(), A.end());
	if (A.size() >= 3) {
		for (int i = 0; i < A.size() - 2; i++) {
			if (A[i + 2] < ((long long)A[i] + A[i + 1])) return 1;
		}
	}
	return 0;
}