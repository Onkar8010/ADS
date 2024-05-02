#include <iostream>
using namespace std;
#define MAX 10

class Hashing
{
    struct node
    {
        int music_no;
        string song_name,singer;
        node *next;
    };
    node *hashT[MAX];
    public :
        Hashing()
        {
            int i;
            for(i=0;i<MAX;i++)
            {
                hashT[i]=NULL;
            }
        }

        void insert()
        {
            node *ptr,*temp;
            int addr;
            temp = new node;
            cout << "Enter the unique music number : ";
            cin >> temp->music_no;
            cout << "Enter name of the music : ";
            cin >> temp->song_name;
            cout << "Enter name of the singer : ";
            cin >> temp->singer;
            addr = temp -> music_no%MAX;
            temp->next = NULL;
            if(hashT[addr] == NULL)
            {
                hashT[addr] = temp;
            }
            else
            {
                ptr = hashT[addr];
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next=temp;
            }
        }

        void search()
        {
            node *ptr;
            int key,addr;
            cout << "Enter music number to search the music : ";
            cin >> key;
            addr = key%MAX;
            ptr=hashT[addr];
            while(ptr!=NULL && key!=ptr->music_no)
            {
                   ptr=ptr->next;
            }
            if(key==ptr->music_no)
            {
                cout<<ptr->music_no<<"\nKey Found at location::"<<addr;
                // break;
            }
        }

        void deletemusic()
        {
            int addr,key;
            node *ptr,*temp,*prev;
            cout<<"Enter music no for record to be deleted::";
            cin>>key;
            addr=key % MAX;//Mapped Location
            prev=ptr=hashT[addr];
            if(ptr->music_no==key)
            {
                prev=prev->next;
                hashT[addr]=prev;
                delete(ptr);
            }
            else
            {
                while(ptr->next!=NULL && ptr->music_no!=key)
                {
                    prev=ptr;
                    ptr=ptr->next;
                }
                if(ptr->music_no==key)
                {
                    prev->next=ptr->next;
                    delete(ptr);
                }
            }
        }

        void display()
        {
            node *ptr;
            int i;
            cout<<"HASH TABLE\n";
            cout<<"Index\t"<<"Record {music_no, song and singer}\n";
            for(i=0;i<MAX;i++)
            {
                ptr=hashT[i];
                cout<<"\n"<<i<<"::\t";
                while(ptr!=NULL)
                {
                    cout<<ptr->music_no<<"  ";
                    cout<<ptr->song_name<<"  ";
                    cout<<ptr->singer<<"\t";
                    ptr=ptr->next;
                } 
            }
        }
};

int main()
{
      Hashing h;
     
     int choice;
     while (1)
     {
         cout<<"\n------------------------------------------"<<endl;
         cout<<"Operations on Hash Table"<<endl;
         cout<<"\n------------------------------------------"<<endl;
         cout<<"1.Insert element into the table"<<endl;
         cout<<"2.Search element from the key"<<endl;
         cout<<"3.Delete element at a key"<<endl;
         cout<<"4.Display"<<endl;
         cout <<"5.Exit"<<endl;
         cout<<"Enter your choice: ";
         cin>>choice;
         switch(choice)
         {
         case 1:
            h.insert();
            break;
         case 2:
           	h.search();
            break;
         case 3:
            h.deletemusic();
            break;
         case 4:
            h.display();
            break;
        case 5:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
        }
    }
}
