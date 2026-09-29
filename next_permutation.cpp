#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> v {1, 2, 3};

  sort(v.begin(), v.end());

  do
    {
      for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << ' ';
      cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}
