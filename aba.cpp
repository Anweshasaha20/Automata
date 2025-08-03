#include <bits/stdc++.h>
using namespace std;

enum State
{
    q0,
    q1,
    q2,
    q3,
    q4
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
    case q3:
        return "q3";
    case q4:
        return "q4";
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
        finalStates = q3;
        init = q0;
    }

    State transFunction(State st, char input)
    {
        if (st == q4)
        {
            cout << "Currently in q4 (dead state), input: " << input << " -> stay in q4\n";
            return q4;
        }

        if (st == q0 && input == 'a')
        {
            cout << "Currently in q0, input: a -> move to q1\n";
            return q1;
        }
        else if (st == q1 && input == 'b')
        {
            cout << "Currently in q1, input: b -> move to q2\n";
            return q2;
        }
        else if (st == q2 && input == 'a')
        {
            cout << "Currently in q2, input: a -> move to q3\n";
            return q3;
        }
        else
        {
            cout << "Currently in " << stateToString(st) << ", input: " << input << " -> invalid, move to q4\n";
            return q4;
        }
    }

    void printMap()
    {
        cout << "\nTransition Table:\n";
        cout << "        a   b\n";
        cout << "      --------\n";

        for (State s : {q0, q1, q2, q3, q4})
        {
            cout << stateToString(s) << "  | ";

            for (char c : {'a', 'b'})
            {
                State next;

                if (s == q0 && c == 'a')
                    next = q1;
                else if (s == q1 && c == 'b')
                    next = q2;
                else if (s == q2 && c == 'a')
                    next = q3;
                else
                    next = q4;

                cout << " " << stateToString(next) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    string s;
    cout << "Enter input string (only a and b): ";
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
        if (ch != 'a' && ch != 'b')
        {
            cout << "Invalid character in input: " << ch << "\n";
            return 1;
        }

        curr = a.transFunction(curr, ch);
    }

    if (curr != a.finalStates)
    {
        cout << "Invalid input: rejected\n";
    }
    else
    {
        cout << "Valid input: accepted\n";
    }

    a.printMap();
    return 0;
}
