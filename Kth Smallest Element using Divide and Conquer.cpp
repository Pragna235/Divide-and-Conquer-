#include <bits/stdc++.h>
using namespace std;

//Function to swap two integers.
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function of QuickSort(). It takes the last element as Pivot and rearranges the array so that Pivot is at its right place with all smaller to its left and greater elements to its right.
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l; //last element as pivot
    for (int j = l; j < r ; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
// This function finds and returns the kth smallest element in arr[l to r] using the above partition function.
int tofindkthSmallest(int arr[], int l, int r, int k)
{
    // If k is greater than no. of elements in the array.i.e., k is not a valid number position in the array
    if (k < 0 || k > r+1)
        return -1; //Invalid k value

    // If k is smaller than number of elements in array
    else {
    // Call the Partition function on the array with last element as pivot, it will return the index of pivot element in the sorted array.
        int pos = partition(arr, l, r);

        // If index of pivot is same as k.
        if (pos - l == k - 1)
            return arr[pos];
        // If Index of Pivot is greater, recur for left subarray.
        if (pos - l > k - 1)
            return tofindkthSmallest(arr, l, pos - 1, k);

        // Else recur for right subarray.
        return tofindkthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
}

// Driver Function.
int main()
{
    int arr[] = {50,10,75,55,45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    if(tofindkthSmallest(arr,0,n-1,k)<0) //i.e., ==-1
        cout<<"Invalid k Value!"<<endl;
    else
        cout << "Kth smallest element is " << tofindkthSmallest(arr, 0, n - 1, k);
    return 0;
}


