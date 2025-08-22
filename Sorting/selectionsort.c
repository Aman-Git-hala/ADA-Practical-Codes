#include<stdio.h>
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d",arr[i]);
        if(i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
        }
    }
    int main() {
        int arr[100];
        int n = sizeof(arr) /sizeof(arr[0]);
        printf("what is the total number of your elements hey?");
        scanf("%d",&n);
        printf("Input your elements please\n");
        for(int i = 0; i < n; i++) {
            scanf("%d",&arr[i]);
        }
        selectionSort(arr, n);
        printf("Sorted array \n");
        printArray(arr, n);
        return 0;
    }

