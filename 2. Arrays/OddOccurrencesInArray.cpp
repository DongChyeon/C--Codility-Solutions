int solution(vector<int>& A) {
	int num = A[0];
	for (int i = 1; i < A.size(); i++) {
		num = num ^ A[i];
	}	// XOR 연산을 통해 쌍이 되는 숫자는 사라지고 쌍이 아닌 숫자만 남게됨
	return num;
}