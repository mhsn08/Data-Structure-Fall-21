#include<iostream>

using namespace std;

struct node
{
	string info;
	node * next;
};

class queue
{
	node * head;
	node * rear;
	node * temp;
	int size;
	int length;
public:
	queue(int = 7);
	~queue();
	void enqueue(string);
	void dequeue();
	bool isfull();
	bool isempty();
	string peek();
};

int main()
{
    int no_queues , no_people , op;
    string person_name;
    cout << "How many Queues? ";
    cin >> no_queues;
    queue * que = new queue[no_queues];
    while (1)
    {
        cout << "Choose:" << endl << endl;
        cout << "0. To Exit" << endl;
        cout << "1. Enqueue Person" << endl;
        cout << "2. Dequeue Person" << endl;
        cout << "Choose: ";
        cin >> op;
        if(op == 0)
            break;
        if(op > 2 && op < 1)
        {
            cout << "Invalid Input!" << endl;
            continue;
        }
        if(op == 1)
        {
            for(int i = 0; i < no_queues; i++)
            {
                if(!(que+i)->isfull())
                {
                    cout << "Enter Person's Name: ";
                    cin >> person_name;
                    (que + i)->enqueue(person_name);
                    cout << person_name << " got in the Line!" << endl;
                    break;
                }
                if(no_queues = i + 1)
                {
                    cout << "Seems, every Line is Full!" << endl;
                }
            }
        }
        else
        {
            if(!(que)->isempty())
            {
                cout << que->peek() << " got his ticket!" << endl;
                (que)->dequeue();
                for(int i = 0 ; i < no_queues - 1 ; i++)
                {
                    if((que + i + 1)->isempty())
                        break;
                    (que + i)->enqueue((que + i + 1)->peek());
                    (que + i + 1)->dequeue();
                }
            }
            else
            {
                cout << "Noone in the Line!" << endl;
            }
        }
    }
	return 0;
}

queue::queue(int size)
{
	head = rear = NULL;
	this->size = size;
	length = 0;
}

queue::~queue()
{
	while(head != NULL)
		dequeue();
}

void queue::enqueue(string name)
{
	rear = new node;
	rear->info = name;
	rear->next = NULL;
	if(head == NULL)
		head = rear;
	length++;
}

void queue::dequeue()
{
	temp = head;
	head = head->next;
	delete temp;
	temp = NULL;
	if(head == NULL)
		rear = NULL;
	length--;
}

bool queue::isfull()
{
	if(length == size)
		return true;
	return false;
}

bool queue::isempty()
{
	if(length == 0)
		return true;
	return false;
}

string queue::peek()
{
	if(isempty())
	{
		cout << "Nothing in Queue" << endl;
		return 0;
	}
	string ret = head->info;
	return ret;
}