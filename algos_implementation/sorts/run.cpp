// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "merge_sort.h" // merge_sort
#include "heap_sort.h" // heap_sort
#include "quick_sort.h" // contains swap and quick_sort
#include <chrono>
#include <algorithm>
#include <iostream>
using namespace std;

//void swap(int &a, int &b)
//{
//  int temp = a;
//  a = b;
//  b = temp;
//}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void selection_sort(int a[], int l, int h)
{
    for (int i = l; i <= h; i++)
    {
        int min = INT32_MAX;
        int min_index = -1;
        for (int j = i; j <= h; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}

void copy(int a[], int b[], int n)
{
    for(int i=0;i<n;i++)
    {
        // cout<<"\r"<<i;
        a[i] = b[i];
    }
    // cout<<endl;
}

void execute(string name, int a[], int n, void func(int[], int, int))
{
    int runs = 10;
    double time = 0;
    for(int i=0;i<runs;i++)
    {
        auto start = chrono::high_resolution_clock::now();
        func(a, 0, n-1); 
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration<double, std::milli>(end-start).count();
        time += duration;
    }
    // print(a, n);
    cout<<name<<": "<<time/runs<<" milli seconds\n";
}

void inbuilt_sort(int a[], int l, int h)
{
    sort(a+l, a+h+1);
}

int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    copy(b, a, n);
    
    cout<<"Size of array: "<<n<<"\n\n";
    copy(a, b, n);
    execute("Merge Sort", a, n, merge_sort);

    copy(a, b, n);
    execute("Heap Sort", a, n, heap_sort);

    copy(a, b, n);
    execute("Quick Sort", a, n, quick_sort);

    copy(a, b, n);
    execute("Inbuilt Sort", a, n, inbuilt_sort);
    
    copy(a, b, n);
    execute("Selection Sort", a, n, selection_sort);

}   