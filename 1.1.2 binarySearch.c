#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;  // key not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;  // key found at index mid
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);  // search left half
    else
        return binarySearch(arr, mid + 1, high, key); // search right half
}

int main() {
    int n, key;

    printf("Enter the number of elements (sorted array): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element %d not found in the array.\n", key);
    else
        printf("Element %d found at index %d.\n", key, result);

    return 0;
}
