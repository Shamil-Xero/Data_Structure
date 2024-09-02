// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=false

void printLinkedList(SinglyLinkedListNode *head)
{
    for (SinglyLinkedListNode *current = head; current != NULL; current = current->next)
    {
        printf("%d\n", current->data);
    }
}
