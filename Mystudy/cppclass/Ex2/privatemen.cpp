#include<iostream>
using namespace std;

class Box{
    double length, wideth,height;
    public:
        void setValue(double len, double wid, double high);
        double getVolume();
};

void Box::setValue(double len, double wid, double high){
    length=len;
    wideth=wid;
    height=high;
}

double Box::getVolume(){
    return length*wideth*height;
}

int main(){
    Box box;
    double len, wid, high,volume;
    cin>>len;
    cin>>wid;
    cin>>high;
    box.setValue(len,wid,high);

    cout<<box.length<<endl; //无法访问
    
    cout<< box.getVolume()<<endl;
    return 0;
}