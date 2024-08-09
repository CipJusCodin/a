void merge(int arr[], int low, int mid, int high) { 
    int temp[100]; 
    int i = low, j = mid + 1, k = low; 
 
    // Merge the two halves into temp[] 
    while (i <= mid && j <= high) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } else { 
            temp[k++] = arr[j++]; 
        } 
    } 
 
    // Copy the remaining elements of left half, if any 
    while (i <= mid) { 
        temp[k++] = arr[i++]; 
    } 
 
    // Copy the remaining elements of right half, if any 
    while (j <= high) { 
        temp[k++] = arr[j++]; 
    } 
 
    // Copy the sorted subarray into Original array 
    for (i = low; i <= high; i++) { 
        arr[i] = temp[i]; 
    } 
} 
 
// MergeSort function to sort the array 
void mergeSort(int arr[], int low, int high) { 
    if (low < high) { 
        int mid = (low + high) / 2; 
        mergeSort(arr, low, mid);      // Sort the first half 
        mergeSort(arr, mid + 1, high); // Sort the second half 
        merge(arr, low, mid, high);    // Merge the two halves 
    } 
} 
 
int main() { 
    int n, arr[100]; 
 
    // Input number of elements 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    // Input array elements 
    printf("Enter the %d elements:\n", n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    // Sort the array 
    mergeSort(arr, 0, n - 1); 
 
    // Output the sorted array 
    printf("The sorted elements are:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
 
    return 0; 
}