#include <vector>

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
	vector<int> A; A.assign(S.size(), 0);
	vector<int> C; C.assign(S.size(), 0);
	vector<int> G; G.assign(S.size(), 0);
	vector<int> T; T.assign(S.size(), 0);	// 발생한 인덱스를 저장할 vector

	vector<int> result;

	int A_occur = 0;
	int C_occur = 0;
	int G_occur = 0;
	int T_occur = 0;	// 발생 빈도 수 카운팅

	for (int i = 0; i < S.size(); i++) {
		switch (S[i]) {
		case 'A':
			A_occur++;
			break;
		case 'C':
			C_occur++;
			break;
		case 'G':
			G_occur++;
			break;
		case 'T':
			T_occur++;
			break;
		}
		A[i] = A_occur;
		C[i] = C_occur;
		G[i] = G_occur;
		T[i] = T_occur;
	}	// 발생빈도 구간합 구하기

	for (int i = 0; i < P.size(); i++) {
		if (P[i] > 0) {
			if (A[P[i] - 1] < A[Q[i]]) result.push_back(1);
			else if (C[P[i] - 1] < C[Q[i]]) result.push_back(2);
			else if (G[P[i] - 1] < G[Q[i]]) result.push_back(3);
			else if (T[P[i] - 1] < T[Q[i]]) result.push_back(4);
		}
		else {
			if (A[Q[i]] > 0) result.push_back(1);
			else if (C[Q[i]] > 0) result.push_back(2);
			else if (G[Q[i]] > 0) result.push_back(3);
			else if (T[Q[i]] > 0) result.push_back(4);
		}
	}	// 시작 인덱스와 끝 인덱스의 발생 빈도 수 차이를 이용

	return result;
}