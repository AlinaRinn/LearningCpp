#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Point { // 2 args
protected:
	float x = 0, y = 0;

public:
	Point() {

	}
	Point(float x, float y) {
		set_x(x);
		set_y(y);
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
	~Point() {

	}
};

class Line : public Point {
	using Point::Point; // constructor inheritance
protected:
	float x1 = 0, y1 = 0;

public:
	Line(float x, float y, float x1, float y1) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
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
};

class Colored { // Interface

	virtual std::string get_color() = 0;
	virtual void set_color(std::string color) = 0;

};

class ColoredPoint : public Point, public Colored {
	using Point::Point;   //ColoredPoint() : Point() {}
protected:
	std::string color = "";

public:
	ColoredPoint(float x, float y, std::string color) {
		set_x(x);
		set_y(y);
		set_color(color);
	}

	virtual std::string get_color() {
		return color;
	}
	virtual void set_color(std::string color) {
		this->color = color;
	}
};


class ColoredLine : public Line, public Colored {
	using Line::Line;

protected:
	std::string color = "";

public:
	ColoredLine(float x, float y, float x1, float y1, std::string color) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
		set_color(color);
	}

	virtual std::string get_color() {
		return color;
	}
	virtual void set_color(std::string color) {
		this->color = color;
	}
};

class PolyLine : public Line {
	using Line::Line;

protected:
	int shape = 0;

public:
	PolyLine(float x, float y, float x1, float y1, int shape) {
		set_x(x);
		set_y(y);
		set_x1(x1);
		set_y1(y1);
		set_shape(shape);
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
	std::vector<ColoredPoint*> cpoints;
	std::vector<Line*> lines;
	std::vector<ColoredLine*> clines;
	std::vector<PolyLine*> plines;

	for (int i = 0; i < 5; i++)
	{
		points.push_back(new Point((float)i, (float)i));
		std::cout << "Object " << points.size() << "   X: " << points[i]->get_x() << "   Y: " << points[i]->get_y() << std::endl;
	}
	for (int i = 0; i < 5; i++) 
	{
		cpoints.push_back(new ColoredPoint((float)i, (float)i, "Yellow"));
		std::cout << "Object " << cpoints.size() << "   X: " << cpoints[i]->get_x() << "   Y: " << cpoints[i]->get_y() << "   Color: " << cpoints[i]->get_color() << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		lines.push_back(new Line((float)i, (float)i, (float)i, (float)i));
		std::cout << "Object " << lines.size() << "   X: " << lines[i]->get_x() << "   Y: " << lines[i]->get_y() << "   X1: " << lines[i]->get_x1() << "   Y1: " << lines[i]->get_y1() << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		clines.push_back(new ColoredLine((float)i, (float)i, (float)i, (float)i, "Red"));
		std::cout << "Object " << clines.size() << "   X: " << clines[i]->get_x() << "   Y: " << clines[i]->get_y() << "   X1: " << clines[i]->get_x1() << "   Y1: " << clines[i]->get_y1() << "   Color: " << clines[i]->get_color() << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		plines.push_back(new PolyLine((float)i, (float)i, (float)i, (float)i, 1));
		std::cout << "Object " << plines.size() << "   X: " << plines[i]->get_x() << "   Y: " << plines[i]->get_y() << "   X1: " << clines[i]->get_x1() << "   Y1: " << clines[i]->get_y1() << "   Shape: " << plines[i]->get_shape() << std::endl;
	}
}
