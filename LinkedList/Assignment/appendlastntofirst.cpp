/*

Node* removedublicate(Node* head){
    if(head==NULL) return head;
    Node* prev=head;
    Node* curr=head->next;
    while(curr != NULL){
        if(prev->data == curr->data){
           prev->next=curr->next;
           curr=curr->next;
        }else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

*/


/*

// problem print the reverse of the linke listt
void printrecursively(Node* head){
    if(head==NULL) return;
    printrecursively(head->next);
    cout<<head->data<<" ";
}

*/
