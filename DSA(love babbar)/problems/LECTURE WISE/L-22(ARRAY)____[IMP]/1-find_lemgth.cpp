#include<iostream>
using namespace std;
int man()
{
    char name[10];
    cout<<"enter"<<endl;
    cin>>name;
    int count =0;
    for (int i = 0; name[i]!='\0'; i++)
    {
        count++;
    }
    cout<<"length of input name is "<<count<<endl;
}