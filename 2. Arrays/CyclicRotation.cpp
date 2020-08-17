#include <vector>

vector<int> solution(vector<int> &A, int K) {
    int temp, temp2;
    
    for (int i = 0; i < K; i++) {
        if (A.size() == 2) {
            temp = A[0];
            A[0] = A[1];
            A[1] = temp;
        }   // 두 개의 원소만 있을 시 예외 처리
        else if (A.size() > 1) {
            temp = A[1];
            A[1] = A[0];
            for (int j = 1; j < A.size() - 2; j++) {
                temp2 = A[j + 1];
                A[j + 1] = temp;
                temp = temp2;
            }
            temp2 = A[A.size() - 1];
            A[A.size() - 1] = temp;
            A[0] = temp2;
        }   // 원소의 개수가 두 개 이상일 시 실행
    }
    return A;
}