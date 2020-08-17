#include <vector>
#include <map>
#include <set>

int solution(vector<int>& A) {
	map<int, int> map;
	set<int> set;

	int prev_size = 0;

    if (A.size() == 1) return 0;

	for (int i = 0; i < A.size(); i++) {
		prev_size = set.size();
		set.insert(A[i]);

		if (set.size() == prev_size) {
			if (map[A[i]] != 0) {
				map[A[i]] = map[A[i]] + 1;
				if (map[A[i]] > A.size() / 2) return i;
			}
		}   // prev_size와 set의 크기가 같을 시 같은 원소이므로 value값 1증가
		else {
			map.insert(pair<int, int>(A[i], 1));
		}   // prev_size와 set의 크기가 다를 시 새로운 원소이므로 삽입
	}

	return -1;
}