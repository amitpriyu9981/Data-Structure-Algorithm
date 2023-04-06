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

Node* merget(Node* head1,Node* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node* finalhead;
    Node* finaltail;
    if(head1->data <= head2->data){
        finalhead=head1;
        finaltail=head1;
        head1=head1->next;
    }else{
        finalhead=head2;
        finaltail=head2;
        head2=head2->next;

    }
    while(head1 != NULL and head2 !=NULL){
        if(head1->data <= head2->data){
            finaltail->next=head1;
            finaltail=head1;
            head1=head1->next;
        }else{
            finaltail->next=head2;
            finaltail=head2;
            head2=head2->next;
        }
    }
    if(head1 != NULL) finaltail->next=head1;
    if(head2 != NULL) finaltail->next=head2;
    return finalhead;
}