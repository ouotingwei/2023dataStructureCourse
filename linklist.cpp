#include<stdlib.h>

typedef struct tagListNode{
    int data;
    struct tagListNode *next;

}ListNode;  //ListNode == struct 
ListNode *listA;

int InsertAfter(ListNode *p, int value);
int DeleteNode(ListNode *head, ListNode *OldNode);
ListNode *GetPreNode(ListNode *head, ListNode *OldNode);

int main(){

    return 0;
}

int InsertAfter(ListNode *p, int value){
    ListNode *NewNode;
    NewNode = new ListNode;     //pass the location of ListNode in memory to NewNode

    if ( NewNode == NULL ){
        return false;   //configuration failed
    }

    NewNode -> data = value;    //fill in the value of the new node
    NewNode -> next = p -> next;    //link to the new node
    p -> next = NewNode;    //change original link

    return true;    // success
}

int DeleteNode(ListNode *head, ListNode *OldNode){
    ListNode *PreNode;
    if ( head == OldNode ){
        return  false;
    }

    PreNode = GetPreNode(head, OldNode);
    if ( PreNode == NULL ){
        return false;
    }

    PreNode -> next = OldNode -> next;
    delete OldNode;
    
    return true;
}

ListNode *GetPreNode(ListNode *head, ListNode *node){
    ListNode *p, *q;
    p = head;
    q = head -> next;
    while ( (q != NULL) && (q != node) ){
        p = q;
        q = q -> next;
    }

    if( q != NULL ){
        return (p);

    }else{
        return (NULL);
        
    }
}



