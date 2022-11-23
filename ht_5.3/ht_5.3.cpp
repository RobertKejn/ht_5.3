#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
protected:
	std::string name;
	int points;

	
public:
	Figure() {
		name = "Фигура";
		points = 0;
	}

	virtual bool IsRight() {
		return true;
	}

	virtual void print_info() {
		std::cout << name << ":\n";
		std::cout << ((this->IsRight()) ? "Правильная" : "Неправильная") << "\n";
		std::cout << "Стороны: " << points << "\n";
	}
};



class Triangle : public Figure {
protected:
	int a = 0;
	int b = 0;
	int c = 0;
	int A = 0;
	int B = 0;
	int C = 0;

	Triangle() {
		name = "Треугольник";
		points = 3;
	}

public:

	Triangle(int a, int b, int c, int A, int B, int C) : Triangle() {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	void print_info() override {
		std::cout << name << ":\n";
		std::cout << ((this->IsRight() && Triangle::IsRight()) ? "Правильная" : "Неправильная") << "\n";
		std::cout << "Количество сторон: " << this->points << "\n";
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
	}

	bool IsRight() override {
		return A + B + C == 180 && this->points == 3;
	}
};



class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { name = "Прямоугольный треугольник"; }

	bool IsRight() override {
		return C == 90;
	}
};



class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, a, a, A, B, A) { name = "Равнобедренный треугольник"; }

	bool IsRight() override {
		return a == b && A == B;
	}
};



class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) { name = "Равносторонний треугольник"; }

	bool IsRight() override {
		return a == b && b == c && A == B && B == C;
	}
};





class Quadrangle : public Figure {
protected:
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

	Quadrangle() {
		name = "Четырехугольник";
		points = 4;
	}

public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle() {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}

	void print_info() override {
		std::cout << name << ":\n";
		std::cout << ((this->IsRight() && Quadrangle::IsRight()) ? "Правильная" : "Неправильная") << "\n";
		std::cout << "Количество сторон: " << this->points << "\n";
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
	}

	bool IsRight() override {
		return A + B + C + D == 360 && this->points == 4;
	}
};



class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) { name = "Параллелограмм"; }

	bool IsRight() override {
		return a == c && b == d && A == C && B == D;
	}

};



class Rect : public Parallelogram {
public:
	Rect(int a, int b) : Parallelogram(a, b, 90, 90) { name = "Прямоугольник"; };

	bool IsRight() override {
		return a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90;
	}
};



class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) { name = "Ромб"; };

	bool IsRight() override {
		return a == b && b == c && c == d && A == C && B == D;
	}
};



class Square : public Rhombus {
public:
	Square(int a) : Rhombus(a, 90, 90) { name = "Квадрат"; };
	
	bool IsRight() override {
		return a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure f = Figure();
	f.print_info();
	std::cout << std::endl;

	Triangle tr = Triangle(10, 20, 30, 30, 60, 90);
	Figure* fig = &tr;
	fig->print_info();
	std::cout << std::endl;

	RightTriangle rt = RightTriangle(1, 1, 1, 45, 45);
	fig = &rt;
	fig->print_info();
	std::cout << std::endl;

    rt = RightTriangle(1, 1, 1, 2, 2);
	fig = &rt;
	fig->print_info();
	std::cout << std::endl;

	IsoscelesTriangle it = IsoscelesTriangle(10, 20, 100, 100);
	fig = &it;
	fig->print_info();
	std::cout << std::endl;

	EquilateralTriangle et = EquilateralTriangle(200);
	fig = &et;
	fig->print_info();
	std::cout << std::endl;

	Parallelogram p = Parallelogram(10, 20, 30, 60);
	fig = &p;
	fig->print_info();
	std::cout << std::endl;

	Rect rect = Rect(10, 20);
	fig = &rect;
	fig->print_info();
	std::cout << std::endl;

	Rhombus rhomb = Rhombus(10, 45, 45);
	fig = &rhomb;
	fig->print_info();
	std::cout << std::endl;

	Square square = Square(30);
	fig = &square;
	fig->print_info();
}