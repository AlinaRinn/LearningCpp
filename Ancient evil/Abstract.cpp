// Абстракция данных
// Создайте программу на любом языке, демонстрирующую абстракцию на уровне данных. Загрузите файл программы и поясните, в чем абстракция.

#include <iostream>
#include <vector>

// Класс ICar - интерфейс, который гарантирует, что метод time всегда получает и возвращает 1 переменную типа double.
// У него есть дочерние классы: Машина, Гоночная машина, Грузовик. 
// У каждого класса своя скорость и параметры => метод расчета времени в пути отличается.
// Таким образом, с помощью интерфейса мы абстрагировались от данных - передав в метод time путь, мы в любом случае получим время в пути, независимо от метода рачета.

class ICar {
public:
    virtual double time(double path) = 0;
};

class RacingCar : ICar {
private:
    double speed = 380.0;
public:
    double time(double path) {
        return path / speed;
    }
};

class Car : ICar {
private:
    double speed = 180.0;
    double condition = 0.9;
public:
    double time(double path) {
        return (path / speed) / condition;
    }
};

class Truck : ICar {
private:
    double speed = 120.0;
    double load = 0.8;
public:
    double time(double path) {
        return (path / speed) + ((path / speed) * load);
    }
};


int main() {

    Truck truck;
    Car car;
    RacingCar rcar;

    std::cout << "Arrival after: " << truck.time(100.0) << " hours\n";
    std::cout << "Arrival after: " << car.time(100.0) << " hours\n";
    std::cout << "Arrival after: " << rcar.time(100.0) << " hours\n";

}