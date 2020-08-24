#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;
class Solution {
public:

    int close(int i, int j, int target)
	{
		int temp1 = (i>target)? (i-target):(target-i);
		int temp2 = (j>target)? (j-target):(target-j);
		return temp1>temp2?j:i;
	}
    int threeSumClosest(vector<int>& nums, int target) {
		typedef vector<int> VECINT;
        int rtn=100000;
        int N=nums.size();
		time_t now = time(0);
		//cout<<"start:"<<now<<endl;
		sort (nums.begin(),nums.end());
		
        for(int i=0;i<N;i++)
        {
			int j=0;
			int m=N-1;
			while(j<m)
			{
				if(i==j)
				{
					j++;
					continue;
				}
				if(i==m)
				{
					m--;
					continue;
				}
				int sum = nums[i]+nums[j]+nums[m];
				//cout<<"three"<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<" "<< sum <<endl;
				if( sum > target)
				{
					rtn = close(sum, rtn, target);
					m--;
				}
				else if(sum < target)
				{
					rtn = close(sum, rtn, target);
					j++;
				}
				else
				{
					return sum;
				}
			}
        }
		
		now = time(0);
		//cout<<"end:"<<now<<endl;

        return rtn;

    }
};

int main()
{
	Solution s;
	//vector<int> a={-1, 0, 1, 2, -1, -4};
	//vector<int> a={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<int> a={-1,2,3,-4};
	cout<<s.threeSumClosest(a,1)<<endl;
	//cout<<s.threeSum(a);
}