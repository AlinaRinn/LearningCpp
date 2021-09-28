#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Cat{
public:
    string name, type;
    int playаbility = 44;

    void Play(){
        if (playаbility > 50) {

        }
    }
    void Sleep(){

    }
};

class Dog : public Cat {
    int playаbility = 88;
};

int main()
{
    cout << "Hello World!\n";
}

