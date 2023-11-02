#include <iostream>
using namespace std;

class num
{
    int x;

public:
    num(int x)
    {
        this->x = x;
    }

    friend string operator+(num,string);
};

string operator+(num n,string s)
{
    string num_string = to_string(n.x);
    num_string.append(s);

    return num_string;
}

int main()
{
    num n(123);
    string s = "Abc";
    cout << n + s << endl;
    return 0;
}