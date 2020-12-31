#include <vector>
#include <cmath>

vector<int> solution(vector<int> &A, vector<int> &B) {
    vector<int> fibonacci {0, 1, 2};
    vector<int> result;
    int div = pow(2, 30);

    for (int i = 3; i < A.size() + 1; i++) {
        fibonacci.push_back((fibonacci[i - 1] + fibonacci[i - 2]) % div);
    }

    for (int i = 0; i < A.size(); i++) {
        div = pow(2, B[i]);
        result.push_back(fibonacci[A[i]] % div);
    }

    return result;
}