#include <vector>
#include <cmath>
#include <algorithm>

int solution(vector<int>& A) {
    if (A.size() < 3) return 0;

    vector<int> peaks;  // peak의 개수 구간합
    peaks.assign(A.size() + 1, 0);

    int peak = 0;

    for (int i = 1; i < A.size() - 1; i++) {
        if ((A[i] > A[i - 1]) & (A[i] > A[i + 1])) {
            peak++;
        }
        peaks[i + 1] = peak;
    }
    peaks[A.size()] = peaks[A.size() - 1];

    vector<int> factors;    // A의 약수 모음
    for (int i = 1; i < sqrt(A.size()) + 1; i++) {
        if (A.size() % i == 0) {
            factors.push_back(i);
            factors.push_back(A.size() / i);
        }
    }

    int max_blocks = 0;
    int j = 0;

    for (int i = 0; i < factors.size(); i++) {
        while (peaks[j] < peaks[j + factors[i]]) {
            j += factors[i];
            if (j == (peaks.size() - 1)) {
                max_blocks = max(max_blocks, (int)(A.size() / factors[i]));
                break;
            }
        }
        j = 0;
    }

    return max_blocks;
}