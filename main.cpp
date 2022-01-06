/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
using namespace std;

class Complex
{
  private:
  int m_real{};
  int m_img{};
  
  public:
  Complex(int real=0,int img=0):m_real{real},m_img{img}
  {
    cout<<"Inside parametrized constructor"<<endl;
  }
  
 // member functions of a class can access the private members of parameters of the same class type. 
  Complex(Complex const & copyobj):m_real{copyobj.m_real},m_img{copyobj.m_img}
  {
    cout<<"Inside copy constructor"<<endl;
  }
  
  
  void print()
  {
    cout<<m_real<<"+i"<<m_img<<endl;
  }
  
  friend Complex operator + (Complex const &, Complex const &);
  
  friend std::ostream& operator <<(std::ostream& out,const Complex& c);
};

  Complex operator+(Complex const &c1, Complex const &c2)
  {
    cout<<"Inside operator overloading +"<<endl;
    Complex res;
    res.m_real=c1.m_real+c2.m_real;
    res.m_img= c1.m_img+c2.m_img;
    return res;
  }

 std::ostream& operator <<(std::ostream& out,const Complex& c)
 {
     return out<<c.m_real<<"+i"<<c.m_img;
 }
 
int main()
{
  Complex c1;
  cout<<"c1 "<<c1<<endl;
  Complex c2(1,2);
  cout<<"c2 "<<c2<<endl;
  Complex c3=c2+c1;
  cout<<"c3 "<<c3<<endl;
  Complex c4{c3};
  cout<<"c4 "<<c4<<endl;
  //here although a temporary object is created and used as parameter, it does not call
  //copy constructor because compiler optimizes and directly calls the parametrized constructor---this is called elision
  //https://www.learncpp.com/cpp-tutorial/the-copy-constructor/
  Complex c5{Complex(2,3)};
  cout<<"c5 "<<c5<<endl;
}
