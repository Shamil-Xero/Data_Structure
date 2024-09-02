//https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=false

bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *current1 = head1, *current2 = head2;
    bool same = 1;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data != current2->data)
        {
            same = 0;
        }
        else
        {
            same = 1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 == NULL && current2 == NULL)
    {
        return same;
    }
    else
    {
        return false;
    }
}
