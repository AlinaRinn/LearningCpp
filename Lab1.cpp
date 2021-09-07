#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int n = 0, m = 0, i = 0, sum = 0;
    cout << "Enter value for 'n' and 'm':" << endl;
    cin >> n >> m;
    srand(time(0));
     do {
        i++;
        sum = 0;
        while (sum < n) {
            sum += rand() % 10 + 1;
            //cout << "prom: " << sum << endl;
        }   
     } while (!(sum % m == 0));
     cout << "Summary: " << sum << endl;
     cout << "Tries: " << i << endl;
    system("pause");
}
