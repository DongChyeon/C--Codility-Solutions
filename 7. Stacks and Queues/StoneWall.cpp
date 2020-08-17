#include <vector>
#include <stack>

int solution(vector<int>& H) {
	stack<int> stack;
	int block_cnt = 0;

	int prev = 0;
	int current = 0;

	for (int i = 0; i < H.size(); i++) {
		current = H[i];
		
		while (current < prev) {
			prev -= stack.top();
			stack.pop();
		}
		if (current > prev) {
			stack.push(current - prev);
			prev = current;
			block_cnt++;
		}
	}

	return block_cnt;
}

/*
이전 단계의 높이는 prev, 현재 단계의 높이는 current이다.
처음 블록을 쌓고 prev가 current보다 클 경우 stack에서 블록을 뺀다. prev는 prev에서 stack에서 블록을 뺀 값이 된다.
current가 prev보다 커질 경우 둘의 차이 만큼 stack에 집어넣고 블록 개수를 증가시킨다.
이전 단계와 현재 단계의 높이가 같을 경우는 이전 블록을 재사용하면 되므로 아무것도 하지 않는다.
*/