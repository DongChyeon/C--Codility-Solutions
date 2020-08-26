int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}   // 최대 공약수 구하기

int solution(int N, int M) {
    return N / gcd(M, N);
}