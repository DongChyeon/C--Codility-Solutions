#include <vector>
#include <cmath>

vector<int> solution(int N, vector<int>& P, vector<int>& Q) {
    vector<int> flags;
    flags.assign(N + 1, 1);
    flags[0] = 0;
    flags[1] = 0;

    // 0 no prime
    // 1 prime
    // 2 semi prime

    for (int i = 2; i <= sqrt(N); i++) {
        if (flags[i]) {
            int j = i * i;
            while (j <= N) {
                flags[j] = 0;
                j += i;
            }
        }
    }

    for (int i = 2; i <= sqrt(N); i++) {
        if (flags[i]) {
            int j = i * i;
            while (j <= N) {
                if ((flags[i] == 1) & (flags[j / i] == 1)) {
                    flags[j] = 2;  
                }
                j += i;
            }
        }
    }

    vector<int> prefix_sum;
    prefix_sum.assign(N + 1, 0);
    int semi_prime_count = 0;
    for (int i = 4; i < N + 1; i++) {
        if (flags[i] == 2) {
            semi_prime_count++;
        }
        prefix_sum[i] = semi_prime_count;
    }

    vector<int> result;
    for (int i = 0; i < P.size(); i++) {
        result.push_back(prefix_sum[Q[i]] - prefix_sum[P[i] - 1]);
    }

    return result;
}