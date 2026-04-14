#include <stdio.h>
#include <time.h> 


long long fibo_r(int n) {
    if (n <= 2) return 1;
    return fibo_r(n - 1) + fibo_r(n - 2);
}


long long fibo_i(int n) {
    if (n <= 2) return 1;

    long long a = 1, b = 1, c = 0;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int max = 40;
    clock_t start, end;

    printf("N\t재귀 시간(s)\t반복 시간(s)\t결과\n");
    printf("--------------------------------------------------\n");

    for (int n = 1; n <= max; n++) {
    
        start = clock();
        long long ans1 = fibo_r(n);
        end = clock();
        double time1 = (double)(end - start) / CLOCKS_PER_SEC;

        
        start = clock();
        long long ans2 = fibo_i(n);
        end = clock();
        double time2 = (double)(end - start) / CLOCKS_PER_SEC;


        printf("%d\t%.6f\t%.6f\t%lld\n", n, time1, time2, ans2);
    }

    return 0;
}
