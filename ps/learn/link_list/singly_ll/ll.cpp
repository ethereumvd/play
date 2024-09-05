#include<bits/stdc++.h>
using namespace std;

class node
{
    public :
        int data ;
        char data2 ;
        node* next ;//because the pointer is pointing to a data type of node
};

void free_mem(node* start)
{
    node* dlt = start ;
    while(dlt!=nullptr)
    {
        node* tmp = dlt ;
        dlt = dlt->next ;
        delete tmp ;
    }

}

int search_ll(node* start , int target , int target_2)
{
    node* temp = start ;
    int cnt = 0 ;
    while(temp!=nullptr)
    {
        cnt++;
        if(temp->data==target && temp->data2==target_2)
        {
            return cnt ;
        }
        temp = temp->next ;
    }
    return -1;
}

int main()
{
    //static allocation
    node* node1 = new node ;
    node* node2 = new node ;
    node* head ;

    node1->data = 1 ;
    node1->data2 = 'A' ;
    node2->data = 2 ;
    node2->data2 = 'B' ;
    node1->next = node2 ;
    node2->next = NULL ;
    
    head = node1 ;
    while(head!=NULL)
    {
        cout << head->data <<"\n" ;
        cout << head->data2 <<"\n" ;
        head = head->next ;
    }
    delete node1 , node2 ,head;

    //time for dynamic allocation 
    node* start = NULL ;
    node* tail = NULL ;
    node* temp ;
    bool choice = true ;
    while(choice)
    {
        temp = new node ;

        cout << "enter your data" << "\n" ;
        cin >> temp->data ;
        cin >> temp->data2 ;

        temp->next = NULL ;
        
        //we are trying to fix the start ptr and move the tail pointer ;
        if(start==nullptr) 
        {
            start = temp ;
            tail = temp;
        }
        else 
        {
            tail->next = temp ;
            tail = temp ;
        }

        cout << "enter 1 to continue entering elements or 0 to exit" << "\n";
        cin >> choice ;
        
    }

    node* prnt = start ;
    int cnt = 0 ;
    while(prnt!=nullptr)
    {
        cout<< prnt->data << " " << prnt->data2 << "\n";
        prnt = prnt->next ;
        cnt++ ;
    }
    
    cout << " no of nodes in list :" << cnt << "\n" ;

    cout << "enter the data and data2 you want to search: " << "\n" ;
    int target ; char target_2 ;
    cin >> target >> target_2 ;

    int ans_node = search_ll(start , target ,target_2) ;
    cout << "target was at node number: " << ans_node << "\n" ; 

    free_mem(start) ;

}
