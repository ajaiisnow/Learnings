#include <iostream>
using namespace std;

//void swap(int& a, int &b)
//{
//    int sum = a+b;
//    a = sum - a;
//    b = sum - b;
//}
//
//void quick_sort(int *_array, int start, int end)
//{
//    int pivot = end;
//    int i = start -1;
//    int j = start;
//    while( j < pivot-1)
//    {
//        while (_array[j] > _array[pivot])
//        {
//            // till you find a value greater than the pivot element 
//            // increment.
//            ++j;
//        }
//        // else you found a value less than the pivot element and so swap with the first element in the array.
//        ++i;
//        swap(_array[i], _array[j]);
//    }
//    swap( _array[i+1], _array[pivot]);
//    quick_sort( _array, start, i-1);
//    quick_sort( _array, i+1, end);
//}