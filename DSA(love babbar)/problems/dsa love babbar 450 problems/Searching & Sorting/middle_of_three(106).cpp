// only using 3 comparision .................................................
#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

int middleOfThree(int x, int y, int z)

{

    if(x>y)

    {

        swap(x,y);

    }  

    if(y>z)

    {

        swap(y,z);

    }  

    if(x>y)

    {

        swap(x,y);

    }  

    return y;   

}