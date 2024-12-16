// search element || --> array along row and column sorted hai 


#include<iostream>
using namespace std;

    int main() 
    {
        int target ;
        cin>>target;
        int row =5,col=5;
        int matrix[row][col] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

        int rowIdx = 0;
        int colIdx = col - 1;

        while(rowIdx < row && colIdx >= 0){
            int val = matrix[rowIdx][colIdx];

            if(val == target){
                return true;
            }
            if(val < target){
                rowIdx++;
            }
            else colIdx--;
        }

        return false;
    }