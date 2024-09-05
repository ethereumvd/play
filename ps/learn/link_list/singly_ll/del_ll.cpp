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

void print_ll(node* start)
{
    node* temp = start ;
    while(temp!=nullptr)
    {
        cout << temp->data << " " << temp->data2 << "\n";
        temp = temp->next ;
    }

}
void del_at_any_pos(node* start)
{
    cout << " enter the node you want to delete: " << "\n" ;
    int node_pos ; cin >> node_pos ;

    node* iter = start ;
    int flag = 0 ;
    node* prev_node = NULL ;
    while(iter!=nullptr)
    {
        flag++ ;
        if(flag==node_pos-1)
        {
             prev_node = iter ;
        }
        else
        {
            iter = iter->next ;
        }
    }
    iter = start ;
    flag = 0 ;
    while(iter!=nullptr)
    {
        flag++ ;
        if(flag==node_pos)
        {
            prev_node->next = iter->next ;
        }
        else
        {
            iter = iter->next ;
        }
    }
    delete iter ;

    print_ll(start) ;

}

int main()
{
    node* start = NULL ;
    node* tail = NULL ;
    node* temp = NULL ;
    bool choice = true ;
    while(choice)
    {
        temp = new node ;

        cout << "enter the elements , data and data2" << "\n" ;
        cin >> temp->data >> temp->data2 ;

        if(start==nullptr)
        {
            start = temp ;
            tail = temp ;
        }
        else
        {
            tail->next = temp ;
            tail = temp ;
        }
        cout << " enter 1 if you want to continue: " << "\n" ;
        cin >> choice;
    }

    del_at_any_pos(start) ;

    free_mem(start);
}
