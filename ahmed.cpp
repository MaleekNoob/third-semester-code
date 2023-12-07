#include <iostream>
#include <fstream>
using namespace std;

class String
{
    char *s;
    int size;

public:
    String()
    {
        size = 20;
        s = new char[size];
    }

    int stringSize(char const *str)
    {
        int i = 0;
        while (str[i] != '\0')
            i++;
        return i;
    }

    String(char const *str)
    {
        size = stringSize(str);
        s = new char[size];
        for (int i = 0; i < size; i++)
            s[i] = str[i];
    }

    void operator=(char const *str)
    {
        size = stringSize(str);
        s = new char[size];
        for (int i = 0; i < size; i++)
            s[i] = str[i];
    }

    void operator+=(char ch)
    {
        int i = 0;
        while (s[i] != '\0')
            i++;
        s[i] = ch;
        s[i + 1] = '\0';
    }

    friend ostream &operator<<(ostream &out, String &obj)
    {
        for (int i = 0; i < obj.size; i++) {
            out << obj.s[i];
        }

        return out;
    };

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << s[i];
    }
};

class Complex
{
    double real;

public:
    Complex(){};
    void input()
    {
        cout << "\nEnter real part";
        cin >> real;
    }
};

class equation
{
    String eqn;

public:
    equation()
    {
    }

    String getEqn()
    {
        return eqn;
    }

    void readData()
    {
        char arr[20];
        ifstream myfile;
        myfile.open("equations.txt");
        if (myfile.is_open())
        {
            // read character by character until end of line
            char c;
            int i = 0;
            while (myfile.get(c) && c != '\n')
            {
                arr[i] = c;
                eqn += c;
                i++;
            }
            
            arr[i] = '\0';

            cout << arr << endl;
            cout << eqn << endl;
            myfile.close();
        }
        else
            cout << "Unable to open file";
    }
};

class SysOfEq
{
public:
    SysOfEq(){};
};

class matrix
{
public:
    matrix(){};
};

int main()
{

    equation E;
    E.readData();

    return 0;
}