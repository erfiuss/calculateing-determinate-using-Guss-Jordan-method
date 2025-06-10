#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
vector<vector<float>> transpose (vector<vector<float>> A)
{
    vector<vector<float>> C;
    for (int j = 0; j < A[0].size(); j++)
    {
        vector <float> B;
        for (int i = 0; i < A.size(); i++)
        {
            B.push_back(A[i][j]);
        }
        C.push_back(B);
    }
    return C;
}
int det (vector<vector<float>> A)
{
    if (A.size() == 2)
    {
        int a = 0;
        a = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        return a;     
    }
    else
    {
        float a = 0;
        float e = 0;
        float c = 0;
        for (int k = 0; k < 3; k++)
        {
            vector<vector<float>> B;
            for (int i = 0; i < A.size(); i++)
            {
            vector<float>b;
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
            c = pow(-1, k+2)*det(B);
            a += e;
        }
        return a;
    }
}
vector<vector<float>> inv (vector<vector<float>> A)
{
    
    vector<vector<float>> N;
    if (A.size() == 2)
    {
        N = {{A[1][1], -A[0][1]}, {-A[1][0], A[0][0]}};
        int vv = 0;
    }
    
    else
    {
        float a = 0;
        float e = 0;
        float c = 0;
        for (int m = 0; m < A.size(); m++)
        {
            vector<float> V;
            for (int k = 0; k < A.size(); k++)
            {
                vector<vector<float>> B;
                for (int i = 0; i < A.size(); i++)
                {
                    vector<float>b;
                    for (int j = 0; j < A[i].size(); j++)
                    {
                        if (i != m && j != k) 
                        {   
                            b.push_back(A[i][j]);
                        }
                    }
                    if (b.size() > 0)                            
                    {
                        B.push_back(b);
                    }
                }
                c = pow(-1, k+2+m)*det(B);
                cout << "cc" << c << endl;
                V.push_back(c);  
            }
            N.push_back(V);
        }

    }
    vector<vector<float>> E = N;
    //E = transpose(N);
    for(int i = 0; i < E.size(); i++)
    {
        for (int j = 0; j < E.size(); j++)
        {
            cout << E[i][j] << " ";
        }
        cout << endl;
    }
    float cc = 0;
    cc = det(A);
    vector<vector<float>> F;
    for (int i = 0; i < E.size(); i++)
    {
        vector<float> f;
        for (int j = 0; j < E.size(); j++)
        {
            float w = 0;
            w = E[i][j]/cc;
            f.push_back(w);
        }
        F.push_back(f);
    }
    return F;
}
int main()
{
    vector<vector<float>> A = {{2,2,0},{-2,3,10},{2,-3,0}};
    float a = det(A);
    vector<vector<float>> B;
    B = inv(A);
    for(int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << "<<" << a << endl;
    return 0;
}