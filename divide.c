#include <stdio.h>
#include <stdlib.h>

int count = 0;


int div1(int dividend, int divisor) {
    count++;
    int curr = dividend - divisor;
    if (curr > 0) {
        return div1(curr, divisor) + 1;
    } else if (curr == 0) {
        return 1;
    } else {
        return 0;
    }
}

int div2(int dividend, int divisor, int multi) {
    count++;
    int curr = dividend - (multi * divisor);
    if (curr > 0) {
        return div2(curr, divisor, multi * 2) + multi;
    } else if (curr == 0) {
        return multi;
    } else {
        if (multi > 1) {
            return div2(dividend, divisor, (multi / 2));
        } else {
            return 0;
        }
    }
}

long div3(long dividend, long divisor) {
    long i=0;
    long sign=0;
    long div=0;

    if( dividend < 0 ) {
        dividend = ~dividend + 1;
        sign++;
    }

    if( divisor < 0 ) {
        divisor = ~divisor + 1;
        sign++;
    }

    if( dividend < divisor ) {
        div = 0;
    } else {
        for(i=0; i<32; i++) {
            long tmp = (divisor << i);
            if( dividend < (divisor<<i) ) {
                if( i > 0 ) i--;
                break;
            } else if( dividend == (divisor<<i) ) {
                break;
            }
        }

        div = 0;
        for(; i>=0; i--) {
            if( dividend < divisor ) {
                break;
            }

            if( dividend >= (divisor<<i) ) {
                dividend -= (divisor<<i);
                div      += (1<<i);
            }
        }
    }

    if( sign & 0x01 ) {
        div = ~div + 1;
    }

    return div;
}

int countPerfect(int n) {
    int arraySize = (n/2) + 1;
    int *dp = (int *) malloc(sizeof(int) * arraySize);

    dp[0] = 1;

    for (int i = 1; i <= n / 2; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    int ans = dp[n / 2];
    free(dp);

    return ans;
}



int main() {

    /*printf("div1: %d, count: %d\n", div1(23, 2), count);
    printf("div2: %d, count: %d\n", sdiv2(23, 2, 10), count);
    printf("div3: %d", div3(23, 2));*/
    printf("handshaking: %d", countPerfect(8));

    return 0;
}