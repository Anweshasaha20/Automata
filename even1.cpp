#include <bits/stdc++.h>
using namespace std;

enum State
{
    q0,
    q1,
    q2,

};

string stateToString(State s)
{
    switch (s)
    {
    case q0:
        return "q0";
    case q1:
        return "q1";
    case q2:
        return "q2";

    default:
        return "?";
    }
}

class Automata
{
public:
    State finalStates;
    State init;

    Automata()
    {
        finalStates = q2;
        init = q0;
    }

    State transFunction(State st, char input)
    {
        if (st == q0)
        {
            if (input == '0')
            {
                cout << "Currently in q0, input: 0 -> stay in q0\n";
                return q0;
            }
            else if (input == '1')
            {
                cout << "Currently in q0, input: 1 -> move to q1\n";
                return q1;
            }
        }
        else if (st == q1)
        {
            if (input == '0')
            {
                cout << "Currently in q1, input: 0 -> stay in q1\n";
                return q1;
            }
            else if (input == '1')
            {
                cout << "Currently in q1, input: 1 -> move to q2\n";
                return q2;
            }
        }
        else if (st == q2)
        {
            if (input == '0')
            {
                cout << "Currently in q2, input: 0 -> stay in q2\n";
                return q2;
            }
            else if (input == '1')
            {
                cout << "Currently in q2, input: 1 -> move to q1\n";
                return q1;
            }
        }
        return st;
    }

    void printMap()
    {
        cout << "\nTransition Table:\n";
        cout << "        0      1    \n";
        cout << "      -----------------\n";

        for (State s : {q0, q1, q2})
        {
            cout << stateToString(s) << "  | ";

            for (char c : {'0', '1'})
            {
                State next;

                if (s == q0 && c == '0')
                    next = q0;
                else if (s == q0 && c == '1')
                    next = q1;
                else if (s == q1 && c == '0')
                    next = q1;
                else if (s == q1 && c == '1')
                    next = q2;
                else if (s == q2 && c == '0')
                    next = q2;
                else if (s == q2 && c == '1')
                    next = q1;

                cout << "  " << stateToString(next) << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    string s;
    cout << "Enter binary string: ";
    cin >> s;

    if (s.empty())
    {
        cout << "Empty string not allowed.\n";
        return 0;
    }

    Automata a;
    State curr = a.init;

    for (char ch : s)
    {
        if (ch != '0' && ch != '1')
        {
            cout << "Invalid character in input: " << ch << "\n";
            return 1;
        }

        curr = a.transFunction(curr, ch);
    }

    if (curr != a.finalStates)
    {
        cout << "Invalid input: rejected \n";
    }
    else
    {
        cout << "Valid input: accepted \n";
    }

    a.printMap();
    return 0;
}
