// Преамбула
// 
// Наследование от интерфейса, по сути, уже является полиморфизмом классов, поэтому, задача была выполнена в предыдущем домашнем задании =)
// Чтобы не оставаться без задания, переписал программу с использованием полиморфизма в конструкторах

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Colored { // Interface

	virtual std::string get_color() = 0;
	virtual void set_color(std::string color) = 0;

};

class Point : public Colored { 
protected:
	float x = 0, y = 0;
	std::string color = "";

public:
	Point() {

	}
	Point(float x, float y) {
		set_x(x);
		set_y(y);
	}
	Point(float x, float y, std::string color) {  // constructor overloading
		set_x(x);
		set_y(y);
		set_color(color);
	}
	
	float get_x() {
		return x;
	}
	float get_y() {
		return y;
	}
	void set_x(float x) {
		this->x = x;
	}
	void set_y(float y) {
		this->y = y;
	}
	std::string get_color() {   // interface realisation
		return color; 
	}
	void set_color(std::string color) {
		this->color = color;
	}

	~Point() {

	}
};

class Line : public Point {
	using Point::Point; // constructor inheritance
protected:
	float x1 = 0, y1 = 0;
	int shape = 0;

public:
	Line(float x, float y, float x1, float y1) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
	}
	Line(float x, float y, float x1, float y1, std::string color) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
		set_color(color);
	}
	Line(float x, float y, float x1, float y1, int shape) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
		set_shape(shape);
	}	
	Line(float x, float y, float x1, float y1, int shape, std::string color) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
		set_shape(shape);
		set_color(color);
	}

	float get_x1() {
		return x1;
	}
	float get_y1() {
		return y1;
	}
	void set_x1(float x1) {
		this->x1 = x1;
	}
	void set_y1(float y1) {
		this->y1 = y1;
	}
	std::string get_shape() {
		if (shape == 0)
			return "Linear";
		else if (shape == 1)
			return "curve";
		else
			return "arc";
	}
	void set_shape(int shape) {
		this->shape = shape;
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	std::vector<Point*> points;
	std::vector<Line*> lines;
	lines.push_back(new Line(12.0, 1.0, 22.0, 9.0));
	lines.push_back(new Line(8.0, 6.0, 48.0, 5.0, "Yellow"));
	lines.push_back(new Line(6.0, 3.0, 88.0, 7.0, 1));
	lines.push_back(new Line(19.0, 8.0, 84.0, 0.0, 77, "Green"));
	points.push_back(new Point(1.0, 2.0));
	points.push_back(new Point(1.0, 7.0, "Red"));

	int j = 0;
	for (auto line : lines) {
		j++;
		std::cout << "Line " << std::setw(2) << j << "   X: " << std::setw(3) << line->get_x() << "   Y: " << std::setw(3) << line->get_y() << "   X1: " << std::setw(3) << line->get_x1() << "   Y1: " << std::setw(3) << line->get_y1()
			<< "   Shape: " << std::setw(6) << line->get_shape() << "   Color: " << line->get_color() << std::endl;
	}	

	j = 0; std::cout << "\n\n";
	for (auto point : points) {
		j++;
		std::cout << "Point " << std::setw(2) << j << "   X: " << std::setw(3) << point->get_x() << "   Y: " << std::setw(3) << point->get_y() << "   Color: " << point->get_color() << std::endl;
	}
}
