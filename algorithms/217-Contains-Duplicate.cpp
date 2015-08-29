#include <iostream>
#include <set>
#include <vector>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> collisionSet;
        pair<set<int>::iterator, bool> ret;
        
        
        for(vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
        {
		ret = collisionSet.insert(*it);
		if(ret.second == false)
		{
			//duplicate found
			return true;
		}
        }
        
	
	return false;
    }
};



int main()
{

	Solution solution;
	
	vector<int> input1;
	
	input1.insert(input1.begin(), 10);
	input1.insert(input1.begin(), 20);
	input1.insert(input1.begin(), 30);
	input1.insert(input1.begin(), 40);

	vector<int> input2;
	
	input2.insert(input2.begin(), 10);
	input2.insert(input2.begin(), 20);
	input2.insert(input2.begin(), 20);
	input2.insert(input2.begin(), 40);

	if(solution.containsDuplicate(input1))
	{
		cout<<"input1 contains duplicate"<<endl;
	}
	else
	{
		cout<<"input1 contains no duplicate"<<endl;
	}	


	if(solution.containsDuplicate(input2))
	{
		cout<<"input2 contains duplicate"<<endl;
	}
	else
	{
		cout<<"input2 contains no duplicate"<<endl;
	}	


	return 1;
}
