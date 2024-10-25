#include<iostream.h>
using namespace std;

float F(float x)
{
    return 4*x - (x*x)/2;
}

int main()
{
    int i,j,m,n;
    float c,r,M[10][10];
    float h = 1;
    float k = 0.125;
    cout<<"enter the values of c,m,n\n";
    cin>>c>>m>>n;
    r=(c*c*k)/(h*h);
    for(j=0;j<n;j++)
    {
        M[0][j] = 0;
        M[m-1][j] = 0;
    }
    for(i=1;i<m-1;i++)
    {
        M[i][0] = F(i*h);
    }
    for(j=0;j<n;j++)
    {
        for(i=1;i<m-1;i++)
        {
            M[i][j+1] = r*(M[i-1][j]+M[i+1][j])+(1-2*r)*(M[i][j]);
        }
    }
    cout<<"solution of heat equation\n";
    for(j=n-1;j>=0;j--)
    {
        for(i=0;i<m;i++)
        {
            cout<<M[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
