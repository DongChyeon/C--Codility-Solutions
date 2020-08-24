#include <vector>

vector<int> solution(vector<int>& A) {
    int N = A.size();

    vector<int> result;
    vector<int> elem_count;
    vector<int> factor;
    
    elem_count.assign((2 * N) + 1, 0);
    for (auto a : A) {
        elem_count[a]++;
    }

    factor.assign((2 * N) + 1, 0);
    for (int i = 1; i < elem_count.size(); i++) {
        if (elem_count[i]) {    
            int j = i;
            while (j <= 2 * N) {
                if (elem_count[j]) {
                    factor[j] += elem_count[i];
                }
                j += i;
            }   // 1부터 존재하는 요소 배수마다 개수를 더해줌.
        }
    }
    
    for (auto a : A) {
        result.push_back(N - factor[a]);
    }

    return result;
}