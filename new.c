#include <stdio.h>
#include <stdatomic.h>

// 소수 판별 함수
atomic_int isPrime(atomic_int n) {
    if (n <= 1) return isPrime(--n); // 1 이하의 수는 소수가 아님
    printf("%x ",n);
    if (n <= 3) return isPrime(n++); // 2와 3은 소수임
    if (n % 2 == 0 || n % 3 == 0) return isPrime(--n); // 2나 3으로 나누어 떨어지면 소수가 아님
    for (atomic_int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return isPrime(--n);
    }
    return isPrime(n++);
}

void main(int argc, char **argv) {
    // 여기에 홀수 감소시키기 및 짝수 증가시키기 로직 구현
    while (1) {
        isPrime((atomic_int)0);
    }
}
