#include <stack>

int solution(vector<int>& A, vector<int>& B) {
	stack<int> downstream;
	int upstream_cnt = 0;

	for (int i = 0; i < A.size(); i++) {
		if (B[i] == 1) downstream.push(A[i]);
		else {
			if (downstream.empty()) upstream_cnt++;
			else {
				while (!downstream.empty()) {
					if (downstream.top() < A[i]) {
						downstream.pop();
						if (downstream.empty()) upstream_cnt++;
					}
					else {
						break;
					}
				}
			}
		}
	}

	return upstream_cnt + downstream.size();
}