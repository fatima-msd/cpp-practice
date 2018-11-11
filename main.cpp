#include "CLASS.h"








int main()
{
    list_shape sh;
    Circle cir(5);
    Rectangle rec(3,2);
    Circle cir2(1);
    sh.add(&rec);
    sh.add(&cir);
    sh.add(&cir2);
    shape * l=sh.GetItem(0);
    l->draw();
    sh.sort();
    l=sh.GetItem(0);
    l->draw();
    l=sh.GetItem(1);
    l->draw();
    l=sh.GetItem(2);
    l->draw();
  //  (*(sh.SHAPE.begin()))->draw();


    return 0;
}

