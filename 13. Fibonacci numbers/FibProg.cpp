#include <vector>
#include <algorithm>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int solution(vector<int> &A) {
    // 목적지에도 leaf가 있는 것처럼 취급
    A.push_back(1);

    // 점프할 수 있는 거리를 담은 jumps 벡터 생성
    int i = 0;
    vector<int> jumps;
    while (1) {
        i++;
        int jump = fibonacci(i);
        if (jump > A.size()) {
            break;
        } else {
            jumps.push_back(jump);
        }
    }

    // 해당 인덱스에 도착할 수 있는 최소 점프수를 담은 reachable 벡터 생성
    vector<int> reachable(A.size()); 
    for (int j = 0; j < jumps.size(); j++) {
        if (A[jumps[j] - 1] == 1) {
            reachable[jumps[j] - 1] = 1;
        }
    }

    // reachable 벡터에 최소 점프수를 구함
    int min, minIdx, pre;
    for (int i = 0; i < reachable.size(); i++) {
        if (A[i] == 1 && reachable[i] == 0) {
            min = A.size() + 1;
            minIdx = -1;
            for (int j = 0; j < jumps.size(); j++) {
                pre = i - jumps[j];
                if (pre < 0 || reachable[pre] == 0) continue;
                if (min > reachable[pre]) {
                    min = reachable[pre];
                    minIdx = pre;
                }
            }
            if (minIdx != -1) {
                reachable[i] = min + 1;
            }
        }
    }

    // 마지막 목적지에 도착할 수 있는 최소 점프수를 리턴 (0일 경우 도착할 수 없으므로 -1)
    if (reachable.back()) return reachable.back();
    else return -1;
}