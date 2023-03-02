#include <iostream>


class Figure
{
public:
	Figure() {};
	virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
	double a, h;

public:
	Parallelogram(double inputA, double inputH)
		: a(inputA), h(inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Circle : public Figure
{
private:
	double r;
public:
	Circle(double inputR)
		: r(inputR) {};

	double area() override
	{
		return (3.14 * r * r / 2);
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Square : public Parallelogram
{
public:
	Square(double inputA)
		: Parallelogram(inputA, inputA) {};

	double area() override
	{
		return (a * a);
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};



class Car
{
protected:
	std::string company, model;
public:
	Car() {}
	Car(std::string inputCompany, std::string inputModel)
		: company(inputCompany), model(inputModel)
	{
		std::cout << "\nCar конструктор";
	}

	virtual ~Car()
	{
		std::cout << "\nCar деструктор\n\n";
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar() {}
	PassengerCar(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\nPassengerCar конструктор";
		std::cout << "\n" << company << " " << model;
	}

	std::string getModel()
	{
		return model;
	}

	~PassengerCar()
	{
		std::cout << "\nPassengerCar деструктор";
	}
};

class Bus : virtual public Car
{
public:
	Bus() {}
	Bus(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\nBus конструктор";
		std::cout << "\n" << company << " " << model;
	}

	~Bus()
	{
		std::cout << "\nBus деструктор";
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\nMinivan конструктор";
		std::cout << "\n" << company << " " << model;
	}

	~Minivan()
	{
		std::cout << "\nMinivan деструктор";
	}
};



class Fraction
{
private:
	double numerator, denominator;
public:
	Fraction(double inputNumerator, double inputDenominator)
		: numerator(inputNumerator), denominator(inputDenominator)
	{
		if (denominator == 0) denominator = 0.00000001;
	}

	friend Fraction operator+(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1, const Fraction& d2);
	friend Fraction operator*(const Fraction& d1, const Fraction& d2);
	friend Fraction operator/(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

	void setDenominator(double inputDenominator)
	{
		if (inputDenominator == 0) inputDenominator = 0.00000001;
		denominator = inputDenominator;
	}

	void setNumerator(double inputNumerator)
	{
		numerator = inputNumerator;
	}

	double getNumerator()
	{
		return numerator;
	}

	double getDenominator()
	{
		return denominator;
	}
};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
	return Fraction(-d1.numerator, -d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
	else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
	if (d1 == d2) return false;
	else return true;
}

bool operator>(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator<=(Fraction& d1, Fraction& d2)
{
	if (!(d1 > d2)) return true;
	else return false;
}

bool operator<(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
	if (!(d1 < d2)) return true;
	else return false;
}


std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Задание №1\n\nСоздать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).\n\nДля всех классов создать конструкторы.Для класса Figure добавить виртуальную функцию area() (площадь).Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.\n\n";
	
	double parallelorgamHeight(3), parallelogramBase(3.1);
	Parallelogram parallelogram(parallelogramBase, parallelorgamHeight);
	std::cout << parallelogram.area() << "\n";

	double circleRadius(4.2);
	Circle circle(circleRadius);
	std::cout << circle.area() << "\n";

	double squareBase(6);
	Square square(squareBase);
	std::cout << square.area() << "\n";

	double rectangleBase(2), rectangleHeight(2);
	Rectangle rectangle(rectangleBase, rectangleHeight);
	std::cout << rectangle.area() << "\n";

	double rhombusBase(5), rhombusHeight(7);
	Rhombus rhombus(rhombusBase, rhombusHeight);
	std::cout << rhombus.area() << "\n";

	std::cout << "\n\nЗадание №2\n\nСоздать класс Car(автомобиль) с полями company(компания) и model(модель).Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).От этих классов наследует класс Minivan(минивэн).Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.Обратить внимание на проблему ромбовидного наследования.\n\n";

	Car* car = new Car("Mazda", "R-3");
	std::cout << "\n==============================";
	PassengerCar* passengerCar = new PassengerCar("BMW", "E293");
	std::cout << "\n==============================";
	Bus* bus = new Bus("Lada", "Granta");
	std::cout << "\n==============================";
	Minivan* minivan = new Minivan("Pegeot", "406");
	std::cout << "\n==============================";
	delete minivan;
	std::cout << "\n==============================";
	delete bus;
	std::cout << "\n==============================";
	delete passengerCar;
	std::cout << "\n==============================";
	delete car;

	std::cout << "\nЗадание №3\n\nСоздать класс Fraction(дробь).Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:\n\n-математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями\n\n- унарный оператор(-)\n\n- логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).\n\nПримечание: Поскольку операторы < и >= , > и <= — это логические противоположности, попробуйте перегрузить один через другой.\n\n";
	Fraction d1(1, 2);
	Fraction d2(3, 2);
	std::cout << "\n\n" << (d1 + d2);
	std::cout << "\n\n" << (d1 - d2);
	std::cout << "\n\n" << (d1 * d2);
	std::cout << "\n\n" << (d1 / d2);
	std::cout << "\n\n" << (-d1) << "\n";

	if (d1 == d2) std::cout << "\nFraction 1 == Fraction 2";
	if (d1 != d2) std::cout << "\nFraction 1 != Fraction 2";
	if (d1 > d2) std::cout << "\nFraction 1 > Fraction 2";
	if (d1 <= d2) std::cout << "\nFraction 1 <= Fraction 2";
	if (d1 < d2) std::cout << "\nFraction 1 < Fraction 2";
	if (d1 >= d2) std::cout << "\nFraction 1 >= Fraction 2";
	system("pause");
}