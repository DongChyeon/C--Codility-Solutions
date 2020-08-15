#include <set>

int solution(int X, vector<int>& A) {
	set<int> check;	// set에 중복 원소가 허용 안된다는 점을 이용

	for (int i = 0; i < A.size(); i++) {
		if (A[i] <= X) {
			check.insert(A[i]);
			if (check.size() == X) return i;
		}
	}
	return -1;
}