#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


class Point {//点类
private:
    int x;
    int y;
    int z;
public:
    Point(int xi = 0, int yi = 0, int zi = 0) : x(xi), y(yi), z(zi) {}
    Point(const Point& p){
        x = p.x;
        y = p.y;
        z = p.z;
    }
    friend double Cauculate(const Point &p1, const Point &p2);
    friend istream &operator>>(istream &is, Point &p);
    friend ostream& operator << (ostream& os, Point& p);
};


class Dist{//距离类
private:
    Point p1;
    Point p2;
    double dist;
public:
    Dist(Point const& pi1, Point const& pi2, double d):p1(pi1), p2(pi2), dist(d){}
    friend ostream& operator << (ostream& os, Dist& d);
    friend bool operator < (const Dist& d1, const Dist& d2);
};


double Cauculate(const Point& p1, const Point& p2){//计算两点之间的距离
    return sqrt(pow(p1.x - p2.x, 2)+pow(p1.y - p2.y, 2)+pow(p1.z - p2.z, 2));
}


istream& operator >> (istream& is, Point& p){//重载输入运算符可以输入点
    is >> p.x >> p.y >> p.z;
    return is;
}


ostream& operator << (ostream& os, Point& p){//重载输出运算符可以输出点
    os << '(' << p.x << ',' << p.y << ',' << p.z << ')';
    return os;
}


ostream& operator << (ostream& os, Dist& d){//重载输出运算符可以输出dist
    os << d.p1 << '-' << d.p2 << '=' << fixed << setprecision(2) << d.dist << endl;
    return os;
}


bool operator < (const Dist& d1, const Dist& d2){//重载<号可以比较两个dist
    return d1.dist < d2.dist;
}


void BubbleSort(Dist *distances[], int n){//冒泡排序，符合题目输出要求，不用特殊改变
    bool noSwap;
    Dist *tmp;
    for(int i = 1; i < n; i++){
        noSwap = true;
        for(int j = n-1; j >= i; j--){
            if(*(distances[j-1]) < *(distances[j])){
                tmp = distances[j];
                distances[j] = distances[j-1];
                distances[j-1] = tmp;
                noSwap = false;
            }
        }
        if(noSwap){
            break;
        }
    }
}


int main(){
    int n;
    cin >> n;
    Point points[11];
    Dist *distances[50];
    for(int i = 0; i < n; i++){
        cin >> points[i];//初始化点序列
    }
    int count = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            distances[count] = new Dist(points[i], points[j], Cauculate(points[i], points[j]));//初始化距离序列
            count++;
        }
    }
    BubbleSort(distances, count);//排序
    for(int i = 0; i < count; i++){//从大到小输出
        cout << *(distances[i]);
    }
    return 0;
}

