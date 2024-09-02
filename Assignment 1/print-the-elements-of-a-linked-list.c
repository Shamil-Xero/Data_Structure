void printLinkedList(SinglyLinkedListNode* head) {
    for(SinglyLinkedListNode *current = head; current!=NULL; current=current->next){
        printf("%d\n", current->data);
    }
}
