#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
//class shape{};
//class Tringle{};
//class Circle{};
//class Rectangle{};


class list_shape;
class Rectangle;
class Circle;
class Square;
class shape{
public:

    virtual float Area()=0;
    virtual void draw()=0;
    //virtual bool operator ==(shape * a)=0;

};

class Circle:public shape{
    int r;
public:
    Circle(int r1=0):r(r1){}
    void draw(){
        cout << "Circle "<<r<<endl;
    }
    float Area(){
        return 3.14*r*r;
    }
    bool operator==(Circle *cr){
        return r==cr->r;
    }
};

class Rectangle:public shape{
    int a,b;
    friend Square;
public:
    Rectangle(int a1=0,int b1=0):a(a1),b(b1){}
    void draw(){
        cout << "Rectangle "<<a<<"  "<<b<<endl;
    }
    float Area(){
        return a*b;
    }
    bool operator==(Rectangle *re){
        return a==re->a && a==re->b;
    }
};

class Square:public Rectangle{
public:
    Square(int a1=0){
        a=a1;
        b=a1;
    }
    void draw(){
        cout << "Square "<<a<<"  "<<b<<endl;
    }
    float Area(){
        return a*a;
    }
    bool operator==(Square *sq){
        return a==sq->a && a==sq->a;
    }
};

class list_shape{
    vector<shape *> SHAPE;
    
public:
    //list_shape(){}
    
    void add(shape* s){
        SHAPE.push_back(s);
    }
    shape * find(float AREA){
        for(auto sh = SHAPE.begin(); sh != SHAPE.end(); sh++){
            if((*sh)->Area()==AREA){
                return *sh;
                
            }
        }
        return nullptr;
    }
    shape * GetItem(int index){
        if (index < 0 || (size_t) index >= SHAPE.size())
            return nullptr;
        return SHAPE[index];
    }
    void del(shape* s){
        for(auto sh = SHAPE.begin(); sh != SHAPE.end(); sh++){
            if(*(sh)==s){
                SHAPE.erase(sh);
                return;       
            }
        }
    }
    void sort(){
        for(auto sh = SHAPE.begin(); sh != SHAPE.end(); sh++){
            float Arsh=(*sh)->Area();
            cout<<Arsh<<endl;
            (*sh)->draw();
            for(auto sh2 = ++sh; sh2 != SHAPE.end(); sh2++){
                if((*sh2)->Area()<Arsh){
                    (*sh2)->draw();
                    cout<<(*sh2)->Area()<<endl;
                    shape* s12=*sh2;
                    *sh2=*sh;
                    *sh=s12;
                    Arsh=(*sh)->Area();
                }

            }
            }


        }



    

};


