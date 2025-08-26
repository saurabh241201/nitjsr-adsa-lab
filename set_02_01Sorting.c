#include <stdio.h>
#include <stdlib.h>

// ---------------- Insertion Sort ----------------
void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i], j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// ---------------- Bubble Sort ----------------
void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) {
                int t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
            }
}

// ---------------- Selection Sort ----------------
void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[min]) min=j;
        int t=arr[i]; arr[i]=arr[min]; arr[min]=t;
    }
}

// ---------------- Shell Sort ----------------
void shellSort(int arr[], int n) {
    for(int gap=n/2; gap>0; gap/=2) {
        for(int i=gap;i<n;i++) {
            int temp=arr[i], j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
}

// ---------------- Quick Sort ----------------
int partition(int arr[], int low, int high) {
    int pivot=arr[high], i=low-1;
    for(int j=low;j<high;j++) {
        if(arr[j]<pivot) {
            i++;
            int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
        }
    }
    int t=arr[i+1]; arr[i+1]=arr[high]; arr[high]=t;
    return i+1;
}
void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

// ---------------- Merge Sort ----------------
void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// ---------------- Heap Sort ----------------
void heapify(int arr[], int n, int i) {
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i) {
        int t=arr[i]; arr[i]=arr[largest]; arr[largest]=t;
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--) {
        int t=arr[0]; arr[0]=arr[i]; arr[i]=t;
        heapify(arr,i,0);
    }
}

// ---------------- Print Array ----------------
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
}

// ---------------- Main ----------------
int main() {
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Insertion\n2. Bubble\n3. Selection\n4. Shell\n5. Quick\n6. Merge\n7. Heap\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1: insertionSort(arr,n); break;
        case 2: bubbleSort(arr,n); break;
        case 3: selectionSort(arr,n); break;
        case 4: shellSort(arr,n); break;
        case 5: quickSort(arr,0,n-1); break;
        case 6: mergeSort(arr,0,n-1); break;
        case 7: heapSort(arr,n); break;
        default: printf("Invalid choice\n"); return 0;
    }

    printf("Sorted array: ");
    printArray(arr,n);
    return 0;
}