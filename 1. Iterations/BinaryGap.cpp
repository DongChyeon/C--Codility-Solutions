int solution(int N) {
    int gap = 0;
    int maxlength = 0;
    int cnt = 0;

    while (N > 0) {
        if (N % 2 == 0) gap++;
        else if (N % 2 == 1) {
            cnt ++;
            if (cnt > 1 && gap > maxlength) maxlength = gap;
            gap = 0;
        }
        N = N / 2;
    }
    return maxlength;
}