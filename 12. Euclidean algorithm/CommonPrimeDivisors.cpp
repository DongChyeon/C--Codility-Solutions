#include <vector>

int get_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return get_gcd(b, a % b);
    }
}   // 최대 공약수로 나누기

int solution(vector<int>& A, vector<int>& B) {
    int prime_divisior_count = 0;

    for (int i = 0; i < A.size(); i++) {
        int a = A[i];
        int b = B[i];
        int gcd = get_gcd(a, b);

        while (1) {
            int gcd_a = get_gcd(a, gcd);
            if (gcd_a == 1) {
                break;
            }
            a = a / gcd_a;
        }

        while(1) {
            int gcd_b = get_gcd(b, gcd);
            if (gcd_b == 1) {
                break;
            }
            b = b / gcd_b;
        }

        if ((a == 1) & (b == 1)) {
            prime_divisior_count++;
        }
    }

    return prime_divisior_count;
}   // 소인수분해의 원리를 이용
