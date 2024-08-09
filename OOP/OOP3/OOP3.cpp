#include <iostream>

// Константы
const double g = 9.81;
const double pi = 3.14159265358979323846;

class Pump {
private:
    int po = 0;
    double Q = 0, p1 = 0, p2 = 0, d1 = 0, d2 = 0;

    double pressure_eq(double p1, double p2, int po, double g) {
        return (p2 - p1) / (po * g);
    } // d2 >= d1
        
    double pressure_diff(double d1, double d2, double Q, double pi, double g) {
        return (8 * pow(Q, 2)) / (g * pow(pi, 2)) * (1 / pow(d2, 4) - 1 / pow(d1, 4));
    } // d2 < d1
        
    double power(int po, double Q, double d1, double d2, double p1, double p2) {
        return (d2 < d1) ? po * g * Q * (pressure_eq(p1, p2, po, g) + pressure_diff(d1, d2, Q, pi, g)) : po * g * Q * pressure_eq(p1, p2, po, g);
    }

public:
    Pump() {

    }

    Pump(int po, double Q, double p1, double p2, double d1, double d2) {
        this->po = po;
        this->Q = Q;
        this->p1 = p1;
        this->p2 = p2;
        this->d1 = d1;
        this->d2 = d2;
    }

    void set_all() {
        std::cout << "Введите po — плотность жидкости [кг/м^3] (int): \n";
        std::cin >> this->po;
        std::cout << "Введите Q — расход [м^3/с]:  \n";
        std::cin >> this->Q;
        std::cout << "Введите p1 — давление на всасывающем патрубке [Па]: \n";
        std::cin >> this->p1;
        std::cout << "Введите p2 — давление на напорном патрубке[Па]: \n";
        std::cin >> this->p2;
        std::cout << "Введите d1 — внутренний диаметр всасывающего патрубка [м]: \n";
        std::cin >> this->d1;
        std::cout << "Введите d2 — внутренний диаметр напорного патрубка [м]: \n";
        std::cin >> this->d2;
    }

    void result() {
        std::cout << "Расчетная мощность насоса: " << power(po, Q, d1, d2, p1, p2) << " Вт" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Ввести параметры вручную (y/n)?  \n";
    char chk;
    std::cin >> chk;
    if (chk == 'y') {
        Pump pump;
        pump.set_all();
        pump.result();
    }
    else {
        Pump pump(1100, 0.5, 100000, 120000, 0.5, 0.3);
        pump.result();
    }
}
