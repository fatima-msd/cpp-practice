#include "CLASS.h"


int main()
{
    list_shape sh;
    Circle cir(5);
    Rectangle rec(3,2);
    Circle cir2(1);
    sh.insert(&rec,0);
    sh.insert(&cir2,1);
    int len=sh.getCount();
    cout<<len<<endl;
    try {
        sh.insert(&cir2, -9);
    }
    catch(Exception e) {
        cout<<e.getMessage()<<"!!"<<endl;
    }
    sh.add(&cir);
    sh.print_list();
    try {
        sh.remove(0);
    }
    catch(Exception e) {
        cout<<e.getMessage()<<"!!"<<endl;
    }
    sh.sort();
    sh.print_list();
   // l=sh.find(6);
    //l->draw();
   // l=sh.find(20);
    //l->draw();


    return 0;
}

