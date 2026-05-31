#include <iostream>
#include <typeinfo>
#include <sstream>

using namespace std;

int main()
{
    string s = "Hello My Age is 25";
    istringstream iss(s);
    string s1, s2, s3, s4;
    int age;
    iss >> s1 >> s2 >> s3 >> s4 >> age;

    cout << s1 << "\n";
    cout << s2 << "\n";
    cout << s3 << "\n";
    cout << s4 << "\n";
    cout << age << "\n";

    return 0;
}

#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>

using namespace std;

int main()
{
    string s = "My,Age,is,25";
    stringstream ss(s);

    string token;
    while (getline(ss, token, ','))
    {
        cout << token << "\n";
    }
}
