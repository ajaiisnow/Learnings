#include <vector>
#include <iostream>

using namespace std;

void solution(vector<int>& A, int K)
{
    int N = A.size();
    int temp = 0;
    int temp2 = 0;
    for (int j = 0; j < K; ++j)
    {
        temp = A[0];
        A[0] = A[N - 1];
        for (int i = 1; i <= N - 1; ++i)
        {
            temp2 = A[i];
            A[i] = temp;
            temp = temp2;
        }
    }
    return;
}

vector<int> A = { 3,8,7,9,6 };
//int main()
//{
//    solution(A, 2);
//    for (int nIndex = 0; nIndex < A.size(); ++nIndex)
//    {
//        cout << A[nIndex] << endl;
//    }
//    return 0;
//}