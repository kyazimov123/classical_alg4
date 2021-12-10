// t.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* priv;
};

typedef Node* Long;

struct Long_Numb
{
	Long head = nullptr;
	Long tail = nullptr;
};

void Insert_Begin(Long_Numb& a, int x)
{
	Long temp = new Node();
	temp->data = x;
	temp->next = a.head;
	temp->priv = nullptr;
	if (a.head == nullptr)
	{
		a.tail = temp;
	}
	else
	{
		a.head->priv = temp;
	}
	a.head = temp;
}

void Insert_End(Long_Numb& a, int x)
{
	Long temp = new Node();
	temp->data = x;
	temp->next = nullptr;
	temp->priv = a.tail;
	if (a.tail == nullptr)
	{
		a.head = temp;
	}
	else
	{
		a.tail->next = temp;
	}
	a.tail = temp;
}

void Fill_Long(Long_Numb& a, string data)
{
	for (int i = 0; i < data.length(); i++)
	{
		Insert_Begin(a, int(data[i] - 48));
	}
}

void Print_Long(Long_Numb a)
{
	Long temp = a.tail;
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->priv;
	}
	cout << endl;
}

Long_Numb Sum(Long_Numb num1, Long_Numb num2)
{
	Long a = num1.head, b = num2.head;
	Long_Numb result;
	int x, y, z = 0;
	while ((a != nullptr) || (b != nullptr) || (z != 0))
	{
		if (a != nullptr)
		{
			x = a->data;
			a = a->next;
		}
		else
		{
			x = 0;
		}
		if (b != nullptr)
		{
			y = b->data;
			b = b->next;
		}
		else
		{
			y = 0;
		}
		Insert_End(result, (x + y + z) % 10);
		z = int((x + y + z) / 10);
	}
	return result;
}

Long_Numb Mult(Long_Numb a, int x)
{
	Long_Numb result;
	Long temp = a.head;
	int y, z = 0;
	while ((temp != nullptr) || (z != 0))
	{
		if (temp != nullptr)
		{
			y = temp->data * x;
			temp = temp->next;
		}
		else
		{
			y = 0;
		}
		Insert_End(result, (y + z) % 10);
		z = ((y + z) / 10);
	}
	return result;
}

Long_Numb Mult_Long(Long_Numb num1, Long_Numb num2)
{
	Long a = num1.head, b = num2.head;
	Long_Numb result, aft, bef;
	int n = 1;
	result = Mult(num1, b->data);
	if (b != nullptr)
	{
		b = b->next;
		bef = result;
		while (b != nullptr)
		{
			aft = Mult(num1, b->data);
			for (int i = 0; i < n; i++)
			{
				Insert_Begin(aft, 0);
			}
			n++;
			bef = Sum(bef, aft);
			b = b->next;
		}
		result = bef;
		return result;
	}
	else
	{
		return result;
	}
}

Long_Numb Substr_Long(Long_Numb num1, Long_Numb num2)
{
	Long a = num1.head, b = num2.head;
	Long_Numb result;
	int x, y, z = 0;
	while ((a != nullptr) || (z != 0))
	{
		if (z == -1)
		{
			if (a->data != 0)
			{
				a->data = a->data - 1;
				z = 0;
			}
			else
			{
				a->data = 9;
			}
		}
		if (b != nullptr)
		{
			if (a->data - b->data >= 0)
			{
				Insert_End(result, a->data - b->data);
			}
			else
			{
				Insert_End(result, a->data + 10 - b->data);
				z = -1;
			}
		}
		else
		{
			Insert_End(result, a->data);
		}
		a = a->next;
		if (b != nullptr)
		{
			if (b->next != nullptr)
			{
				b = b->next;
			}
			else
			{
				b = nullptr;
			}
		}
	}
	if (result.tail->data != 0)
	{
		return result;
	}
	else
	{
		
			while (result.tail->data==0)
			{
				if (result.tail->priv == nullptr)
					break;
				result.tail = result.tail->priv;
				result.tail->next = nullptr;
			} 
			if (result.head->data == 0)
			{
				result.head = nullptr;
				result.tail = nullptr;
			}
			return result;
	}
}
int Compare(Long_Numb num1, Long_Numb num2)
{
	int r = 0;
	if (num1.tail->data==0)
		while ((num1.tail->data==0))
		{
			if (num1.tail->priv == nullptr)
				break;
			num1.tail = num1.tail->priv;
			num1.tail->next = nullptr;
		}
	Long a = num1.head, b = num2.head;
	while ((a != nullptr) and (b != nullptr))
	{
		if (a->data > b->data)
		{
			r = 1;
		}
		else
		{
			if (a->data < b->data)
			{
				r = -1;
			}
		}
		a = a->next;
		b = b->next;
	}
	if (a != nullptr)
	{
		r = 1;
	}
	else
	{
		if (b != nullptr)
		{
			r = -1;
		}
	}
	return r;
}

int foo(Long x)
{
	int n = 0;
	while (x != nullptr)
	{
		x = x->next;
		n++;
	}
	return n;
}
Long_Numb Div_Long(Long_Numb num1, Long_Numb num2)
{
	int n;
	Long a = num1.head, b = num2.head;
	Long a_t = num1.tail;
	Long_Numb new_long, temp_long;
	Long_Numb result;
	n = foo(b);
	int r;
	while (n > 0)
	{

		Insert_Begin(new_long, a_t->data);
		a_t = a_t->priv;
		n--;
		if (n == 0)
		{
			r = Compare(num2, new_long);
			if (r == 1)
				n++;
		}
	}
	while (a_t != nullptr)
	{
  		n = 0;
		while (n <= 10)
		{
			r = Compare(new_long, temp_long = Mult(num2, n));
			if (r <= 0)
			{
				if (r < 0)
				{
					n--;
				}
				break;
			}
			n++;
		}
		Insert_Begin(result, n);
		if (a_t != nullptr)
		{
			new_long = Substr_Long(new_long, temp_long = Mult(num2, n));
			Insert_Begin(new_long, a_t->data); 
			r = Compare(new_long, num2);
			if ((r >= 0) && (a_t->priv!=nullptr))
			{
				a_t = a_t->priv;
			}
			else
			{
				if ((r == -1))
				{
					while ((r==-1))
					{
						Insert_Begin(result, 0);
						if (a_t->priv == nullptr)
							break;
						a_t = a_t->priv;
						Insert_Begin(new_long, a_t->data);
						r = Compare(new_long, num2);
					}
					
				}
				if (a_t->priv == nullptr)
					a_t = nullptr;
				else 
					a_t = a_t->priv;
			}
		}
	}
	r= Compare(new_long, num2);
	if (r >= 0)
	{
		n = 0;
		while (n <= 10)
		{
			r = Compare(new_long, temp_long = Mult(num2, n));
			if (r <= 0)
			{
				if (r < 0)
				{
					n--;
				}
				break;
			}
			n++;
		}
		Insert_Begin(result, n);
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Long_Numb a, b, result;
	string data_a, data_b;
	int ind;
	cout << "Введите 1 число ";
	cin >> data_a;
	Fill_Long(a, data_a);
	cout << "Введите 2 число ";
	cin >> data_b;
	Fill_Long(b, data_b);


	ind = Compare(a, b);
	if (ind == -1)
	{
		result = Div_Long(b, a);
	}
	else
	{
		result = Div_Long(a, b);
	}
	cout << "Результат деления:";
	Print_Long(result);
   }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
