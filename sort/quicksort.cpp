//
//  quicksort.cpp
//  learn_algorithm_mac
//
//  Created by Inhee Kim on 2014. 11. 15..
//  Copyright (c) 2014년 Inhee Kim. All rights reserved.
//

// 퀵 소트
#include <iostream>

using namespace std;

void swap_arr(int arr[], int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int len)
{
    int p = 0;

    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[0])
        {
            swap_arr(arr, ++p, i);
        }
    }
    swap_arr(arr, 0, p);

    return p;

}


void quicksort(int arr[], int len)
{
    int p;
    if (len <= 1) {
        return;
    }
    p = partition(arr, len);
    quicksort(arr, p);
    quicksort(arr + p + 1, len - p -1);
}

//int main(int argc, const char * argv[]) {
//    int arr[] = {4, 6, 3, 5, 1, 0, 2, 7};
//    quicksort(arr, 8);
//
//    return 0;
//}


