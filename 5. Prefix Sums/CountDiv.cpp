int solution(int A, int B, int K) {
	int cnt = (B / K) - (A / K);

	if (A % K == 0) cnt += 1;

	return cnt;
}