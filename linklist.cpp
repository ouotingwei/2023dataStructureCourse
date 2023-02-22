//LinkList practice - dynamically configure nodes
//TingWeiOu

#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

typedef struct tagListNode{
    int data;
    struct tagListNode *next;

}ListNode;  //defind : ListNode == struct 
ListNode *listA;        //returns the location of the node in memory

int InsertAfter(ListNode *, int);
int DeleteNode(ListNode *, ListNode *);
int InsertTail(ListNode *, int);
ListNode *GetPreNode(ListNode *, ListNode *);
void ListTraverse(ListNode *);


int main(int argc, char *argv[]){

    ListNode *p;

    

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
        return  false;      //cannot delete the first node
    }

    PreNode = GetPreNode(head, OldNode);    //find the privious node
    if ( PreNode == NULL ){
        return false;   //OldNode is not in the list
    }

    PreNode -> next = OldNode -> next;  //delete the original node by skipping
    delete OldNode;     //return deleted node
    
    return true;
}

int InsertTail(ListNode *head, int value){       //adding new node to tail
    ListNode *NewNode, *p = head;
    NewNode = new ListNode;
    if(NewNode == NULL){
        return false;
    }

    NewNode -> data = value;
    NewNode = NULL;
    while( p -> next != NULL){
        p = p -> next;
    }

    p -> next = NewNode;
    return true;

}

ListNode *GetPreNode(ListNode *head, ListNode *node){
    ListNode *p, *q;
    p = head;
    q = head -> next;   //p on the left & q on the right
    while ( (q != NULL) && (q != node) ){       //not yet grounded and not yet found
        p = q;
        q = q -> next;      //each step to the right
    }

    if( q != NULL ){
        return (p);     //success

    }else{
        return (NULL);      //failed
        
    }
}

void ListTraverse(ListNode *head){
    ListNode *p = head;
    p = p -> next;
    while(p){
        cout<< p -> data;
        p = p -> next;
    }
}



