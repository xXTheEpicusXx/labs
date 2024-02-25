#include <stdio.h>

void findSubarraysWithSum(int arr[], int n, int targetSum) {
    for (int start = 0; start < n; start++) {
        int currentSum = 0;
        for (int end = start; end < n; end++) {
            currentSum += arr[end];
            if (currentSum == targetSum) {
                printf("Подмассив найден: [");
                for (int i = start; i <= end; i++) {
                    printf("%d", arr[i]);
                    if (i <= end - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
            }
        }
    }
}

int main() {
    int arr[] = {4, -7, 1, 5, -4, 0, -3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 5;

    findSubarraysWithSum(arr, n, targetSum);

    return 0;
}
