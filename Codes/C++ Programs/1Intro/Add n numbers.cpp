#include < iostream.h >

int main()
{
    int n, sum = 0, c, value;
    cout<<"Enter the number of integers you want to add\n";
    cin>>n;
    cout<<"Enter"<<n<<"integers"<<"\n";
    for (c = 1; c <= n; c++)
        {
            cin>>value;
            sum = sum + value;
            /*adding each no in sum*/
        }
    cout<<"Sum of entered integers ="<<sum<<"\n";
    return 0;
}