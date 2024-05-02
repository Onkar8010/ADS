#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int publishing_year;
    int ISBN;
    string Book_Tittle;
    string author;
    string location;
    string Avablability;
    int copies;
    struct node *next;
};

node *getnode()
{
    node *temp;
    temp = new node;
    temp -> next = NULL ;
    temp -> Avablability = "YES" ;
    return temp;
}

node *create()
{
    node *temp,*head,*New;
    int isbn,flag,choice,year,b_copies;
    string tittle,writer,b_shell;

    flag = true;
    do
    {
        cout << "Enter Tittle of the book : ";
        cin >> tittle;
        cout << "Enter author : ";
        cin >> writer;
        cout << "Enter number of copies : ";
        cin >> b_copies;
        cout << "Enter ISBN number : ";
        cin >> isbn;
        cout << "Enter Book publishing year : ";
        cin >> year;
        cout << "Enter Book location : ";
        cin >> b_shell;
        New = getnode();
        if(!New)
        {
            cout << "Memory not allocated.";
        }
        else
        {
            New -> Book_Tittle = tittle;
            New -> author = writer;
            New -> ISBN = isbn;
            New -> publishing_year = year;
            New -> copies = b_copies;
            New -> location = b_shell;
        }
        if(flag==true)
        {
            head = New;
            temp = head;
            flag = false;
        }
        else{
            temp -> next = New;
            temp = New;
        }
        cout << "Press 1 to insert more Books : ";
        cin >> choice;
    } while(choice == 1);  
    return head;
}

void display_all(node *head)
{
    node *temp;
    temp = head ;
    if(temp==NULL)
    {
        cout << "List is empty.";
    }
    else
    {
        while(temp != NULL)
        {
            cout << "\n---------------------------------------------------------------\n";
            cout <<"Book Tittle : " <<temp -> Book_Tittle << endl;
            cout << "Author : " << temp -> author << endl;
            cout << "ISBN number : " << temp -> ISBN << endl;
            cout << "Publishing Year : " << temp -> publishing_year << endl;
            cout << "No of Copies : " << temp -> copies << endl;
            cout << "Availability : " << temp -> Avablability << endl;
            cout <<"Location : " << temp -> location << endl;
            temp = temp -> next;
        }
        cout << "\n===============================================================\n";

    }
}


node *insert_book(node *head)
{
    node *temp,*New;
    int year,b_copies,isbn;
    string tittle,writer,b_shell;
    New = getnode();
    if(!New)
    {
        cout << "Node is not created.";
        return head;
    }    
    cout << "Enter Tittle of the book : ";
    cin >> New -> Book_Tittle;
    cout << "Enter author : ";
    cin >> New -> author;
    cout << "Enter number of copies : ";
    cin >> New -> copies;
    cout << "Enter ISBN number : ";
    cin >> New -> ISBN;
    cout << "Enter Book publishing year : ";
    cin >> New -> publishing_year;
    cout << "Enter Book location : ";
    cin >> New -> location;
    temp = head;
    if(temp == NULL)
    {
        head = New;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = New;
    }    
    return head;
}

void search_book(node *head)
{
    node *temp;
    int key,flag=0;
    temp = head;
    cout << "Enter ISBN number of book which you want to search : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "Library is empty.";
        return;
    }
    do
    {
        if(temp->ISBN == key)
        {
            flag = 1;
            cout <<"Book Tittle : " <<temp -> Book_Tittle << endl;
            cout << "Author : " << temp -> author << endl;
            cout << "ISBN number : " << temp -> ISBN << endl;
            cout << "Publishing Year : " << temp -> publishing_year << endl;
            cout << "No of Copies : " << temp -> copies << endl;
            cout << "Availability : " << temp -> Avablability << endl;
            cout <<"Location : " << temp -> location << endl;
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != NULL);
    if(flag==0)
    {
        cout << "Data not found."<<endl;
    }
}

void receive_book(node *head)
{
    node *temp;
    int key,flag=0,recieve;
    temp = head;
    cout << "Enter ISBN number of book to add it in library : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "Library is empty.";
        return;
    }
    do
    {
        if(temp->ISBN == key)
        {
            flag = 1;
            cout << "Enter number of copies recieved.";
            cin >> recieve;
            (temp->copies) = ((temp->copies)+recieve);
            cout << "Received Successfully.";
            temp->Avablability = "YES";
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != NULL);
    if(flag==0)
    {
        cout << "Please enter valid ISBN number."<<endl;
    }
}

void update_book(node *head)
{
    node *temp;
    int key,flag=0;
    temp = head;
    cout << "Enter ISBN number of book to update its data : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "Library is empty.";
        return;
    }
    do
    {
        if(temp->ISBN == key)
        {
            flag = 1;
            cout << "---------------------------------------------------------------\n";
            cout << "Previous data : "<<endl;
            cout <<"Book Tittle : " <<temp -> Book_Tittle << endl;
            cout << "Author : " << temp -> author << endl;
            cout << "ISBN number : " << temp -> ISBN << endl;
            cout << "Publishing Year : " << temp -> publishing_year << endl;
            cout << "No of Copies : " << temp -> copies << endl;
            cout << "Availability : " << temp -> Avablability << endl;
            cout <<"Location : " << temp -> location << endl;
            cout << "---------------------------------------------------------------\n";
            cout << "Enter new data to update.";
            cout << "Enter Tittle of the book : ";
            cin >> temp -> Book_Tittle;
            cout << "Enter author : ";
            cin >> temp -> author;
            cout << "Enter number of copies : ";
            cin >> temp -> copies;
            cout << "Enter ISBN number : ";
            cin >> temp -> ISBN;
            cout << "Enter Book publishing year : ";
            cin >> temp -> publishing_year;
            cout << "Enter Availability of the book : ";
            cin >> temp -> Avablability;
            cout << "Enter Book location : ";
            cin >> temp -> location;
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != NULL);
    if(flag==0)
    {
        cout << "Please enter valid ISBN number."<<endl;
    }
}

void issue_book(node *head)
{
    node *temp;
    int key,flag=0,amount;
    temp = head;
    cout << "Enter ISBN number of required book : ";
    cin >> key;
    cout << "Enter number of copies required : ";
    cin >> amount;
    if(temp == NULL)
    {
        cout << "List is empty.";
        return;
    }
    do
    {
        if(temp->ISBN == key)
        {
            flag = 1;
            if((temp->copies) >= amount)
            {   
                (temp->copies) = ((temp->copies)-amount);
                cout << "Issued Successfully."<<endl;
                if((temp->copies) == 0)
                {
                    temp->Avablability = "NO";
                }
            }
            else
            {
                cout << "Required copies are not available."<<endl;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != NULL);
    if(flag==0)
    {
        cout << "Please enter valid ISBN number."<<endl;
    }
}

node *delete_book(node *head)
{
    node *temp,*prev;
    int key,flag=0;
    temp = head;
    cout << "Enter ISBN number of a book which you want to delete : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "List is empty";
        return head;
    }
    do
    {
        if(temp->ISBN == key)
        {
            flag = 1;
            if(temp == head)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    } while (temp != NULL);
    if(flag==0)
    {
        cout << "Data not found."<<endl;
    }
    return head;    
}

int main()
{
    node *head;
    int choice;
    head = create();
    do
    {
        cout << "*********************************************************************************"<<endl;
        cout << "MENU \n1.Insert a book \n2.Issue a book \n3.Receive a book \n4.Search for a book \n5.display all books \n6.Update a book \n7.Delete a book \n8.Exit"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                head = insert_book(head);
                break;

            case 2:
                issue_book(head);
                break;

            case 3 :
                receive_book(head);
                break;

            case 4:
                search_book(head);
                break;

            case 5:
                display_all(head);
                break;

            case 6:
                update_book(head);
                break;

            case 7:
                delete_book(head);
                break;

            case 8:
                exit(1);
        }
        cout << "*********************************************************************************"<<endl;
        cout << "Press 1 to continue : ";
        cin >> choice;
    }while(choice==1);

    return 0;
}