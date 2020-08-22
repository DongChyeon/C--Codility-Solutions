#include <cmath>
#include <algorithm>

int solution(int N) {
    int one, two;
    int min_perimeter = 2 * (1 + N);
    
    for (int i = 2; i < sqrt(N) + 1; i++) {
        if (N % i == 0) {
            one = N / i;
            two = N / one;
            min_perimeter = min(min_perimeter, 2 * (one + two));
        }
    }
    
    return min_perimeter;
}