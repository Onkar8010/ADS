#include <iostream>
using namespace std;

struct node
{
    string name, designation;
    int age,salary;
    float experience;
    node *left;
    node *right;
};

node *getNode()
{
    node *New;
    New = new node;
    cout << "Enter name of the Employee : ";
    cin >> New->name;
    cout << "Enter Designation of Employee : ";
    cin >> New->designation;
    cout << "Enter age of Employee : ";
    cin >> New->age;
    cout << "Enter salary of the Employee : ";
    cin >> New->salary;
    cout << "Enter experience of Employee (in years) : ";
    cin >> New->experience;
    New ->left=NULL;
    New->right=NULL;
    return New;
}

node *createBST()
{
    node *temp, *ptr, *root=NULL;
    char ch;
    do
    {
    	cout << "\n```````````````````````````````````````````````````````````````````\n";
        temp = getNode();
        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            ptr = root;
            while(ptr != NULL)
            {
                if(temp->salary < ptr->salary)
                {
                    if(ptr->left == NULL)
                    {
                        ptr->left = temp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->left;
                    }
                }
                else
                {
                    if(ptr->right == NULL)
                    {
                        ptr->right = temp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
            }
        }
        cout << "Want to add more data (y/n) : ";
		cin >> ch;
    } while (ch == 'y');
    return root;
}

void dis_inorder(node *h)
{
	if (h != NULL)
	{
		dis_inorder(h->left);
		cout << "\n```````````````````````````````````````````````````````````````````\n";
		cout << "Name : "<<h->name<<endl;
        cout << "Designation : " << h->designation << endl;
        cout << "Age : " << h->age << endl;
        cout << "Salary : " << h->salary << endl;
        cout << "Experience : " << h->experience <<endl;
		dis_inorder(h->right);
	}
}

void dis_preorder(node *h)
{
	if (h != NULL)
	{
        cout << "\n```````````````````````````````````````````````````````````````````\n";
	cout << "Name : "<<h->name<<endl;
        cout << "Designation : " << h->designation << endl;
        cout << "Age : " << h->age << endl;
        cout << "Salary : " << h->salary << endl;
        cout << "Experience : " << h->experience <<endl;
		dis_preorder(h->left);
		dis_preorder(h->right);
	}
}

void dis_postorder(node *h)
{
	if (h != NULL)
	{
		dis_postorder(h->left);
		dis_postorder(h->right);
		cout << "\n```````````````````````````````````````````````````````````````````\n";
		cout << "Name : "<<h->name<<endl;
        cout << "Designation : " << h->designation << endl;
        cout << "Age : " << h->age << endl;
        cout << "Salary : " << h->salary << endl;
        cout << "Experience : " << h->experience <<endl;
	}
}

int main()
{
	node *h;
	int ch;
	h = createBST();
	do
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Menu \n1.Display Preorder \n2.Display Inorder \n3.Display Postorder\nEnter your choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1: 
				dis_preorder(h);
				break;
			case 2:
				dis_inorder(h);
				break;
			case 3:
				dis_postorder(h);
				break;
			default:
				cout << "Invalid choice.\n";
				break;
		}
		cout << "Enter 1 to display by another order : ";
		cin >> ch;
	} while (ch == 1);

	return 0;
}
