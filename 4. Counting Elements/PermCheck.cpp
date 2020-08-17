#include <vector>
#include <set>

int solution(vector<int>& A) {
	set<int> B;
	int sum = 0;
	int sum2 = 0;
	int max = A[0];

	for (int i = 0; i < A.size(); i++) {
		B.insert(A[i]);
	}
	for (set<int>::iterator iter = B.begin(); iter != B.end(); iter++) {
		sum += *iter;
		if (*iter > max) max = *iter;
	}
	for (int i = 1; i < A.size() + 1; i++) {
		sum2 += i;
	}

	if (sum == sum2) return 1;
	else return 0;
}