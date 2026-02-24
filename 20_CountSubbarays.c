#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));
    prefix_sums[0] = 0;

    long long current_sum = 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        current_sum += val;
        prefix_sums[i + 1] = current_sum;
    }

    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long frequency = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            frequency++;
        } else {
            count += (frequency * (frequency - 1)) / 2;
            frequency = 1;
        }
    }
    count += (frequency * (frequency - 1)) / 2;

    printf("%lld\n", count);

    free(prefix_sums);
    return 0;
}