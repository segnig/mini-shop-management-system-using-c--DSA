# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
using namespace std;
float balance = 0.00;
// user define data type
struct Node{
    string name;
    char date_manufactured[15];
    char expire_date[15];
    int quantity;
    float cost;
    Node* Next;
};
struct history{
    string action;
    char target[25];
    history* next;
};
struct order{
    char his_name[15];
    char his_address[15];
    string his_item;
    int amount;
    order* NXT;
};
struct payment{
    float Balance;
};
// to create empty list
void emtpy_list(){
    Node* head  = NULL;
}
float deposit(float birr){
    return balance = balance+birr;
}
void recharge(){
    cout<<"Enter the amount of birr you want to deposit\n";
}
void check_balance(float balance){
    cout<<"your balance is "<<balance<<" birr.\n";
}
void about_balance(){
    float amount;
    char op;
    int n;
    cout<<"1.  to recharge\n";
    cout<<"2.  to see your balance\n";
    cin>>n;
    if (n==1){
        cout<<"enter amount you want to recharge ::: ";
        cin>>amount;
        deposit(amount);
    }
    else if(n==2){
        check_balance(balance);
    }
    else{
        cout<<"invalid input. try again\n";
    }
}

// to add element at the beginning
void insert_at_front(Node** head, history** recent){
    Node* New_Node = new Node();
    cout<<"Enter name of the item you want to insert :-  ";
    cin.ignore();
    getline(cin, New_Node->name);
    cout<<"Enter the manufactured date :::  ";
    cin>>New_Node->date_manufactured;
    cout<<"Enter the Expire date :::  ";
    cin>>New_Node->expire_date;
    cout<<"Enter the the quantity of the item ::::  ";
    cin>>New_Node->quantity;
    cout<<"Enter the cost of item::: ";
    cin>>New_Node->cost;
    New_Node->Next = *head;
    history* recently = new history();
    recently->action = "insertion New item at the beginning of the list.\n";
    recently->next = *recent;
    *recent = recently;
    *head = New_Node;
}
void insert_at_last(Node **head, history** recent){
    Node* New_Node = new Node();
    Node* temp = *head;
    cout<<"Enter name of the item you want to insert :::  ";
    cin.ignore();
    getline(cin, New_Node->name);
    cout<<"Enter the manufactured date :::  ";
    cin>>New_Node->date_manufactured;
    cout<<"Enter the Expire date :::  ";
    cin>>New_Node->expire_date;
    cout<<"Enter the the quantity of the item :::  ";
    cin>>New_Node->quantity;
    cout<<"Enter the cost of item ::: ";
    cin>>New_Node->cost;
    New_Node->Next = NULL;
    while(temp->Next != NULL){
        temp = temp->Next;
        }
    temp->Next = New_Node;
    history* recently = new history();

    recently->action = "insertion New item at the end of the list.\n";
    recently->next = *recent;
    *recent = recently;
    return;
}
void display(Node *head){
    cout<<setw(20)<<"Type of item" <<setw(15)<<"manuf_date"<<setw(15)<<"expire Date";
    cout<<setw(10)<<"quantity"<<setw(8)<<"Cost\n";
    Node* temp = head;
    int n = 1;
    while (temp != NULL){


        cout<<setw(3)<<n<<setw(17)<<temp->name<<setw(15)<<temp->date_manufactured;
        cout<<setw(15)<<temp->expire_date<<setw(10)<<temp->quantity<<setw(8)<<temp->cost<<endl;
        n++;
        temp = temp->Next;
    }

}

void display_History(history* recent){
    history* New_history = recent;
    if (New_history == NULL){
        cout<<"No history recorded \n";
    }

    else {
        int n = 1;

        cout<<setw(30)<<"YOUR RECENT ACTION\n";
        while(New_history != NULL){
            cout<<setw(20)<<n<<"\t"<<New_history->action;
            New_history = New_history->next;
            n++;

        }
    }
}
void clear_history(history** recent) {
    history* temp =  NULL;
    *recent = temp;
    cout<<setw(24)<<"================\n";
    cout<<setw(25)<<"\nHISTORY CLEARED!\n";
    cout<<setw(24)<<"================\n";
}
bool Search(Node* head, string key){
    Node* temp = head;
    if (head == NULL){
        return 0;
    }
    else{
        while(temp != NULL){
            if (temp->name == key){
                break;
            }
            temp = temp->Next;
        }
        if (temp == NULL){
            return false;
        }
        else{
        return true;
        }
    }

}
bool Is_empty(Node* head){
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}

//
void welcome(){
    cout<<"-----------------------------------\n";
    cout<<setw(26)<<"SECTION 11   GROUP 9"<<endl;
    cout<<"-----------------------------------\n";
}
void To_Order(order** first,Node* head){
    order* NEW = new order();
    order* temp = *first;
    Node* temp1 = head;
    if(head == NULL){
        cout<<"Not items on the list\n";
    }
else{
    float price;
    cout<<"Enter your Name ::: ";
    cin>>NEW->his_name;
    cout<<"Enter your address ::: ";
    cin>>NEW->his_address;
    cout<<"\nEnter type item you want buy::: ";
    cin.ignore();
    getline(cin, NEW->his_item);
    NEW->NXT = NULL;
    while(temp1->name != NEW->his_item){
        temp1 = temp1->Next;
        }
    if (!Search(head, NEW->his_item)){
        cout<<"\t\tThe item is not found\n";
    }
    else{

        int amount;

        cout<<"Enter the amount :::: ";
        cin>>NEW->amount;
        price = temp1->cost*NEW->amount;
       if (balance<price) {
        cout<<"YOUR BALANCE INSUFFICIENT!!\n PLEASE RECHARGE YOUR ACCOUNT!\n";
       }
       else if (NEW->amount > temp1->quantity ){
           cout<<setw(30)<<"===================\n";
           cout<<setw(30)<< "your Order too much\n";
            cout<<setw(30)<<"===================\n";
        }
        else{

        if (*first == NULL){
            *first = NEW;
            cout<<"It is price = "<<NEW->amount*temp1->cost<<endl;
        }


        else{
        while(temp->NXT != NULL){
            temp = temp->NXT;
        }
        temp->NXT = NEW;
        cout<<"It is price = "<<amount*temp1->cost<<endl;
        }
        balance -= price;
        }
    }
}
}

void see_the_order(order* first){
    order* temp = first;
    if (first == NULL){
        cout<<"NO ORDED yet\n";
    }
    else{
        cout<<setw(17)<<"Name"<<setw(17)<<"Address"<<setw(15)<<"His Ordered"<<setw(20)<<"Amount"<<endl;
        while(temp != NULL){
            cout<<setw(17)<<temp->his_name<<setw(17)<<temp->his_address<<setw(15)<<temp->his_item<<setw(20)<<temp->amount<<endl;
            temp = temp->NXT;
        }
    }
}
// menu function
void menu_manage(){
    cout<<setw(5)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    cout<<setw(20)<<"| MENU |\n";
    cout<<setw(5)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";

    //cout<<" 1. To create list .   \n";
    cout<<" 1. To add the item.   \n";
    cout<<" 2. To Delete the item.  \n";
    cout<<" 3. To display the item in the store. \n";
    cout<<" 4. To search item\n";
    cout<<" 5. To see ordered\n";
    cout<<" 6. History\n";
    cout<<" 7. to clean History\n";
    cout<<" 8. to sell items\n";
    cout<<" 9. To exit.\n";


    cout<<"ENTER YOUR OPTION :- ";
}
void To_sell(order* first, history ** recent, Node* head){
    order* temp = first;
    Node* temp1 = head;


    if(temp == NULL){
        cout<<"NO ORDED\n";
    }
    else{
        while(temp1->name != temp->his_item){
        temp1 = temp1->Next;
        }
        balance -=temp->amount * temp1->cost;
        temp1->quantity -= temp->amount;
        first = first->NXT;
        cout<<setw(25)<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
        cout<<setw(30)<<"successfully sold!!\n";
        cout<<setw(25)<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
        history* temp = new history();
        temp->action ="selling item.\n";
        temp->next = *recent;
        *recent = temp;

    }
}
void menu_costumer(){
    cout<<setw(5)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    cout<<setw(20)<<"| MENU |\n";
    cout<<setw(5)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    cout<<setw(20)<<"1\t"<<"To see the item on the list.\n";
    cout<<setw(20)<<"2\t"<<"To search the item on the list.\n";
    cout<<setw(20)<<"3\t"<<"To order item.\n";
    cout<<setw(20)<<"4\t"<<"about your balance\n";
    cout<<setw(20)<<"5\t"<<"To exit\n";
    cout<<"ENTER YOUR OPTION :- ";
}
void menu_main(){
    cout<<setw(5)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    cout<<setw(20)<<"| MENU |\n";
    cout<<setw(5)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    cout<<setw(20)<<"1 . "<<"for shop manager\n";
    cout<<setw(20)<<"2 . "<<"for costumer.\n";
    cout<<setw(20)<<"3 . "<<"for exit.\n";
    cout<<"|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n";
    cout<<"ENTER YOUR OPTION :- ";

}


void Search_item(Node* head, history** recent){
    Node* temp = head;
    string key;
    if (head == NULL){
        cout<<"No item in the List!\n";
    }
    else{
        cout<<"Enter the type of Items you want to search:- \n";
        cin.ignore();
        getline(cin, key);
        history* recently = new history();
        recently->action = "searching item on  the list.\n";
        recently->next = *recent;
        *recent = recently;
        while(temp != NULL){
            if (temp->name == key){
                break;
            }
            temp = temp->Next;
        }
        if (temp == NULL){
            cout<<"The items is not found on the list\n";
        }
        else{
        cout<<"\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
        cout<<setw(25)<<"THE ITEM IS FOUND\n";
        cout<<"\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
        cout<<setw(18)<<" "<<"type of item:  "<<temp->name<<endl;
        cout<<setw(18)<<" "<<"Amount :  "<<temp->quantity<<endl;
        cout<<setw(18)<<" "<<"Price :  "<<temp->cost<<endl;
        }
    }
}

void Delete(Node** head, history** recent){
    string key;

    if (*head == NULL){
        cout<<"The list is Empty!\n";
    }
    else{
        Node* Left_Node = *head;
        Node* current = Left_Node->Next;
        cout<<"Enter the Type of item  want to delete :- ";
        cin.ignore();
        getline(cin, key);
        if (Left_Node->name == key){
            *head = current;
            cout<<setw(25)<<"\nSUCCESFULY DELETED\n";
            cout<<setw(20)<<"Type of item" <<setw(15)<<"manuf_date"<<setw(15)<<"expire Date";
            cout<<setw(10)<<"quantity"<<setw(8)<<"Cost\n";
            cout<<setw(3)<<setw(17)<<Left_Node->name<<setw(15)<<Left_Node->date_manufactured;
            cout<<setw(15)<<Left_Node->expire_date<<setw(10)<<Left_Node->quantity<<setw(8)<<Left_Node->cost<<endl;
            delete Left_Node;
            history* recently = new history();
            recently->action = "Deleting item on  the list.\n";
            recently->next = *recent;
            *recent = recently;
            }
        else{
            while (current->Next != NULL){
            if(current->name != key){
                Left_Node = current;
                current = current->Next;
            }
            else{
                break;
            }
            }
            if  (current->name == key){
                Left_Node->Next = current->Next;
                cout<<setw(25)<<"\nSUCCESFULY DELETED\n";
                cout<<setw(20)<<"Type of item" <<setw(15)<<"manuf_date"<<setw(15)<<"expire Date";
                cout<<setw(10)<<"quantity"<<setw(8)<<"Cost\n";
                cout<<setw(3)<<setw(17)<<Left_Node->name<<setw(15)<<Left_Node->date_manufactured;
                cout<<setw(15)<<Left_Node->expire_date<<setw(10)<<Left_Node->quantity<<setw(8)<<Left_Node->cost<<endl;
                delete (current);
                history* recently = new history();
                recently->action = "Deleting item on  the list.\n";
                recently->next = *recent;
                *recent = recently;
            }
        }
    }

}


//main function
int main(){
    char option, option2,option3;
    welcome();

    Node* head  = NULL;
    history* recent = NULL;
    order* first = NULL;
    a:
    menu_main();
    cin>>option;
    // for management
    switch(option){
case '1':
    menu_manage();
    cin>>option2;
    switch (option2){
    case '1':
        int n;
        cout<<"How many items you want to enter::::";
        cin>>n;
        for (int m = 0; m<n; m++){
            if (Is_empty(head)){
                insert_at_front(&head, &recent);
            }
            else{
                cout<<"\n1.  To add at the  front\n";
                cout<<"2.  To add the last \n";
                cin>>option2;
                switch(option2){
                case '1':
                    insert_at_front(&head, &recent);
                    break;
                case '2':
                    insert_at_last(&head, &recent);
                    break;
                default:
                    cout<<"Your option is invalid!\n";
                }
            }
        }
        break;
case '2':
    Delete(&head, &recent);
    break;
case '3':
        if(Is_empty(head)){
            cout<<"\t\t\t===================\n";
            cout<<"\t\t\tTHE LIST IS EMPTY !\n";
            cout<<"\t\t\t===================\n";
        }
        else{
            display(head);
        }
        break;
case '4':
    Search_item(head, &recent);
    break;

case '5':
    see_the_order(first);
    break;

case '6':
    display_History(recent);
    break;
case '7':
    clear_history(&recent);
case '8':
    To_sell(first, &recent, head);
    break;
case '9':
    return 0;
default:
        cout<<"\nYour input is invalid. please try again!\n";
    }
    break;

//for costumer
case '2':
    menu_costumer();
    cin>>option3;
    switch(option3){
case '1':
    display(head);
    break;
case '2':
    Search_item(head, &recent);
    break;
case '3':
    To_Order(&first,head);
    break;
case '4':
    about_balance();
    break;
case '5':
    return 0;
    break;
default:
    cout<<"Your input is Invalid! TRY AGAIN\n";
}
break;
case '3':
    return 0;
    }
    //system("cls");
    goto a;
    return 0;
}
