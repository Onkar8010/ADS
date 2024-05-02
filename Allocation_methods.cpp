#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int *ptr = (int*)malloc(3*sizeof(int));
    if(!ptr)
    {
        cout << "Memory not created";
        exit(1);
    }
    cout <<"Enter 5 values to initialize the pointer : ";
    for(int i=0;i<5;i++)
    {
        cin >> *(ptr+i);
    }
    for(int i=0;i<5;i++)
    {
        cout << *(ptr+i)<<endl;
    }
    free(ptr);
    cout << *(ptr+2);
    return 0;
}
