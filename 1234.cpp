#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


template<typename T >
class Point2D
{
protected:
    T _x;
    T _y;

public:
    // Конструктор точки с заданными координатами
    Point2D(T x, T y): _x(x), _y(y) {
    };

    // Получить координату X точки
    T x() const {
        return _x;
    };

    // Получить координату Y точки
    T y() const {
        return _y;
    };
};


template<typename T>
class Polygone
{
protected:
    vector<Point2D<T>>  poly;
public:
    // Конструктор, создаёт полигон из набора точек.
    // Точки передаются в порядке обхода полигона по контуру.
    Polygone<T>(std::vector<Point2D<T>>& points){
        for( auto i : points){
            poly.push_back(i);
        }
    };

    // Деструктор, если нужен

    // Возвращает площадь полигона

    T area() const{
        T sum = 0;
        for(unsigned int i = 1; i< poly.size(); i++){
            sum += poly[i-1].x() * poly[i].y();
            sum -= poly[i].x()*poly[i-1].y();
        }
        sum += poly[poly.size()-1].x() * poly[0].y() - poly[0].x() * poly[poly.size()-1].y();
        if(sum < 0) return -1*sum/2;
        return sum/2;
    };

    T perimetre(){
        T sum = 0;
        for(unsigned int i = 1; i< poly.size() ; i++){
            sum += sqrt( (poly[i-1].x() - poly[i].x()) * (poly[i-1].x() - poly[i].x()) + (poly[i-1].y() - poly[i].y()) * (poly[i-1].y() - poly[i].y()) );
        }
        sum += sqrt( (poly[poly.size() -1 ].x() - poly[0].x()) * (poly[poly.size() -1 ].x() - poly[0].x()) + (poly[poly.size() -1 ].y() - poly[0].y()) * (poly[poly.size() -1 ].y() - poly[0].y()) );
        return sum;
    };

    // Возвращает количество вершин полигона
    unsigned  int size() const{
        return poly.size();
    };

    // Возвращает N-ую вершину полигона
    // (вершины нумеруются в том же порядке, в котором были переданы)
    Point2D<T> vertex(int N) const{
        return poly[N];
    };
};

int main()
{
    vector<Point2D<double>> points = {{-1.0, -1.0}, {-1.0, 1.0}, {1.0, 1.0}, {2.0, 0.0}, {1.0, -1.0}};
    Polygone<double> p(points);
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.size(); i++) {
        cout << p.vertex(i).x() << " " << p.vertex(i).y() << endl;
    }
    cout << "Area: " << p.area() << endl;
    cout << "Perimetre: " << p.perimetre() << endl;
    return 0;
}
