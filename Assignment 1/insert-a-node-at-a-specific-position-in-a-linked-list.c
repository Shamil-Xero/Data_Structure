//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?isFullScreen=false

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode *new = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    new->data = data;
    for (int i = 1; i < position; i++)
    {
        current = current->next;
    }
    new->next = current->next;
    current->next = new;
    return llist;
}
