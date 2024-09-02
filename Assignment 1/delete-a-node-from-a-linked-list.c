//https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem?isFullScreen=false

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode *current = llist;
    if(position == 0){
        llist = llist->next;
    }
    for (int i = 0; i < position-1 ; i++)
        {
            current = current->next;
        }
        current->next=current->next->next;
    return llist;
}
