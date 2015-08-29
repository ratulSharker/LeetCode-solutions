#include <iostream>
using namespace std;
 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode *answer = new ListNode(0);	

	//find the longest
	ListNode *temp1, *temp2;	
	for(temp1 = l1, temp2 = l2; temp1 != NULL && temp2 != NULL; temp1 = temp1->next, temp2 = temp2->next);

	

	//our goal is to temp1 will point to the longest chain	
	if(temp1 == NULL && temp2 != NULL)	
	{
		//temp2 points to the longest chain
		//swapping
		temp1 = l2;
		temp2 = l1;
	}
	else
	{
		temp1 = l1;
		temp2 = l2;
	}


	int valueAtTenthDigit = 0;	
	ListNode *tempAnswer = answer;
	while(true)
	{
		//add the numbers
		int result = temp2->val + temp1->val + valueAtTenthDigit;
		valueAtTenthDigit = result / 10; //it's got the second digit
		
		result = result % 10;	//it's got the first digit

		tempAnswer->val = result;
		
		if(temp2->next != NULL)
		{
			tempAnswer->next = new ListNode(0);
			tempAnswer = tempAnswer->next;
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		else
		{
			temp2 = temp2->next;
			temp1 = temp1->next;
			break;
		}
	}

	//continue the long chain
	for(; temp1!= NULL ; temp1 = temp1->next)
	{
		int result = temp1->val + valueAtTenthDigit;
		valueAtTenthDigit = result / 10;
		
		result = result % 10;
		
		tempAnswer->next = new ListNode(result);
		tempAnswer = tempAnswer->next;
	}

	//for the remaining digit, if it's non zero then add it
	if(valueAtTenthDigit)
	{
		tempAnswer->next = new ListNode(valueAtTenthDigit);		
	}

	return answer;
    }
};


int main()
{
	//243 & 564

	ListNode *list243 = new ListNode(2);	
	list243->next = new ListNode(4);
	list243->next->next = new ListNode(3);

	ListNode *list1889 = new ListNode(1);	
	list1889->next = new ListNode(8);
	list1889->next->next = new ListNode(8);
	list1889->next->next->next = new ListNode(9);


	Solution solution;
	ListNode *answer = solution.addTwoNumbers(list243, list1889);


	for(ListNode *temp = answer; temp != NULL ; temp = temp->next)
	{
		cout<<temp->val;
	}
	
	cout<<endl;
	return 1;
	
}
