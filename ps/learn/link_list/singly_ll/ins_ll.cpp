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
void ins_at_any_pos(node* start)
{
    int inp ;
    char inp2 ;
    int node_pos ;
    cout << " enter data and data2 and the node number at which you want to insert"<< "\n" ;
    cin >> inp >> inp2 >> node_pos ;

    node* iter = start ;

    int flag =0 ;
    node* new_node = new node ;
    new_node->data = inp ;
    new_node->data2 = inp2 ;
    new_node->next = NULL ;
    while(iter!=nullptr)
    {
        flag++;
        if(flag==node_pos)
        {
            node* temp = iter->next ;
            iter->next = new_node ;
            new_node->next = temp ;
        }
        else 
        {
            iter = iter->next ;
        }
    }
    print_ll(start) ;

}
void ins_at_beg_ll(node* start)
{
    int inp ;
    char inp2;
    cout << "enter the data and data2 you want to insert at the start : " << "\n" ;
    cin >> inp >> inp2 ;

    node* temp = start ;
    node* new_data = new node ;
    new_data->data = inp ; 
    new_data->data2 = inp2 ;

    new_data->next = start ;
    start = new_data ;

    cout << " ll after insertion : " << "\n" ;
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

        cout << " enter data and data2 : " << "\n";
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

        cout << "enter 1 if you want to continue entering elements :" << "\n" ;
        cin >> choice ;


    }

//    ins_at_beg_ll(start) ;
    ins_at_any_pos(start);

    free_mem(start);
    
}
