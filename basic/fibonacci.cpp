
// 피보나치 수열
#include <stdio.h>

#define MAXN 200

long long fibo(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return fibo(n - 1) * fibo (n - 2);
}

// 여러번 피보나치를 수행하는 경우를 위해 피보나치 결과값을 저장해서 사용한다.
long long fibo2(int n)
{
    static long long memo[MAXN];

    if (memo[n] > 0)
    {
        return memo[n];
    }

    if (n == 1 || n == 2)
    {
        return memo[n] = 1;
    }

    return memo[n] = fibo2(n - 1) + fibo2(n - 2);
}

//int main(int argc, const char * argv[]) {
//    long long result = fibo2(50);
//    printf("%lld\n", result);
//
//    return 0;
//}