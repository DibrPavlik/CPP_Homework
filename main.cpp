#include <iostream>
#include <numeric>
using namespace std;

class Fraction {         // n/m

private:
    int n;
    int m;

public:

    Fraction(){
        this->m = 1;
        this->n = 0;
    }

    Fraction(int n, int m) {
        this->m = m;
        this->n = n;
        if ( m == 0 ) cout << " Ошибка! дальше программа работает не правильно " ;
    };


    // Получение числителя и знаменателя
    int getN() const{
        return n;
    };

    int getM() const{
        return m;
    };

    // Задание координат
    void setN(int n){
        this-> n = n;
    };


    void setM(int m){
        this-> m = m;
    };

    // Операторы сравнения
    bool operator == (const Fraction& v){
        if(this->n == v.getN() && this->m == v.getM()) return true;
        else return false;
    };

    bool operator != (const Fraction& v){
        if(this->n == v.getN() && this->m == v.getM()) return false;
        else return true;
    };

    int gcd(int a, int b) {
        auto x = a;
        auto y = b;
        while (a && b)
            if (a > b) a %= b;
            else b %= a;

        return (x * y) / (a + b);
    };
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    };

    // Операторы сложения
    Fraction &operator += (const Fraction& v){
        int s = gcd(this->m, v.getM());
        this->n = this->n * s / this->m + v.getN() * s / v.getM();
        this->m = s;
        int l = lcm(this->n, this->m);
        this->n = this->n / l;
        this->m = this->m / l;
        if (this->m < 1)
        {
            this->m = -1 * this->m;
            this->n = -1 * this->n;
        }
        return *this;

    };

    // Операторы вычитания
    Fraction &operator -= (const Fraction & v){
        int s = gcd(this->m, v.getM());
        this->n = this->n * s / this->m - v.getN() * s / v.getM();
        this->m = s;
        int l = lcm(this->n, this->m);
        this->n = this->n / l;
        this->m = this->m / l;
        if (this->m < 1)
        {
            this->m = -1 * this->m;
            this->n = -1 * this->n;
        }
        return *this;
    }

    // Операторы умножения
    Fraction &operator *= (const Fraction &v){
        this->n = this->n * v.getN();
        this->m = this->m * v.getM();
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
        return *this;
    }

    // Операторы деления
    Fraction &operator /= (const Fraction &v) {
        this->n = this->n * v.getM();
        this->m = this->m * v.getN();
        int l = lcm(this->m, this->n);
        this->n = this->n / l;
        this->m = this->m / l;
        return *this;
    }
};

// Вывод дроби в формате n/m

std::ostream& operator<<(std::ostream& os, const Fraction& v){
    int n, m;
    n = v.getN();
    m = v.getM();
    if( n == 0 ){
       os << "(" << 0 << ")" ;
    }
    else if ( n < 0 && m < 0) os << "(" << -n << "/" << -m << ")";
    else if ( n > 0 && m < 0) os << "(" << -n << "/" << -m << ")";
    else os << "(" << n << "/" << m << ")";
    return os;

}

// Чтение вектора, читает просто числитель и знаменателей, а также  проверяет равен ли знаменатель 0
std::istream& operator>>(std::istream &is, Fraction &v){
    int n, m;
    is >> n >> m;
    if ( m == 0 ) cout << " Ошибка! дальше программа работает не правильно " ;
    else{
        v.setN(n);
        v.setM(m);
    }
    return is;
}

int main(){

    Fraction v1(1, 2);
    Fraction v2;
    cin >> v2;
    cout << v2 << endl;
    cout << boolalpha << (v2 == v1) << endl;
    cout << boolalpha << (v2 != v1) << endl;
    cout << (v2 += v1) << endl;
    cout << (v2 -= v1) << endl;
    cout << (v2 *= v1) << endl;
    cout << (v2 /= v1) << endl;
}



