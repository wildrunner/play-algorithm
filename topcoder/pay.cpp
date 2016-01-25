/****************
 금액 맞추기
 주어진 금액과 지폐의 종류를 이용해 총 몇 가지 조합이 나올지 계산한다.
****************/

#include <stdio.h>

int pay(int money, int bills[], int n)
{
    int count = 0;
    int t;

    if (n == 1) {
        if (money % bills[0] == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    t = money / bills[n - 1];
    for (int i = 0; i <= t; i++) {
        count += pay(money -bills[n - 1] * i, bills, n - 1);
    }

    return count;
}

int main()
{
    int bills[6] = {1, 2, 5, 10, 20, 50};
    int money = 100;

    int result = pay(money, bills, 6);
    printf("%d\n", result);


}