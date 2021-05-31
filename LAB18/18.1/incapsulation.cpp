#include <iostream>
using namespace std;

class Person
{
private:
    string _name = "Janina Kowalski";

    float _salary = 0;
    int _daysWorked = 0;

    float _totalSalary = 0;
    int _daysInMonth = 31;

    void ComputeSalary()
    {
        _totalSalary = _salary * _daysWorked / _daysInMonth;
    }

public:
    float TotalSalary()
    {
        return _totalSalary;
    }

    float Salary() { return _salary; }

    bool SetSalary(float salary)
    {
        if (salary > 0)
        {
            _salary = salary;
            ComputeSalary();
            return true;
        }
        else 
        {
            cout << "Error: invalid salary!!! less than 0." << endl;
            return false;
        }
    }

    int DaysWorked() { return _daysWorked; }

    bool SetDaysWorked(int days)
    {
        if ((days >= 0) && (days <= _daysInMonth))
        {
            _daysWorked = days;
            ComputeSalary();
            return true;
        }
        else
        {
            cout << "Error: invalid days!!! less than 0 or more than days in month." << endl;
            return false;
        }
    }

    int DaysInMonth() { return _daysInMonth; }

    bool SetDaysInMonth(int days)
    {
        if ((days >= 28) && (days <= 31))
        {
            _daysInMonth = days;
            ComputeSalary();
            return true;
        }
        else
        {
            cout << "Error: invalid days, out of [28 ; 31]!!!" << endl;
            return false;
        }
    }

    string GetName() { return _name; }

    void SetName(string name) { _name = name; }
    
    void ReadPersonData()
    {
        cout << "Input the person's salary:" << endl;
        int value; 
        bool isInputSuccessful;

        do 
        {
            cout << "Input the person's salary: ";
            cin >> value;
            isInputSuccessful = SetSalary(value);
        }
        while (!isInputSuccessful);

        do
        {
            cout << "Input days in the month: " << endl;
            cin >> value;
            isInputSuccessful = SetDaysInMonth(value);
        } 
        while (!isInputSuccessful);
        
        do
        {
            cout << "Input worked days: " << endl;
            cin >> value;
            isInputSuccessful = SetDaysWorked(value);
        } 
        while (!isInputSuccessful);
    }

    void PrintPersonData()
    {
        cout << "Person's data:" << endl;
        cout << " -              Name: " << _name << ";\n";
        cout << " -            Salary: " << _salary << ";\n";
        cout << " - Days in the month: " << _daysInMonth << ";\n";
        cout << " -       Worked days: " << _daysWorked << ";\n";
        cout << " >>     Total salary: " << _totalSalary << ";\n\n";
    }

    Person(string name, float salary, int daysInMonth, int daysWorked)
    {
        SetName(name);
        SetSalary(salary);
        SetDaysInMonth(daysInMonth);
        SetDaysWorked(daysWorked);
    }
};

int main()
{
    Person firstPerson("Amelie", 25000.17, 30, 21);
    firstPerson.PrintPersonData();

    firstPerson.ReadPersonData();
    firstPerson.PrintPersonData();

    firstPerson.SetSalary(-1);
    firstPerson.SetDaysWorked(100);
    firstPerson.SetDaysInMonth(13);

    firstPerson.PrintPersonData();

    return 0;
}