SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;

   SinglyLinkedListNode *mergedList;

   if(head1->data<head2->data)
   {
       mergedList = head1;
       head1=head1->next;
   }
   else {
   mergedList=head2;
   head2=head2->next;
   }
   SinglyLinkedListNode *current=mergedList;
   while(head2!=NULL && head1!=NULL)
   {
       if(head1->data<head2->data)
       {
           current->next=head1;
           head1=head1->next;
       }
       else {
       current->next=head2;
       head2=head2->next;
       }
       current=current->next;
   }
   if(head1!=NULL)current->next=head1;
   else current->next=head2;

   return mergedList;
}
