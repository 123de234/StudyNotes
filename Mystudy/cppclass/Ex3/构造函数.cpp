# include <iostream>
using namespace std;

class  Box
{
private:
    /* data */
    double length;
    double width;
public:
     Box(double l, double w);
    ~ Box();
    double volume();
    int compare (Box box);
};

 Box::Box (double l, double w)
{
        length=l;
        width=w;
}


 Box::~ Box()
{
   
}

double Box::volume(){
    return length*width;
}

int Box::compare(Box box){
    return this-> volume() > box.volume(); //this 指针
}

int main(){
    Box box1(3,10);
    Box box2(20,5);

    if (box1.compare(box2))
    {
        cout<<"Box1 bigger"<< box1.volume()<<endl;
    }
    else 
    {
        cout<<"Box2 bigger"<< box2.volume()<<endl;
    }

    return 0;
}
    
    
