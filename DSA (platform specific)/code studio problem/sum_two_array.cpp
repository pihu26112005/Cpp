#include<iostream>
using namespace std;
int main()
{
    int arr1[3]={1,2,3};
    int m=3;
    int arr2[3]={7,8,9};
    int n=3;
    int num1 =0;
    int num2 =0;
    int final[3];
    for (int i = 0; i < m; i++)
    {
        num1 = num1*10 + arr1[i];
    }
    cout<<num1<<endl;
    for (int i = 0; i < m; i++)
    {
        num2 = num2*10 + arr2[i];
    }
    cout<<num2<<endl;
    int num = num1 + num2;
    cout<<num<<endl;
    for (int i = 0; i < 3; i++)
    {
        final[3-(i+1)]=num%10;
        num = num / 10;
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<final[i]<<" ";
    }
    
}