#include <map>
#include <set>

int solution(vector<int>& A) {
	map<int, int> map;
	set<int> set;

	int leader_value;
	int equi_count = 0;
	int prev_size = 0;

	if (A.size() == 1) return 0;

	for (int i = 0; i < A.size(); i++) {
		prev_size = set.size();
		set.insert(A[i]);

		if (set.size() == prev_size) {
			if (map[A[i]] != 0) {
				map[A[i]] = map[A[i]] + 1;
				if (map[A[i]] > A.size() / 2) {
					leader_value = A[i];
					break;
				}
			}
		}
		else {
			map.insert(pair<int, int>(A[i], 1));
		}
	}	// leader_value를 구함

	vector<int> prefixSum;
	prefixSum.assign(A.size(), 0);

	int leader_count = 0;
	int first_slice, second_slice;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == leader_value) leader_count++;
		prefixSum[i] = leader_count;
	}

	for (int i = 0; i < prefixSum.size() - 1; i++) {
		first_slice = prefixSum[i];
		second_slice = prefixSum[prefixSum.size() - 1] - prefixSum[i];

		if ((first_slice > (i + 1) / 2) && (second_slice > (prefixSum.size() - (i + 1)) / 2)) {
			equi_count++;
		}
	}	// leader_value가 나타나는 구간합을 이용

	return equi_count;
}