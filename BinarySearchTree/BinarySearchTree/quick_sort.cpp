#include <iostream>
using namespace std;

void swap(int& first, int& second)
{
    int sum = first + second;
    first = sum - first;
    second = sum - second;
}
int Partition(int* _array, int start, int end)
{
    int i = start - 1;
    int j = start;
    int &pivot = _array[end];
    while( j <= end-1 )
    {
        if(_array[j] <= pivot )
        {
            swap(_array[++i], _array[j]);
        }
        ++j;
    }
    swap(_array[++i], pivot);
    return i;

}

void quick_sort(int* _array, int start, int end)
{
    if( start < end)
    {
        int partition = Partition(_array, start, end);
        quick_sort(_array, start, partition-1 );
        quick_sort(_array, partition + 1, end);
    }
 
}