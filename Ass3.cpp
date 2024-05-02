#include <iostream>
using namespace std;

struct node
{
	string h_name, w_name;
	string h_relation, w_relation;
	node *right;
	node *left;
};

node *getNode()
{
	node *New;
	New = new node;
	cout << "Enter the Husband name : ";
	cin >> New->h_name;
	cout << "Enter the relationship : ";
	cin >> New->h_relation;
	cout << "Enter the Wife name : ";
	cin >> New->w_name;
	cout << "Enter the relationship : ";
	cin >> New->w_relation;
	New->right = NULL;
	New->left = NULL;
	return New;
}

node *create()
{
	node *temp, *ptr, *root = NULL;
	char dir, ch;
	do
	{
		temp = getNode();
		if (root == NULL)
		{
			root = temp;
		}
		else
		{
			ptr = root;
			while (ptr != NULL)
			{
				cout << "Current person : " << ptr->h_name << endl;
				cout << "Enter the Direction(l/r) : ";
				cin >> dir;
				if (dir == 'l')
				{
					if (ptr->left == NULL)
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
					if (ptr->right == NULL)
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
		cout << "Name : " << h->h_name << " | "
			 << "Relation : " << h->h_relation << endl;
		cout << "Name : " << h->w_name << " | "
			 << "Relation : " << h->w_relation << endl;
		dis_inorder(h->right);
	}
}

void dis_preorder(node *h)
{
	if (h != NULL)
	{
		cout << "Name : " << h->h_name << " | "
			 << "Relation : " << h->h_relation << endl;
		cout << "Name : " << h->w_name << " | "
			 << "Relation : " << h->w_relation << endl;
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
		cout << "Name : " << h->h_name << " | "
			 << "Relation : " << h->h_relation << endl;
		cout << "Name : " << h->w_name << " | "
			 << "Relation : " << h->w_relation << endl;
	}
}

int main()
{
	node *h;
	int ch;
	h = create();
	do
	{
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
