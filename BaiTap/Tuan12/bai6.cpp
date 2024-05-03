SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist==NULL || llist->next==NULL)return llist;
    SinglyLinkedListNode* q1=llist;
    SinglyLinkedListNode* q2;

    q2=q1->next;
    while(q2!=NULL)
    {
        if(q1->data==q2->data)
        {
            q1->next=q2->next;
            free(q2);
            q2=q1->next;
        }
        else{
            q1=q1->next;
            q2=q2->next;
        }
    }
    return llist;
}
