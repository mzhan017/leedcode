/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <string>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        typedef struct ListNode node;
		
		node * right; /// first n step
		node * left;
		node * rtn;
		node * temp;
		
		right= l1;
		left = l2;
		if(left==NULL && right==NULL)
		{
			return NULL;
		}
		else if(left == NULL)
		{
			return right;
		}
		else if(right == NULL)
		{
			return left;
		}
		if(l1->val<l2->val)
		{
			rtn = l1;
			right = right->next;
		}
		else
		{
			rtn = l2;
			left = left->next;
		}
		
		temp = rtn;
		while(right || left)
		{
			//cout<<"1temp="<<temp->val<<";right="<<right->val<<";left="<<left->val<<endl;
			if(!right&&left)
			{
				temp->next = left;
				temp=temp->next;
				left=left->next;
				continue;
			}
			if(!left&&right)
			{
				temp->next = right;
				temp=temp->next;
				right=right->next;
				continue;
			}
			if(right->val<left->val)
			{
				temp->next = right;
				temp=temp->next;
				right=right->next;
			}
			else
			{
				temp->next = left;
				temp=temp->next;
				left=left->next;
			}
			//cout<<"2temp="<<temp->val<<";right="<<right->val<<";left="<<left->val<<endl;
		}
		return rtn;
    }
};

int main()
{
	Solution s;
	ListNode a1(1);
	ListNode a2(4);
	ListNode a3(5);
	ListNode a4(5);
	ListNode a5(7);
	a1.next = &a3;
	a2.next = &a4;
	a3.next = &a5;
	a4.next = NULL;
	a5.next = NULL;
	
	ListNode * a = s.mergeTwoLists(&a1,&a2);
	ListNode *temp =a;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
}