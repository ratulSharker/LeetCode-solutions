#include <iostream>
#include <map>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	
	map<int, vector<int> >	indexByValue;
	map<int, vector<int> >::iterator mapItr;

	//first is to populate this indexByValue
	unsigned int index = 0;
	for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++, index++)
	{
		mapItr = indexByValue.find(*it);
		if(mapItr == indexByValue.end())
		{
			//value not found, init it with the new vector
			vector<int> indexes;
			indexes.insert(indexes.end(), index+1);	//1 indexing

			//update the map 
			indexByValue.insert(pair<int, vector<int> >(*it, indexes));
		}
		else
		{
			//value found & get the vector out of there
			vector<int> indexes = mapItr->second;
			indexes.insert(indexes.end(), index+1);	//1 indexing
		}
	}

	index = 1;	//one indexed
	unsigned int index2 = 0;
	for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++, index++)
	{
		int value1 = *it;
		int value2 = target - value1;
		
		//find the value 2 in the map
		mapItr = indexByValue.find(value2);
		if(mapItr != indexByValue.end())
		{
			//value 2 found
			//now get the value 2 index
			vector<int> indexes = mapItr->second;
			index2 = *(indexes.begin());
			
			if(index2 != index)
			{
				break;
			}
		}
	}
	
	//swap if needed
	if(index > index2)
	{
		unsigned int temp = index;
		index = index2;
		index2 = temp;
	}
		
	vector<int> ret;
	ret.insert(ret.end(), index);
	ret.insert(ret.end(), index2);
	
	return ret;

    }
};



int main()
{
	
	Solution solution;
	
	vector<int>	nums;
	nums.insert(nums.end(), 1);
	nums.insert(nums.end(), 3);
	nums.insert(nums.end(), 2);
	nums.insert(nums.end(), 5);
	nums.insert(nums.end(), 6);
	nums.insert(nums.end(), 8);
	nums.insert(nums.end(), 3);
	nums.insert(nums.end(), 5);
	nums.insert(nums.end(), 3);
	nums.insert(nums.end(), 2);
	nums.insert(nums.end(), 5);
	nums.insert(nums.end(), 7);
	nums.insert(nums.end(), 7);

	vector<int> ans = solution.twoSum(nums, 6);
	
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout<<"indexes are :: "<< *it <<endl;
	}

	return 1;
}
