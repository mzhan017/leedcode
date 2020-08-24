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

	void recursion(string prefix, string & digits, vector<string> & rtn,vector<string> & a)
	{
		if (digits.size()==1)
		{
			int digit = atoi(digits.substr(0,1).c_str());
			for (auto b: a[digit-2])
			{
				//prefix = prefix+b;
				rtn.push_back(prefix+b);
			}
			return;
		}
		else if(digits.size()>0)
		{
			int digit = atoi(digits.substr(0,1).c_str());
			for (auto b: a[digit-2])
			{
				string temp = prefix+b;
				string temp2 = digits.substr(1);
				recursion(temp,temp2, rtn,a);
			}
			
		}
		
		
	}
    vector<string> letterCombinations(string digits) {
		vector<string> a={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> rtn;
		recursion("",digits, rtn, a);
		return rtn;
    }
	
public:
	//static vector<string> a={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};
int main()
{
	Solution s;
	vector<string> d=s.letterCombinations("234");
	for(auto b:d)
	{
		cout<<b<<endl;
	}
}