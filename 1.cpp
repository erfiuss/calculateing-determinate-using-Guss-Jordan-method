#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
int det (vector<vector<int>> A)
{
    if (A.size() == 2)
    {
        int a = 0;
        a = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        return a;     
    }
    else
    {
        int a = 0;
        int e = 0;
        for (int k = 0; k < 3; k++)
        {
            vector<vector<int>> B;
            for (int i = 0; i < A.size(); i++)
            {
            vector<int>b;
            for (int j = 0; j < A[i].size(); j++)
                {
                    if (j != k && i > 0) 
                    {   
                        b.push_back(A[i][j]);
                    }
                }   
                if (b.size() > 0)
                {
                    B.push_back(b);
                }
            }
            e = pow(-1, k+2)*A[0][k]*det(B);
            a += e;
        }
        return a;
    }
}
int main()
{
    vector<vector<int>> A = {{3,6,5},{4,4,2},{2,3,1}};
    int a = 0;
    a = det(A);
    cout << a;
    return 0;
}