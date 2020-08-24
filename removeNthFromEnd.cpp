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
 typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }ListNode;
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        typedef struct ListNode node;
		
		node * right; /// first n step
		node * left;
		
		right = head;
		for(int i=1;i<n;i++)
		{
			if(right->next == NULL)
			{
				return head;
			}
			right = right->next;
		}
		//cout<<"right ="<<right->val<<endl;
		
		left = head;
		
		node * temp = NULL;
		//cout<<"left ="<<left->val<<endl;
		while(right->next)
		{
			temp = left;
			left = left->next;
			right= right->next;
		}
		//cout<<"right ="<<right->val<<endl;
		//cout<<"left ="<<left->val<<endl;
		//cout<<"temp ="<<temp->val<<endl;
		if(temp)
		{
			if (left == head)
			{
				return head->next;
			}
			else
			{
				temp->next = left->next;
				return head;
			}
		}
		return head->next;
    }
};

int main()
{
	Solution s;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = NULL;
	
	ListNode * a = s.removeNthFromEnd(&a1,5);
	ListNode *temp =a;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
}