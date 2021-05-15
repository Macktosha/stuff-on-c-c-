#include <iostream>
#include <cstring>
#include <iomanip>
#define MAX 256

using namespace std;

/*для записи нам нужно имя клиента, пол(чтобы понять к муж или жен. мастеру отправить),
номер телефона и время на которое записан*/

int cnt = 0;


class client
{

private:
	string name;
	bool gender;
	char phone_number[12];
	float time;


public:

	client()
	{
		gender = true;
		phone_number[0] = NULL;
		time = 0.0;
	}
	void set_client()
	{
		cout << "\t\tEnter data to set new client" << endl;
		cout << "Enter name:   ";
		cin >> name;
		cout << "\nEnter gender (0 - Male,1 - Female):  ";
		cin >> gender;
		cout << "\nEnter phone number (remember of 11 numbers max length):  ";
		cin >> phone_number;
		cout << "\nTime of visit (hh.mm format):  ";
		scanf_s("%f", &time);
 }
	void get_client()
	{
		cout.setf(ios::fixed);
		cout << setw(9) << name;
		cout << setw(14) << phone_number;
		if (gender) cout<<"\t"<< setw(10) << "Female"; else cout<<"\t" << setw(10) << "Male";
		cout << setw(12) << setprecision(2) << time << endl;
		cout.unsetf(ios::fixed);
	}
	float get_time()//отдельно для сравнения времени 
	{ 
		return time;
	 }
};

void heading() {//функция заголовка 
	for (int i = 1; i <= 50; i++)
		cout << "-";
	cout << endl;

	cout << "|  Name  |" << "    Phone.num    |" << "  Gender  |" << "  Time |" << endl;
	for (int i = 1; i <= 50; i++)
		cout << "-";
	cout << endl;
}

void create_client(client arr[])
{
	arr[cnt].set_client();
	cnt++;
}

int cmp_func(const void* x1, const void* x2)  //для qsort
{
	return (((client*)x1)->get_time() - ((client*)x2)->get_time());
}

void print_and_sort(client barber[])//вывод массива объектов
{
	qsort(barber, cnt, sizeof(client), cmp_func);
	heading();
	for (int j = 0; j != cnt; j++)
		barber[j].get_client();
}

bool check_live_queue(client xyz[])//проверка наличия времени для живой очереди
{
	float x = 0.0;

	cout << "Enter time to find free time in schedule (format hh.mm)" << endl;
	cin >> x;
	int k = 0;
	while(k!=cnt)
	{
		
		if (xyz[k].get_time() > x+0.3)  //смотрим есть ли свободные 30 минут в расписании
			return true;
		
		k++;
	}
}



int main()
{
	class client* visitor;

	visitor = new client[MAX];

	int choice = 0;
	L1:
	cout << "\n\t\tChoose the command:\n 1 - Add client\n 2 - Show the schedule\n 3 - Check live queue\n\t 0 - Exit\n";
	cin >> choice;
	switch (choice)
	{
	case 1: create_client(visitor);
		system("cls");
		goto L1;
		break;
	case 2: print_and_sort(visitor);
		goto L1;
		break;
	case 3: if (check_live_queue(visitor))
		cout << "Time is available" << endl;
		  else cout << "Time isn't available" << endl;
		goto L1;
		break;
	case 0: break;
	default:
		break;
	}
	delete[]visitor;
	return 0;


	
}
