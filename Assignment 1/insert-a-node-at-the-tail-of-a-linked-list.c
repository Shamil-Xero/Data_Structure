//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem?isFullScreen=false

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode *new = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode *current = head;
    new->data = data;
    new->next = NULL;
    if(head==NULL){
        head=new;
    }else{
        while (current->next != NULL)
        {
            current = current->next;
        }
    current->next = new;
    }
    return head;
}
