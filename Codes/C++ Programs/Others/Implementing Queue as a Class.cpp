Implementing Queue as a Class

# include<iostream.h>
# include<conio.h>
# define SIZE 20

class queue
{
	int a[SIZE];
	int front;
	int rear;
public:
	queue();
	~queue();
	void insert(int i);
	int remove();
	int isempty();
	int isfull();
};

queue::queue()
{
front=0;
rear=0;
}
queue::~queue()
{
delete []a;
}
void queue::insert(int i)
{
if(isfull())
{
	cout<<"

******
Queue is FULL !!!
No insertion allowed further.
******
";
	return;
}
a[rear] = i;
rear++;
}
int queue::remove()
{
if(isempty())
{
	cout<<"

******
Queue Empty !!!
Value returned will be garbage.
******
";
	return (-9999);
}

return(a[front++]);
}
int queue::isempty()
{
if(front == rear)
	return 1;
else
	return 0;
}
int queue::isfull()
{
if(rear == SIZE)
	return 1;
else
	return 0;
}

void main()
{
clrscr();
queue q;
q.insert(1);
q.insert(2);
cout<<"
"<<q.remove();
cout<<"
"<<q.remove();
cout<<"
"<<q.remove();
getch();
}
