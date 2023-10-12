#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

class Encryption {
private:
    Queue<char> alphabetQueue;
    Queue<char> numberQueue;
    Queue<char> arithmeticQueue;

    bool isAlphanumeric(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isdigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    bool isArithmetic(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool comparePrecdence(char op1, char op2)
    {
        if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    char findHighestPrecedence(Queue<char> arithmeticQueue)
    {

        return '+';
    }

    string intToString(int num) {
        string str = "";
        while (num > 0) {
            str = (char)(num % 10 + '0') + str;
            num /= 10;
        }
        return str;
    }
    
    int charToInt(char c) {
        return c - '0';
    }

public:
    // string encryptPassword(string password)
    // {
    //     for (int i = 0; i < password.length(); i++)
    //     {
    //         char c = password[i];
    //         if (isAlphanumeric(c))
    //         {
    //             alphabetQueue.enqueue(c);
    //         }
    //         else if (isdigit(c))
    //         {
    //             numberQueue.enqueue(c);
    //         }
    //         else if (isArithmetic(c))
    //         {
    //             arithmeticQueue.enqueue(c);
    //         }
    //     }

    //     char highestPrecedence = findHighestPrecedence(arithmeticQueue);
    //     int product = 0;
    //     Queue<char> tempQueue;
    //     while (!numberQueue.isEmpty()) {
    //         char c = numberQueue.peek();
    //         numberQueue.dequeue();
    //         product = product * 10 + (c - '0');
    //         tempQueue.enqueue(c);
    //     }
    //     numberQueue = tempQueue;

    //     string toReture = "";

    //     while (!alphabetQueue.isEmpty())
    //     {
    //         toReture += alphabetQueue.peek();
    //         alphabetQueue.dequeue();
    //     }
        
    //     toReture += intToString(product);

    //     while (!arithmeticQueue.isEmpty()) {
    //         char c = arithmeticQueue.peek();
    //         arithmeticQueue.dequeue();
    //         toReture += c;
    //     }

    //     return toReture;
    // }

    string encryptPassword(string password)
    {

        for (int i = 0; i < password.length(); i++)
        {
            char c = password[i];
            if (isAlphanumeric(c))
            {
                alphabetQueue.enqueue(c);
            }
            else if (isdigit(c))
            {
                numberQueue.enqueue(c);
            }
            else if (isArithmetic(c))
            {
                arithmeticQueue.enqueue(c);
            }
        }

        string arithmeticOutput = "";
        char highestPrecedence = arithmeticQueue.peek();
        while (!arithmeticQueue.isEmpty())
        {
            char op = arithmeticQueue.peek();
            arithmeticQueue.dequeue();
            arithmeticOutput += op;

            if (comparePrecdence(op, highestPrecedence))
            {
                highestPrecedence = op;
            }
        }
        string output = "";

        while (!alphabetQueue.isEmpty())
        {
            char ch = alphabetQueue.peek();
            alphabetQueue.dequeue();
            output += ch;
        }

        int product = 1;
        while (!numberQueue.isEmpty())
        {
            char ch = numberQueue.peek();
            numberQueue.dequeue();
            product = product * charToInt(ch);
        }

        output += intToString(product);
        output += arithmeticOutput;

        return output;
    }

};

int main() {
    Encryption encryption;
    string password;
    cout << "Enter the your password in plain text: ";
    cin >> password;
    password = encryption.encryptPassword(password);
    cout << "Encrypted password: " << password << endl;

    return 0;
}

