int solution(vector<int>& A) {
	int sum = 0;
	int temp_sum = 0;
	int min, temp_min;

	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
	}
	temp_min = abs(A[0] - (sum - A[0]));
	min = temp_min;	// 초기값 설정
	for (int i = 0; i < A.size() - 1; i++) {
		temp_sum += A[i];
		temp_min = abs(temp_sum - (sum - temp_sum));
		if (min > temp_min) min = temp_min;
	}
	return min;
}