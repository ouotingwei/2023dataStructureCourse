#include<iostream>

using namespace std;

struct listnode{
    int data;
    struct listnode* next;
    listnode(int x): data(x), next(NULL){}
};

listnode *create_listnode(int);
listnode *merge_two_list(listnode *, listnode *, int);

int main(){
    int size1 = 0;
    int size2 = 0;
    cout << "list1.size = ";
    cin >> size1;
    listnode *list1 = create_listnode(size1);
    cout << "list2.size = ";
    cin >> size2;
    listnode *list2 = create_listnode(size2);
    
    int mergesize = size1 + size2;

    listnode *head = merge_two_list( list1, list2, mergesize);
    listnode *merge = head;
    while(merge != NULL){
        cout << merge -> data << " ";
        merge = merge -> next;
    }
    
    cout << endl;
    
    return 0;
}

listnode *create_listnode(int size){
    listnode *head = NULL;
    listnode *tail = NULL;

    for(int i = 0; i < size; i++){
        int input;
        cin >> input;
        listnode *node = new listnode(input);
        if(head == NULL){
            head = node;
            tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
    }

    return head;
}

listnode *merge_two_list(listnode *l1, listnode *l2, int merge_size){
    int temp;
    listnode *head = NULL;
    listnode *tail = NULL;

    for(int i = 0; i < merge_size; i++){

        if(l1 != NULL && l2 != NULL){
            if(l1 -> data <= l2 -> data){
                temp = l1 -> data;
                l1 = l1 -> next;
                cout << "1-1" << endl;
            }else{
                temp = l2 -> data;
                l2 = l2 -> next;
                cout << "1-2" << endl;
            }
        }else if(l1 != NULL && l2 == NULL){
            temp = l1 -> data;
            l1 = l1 -> next;
            cout << "touch 2" << endl;
        }else if(l1 == NULL && l2 !=NULL){
            temp = l2 -> data;
            l2 = l2 -> next;
            cout << "touch 3 " << endl;
        }

        //cout << "nowtemp = " << temp << endl;
        
        listnode *node = new listnode(temp);
        if(head == NULL){
            head = node;
            tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
    }

    return head;

}