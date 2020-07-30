vector<int> solution(int N, vector<int>& A) {
	vector<int> B;
	int max = 0;
	int temp = 0;

	B.assign(N, 0);

	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= 1 && N >= A[i]) {
			if (B[A[i] - 1] > temp) B[A[i] - 1] += 1;
			else B[A[i] - 1] = temp + 1;

			if (B[A[i] - 1] > max) max = B[A[i] - 1];
		}
		else if (A[i] == N + 1) temp = max;
	}
	for (int i = 0; i < B.size(); i++) {
		if (B[i] < temp) B[i] = temp;
	}

	return B;
}