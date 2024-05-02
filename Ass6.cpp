//Assignment to store medical record like patient information, medical history, treatement plans using the concept of Hashing (Linear Probing)
#include <iostream>
using namespace std;
#define MAX 10

class Hashing
{
    struct node
    {
        int patient_no;
        string patient_name, disease, addmision_date, doctor_name, room_no;
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
            int addr;
            node *temp;
            temp = new node;
            cout << "Enter Patient number : ";
            cin >> temp->patient_no;
            cout << "Enter Patient name : ";
            cin >> temp->patient_name;
            cout << "Enter Patient's disease : ";
            cin >> temp->disease;
            cout << "Enter the room no of the patient : ";
            cin >> temp->room_no;
            cout << "Enter the admission date of the patient : ";
            cin >> temp->addmision_date;
            cout << "Enter the Doctor name : ";
            cin >> temp->doctor_name;
            addr = temp->patient_no % MAX;
            if(hashT[addr] == NULL)
            {
                hashT[addr] = temp;
            }
            else
            {
                while(addr != MAX)
                {
                    addr++;
                    if(hashT[addr] == NULL)
                    {
                        hashT[addr] = temp;
                        break;
                    }
                }
            }
        }
        
        void search()
        {
            int addr,key,found=0;
            node *ptr;
            cout << "Enter the patient number to search : ";
            cin >> key;
            addr = key%10;
            while(addr != MAX)
            {
                ptr = hashT[addr];
                if(ptr->patient_no == key)
                {
            	found = 1;
           	cout << "Patient "<<key<<" found at location " << addr ;
                	break;
                }
                addr++;
                
            }
            if(found == 0)
            {
                cout << "Patient not found.";
            }
        }
        
        void deletepatient()
        {
            int addr,key,found=0;
            node *ptr;
            cout << "Enter the patient number to delete ";
            cin >> key;
            addr = key%10;
            while(addr != MAX)
            {
                ptr = hashT[addr];
                if(ptr->patient_no == key)
                {
            	found = 1;
           	hashT[addr] = NULL ;
                	break;
                }
                addr++;
            }
            if(found == 0)
            {
                cout << "Patient not found.";
            }
        }
        
        void display()
        {
            node *ptr;
            int i;
            cout<<"HASH TABLE\n";
            cout<<"Index\t|\t"<<"Patient_no \t Name \t Disease \t Room_no \t Admission \t Doctor_name \n";
            for(i=0;i<MAX;i++)
            {
                ptr=hashT[i];
                cout<<"\n"<<i<<"::\t";
                if(hashT[i] != NULL)
                {
                cout << ptr->patient_no << endl;
                cout << ptr->patient_name << endl;
                cout << ptr->disease << endl;
                cout << ptr->room_no << endl;
                cout << ptr->addmision_date << endl;
                cout << ptr->doctor_name << endl;
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
            h.deletepatient();
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
