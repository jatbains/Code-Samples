// GenerateParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
vector<string> generateParenthesis(int n);
void _generateParenthesisHelper(int pos, string out, int n, int open, int close, vector<string>& output);

int main()
{
    int num = 8;

    for (string s : generateParenthesis(num))
    {
        cout << s << endl;
    }

    
}

vector<string> generateParenthesis(int n) {
    vector<string> output;
    output.clear();
    _generateParenthesisHelper(0, "", n, 0, 0, output);
    return output;
}


void _generateParenthesisHelper(int pos, string out, int n, int open, int close, vector<string>& output)
{


    if (close == n)
    {
        output.push_back(out);
        return;
    }
    else
    {
        if (open > close)
        {

            _generateParenthesisHelper(pos + 1, out + ")", n, open, close + 1, output);
        }

        if (open < n)
        {

            _generateParenthesisHelper(pos + 1, out + "(", n, open + 1, close, output);
        }
    }

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
