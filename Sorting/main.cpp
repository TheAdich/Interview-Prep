#include<iostream>
#include<string>
#include<string.h>
#include <vector>

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int* arr, int n)
{
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n-i-1 ; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
}

void SelectionSort(int* arr, int n)
{
    int min;
    for(int i = 0; i < n ; i++)
    {    min = arr[i];
        for(int j = i+1 ; j < n ; j++)
            if(arr[j] < min)
            {
                min = arr[j];
                swap(arr[i],arr[j]);
            }
    }
}

void Merge(int* arr, int* L, int* R, int n , int mid)
{
    int soL = mid;
    int soR = n-mid;

    int ptrL = 0;
    int ptrR = 0;
    int i = 0;
    while(ptrL < soL && ptrR < soR)
    {
        if(L[ptrL] > R[ptrR])
            arr[i++] = R[ptrR++];

        else
            arr[i++] = L[ptrL++];
    }

    while(ptrL < soL) arr[i++] = L[ptrL++];
    while(ptrR < soR) arr[i++] = R[ptrR++];

}

void MergeSort(int* arr, int n)
{
    if(n < 2) return;

        int mid = n/2;

        int L[mid];
        for(int i = 0 ; i < mid ; i++) L[i] = arr[i];

        int R[n-mid];
        for(int i = mid ; i < n ; i++) R[i-mid] = arr[i];

        MergeSort(L,mid);
        MergeSort(R,n-mid);
        Merge(arr,L,R,n,mid);
}

//WRAPPER
void CountingSorted(int* arr,int* output, int n)
{
    int integer[10] = {0};

    for(int i = 0 ; i < n ; i++)    integer[arr[i]]++;

    for(int i = 1 ; i < 10 ; i++)   integer[i] = integer[i-1] + integer[i];

    for(int i = 0 ; i < n ; i++)    output[integer[arr[i]]--] = arr[i];

    for(int i = 0 ; i < n ; i++)    arr[i] = output[i];
}

void CountingSort(int* arr, int n)
{
    int output[n];
    CountingSorted(arr,output,n);
}



int main()
{
    int arr[] = {4,5,9,1,1,1,6,2,3,8};

    int n = sizeof(arr)/ sizeof(int);
    //BUBBLE SORT
    CountingSort(arr,n);

    cout<<arr[0];

    for(int i = 1 ; i < n ; i++)
        cout<<", "<<arr[i];


}