#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}


// step to solve 
// find the mid of the linked list
// make two recursive calls
// merge two sorted linked list
// return the final head;
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
// function to find the mid
Node* getmid(Node* head){
	if(head==NULL) return head;
	Node* slow=head;
	Node* fast=head;
	while(fast->next != NULL and fast->next->next != NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    
	if(head1==NULL)
	  return head2;
	if(head2==NULL)
	  return head1;
	Node* fh;
	Node* ft;
	
	
	if(head1->data<=head2->data){
		fh=head1;
		ft=head1;
		head1=head1->next;
	}
	else{
		fh=head2;
		ft=head2;
		head2=head2->next;
	}

	while(head1 !=NULL and head2 !=NULL){
		if(head1->data<=head2->data){
			// update the tail 
			ft->next=head1;
			ft=head1;
			head1=head1->next;
		}
		else{
			ft->next=head2;
			ft=head2;
			head2=head2->next;
		}

	}

	if(head1 !=NULL){
		ft->next=head1;
	}
	if(head2 != NULL){
		ft->next=head2;
	}

	return fh;
}


Node *mergeSort(Node *head)
{
	// base  case
	if(head==NULL or head->next==NULL) return head;
	Node* mid=getmid(head);

	Node* halfpart1=head;
	Node* halfpart2=mid->next;
	mid->next=NULL;
	// make recursive call
	halfpart1=mergeSort(halfpart1);
	halfpart2=mergeSort(halfpart2);
	Node* finalhead=mergeTwoSortedLinkedLists(halfpart1,halfpart2);
	return finalhead;
}