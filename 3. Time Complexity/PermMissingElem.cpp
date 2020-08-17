#include <vector>

int solution(vector<int> &A) {
	int a = 0, b = 0;
	for (int i = 0; i < A.size(); i++) a += A[i];
	for (int i = 1; i < A.size() + 2; i++) b += i;
	return b - a;
}