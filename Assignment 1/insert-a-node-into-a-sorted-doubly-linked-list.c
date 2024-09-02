//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=false

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
    new->data= data;

    if (llist == NULL || llist->data >= data) {
        new->next = llist;
        if (llist != NULL) {
            llist->prev = new;
        }
        return new;
    }

    DoublyLinkedListNode* current = llist;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    new->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new;
    }
    current->next = new;
    new->prev = current;

    return llist;
}
