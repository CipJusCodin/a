
#include<stdio.h>

int partition(int arr[], int low, int high) { 
    int pivot = arr[low]; // Choosing the pivot element 
    int i = low + 1; 
    int j = high; 
    int temp; 
     
    while (i < j) { 
        while (i <= high && arr[i] <= pivot) i++;  
        while (arr[j] > pivot) j--; 
        if (i < j) { 
            // Swap arr[i] and arr[j] 
            temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
    } 
     
    temp = arr[j]; 
    arr[j] = arr[low]; 
    arr[low] = temp; 
    return j; 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int j = partition(arr, low, high); 
        quickSort(arr, low, j - 1); 
        quickSort(arr, j + 1, high);
    } 
} 
 
int main() { 
    int n, arr[100]; 
     
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
     
    printf("Enter the %d elements:\n", n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
     
    quickSort(arr, 0, n - 1); 
     
    printf("The sorted elements are:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
     
    return 0; 
} 