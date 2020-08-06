#include <algorithm>

int solution(vector<int>& A) {
	vector<int> lower;
	vector<long long> upper;
	int cnt = 0;
	int j = 0;

	for (int i = 0; i < A.size(); i++) {
		lower.push_back(i - A[i]);
		upper.push_back((long long)i + A[i]);
	}

	sort(lower.begin(), lower.end());
	sort(upper.begin(), upper.end());

	for (int i = 0; i < A.size(); i++) {
		while (j < A.size() && upper[i] >= lower[j]) {
			cnt += j;
			cnt -= i;	// 이전 uppper와 겹치지 않기 위해서 빼준다
			j++;
		}
	}

	if (cnt > 10000000) return -1;
	return cnt;
}