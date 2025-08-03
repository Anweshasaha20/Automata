#include <bits/stdc++.h>
using namespace std;

enum State
{
    q0,
    q1,
    q2,
    q3
};

class Automata
{
public:
    State finalStates;
    State init;

    Automata()
    {
        finalStates = q1;
        init = q0;
    }

    State transFunction(State st, char input)
    {
        if (st == q3)
            return q3;

        if (input != '0' && input != '1')
        {
            cout << "Invalid character '" << input << "'. Moving to dead state q3." << endl;
            return q3;
        }

        if (st == q0)
        {
            if (input == '0')
            {
                cout << "Currently in q0 moving to q1" << endl;
                return q1;
            }
            else
            {
                cout << "Currently in q0 moving to q2" << endl;
                return q2;
            }
        }
        else if (st == q1)
        {
            if (input == '0')
            {
                cout << "Currently in q1 moving to q1" << endl;
                return q1;
            }
            else
            {
                cout << "Currently in q1 moving to q2" << endl;
                return q2;
            }
        }
        else if (st == q2)
        {
            if (input == '0')
            {
                cout << "Currently in q2 moving to q1" << endl;
                return q1;
            }
            else
            {
                cout << "Currently in q2 moving to q2" << endl;
                return q2;
            }
        }

        cout << "Invalid transition from state q" << st << " with input '"
             << input << "'. Moving to dead state q3." << endl;
        return q3;
    }

    void printMap()
    {
        cout << "\nTransition Table:" << endl;
        cout << "       0     1   " << endl;
        cout << "     ------------" << endl;

        for (State s : {q0, q1, q2})
        {
            cout << "q" << s << "  | ";

            for (char c : {'0', '1'})
            {
                State next = transFunctionNoPrint(s, c);
                cout << " q" << next << "  ";
            }

            cout << endl;
        }
    }

    State transFunctionNoPrint(State st, char input)
    {
        if (st == q0)
            return (input == '0') ? q1 : q2;
        if (st == q1)
            return (input == '0') ? q1 : q2;
        if (st == q2)
            return (input == '0') ? q1 : q2;
        return q3;
    }
};

int main()
{
    string s;
    cout << "Enter the binary string: ";
    cin >> s;

    if (s.empty())
    {
        cout << "Empty string not allowed!" << endl;
        return 0;
    }

    Automata a;
    State curr = a.init;

    for (auto &i : s)
    {
        curr = a.transFunction(curr, i);
    }

    if (curr != a.finalStates)
    {
        cout << "Rejected: Not a multiple of 2." << endl;
    }
    else
    {
        cout << "Accepted: Multiple of 2." << endl;
    }

    a.printMap();
    return 0;
}
