#include <iostream>
#include <string>
#include <vector>
using namespace std;

void method(string& str)
{
    try
    {
        int x = std::stoi(str);
        cout << "Число: " << x << std::endl;
    }
    catch (invalid_argument& e)
    {
        cout << "Ошибка: Неправильный аргумент - " << e.what() << endl;
    }
    catch (out_of_range& e)
    {
        cout << "Ошибка: Выход за пределы диапазона - " << e.what() << endl;
    }
    catch (exception& e)
    {
        cout << "Ошибка: " << e.what() << endl;
    }
}


//HL
class List
{
private:
    vector<int> data;
public:
    virtual void addValue(int value) = 0;
    virtual int remove() = 0;
};

class Stack : public List
{
private:
    vector<int> data;
public:
    Stack(){}

    void addValue(int value) override
    {
        data.push_back(value);
    }
    
    int remove() override
    {
        if (data.empty())
        {
            throw runtime_error("Стек пуст!");
        }
        int value = data.back();
        data.pop_back();
        return value;
    }
    
    void print()
    {
        if (data.empty())
        {
            throw runtime_error("Стек пуст!");
        }
        for (int i = 0; i < data.size(); i++)
        {
            cout<<data[i]<<" ";
        }
    }
};

class Queue : public List
{
private:
    vector<int> data;
public:
    void addValue(int value) override
    {
        data.push_back(value);
    }
    
    int remove() override
    {
        if (data.empty())
        {
            throw runtime_error("Стек пуст!");
        }
        int value = data.front();
        data.erase(data.begin());
        return  value;
    }
    
    void print()
    {
        if (data.empty())
        {
            throw runtime_error("Стек пуст!");
        }
        for (int i = 0; i < data.size(); i++)
        {
            cout<<data[i]<<" ";
        }
    }
};



int main()
{
//    Написати функцію обчислення значення за заданим рядком символів, що є записом цього числа в десятковій системі числення.  (метод від рядка до числа std::stoi(type)).
//    Передбачити випадок виходу за межі діапазону визначеного типом int.
//    Використовуйте механізм винятків.
    
//    string x = "123";
//    string y = "qwerty";
//    string d = "99999999999999999999999999999999";
//    method(x);
//    method(y);
//    method(d);
    
    
//    Напишіть програму, яка використовує обробку виключень для перехоплення виходу за межі масиву.
    
//    try {
//        const int SIZE = 3;
//        int arr[SIZE] = {7, 5, 8};
//            
//        cout << "Введите индекс элемента массива для вывода: ";
//        int index;
//        cin >> index;
//            
//        if (index <= 0 || index >= SIZE) {
//            throw out_of_range("Индекс вне диапазона");
//        }
//        cout << "Элемент с индексом " << index << ": " << arr[index] - 1 << endl;
//    } catch (out_of_range& e) {
//        cout << e.what() << endl;
//    }
    
//    Додайте в клас двозв'язного списку/стеку/черги/тощо (або будь-якого класу з колекцією з будь-якої попередньої дз/лр) механізм обробки винятків. На ваш вибір генеруйте винятки в разі помилок. Наприклад, нехватка пам'яті, спроба видалення з порожнього списку тощо. Використовуйте свій клас обробки винятків, успадкований від базового класу std::exception

    try {
        Stack stack;
//        stack.remove();
        stack.addValue(1);
//        stack.addValue(2);
        stack.print();
    } catch (const exception& ex)
    {
        cout<<ex.what()<<endl;
    }

}
