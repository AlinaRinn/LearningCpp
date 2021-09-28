#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Cat{
public:
    string name, type;
    int playаbility = 44;

    void Play(){
        if ((playаbility > 50) && (playаbility < 100)) {
            cout << "Playing..." << endl;
            playаbility -= 10;
        }
        else {
            cout << "Need more sleep" << endl;
        }
    }
    void Sleep(){
        srand((unsigned int)time(0));
        if (playаbility < 80) {
            cout << "Sleeping..." << endl;
            playаbility += rand() % 10 + 10;
        }
        else {
            cout << "Don't need now" << endl;
        }
    }
};

class Dog {
public:
    string name, type;
    int playаbility = 84;

    void Play() {
        if ((playаbility > 50) && (playаbility < 100)) {
            cout << "Playing..." << endl;
            playаbility -= 10;
        }
        else {
            cout << "Need more sleep" << endl;
        }
    }
    void Sleep() {
        srand((unsigned int)time(0));
        if (playаbility < 80) {
            cout << "Sleeping..." << endl;
            playаbility += rand() % 10 + 10;
        }
        else {
            cout << "Don't need now" << endl;
        }
    }
};

int main()
{
    const int anim = 10;
    Cat cat[anim];
    Dog dog[anim];
    for (int i = 0; i < anim; i++) {
        cat[i].Play();
        dog[i].Play();
        cat[i].Sleep();
        dog[i].Play();
    }
}