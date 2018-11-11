//
// Created by fatima_msd on 11/11/18.
//

#ifndef HW3_CLASS_H
#define HW3_CLASS_H

#endif //HW3_CLASS_H


#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;




class Exception{
public:
    Exception(const string& msg) : msg_(msg){}
    string getMessage() const {return(msg_);}
private:
    string msg_;
}; //TODO: Give exceptions a better structure. search google (optional)





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
        cout << "Shape:Circle --> Radius : "<<r<<" , Area :"<< Area()<<endl;
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
        cout << "Shape:Rectangle --> length : "<<a<<" , width : "<<b<<" , Area :"<< Area()<<endl;
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
        cout << "Shape:Square --> length : "<<a<<" , Area :"<< Area()<<endl;
    }
    float Area(){
        return a*a;
    }
    bool operator==(Square *sq){
        return a==sq->a;
    }
};

class list_shape{
    vector<shape *> SHAPE;

public:

    void add(shape* s){
        SHAPE.push_back(s);
    }
    shape * find(float AREA){//find area
        for(auto sh = SHAPE.begin(); sh != SHAPE.end(); sh++){
            if((*sh)->Area()==AREA){
                return *sh;

            }
        }
        Exception ex("not found Area");
        throw ex;
    }
    int getCount() const {return SHAPE.size();}
    shape * GetItem(int index){
        if (index < 0 || (size_t) index >= SHAPE.size()){
            Exception ex("index is incorrect");
            throw ex;
        }
        return SHAPE[index];
    }
    void del(shape* s){
        for(auto sh = SHAPE.begin(); sh != SHAPE.end(); sh++){
            if(*(sh)==s){
                SHAPE.erase(sh);
                return;
            }
        }
        Exception ex("not found shape");
        throw ex;
    }
    void remove(int index){
        if (index < 0 || (size_t) index >= SHAPE.size()){
            Exception ex("index is incorrect");
            throw ex;
        }
        auto sh = SHAPE.begin()+index;
        SHAPE.erase(sh);
    }

    void insert(shape* s, int index) {
        if (index < 0){
            Exception ex("index is incorrect");
            throw ex;
        }

        if ((size_t)index >= SHAPE.size())
            index = SHAPE.size();

        SHAPE.insert(SHAPE.begin() + index, s);
    }
    void print_list(){
        for(int i=0;i<getCount();i++) {
        shape *l = GetItem(i);
        l->draw();
    }
    }
    void sort(){
        for(auto sh = SHAPE.begin(); sh != SHAPE.end(); sh++){
            float Arsh=(*sh)->Area();
            for(auto sh2 = sh+1; sh2 != SHAPE.end(); sh2++){
                if((*sh2)->Area()<Arsh){
                    shape* s12=*sh2;
                    *sh2=*sh;
                    *sh=s12;
                    Arsh=(*sh)->Area();
                }

            }
        }


    }





};



