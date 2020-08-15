int solution(int X, int Y, int D) {
	int dist = Y - X;
	if (dist) {
		if ((dist / D) == (dist / (double)D)) return dist / D;
		else return dist / D + 1;
	}	// Y가 X보다 멀리 있을 시
	else return 0;
}