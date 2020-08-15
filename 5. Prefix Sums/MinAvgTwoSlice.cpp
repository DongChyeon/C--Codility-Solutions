int solution(vector<int>& A) {
	float min = 10000;
	int minIndex = 0;

	for (int i = 0; i < A.size(); i++) {
		if (i + 1 < A.size()) {
			if (min > (float)(A[i] + A[i + 1]) / 2) {
				min = (float)(A[i] + A[i + 1]) / 2;
				minIndex = i;
			}
		}	// 2개의 원소로 이루어진 부분집합으로 고려
		if (i + 2 < A.size()) {
			if (min > (float)(A[i] + A[i + 1] + A[i + 2]) / 3) {
				min = (float)(A[i] + A[i + 1] + A[i + 2]) / 3;
				minIndex = i;
			}
		}	// 3개의 원소로 이루어진 부분집합으로 고려
	}	// 최소 평균은 반드시 2개나 3개의 연속된 숫자 안에서 나온다.

	return minIndex;
}