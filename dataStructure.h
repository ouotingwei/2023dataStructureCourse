#ifndef dataStructure
#define dataStructure

typedef struct tagListNode{
    int data;
    struct tagListNode *next;

}ListNode;

ListNode *GetPreNode(ListNode *head, ListNode *OldNode){
    ListNode *p, *q;
    p = head;
    q = head -> next;
    while( (q != NULL) && (q != head)){
        p = q;
        q = q -> next;

    }

    if(q != NULL){
        return (p);

    }else{
        return (NULL);

    }
}

int linked_InsertAfter(ListNode *p, int value){
    ListNode *NewNode;
    NewNode = new ListNode;
    if (NewNode == NULL){
        return false;

    }

    NewNode -> data = value;
    NewNode -> next = p -> next;
    p -> next = NewNode;
    
    return true;
}

int linked_DeleteNode(ListNode *head, ListNode *OldNode){
    ListNode *PreNode;
    if(head == OldNode){
        return false;
    
    }

    PreNode = GetPreNode(head, OldNode);
    if(PreNode  == NULL){
        return false;

    }

    PreNode -> next = OldNode ->next;
    delete OldNode;
    return true;

}


#endif 