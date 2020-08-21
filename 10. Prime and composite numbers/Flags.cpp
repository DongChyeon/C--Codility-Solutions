#include <vector>
#include <algorithm>

vector<int> peak_check(vector<int>& A) {
	vector<int> P;
	P.assign(A.size(), 0);

	for (int i = 1; i < P.size() - 1; i++) {
		if ((A[i] > A[i - 1]) & (A[i] > A[i + 1])) {
			P[i] = 1;
		}
	}

	return P;
}

vector<int> next_peak(vector<int>& A) {
	vector<int> P;
	P.assign(A.size() +	1, 0);
	P[A.size()] = -1;

	for (int i = P.size() - 2; i > -1; i--) {
		if (A[i]) {
			P[i] = i;
		}
		else {
			P[i] = P[i + 1];
		}
	}

	return P;
}

int solution(vector<int>& A) {
	vector<int> peaks;  // peak일 시 1로 표시
	vector<int> next_peaks; // 해당 위치에서 다음 peak 표시

	int peak_count = 0;

	peaks = peak_check(A);
	next_peaks = next_peak(peaks);

	for (int i = 0; i < peaks.size(); i++) {
		if (peaks[i]) peak_count++;
	}

	if (peak_count < 3) {
		return peak_count;
	}
	else {
		int max_flag = 0;
		int interval = 2;
		while (interval * (interval - 1) <= A.size()) {
			int flag_count = 0;
			int peak = 0;
			while ((peak < A.size()) & (flag_count < interval)) {
				peak = next_peaks[peak];
				if (peak == -1) break;
				flag_count++;
				peak += interval;   // 간격만큼 이동하며 탐색
			}
			max_flag = max(flag_count, max_flag);
			interval++;
		}

		return max_flag;
	}
}