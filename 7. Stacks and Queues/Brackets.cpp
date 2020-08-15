#include <stack>

int solution(string& S) {
	stack<char> stack;

	for (auto s : S) {
		if (stack.empty()) {
			stack.push(s);
		}
		else {
			if ((stack.top() == '{' && s == '}') || (stack.top() == '[' && s == ']') || (stack.top() == '(' && s == ')')) {
				stack.pop();
			}
			else {
				stack.push(s);
			}
		}
	}

	if (stack.empty()) return 1;
	else return 0;
}