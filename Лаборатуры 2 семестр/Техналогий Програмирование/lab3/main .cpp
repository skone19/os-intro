/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
#define PI 3.1415926

class Point{
public:
    Point() {}
    Point(double x1, double y1, double z1){}
    Point(double x1, double y1){}
    virtual void setX(double x1) = 0;
    virtual void setY(double y1) = 0;
    virtual void setZ(double z1) {}
    
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getZ() const {}
    
    virtual void print() const = 0;
protected:
    virtual ~Point(){}
    
};

class Point2D : public Point {
private:
    double x;
    double y;
public:

    Point2D(){
        x =0;
        y =0;
    }
    
    Point2D(double x1, double y1):x(x1),y(y1),Point(){}
    
    void setX(double x1) override { x=x1;}
    void setY(double y1) override { y=y1;}
    
    double getX() const override {return x;}
    double getY() const override {return y;}
    
    void print() const override { cout << "Point2D: (" << x << ";" << y << ")\n";}
    
    ~Point2D(){cout << "This is Point2D destructor\n";}
};

class Point3D : public Point{
private:
    double x;
    double y;
    double z;
public:
    Point3D(){
        x=0;
        y=0;
        z=0;
    }
    
    Point3D(double x1, double y1, double z1): x(x1), y(y1), z(z1){}
    
    void setX(double x1) override { x=x1;}
    void setY(double y1) override { y=y1;}
    void setZ(double z1) override { z=z1;}
    
    double getX() const override {return x;}
    double getY() const override {return y;}
    double getZ() const override {return z;}
    
    void print() const override {cout << "Point3D: (" << x << ";" << y << ";" << z << ")\n";}
    
    ~Point3D(){cout << "This is Point3D destructor\n";}
};
class Figure{
    protected:
        string name;
        vector<Point*> points;
        virtual ~Figure(){}
        
    public:
        Figure(){}
        Figure(const Figure &other){
            cout << "Called copy constructor for Figure\n";
            this->name = other.name;
            this->points = other.points;
        }
        
        void setName(string n){ name = n;}
        string getName() const {return name;} 
        
        void setPoints(vector<Point*> &points_){ points = points_;}
        vector<Point*> getPoints() const { return points;}
        
        virtual double getSquare() const {}
        virtual double getVolume() const {}
        virtual double getPerimeter() const {}

        void print() const {
            cout << name << " is points: \n";
            for(int i=0;i<points.size();i++){
                points[i]->print();
            }
        };
};

class Triangle :public Figure{
private:
    Point2D A;
    Point2D B;
    Point2D C;
public:
    int xa, ya, xb, yb, xc,yc;
    Triangle(): A(xa,ya), B(xb, yb), C(xc, yc){
        name = " ";
        points.push_back(&A);
        points.push_back(&B);
        points.push_back(&C);
    }
    Triangle(string n, vector<Point*> &points_){
        name = n;
        points = points_;
    }
    ~Triangle(){
        cout<< "Triangle destructor called\n";
    }
    
    double getPerimeter() const override{
        double P=0;
        for(int i=0;i<3;i++)
            P += sqrt(pow(points[i]->getX()-points[(i+1)%3]->getX(),2)+pow(points[i]->getY()-points[(i+1)%3]->getY(),2));
        return P;
    }
    
    double getSquare()const override{
        double a = sqrt(pow(points[0]->getX()-points[1]->getX(),2)+pow(points[0]->getY()-points[1]->getY(),2));
        double b = sqrt(pow(points[1]->getX()-points[2]->getX(),2)+pow(points[1]->getY()-points[2]->getY(),2));
        double c = sqrt(pow(points[2]->getX()-points[0]->getX(),2)+pow(points[2]->getY()-points[0]->getY(),2));
        double p = (a+b+c)/2.0;
        double S = sqrt(p*(p - a)*(p - b)*(p - c));
        return S;
    }
    
};

class Circle :public Figure{
private:
    Point2D A;
    Point2D B;
public:
    int xb, yb, xa, ya;
    Circle(): A(xa,ya), B(xb,yb){
        name = " ";
        points.push_back(&A);
        points.push_back(&B);
    }
    Circle(string n, vector<Point*> &points_){
        name = n;
        points = points_;
    }
    ~Circle(){
        cout<< "Circle destructor called\n";
    }
    
    double getPerimeter() const override{
        double P= 2*PI*sqrt(pow(points[0]->getX()-points[(1)]->getX(),2)+pow(points[0]->getY()-points[(1)%3]->getY(),2));
        return P;
    }
    
    double getSquare()const override{
        double S = PI*pow(sqrt(pow(points[0]->getX()-points[(1)]->getX(),2)+pow(points[0]->getY()-points[(1)%3]->getY(),2)),2);
        return S;
    }
    
};

class Rectangle :public Figure{
private:
    Point2D A;
    Point2D B;
    Point2D C;
    Point2D D;
public:
    int xa, ya, xb, yb, xc,yc, xd, yd;
    Rectangle():A(xa,ya), B(xb,yb),C(xc,yc),D(xd,yd){
        name = " ";
        points.push_back(&A);
        points.push_back(&B);
        points.push_back(&C);
        points.push_back(&D);
    }
    Rectangle(string n, vector<Point*> &points_){
        name = n;
        points = points_;
    }
    ~Rectangle(){
        cout<< "Rectangle destructor called\n";
    }
    
    double getPerimeter() const override{
        double P=0;
        for(int i=0;i<2;i++)
            P += sqrt(pow(points[i]->getX()-points[(i+1)]->getX(),2)+pow(points[i]->getY()-points[(i+1)]->getY(),2));
        return 2*P;
    }
    
    double getSquare()const override{
        double a = sqrt(pow(points[0]->getX()-points[1]->getX(),2)+pow(points[0]->getY()-points[1]->getY(),2));
        double b = sqrt(pow(points[1]->getX()-points[2]->getX(),2)+pow(points[1]->getY()-points[2]->getY(),2));
        return a*b;
    }
};

class Sphere :public Figure{
private:
    Point3D A;
    Point3D B;
public:
    int xa, ya,za, xb, yb,zb;
    Sphere():A(xa,ya,za),B(xb,yb,zb){
        name = " ";
        points.push_back(&A);
        points.push_back(&B);
    }
    Sphere(string n, vector<Point*> &points_){
        name = n;
        points = points_;
    }
    ~Sphere(){
        cout<< "Sphere destructor called\n";
    }
    
    double getSquare()const override{
        double R = sqrt(pow(points[0]->getX()-points[1]->getX(),2)+pow(points[0]->getY()-points[1]->getY(),2)+pow(points[0]->getZ()-points[1]->getZ(),2));
        return 4*PI*pow(R,2);
    }
    
    double getVolume()const override{
        double R = sqrt(pow(points[0]->getX()-points[1]->getX(),2)+pow(points[0]->getY()-points[1]->getY(),2)+pow(points[0]->getZ()-points[1]->getZ(),2));
        return (4.0/3.0)*PI*pow(R,3);
    }
};

class Tetrahedron :public Figure{
private:
    Point3D A;
    Point3D B;
    Point3D C;
    Point3D D;
public:
    int xa, ya, za, xb, yb, zb, xc, yc, zc, xd,yd, zd;
    Tetrahedron():A(xa,ya,za),B(xb,yb,zb),C(xc,yc,zc),D(xd,yd,zd){
        name = " ";
        points.push_back(&A);
        points.push_back(&B);
        points.push_back(&C);
        points.push_back(&D);
    }
    Tetrahedron(string n, vector<Point*> &points_){
        name = n;
        points = points_;
    }
    ~Tetrahedron(){
        cout<< "Tetrahedron destructor called\n";
    }
    
    double getSquare()const override{
        double a = sqrt(pow(points[1]->getX()-points[2]->getX(),2)+pow(points[1]->getY()-points[2]->getY(),2)+pow(points[1]->getZ()-points[2]->getZ(),2));
        return sqrt(3)*pow(a,2);
    }
    
    double getVolume()const override{
        double a = sqrt(pow(points[1]->getX()-points[2]->getX(),2)+pow(points[1]->getY()-points[2]->getY(),2)+pow(points[1]->getZ()-points[2]->getZ(),2));
        return pow(a,3)*sqrt(2)/12;
    }
};  

class Parallelepiped :public Figure{
private:
    Point3D A;
    Point3D B;
    Point3D C;
    Point3D D;
    Point3D E;
    Point3D F;
    Point3D G;
    Point3D H;
public:
      int xa, ya,za, xb, yb,zb, xc,yc, zc, xd, yd, zd, xe, ye, ze, xf, yf, zf, xg, yg,zg, xh,yh,zh;
    Parallelepiped():A(xa,ya,za),B(xb,yb,zb),C(xc,yc,zc),D(xd,yd,zd),E(xe,ye,ze),F(xf,yf,zf),G(xg,yg,zg),H(xh,yh,zh){
        name = " ";
        points.push_back(&A);
        points.push_back(&B);
        points.push_back(&C);
        points.push_back(&D);
        points.push_back(&E);
        points.push_back(&F);
        points.push_back(&G);
        points.push_back(&H);
    }
    Parallelepiped(string n, vector<Point*> &points_){
        name = n;
        points = points_;
    }
    ~Parallelepiped(){
        cout<< "Parallelepiped destructor called\n";
    }
    
    double getSquare()const override{
        double a = sqrt(pow(points[0]->getX()-points[1]->getX(),2)+pow(points[0]->getY()-points[1]->getY(),2)+pow(points[0]->getZ()-points[1]->getZ(),2));
        double b = sqrt(pow(points[0]->getX()-points[2]->getX(),2)+pow(points[0]->getY()-points[2]->getY(),2)+pow(points[0]->getZ()-points[2]->getZ(),2));
        double c = sqrt(pow(points[0]->getX()-points[4]->getX(),2)+pow(points[0]->getY()-points[4]->getY(),2)+pow(points[0]->getZ()-points[4]->getZ(),2));
        return 2*(a*b+b*c+c*a);
    }
    
    double getVolume()const override{
        double a = sqrt(pow(points[0]->getX()-points[1]->getX(),2)+pow(points[0]->getY()-points[1]->getY(),2)+pow(points[0]->getZ()-points[1]->getZ(),2));
        double b = sqrt(pow(points[0]->getX()-points[2]->getX(),2)+pow(points[0]->getY()-points[2]->getY(),2)+pow(points[0]->getZ()-points[2]->getZ(),2));
        double c = sqrt(pow(points[0]->getX()-points[4]->getX(),2)+pow(points[0]->getY()-points[4]->getY(),2)+pow(points[0]->getZ()-points[4]->getZ(),2));
        return a*b*c;
    }
}; 



int main(){
    
    int xa, ya,za, xb, yb,zb, xc,yc, zc, xd, yd, zd, xe, ye, ze, xf, yf, zf, xg, yg,zg, xh,yh,zh;
    
    while (1)
    {
        
       cout <<">-------------MENU---------------<\n";
       cout <<"1. Triangle Area and Perimetre\n" ;
       cout <<"2. Rectangle Area and Perimetre\n" ;
       cout <<"3. Circle Area and Perimetre\n";
       cout <<"4. Sphere Area and volume\n" ;
       cout <<"5. Tetrahedron Area and Volume\n";
       cout <<"6. Parallelepiped Area and Volume\n";
       cout <<"7. Exit\n";
       cout <<"Enter your choice:\n";
       int Operation=0;
       cin>>Operation;
       if (Operation<=0 || Operation>7)
             {
            cout<<"Invalid CHOICE:\n";
            continue;
             }
       if (Operation==1)
       {
           
    cout <<"abscisse xa and ordonne ya of A:\n";
    cin>>xa>>ya;
    cout <<"abscisse xb and ordonne yb of  B:\n";
    cin>>xb>>yb;
    cout <<"abscisse xc and ordonne yc of C:\n";
    cin>>xc>>yc;
    Point2D A(xa,ya);
    Point2D B(xb,yb);
    Point2D C(xc,yc);
    vector <Point*> point;
    point.push_back(&A);
    point.push_back(&B);
    point.push_back(&C);
    Triangle triangle(" Triangle", point);
    triangle.print();
    cout <<"Triangle Perimeter:"<< triangle.getPerimeter() <<endl;
    cout <<"Triangle Square :" <<triangle.getSquare() << endl;
    
       }
       
       if (Operation==2)
       {
    cout <<"abscisse xa and ordonne ya of A:\n";
    cin>>xa>>ya;
    cout <<"abscisse xb and ordonne yb of  B:\n";
    cin>>xb>>yb;
    cout <<"abscisse xc and ordonne yc of C:\n";
    cin>>xc>>yc;
    cout <<"abscisse xd and ordonne yd of D:\n";
    cin>>xd>>yd;
    Point2D A(xa,ya);
    Point2D B(xb,yb);
    Point2D C(xc,yc);
    Point2D D(xd,yd);
    vector <Point*> point;
    point.push_back(&A);
    point.push_back(&B);
    point.push_back(&C);
    point.push_back(&D);
    Rectangle rectangle("Rectangle", point);
    rectangle.print();
    cout <<"Perimeter Rectangle: "<<rectangle.getPerimeter() << endl;
    cout <<"Square Rectangle: "<<rectangle.getSquare() << endl;
           
       }
       if (Operation==3)
       {
    cout <<"abscisse xa and ordonne ya of A:\n";
    cin>>xa>>ya;
    cout <<"abscisse xb and ordonne yb of  B:\n";
    cin>>xb>>yb;
           
    Point2D A(xa,ya);
    Point2D B(xb,yb);
    vector <Point*> point;
    point.push_back(&A);
    point.push_back(&B);
    Circle circle("Circle",point);
    circle.print();
    cout <<"Perimeter Circle:"<< circle.getPerimeter()<< endl;
    cout <<"Square Circle : "<< circle.getSquare() <<endl;
    
       }
       if (Operation==4)
       {
    cout <<"abscisse xa , ordonne ya and altitude za of A:\n";
    cin>>xa>>ya>>za;
    cout <<"abscisse xb ,ordonne yb and altitude zb of  B:\n";
    cin>>xb>>yb>>zb;
    Point3D A(xa,ya,za);
    Point3D B(xb,yb,zb);
    vector <Point*> point;
    point.push_back(&A);
    point.push_back(&B);
    Sphere sphere("Sphere",point);
    sphere.print();
    cout << "Square Sphere:"<<sphere.getSquare()<< endl;
    cout <<"Volume Sphere:" << sphere.getVolume() << endl;
       }
       if (Operation==5)
       {
    cout <<"abscisse xa and ordonne ya , altitude za 1 of A:\n";
    cin>>xa>>ya>>za;
    cout <<"abscisse xb and ordonne yb and altitude zb of B:\n";
    cin>>xb>>yb>>zb;
    cout <<"abscisse xc and ordonne yc , altitude zc 1 of C:\n";
    cin>>xc>>yc>>zc;
    cout <<"abscisse xd and ordonne yd and altitude zd of  D:\n";
    cin>>xd>>yd>>zd;
    Point3D A(xa,ya,za);
    Point3D B(xb,yb,zb);
    Point3D C(xc,yc,zc);
    Point3D D(xd,yd,zd);
    vector <Point*> point;
    point.push_back(&A);
    point.push_back(&B);
    point.push_back(&C);
    point.push_back(&D);
           
    Tetrahedron tetrahedron("Tetrahedron",point);
    tetrahedron.print();
    cout <<"Square Tetrahedron:"<< tetrahedron.getSquare() << endl;
    cout << "Volume Tetrahedron:"<< tetrahedron.getVolume() << endl;
       }
       
        if (Operation==6)
        {
     int x1, y1, z1, x2, y2, z2, x3, y3,z3, x4, y4,z4, x5,y5,z5,x6,y6,z6,x7,y7,z7,x8,y8,z8;
    cout <<"abscisse xa and ordonne ya , altitude za 1 of A:\n";
    cin>>xa>>ya>>za;
    cout <<"abscisse xb and ordonne yb and altitude zb of  B:\n";
    cin>>xb>>yb>>zb;
    cout <<"abscisse xc and ordonne yc , altitude zc 1 of C:\n";
    cin>>xc>>yc>>zc;
    cout <<"abscisse xd and ordonne yd and altitude zd of  D:\n";
    cin>>xd>>yd>>zd;
    cout <<"abscisse xe and ordonne ye , altitude ze 1 of E:\n";
    cin>>xe>>ye>>ze;
    cout <<"abscisse xf and ordonne yf and altitude zf of  F:\n";
    cin>>xf>>yf>>zf;
    cout <<"abscisse xg and ordonne yg , altitude zg 1 of G:\n";
    cin>>xg>>yg>>zg;
    cout <<"abscisse xh and ordonne yh and altitude zh of  H:\n";
    cin>>xh>>yh>>zh;
    
    Point3D A(xa,ya,za);
    Point3D B(xb,yb,zb);
    Point3D C(xc,yc,zc);
    Point3D D(xd,yd,zd);
    Point3D E(xe,ye,ze);
    Point3D F(xf,yf,zf);
    Point3D H(xh,yh,zh);
    Point3D G(xg,yg,zg);
    vector <Point*> point;
    point.push_back(&A);
    point.push_back(&B);
    point.push_back(&C);
    point.push_back(&D);
    point.push_back(&E);
    point.push_back(&F);
    point.push_back(&G);
    point.push_back(&H);
    Parallelepiped parallelepiped("Parallelepiped", point);
    parallelepiped.print();
    cout <<"Square parallelepiped:" << parallelepiped.getSquare()<< endl;
    cout <<"Volume parallelepiped: " << parallelepiped.getVolume() << endl;
            
            
        }
         if (Operation==7)
             exit(1);
        else
            {
                 continue;
            }
             
             
        }
           
    }
       
  





