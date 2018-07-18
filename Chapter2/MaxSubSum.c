#include <stdio.h>

int Max3(int a, int b, int c){
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else
        return c;
}


int MidSubSum(const int a[], int left, int right){
    int i, center;
    int left_border_sum, right_border_sum, temp_sum;
    center = (left + right) / 2;

    temp_sum = 0;
    left_border_sum = a[center];
    for(i=center; i>=left; i--){
        temp_sum += a[i];
        if(temp_sum > left_border_sum)
            left_border_sum = temp_sum;
    }

    temp_sum = 0;
    right_border_sum = a[center+1];
    for(i=center+1; i<=right; i++){
        temp_sum += a[i];
        if(temp_sum > right_border_sum)
            right_border_sum = temp_sum;
    }

    return (left_border_sum + right_border_sum);

}

int MaxSubSum1(const int a[], int n){
    int i, j, k, max_sum, sum;
    max_sum = a[0];
    for(i=0; i<n; i++)
        for(j=i; j<n; j++){
            sum = 0;
            for(k=i; k<=j; k++)
                sum += a[k];
            if(sum > max_sum)
                max_sum = sum;
        }
    return max_sum;
}


int MaxSubSum2(const int a[], int n){
    int i, j, k, max_sum, sum;
    max_sum = a[0];
    for(i=0; i<n; i++){
        sum = 0;
        for(j=i; j<n; j++){
            sum += a[j];
            if(sum > max_sum)
                max_sum = sum;
        }
    }
    return max_sum;
}


int MaxSubSum3(const int a[], int left, int right){
    int center;
    int left_sum, right_sum, mid_sum;

    if(left == right){
        return a[left];
    }

    center = (left + right) / 2;
    left_sum = MaxSubSum3(a, left, center);
    right_sum = MaxSubSum3(a, center+1, right);
    mid_sum = MidSubSum(a, left, right);

    return Max3(left_sum, right_sum, mid_sum);
}


int MaxSubSum4(const int a[], int n){
    int i, this_sum, max_sum;

    max_sum = a[0];
    this_sum = 0;
    for(i=0; i<n; i++){
        //printf("%d  %d  %d\n", i, a[i], this_sum);
        this_sum += a[i];
        if(this_sum > max_sum){
            max_sum = this_sum;
        }
        if(this_sum < 0){
            this_sum = 0;
        }
    }

    return max_sum;
}




int main(int argc, char const *argv[])
{
    int a[8] = {4, -3, 5, -2, -1, 2, 6, -2};
    int n, max_sum1, max_sum2, max_sum3, max_sum4;
    n = sizeof(a) / sizeof(a[0]);
    max_sum1 = MaxSubSum1(a, n);
    printf("Max Sum1: %d\n", max_sum1);

    max_sum2 = MaxSubSum2(a, n);
    printf("Max Sum2: %d\n", max_sum2);

    max_sum3 = MaxSubSum3(a, 0, n-1);
    printf("Max Sum3: %d\n", max_sum3);

    max_sum4 = MaxSubSum4(a, n);
    printf("Max Sum4: %d\n", max_sum4);




    return 0;
}