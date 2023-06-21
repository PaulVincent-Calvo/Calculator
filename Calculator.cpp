#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// by Paul Vincent Calvo - CS1303
struct calculator
{
    float num1, num2, result;
    char operation;
    string user_input;
};

//operations
float add(float num1, float num2)
{
    float result = num1 + num2;
    return result;
}

float subtract(float num1, float num2)
{
    float result = num1 - num2;
    return result;
}

float multiply(float num1, float num2)
{
    float result = num1 * num2;
    return result;
}

float divide(float num1, float num2)
{   
    if (num2 == 0)
    {
        cout << "Any number diveded by 0 is undefined.";
        return 0;
    } 
    else 
    {
        float result = num1 / num2;
        return result;
    }
}

// input validation
bool check_operator (char operation)
{
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/');
}

bool check_input(const string& user_input, calculator& calc)
{
    // checks if there is an operation on the user input
    size_t operation_position = user_input.find_first_of("+-*/");
    if (operation_position == string::npos)
    {
        cout << "Invalid input. Enter an expression in the following format: number-operation-number (e.g. 10-2)." << endl;
        return false;
    }
   
    try 
    {
        // creates a substring from the user input starting from the first letter up until the position of the operation
        calc.num1 = stof(user_input.substr(0, operation_position));
        // creates a substring from the user input starting from the first letter in front of the operaion
        calc.num2 = stof(user_input.substr(operation_position + 1));
    }
    catch (const exception&) 
    {
        cout << "Invalid number. Please input a valid number." << endl;
        return false;
    }

    calc.operation = user_input[operation_position];
    if (!check_operator(calc.operation))
    {
        cout << "Invalid operator. Please enter a valid operator [+, -, *, /]" << endl;
        return false;
    }

    return true;
}

int main()
{
    calculator calc;
    string history[2], *history_pointer[2];
    int n=2, i;
    // limited to two times for ease of checking but can be edited

    do {

        system("cls");
    
        cout << "==========================" << endl << "\tCalculator\t" << endl << "==========================" << endl << endl;

        getline(cin, calc.user_input);

        while(!check_input(calc.user_input, calc))
        {
            getline(cin, calc.user_input);
        }

        switch (calc.operation)
        {
            case '+':
                calc.result = add(calc.num1, calc.num2);
                cout << calc.num1 << " " << calc.operation << " " << calc.num2 << " = " << calc.result << endl << endl;
                i = 2-n;
                history[i] = (to_string(calc.num1) + " + " + to_string(calc.num2) + " = " + to_string(calc.result));
                break;
            case '-':
                calc.result = subtract(calc.num1, calc.num2);
                cout << calc.num1 << " " << calc.operation << " " << calc.num2 << " = " << calc.result << endl << endl;
                i = 2-n;
                history[i] = (to_string(calc.num1) + " - " + to_string(calc.num2) + " = " + to_string(calc.result));
                break;
            case '*':
                calc.result = multiply(calc.num1, calc.num2);
                cout << calc.num1 << " " << calc.operation << " " << calc.num2 << " = " << calc.result << endl << endl;
                i = 2-n;
                history[i] = (to_string(calc.num1) + " * " + to_string(calc.num2) + " = " + to_string(calc.result));
                break;
            case '/':
                calc.result = divide(calc.num1, calc.num2);
                cout << calc.num1 << " " << calc.operation << " " << calc.num2 << " = " << calc.result << endl << endl;
                i = 2-n;
                history[i] = (to_string(calc.num1) + " / " + to_string(calc.num2) + " = " + to_string(calc.result));
                break;
            default:
                cout << "Invalid input!";
                break;
        }
        n = n - 1;
    }while(n != 0 );

    system("cls");
    cout << endl;

    // assigns the address of the history array into the history_pointer array
    for (int j = 0 ; j < 2; j++)
    {
        history_pointer[j] = &history[j];
    }

    cout << "History" << endl;
    // prints the history 
    for (int k = 0 ; k < 2; k++)
    {
        cout << history[k] << endl; 
    }
    
    cout << endl << "Addresses" << endl;
    // prints the adresses of the history
    for (int l = 0 ; l < 2; l++)
    {
        cout << history_pointer[l] << endl;
    }

    return 0;
}