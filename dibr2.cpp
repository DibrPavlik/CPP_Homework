#include <iostream>
#include <cmath>
using namespace std;

class Figure{
public:
    virtual double perimeter() = 0;
    virtual int angels_amount() = 0;
    virtual double square() = 0;

};

class Circle : public Figure{
private:
    double r =0;
public:

    Circle(double r){
        this->r =r;

    }
    double perimeter() override{
        return 2 * 3.14 * r;
    };

    int angels_amount() override{
        return 0;
    };

    double square() override{
        return r * r * 3.14;
    };

};

class Triangle : public Figure {
private:
    double a = 0;
    double b = 0;
    double c = 0;

public :

    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;

    }

    double perimeter() override {
        return a + b + c;
    };

    int angels_amount() override {
        return 3;
    };

    double square() override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    };
};

class Rectangle : public Figure{
private:
    double a = 0;
    double b = 0;

public:

    Rectangle(double a, double b){
        this-> a = a;
        this-> b = b;
    }

    double perimeter() override{
        return a + b + a + b;
    };

    int angels_amount() override{
        return 4;
    };

    double square() override{
        return a * b;
    };
};

class Square : public Figure{
private:
    double a = 0;

public:

    Square(double a){
        this-> a = a;
    }

    double perimeter() override{
        return 4 * a;
    };

    int angels_amount() override{
        return 4;
    };

    double square() override{
        return a * a;
    };
};

class Ellipse : public Figure{
private:
    double a = 0;
    double b = 0;

public:

    Ellipse(double a, double b){
        this-> a = a;
        this-> b = b;
    }

    double perimeter() override{
        return 6.28 * sqrt( 0.5 * (a*a + b*b));
    };

    int angels_amount() override{
        return 0;
    };

    double square() override{
        return  3.14 * a * b;
    };
};

int main(){
    Circle A(10);
    cout << "Периметр круга: " << A.perimeter() << endl;
    cout << "Площадь круга: " << A.square() << endl ;
    cout << "Количество углов круга: " << A.angels_amount() << endl << endl;

    Triangle B(3,4, 5);
    cout << "Периметр треугольника: " << B.perimeter() << endl;
    cout << "Площадь трегоульника: " << B.square() << endl ;
    cout << "Количество углов треугольника: " << B.angels_amount() << endl << endl;

    Rectangle C(5.5, 2);
    cout << "Периметр прямоугольника: " << C.perimeter() << endl;
    cout << "Площадь прямоугольника: " << C.square() << endl ;
    cout << "Количество углов прямоугольника: " << C.angels_amount() << endl << endl;

    Square D(10);
    cout << "Периметр квадрата: " << D.perimeter() << endl;
    cout << "Площадь квадрата: " << D.square() << endl ;
    cout << "Количество углов квадрата: " << D.angels_amount() << endl << endl;

    Ellipse E(10, 5);
    cout << "Периметр эллипса: " << E.perimeter() << endl;
    cout << "Площадь эллипса: " << E.square() << endl ;
    cout << "Количество углов эллипса: " << E.angels_amount() << endl << endl;
}