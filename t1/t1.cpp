// t1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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


void Insert_End (Long_Numb& a, int x)
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

void Print_Long(Long_Numb a)
{
    Long temp = a.tail;
    while (temp!=NULL)
    {
        cout << temp->data;
        temp = temp->priv;
    }
    cout << endl;
}
Long_Numb Mult(Long_Numb a, int x)
{
    Long_Numb result;
    Long temp = a.head;
    int y, z = 0;
    while ((temp!=nullptr)||(z!=0))
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
        z = (( y + z) / 10);
    }
    return result;
}
int main()
{
    Long_Numb a;
    int n;
    cin >> n;
    Insert_End(a, 1);

    for (int i = 1; i <= n; i++)
    {
        a= Mult(a, i);
    }
    Print_Long(a);
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
