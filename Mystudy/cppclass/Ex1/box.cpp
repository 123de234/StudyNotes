#include<iostream>
using namespace std;

class Box{
    public:
        double length;
        double wideth;
        double hight;

        double get(void);
        void set(double len, double wid, double high);
};

double Box::get(){
    return length*wideth*hight;
}

void Box::set(double len, double wid, double high){
    length=len;
    wideth=wid;
    hight=high;
}

int main(){
    Box Box1, Box2;
    double volume=0.0;
    double length, wideth,hight;

    //计算Box1体积
    cout<<"输入长"<<endl;
    cin>>length;
    cout<<"输入宽"<<endl;
    cin>>wideth;
    cout<<"输入高"<<endl;
    cin>>hight;

    Box1.set(length, wideth, hight);
    cout <<"volume of Box1 is:"<<Box1.get()<<endl;

    //计算Box2体积
    cout<<"输入长"<<endl;
    cin>>length;
    cout<<"输入宽"<<endl;
    cin>>wideth;
    cout<<"输入高"<<endl;
    cin>>hight;

    Box2.length=length;
    Box2.wideth=wideth;
    Box2.hight=hight;
    cout <<"volume of Box2 is:"<<Box2.get()<<endl;

}