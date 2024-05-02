#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct node
{
    string tittle;
    string singer;
    string album;
    string generation;
    string duration;
    int release_year;
    struct node *next;
};

node *getnode()
{
    node *temp;
    temp = new node;
    temp -> next = NULL ;
    return temp;
}

node *create()
{
    node *temp,*head,*New;
    int year,flag,choice;
    string song,artist,_album,_generation,_duration;

    flag = true;
    do
    {
        cout << "Enter Tittle of the song : ";
        cin >> song;
        cout << "Enter name of the singer : ";
        cin >> artist;
        cout << "Enter the album name : ";
        cin >> _album;
        cout << "Enter the generation of song : ";
        cin >> _generation;
        cout << "Enter the duration of the song : ";
        cin >> _duration;
        cout << "Enter the release year of the song : ";
        cin >> year;
        New = getnode();
        if(!New)
        {
            cout << "Memory not allocated.";
        }
        else
        {
            New -> tittle = song;
            New -> singer = artist;
            New -> album = _album;
            New -> generation = _generation;
            New -> duration = _duration;
            New -> release_year = year;
        }
        if(flag==true)
        {
            head = New;
            New->next = head;
            temp = head;
            flag = false;
        }
        else{
            temp -> next = New;
            New->next = head;
            temp = New;
        }
        cout << "Press 1 to insert more songs : ";
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
        cout << "Music player is empty.";
    }
    else
    {
            cout << "================================================================================================================================\n";
            cout << "  ";
            cout << setw(20) << left << "|Tittle";
            cout << setw(20) << left << "|Singer";
            cout << setw(20) << left << "|Album";
            cout << setw(20) << left << "|Generation";
            cout << setw(20) << left << "|Duration";
            cout << setw(20) << left << "|Release_year";
            cout << setw(20) << left << "|    |"<<endl;
            cout << "================================================================================================================================\n";
        do
        {
            cout << "  |";
            cout <<setw(19) << left <<temp -> tittle;
            cout << "|";
            cout << setw(19) << left << temp -> singer;
            cout << "|";
            cout << setw(19) << left << left<<temp -> album;
            cout << "|";
            cout << setw(19) << left << temp -> generation;
            cout << "|";
            cout << setw(19) << left << temp -> duration;
            cout << "|";
            cout <<setw(19) << left << temp -> release_year;
            cout << "|";
            cout <<setw(19) << left <<" -> |"<<endl;
            temp = temp -> next;
            
        }
        while(temp != head);
        cout << "================================================================================================================================\n";

    }
}


node *add_song(node *head)
{
    node *temp,*New;
    int year;
    string song,artist,_album,_generation,_duration;
    New = getnode();
    if(!New)
    {
        cout << "Node is not created.";
        return head;
    }    
    cout << "Enter Tittle of the Song : ";
    cin >> New -> tittle;
    cout << "Enter singer : ";
    cin >> New -> singer;
    cout << "Enter album name : ";
    cin >> New -> album;
    cout << "Enter Generation of the song : ";
    cin >> New -> generation;
    cout << "Enter the duration of the song : ";
    cin >> New -> duration;
    cout << "Enter the release year : ";
    cin >> New -> release_year;
    temp = head;
    if(temp == NULL)
    {
        head = New;
        New->next = head;
    }
    else
    {
        do
        {
            temp = temp -> next;
        }while(temp->next != head);
        temp -> next = New;
        New->next = head;
    }    
    cout << "Song inserted successfully."<<endl;
    return head;
}

void search_song(node *head)
{
    node *temp;
    int flag=0;
    string key;
    temp = head;
    cout << "Enter tittle of the song which you want to search : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "Music player is empty.";
        return;
    }
    do
    {
        if(temp->tittle == key)
        {
            flag = 1;
            cout <<"Song Tittle : " <<temp -> tittle << endl;
            cout << "Music singer : " << temp -> singer << endl;
            cout << "Album : " << temp -> album << endl;
            cout << "Generation : " << temp -> generation << endl;
            cout << "Duration : " << temp -> duration << endl;
            cout <<"Release year : " << temp -> release_year << endl;
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != head);
    if(flag==0)
    {
        cout << "Song not found."<<endl;
    }
}

void update_track(node *head)
{
    node *temp;
    int flag=0;
    string key;
    temp = head;
    cout << "Enter song name to update its data : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "Music player is empty.";
        return;
    }
    do
    {
        if(temp->tittle == key)
        {
            flag = 1;
            cout << "---------------------------------------------------------------\n";
            cout << "Previous data : "<<endl;
            cout <<"Song Tittle : " <<temp -> tittle << endl;
            cout << "Music singer : " << temp -> singer << endl;
            cout << "Album : " << temp -> album << endl;
            cout << "Generation : " << temp -> generation << endl;
            cout << "Duration : " << temp -> duration << endl;
            cout <<"Release year : " << temp -> release_year << endl;
            cout << "---------------------------------------------------------------\n";
            cout << "Enter new data to update."<<endl;
            cout << "Enter Tittle of the Song : ";
            cin >> temp -> tittle;
            cout << "Enter singer : ";
            cin >> temp -> singer;
            cout << "Enter album name : ";
            cin >> temp -> album;
            cout << "Enter Generation of the song : ";
            cin >> temp -> generation;
            cout << "Enter the duration of the song : ";
            cin >> temp -> duration;
            cout << "Enter the release year : ";
            cin >> temp -> release_year;
            cout << "Details updated Successfully."<<endl;
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != head);
    if(flag==0)
    {
        cout << "No song with this name is present in your track."<<endl;
    }
}

node *delete_track(node *head)
{
    node *temp,*prev,*ptr;
    int flag=0;
    string key;
    temp = head;
    cout << "Enter name of song which you want to delete : ";
    cin >> key;
    if(temp == NULL)
    {
        cout << "Music player is empty";
        return head;
    }
    while(temp->tittle!=key)
    {
        prev = temp;
        temp = temp->next;
        if(temp == head)
        {
            break;  
        }
    }
    if(temp->tittle == key)
    {
        flag = 1;
        if(temp==head)
        {
            ptr = head;
            do
            {
                ptr = ptr->next;
            } while (ptr->next != head);
            head = temp->next;
            ptr->next = head;
        }
        else{
            prev->next = temp->next;
        }
        cout << "Removed Successfully"<<endl;
        delete temp;
    }
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
        cout << "********************************************************************"<<endl;
        cout << "MENU \n1.Insert a new song \n2.Search for a song \n3.update the song \n4.delete a song \n5.display all songs details \n6.Exit"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                head = add_song(head);
                break;

            case 2:
                search_song(head);
                break;

            case 3 :
                update_track(head);
                break;

            case 4:
                head = delete_track(head);
                break;

            case 5:
                display_all(head);
                break;

            case 6:
                exit(1);
                break;
        }
        cout << "*********************************************************************************************************************************"<<endl;
        cout << "Press 1 to continue : ";
        cin >> choice;
    }while(choice==1);

    return 0;
}
