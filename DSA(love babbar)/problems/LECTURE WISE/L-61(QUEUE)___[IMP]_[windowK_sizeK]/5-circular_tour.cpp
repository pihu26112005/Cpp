#include<iostream>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
	for(int i=0 ; i<N ; i++)
	{
        bool firstiter = true;
	    bool seconditer = true;
        int sum_petrol = petrol[i]-distance[i];
		if(sum_petrol>=0)
		{
			for(int j=i+1 ; j<N ; j++)
			{
            sum_petrol = sum_petrol + petrol[j]-distance[j];
				if(sum_petrol<0)
				{
					firstiter = false;
                    break;
				}
			}

			if(firstiter)
			{
				for(int k = 0 ; k<i ; k++)
				{
                    sum_petrol = sum_petrol + petrol[k]-distance[k];
					if(sum_petrol < 0)
					{
						seconditer = false ;
                        break;
					}
				}

                if(firstiter && seconditer)
			    {
			    	return i ;
			    }
			}
		}
	}
	return -1 ;
}

int main()
{
    vector<int> p = {5,4,8,4,5,1,5,10} ;
    vector<int> d = {4,5,3,6,9,2,2,10} ;
    int ans = firstCircularTour(p,d,8);
    cout<<ans;
}