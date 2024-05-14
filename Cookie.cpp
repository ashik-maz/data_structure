#include <iostream>
using namespace std;
class Cookie
{
private:
    string color;
public:
    Cookie(string color){
        this->color=color;
    }
    string getcolor(){
        return color;
    }
    void setcolor(string color){
        this->color=color;
    }
};

int main(){
    Cookie* cookieOne=new Cookie("green");
    Cookie* cookieTwo=new Cookie("Blue");

    cookieOne->setcolor("pink");
    cout<<cookieOne->getcolor()<<endl;
    cout<<cookieTwo->getcolor()<<endl;

}