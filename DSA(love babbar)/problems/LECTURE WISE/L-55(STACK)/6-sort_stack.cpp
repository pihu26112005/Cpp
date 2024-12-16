// TC - O(n*n)   SC - O(n)
// my method

#include<iostream>
#include<stack>
using namespace std;

int true_position(stack<int> s,int& number , int& count)
{
	int num ;
	if(!s.empty())
	{
	 	if(number > s.top())
	 	{
	 		return count ;
	 	}
	 	else
	 	{
	 		count++;
	 		s.pop();
	 		num = true_position(s, number, count);
	 	return num ;
	 	}
	}

	else
	{
		return count ;
	}

}

void insert(stack<int> &st , int& number , int& position, int& count)
{
	if(count == position)
	{
		st.push(number);
		return ;
	}
	else
	{
		count++;
		int temp = st.top();
		st.pop();
		insert(st,number,position,count);
		st.push(temp);
	return ;
	}
}

void sort(stack<int> &st)
{
	if(st.empty())
	{
		return ;
	}
    else 
    {
    int num = st.top();
	st.pop();
	sort(st);
	int count1 = 0;
	int position = true_position(st,num,count1);
	int count2 = 0;
	insert(st,num,position,count2);
    return ;
    }
}

int main()
{
    stack<int> s ;
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(1);

    sort(s);

    for (int i = 0; i < 4; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

}