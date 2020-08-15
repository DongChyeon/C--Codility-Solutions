int solution(vector<int>& A) {
	double cnt = 0;
	int sum = 0;

	vector<int> prefixSum;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		prefixSum.push_back(sum);
	}

	for (int i = 0; i < prefixSum.size(); i++) {
		if (A[i] == 0 || prefixSum[i] == prefixSum[i - 1]) {
			cnt += (prefixSum[prefixSum.size() - 1] - prefixSum[i]);
		}
	}   // 구간합 표를 이용해 해결

	if (cnt > 1000000000) return -1;
	return cnt;
}