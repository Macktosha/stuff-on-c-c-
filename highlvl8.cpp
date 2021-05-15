#include<iostream>
#include <stack>
#include <cstring>
using namespace std;

//проверка правильности скобок
bool brackets_detection(char elem[])
{
	stack <char> s;
	char round_bracket, figure_bracket, square_bracket;

	//проверка элементов
	for (size_t i = 0; i < strlen(elem); i++)
	{
		if (elem[i] == '(' || elem[i] == '[' || elem[i] == '{')
		{
			//проталкиваем в стэк
			s.push(elem[i]);
		}
		else
		{
			switch (elem[i])
			{
			case ')':

				//сохраняем элемент
				round_bracket = s.top();
				s.pop();
				if (round_bracket == '{' || round_bracket == '[')
					cout << "Not correct, expected round bracket" << endl;
				break;
			case '}':

				figure_bracket = s.top();
				s.pop();
				if (figure_bracket == '(' || figure_bracket == '[')
					cout << "Not correct, expected figure bracket"<< endl;
				break;
			case ']':
				square_bracket = s.top();
				s.pop();
				if (square_bracket == '(' || square_bracket == '{')
					cout << "Not correct, expected square bracket" << endl;
				break;
			}
		}
	}

	//проверяем стэк
	if (s.empty())
		return true;
	else
		return false;
}


int main()
{
	char elem[] = "{()}[]";//можно ввести с клавиатуры,задать другие и т.д.

	if (brackets_detection(elem))
		cout << "Brackets were put correctly" << endl;
	else
		cout << "Brackets are incorrect" << endl;
	return 0;
}