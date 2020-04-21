#include <iostream>
using namespace std;

class Complex {
private:
    float re, im;

public:
    Complex()
    {
        re = 0;
        im = 0;
    }
    Complex(float x, float y)
    {
        re = x;
        im = y;
    }
    Complex(const Complex& c2)
    {
        re = c2.re;
        im = c2.im;
    }
    ~Complex(){
        re = NULL;
        im = NULL;
    }
    Complex operator = (Complex const& obj)
    {
        re = obj.re;
        im = obj.im;
        return Complex(re,im);
    }
    float getRe()
    {
        return re;
    }
    float getIm()
    {
        return im;
    }
    void setRe(float x)
    {
        re = x;
    }
    void setIm(float x)
    {
        im = x;
    }
};

ostream& operator<<(ostream& os, Complex& c)
{
    os << c.getRe() << "+" << c.getIm() << "i";
    return os;
}

Complex operator>>(istream& is, Complex& c)
{
    float x;
    cout << "partea reala:";
    is >> x;
    c.setRe(x);
    cout << "partea imaginara:";
    is >> x;
    c.setIm(x);
    return c;
}

class Vector {
protected:
    int dim;
    Complex* v;
public:
    Vector() {
        dim = 0;
    }
    Vector(int k) {
        dim = k;
        v = new Complex[dim];
    }
    Vector(const Vector& v2)
    {
        dim = v2.dim;
        v = v2.v;
    }
    ~Vector(){
        dim = NULL;
        delete v;
    }
    Vector operator = (Vector const& v2)
    {
        dim = v2.dim;
        v = v2.v;
    }
    void setDim(int x) {
        dim = x;
        v = new Complex[dim];
    }
};

class Stiva: Vector {
private:
    int varf;
public:
    
    Stiva():Vector() {
        varf = 0;
    }
    Stiva(int k):Vector(k){
        varf = 0;
    }
    bool plin()
    {
        if (varf == dim)
            return true;
        return false;
    }
    bool vid()
    {
        if (varf==0)
            return true;
        return false;
    }
    void push(Complex x)
    {
        if (plin())
            cout << "stiva este plina";
        else
        {
            v[varf] = x;
            varf++;
        }
    }
    Complex pop()
    {
        if (vid())
        {
            cout << "stiva este vida";
            exit;
        }
        else
        {
            varf--;
            Complex x = v[varf];
            v[varf].~Complex();
            return x;
        }
    }
    void citireD()
    { 
        int i = 1;
        while (!plin())
        {
            if (i == 1)
                cout << "citeste primul numar \n";
            else
                cout << "citeste al " << i << "lea numar \n";
            Complex a;
            cin >> a;
            push(a);
            i++;
            cout << "\n";
        }
    }
    void afisare()
    {
        while (!vid())
        {
            Complex a=pop();
            cout << a<<"\n";
        }
    }
};
int main()
{
    int d;
    cin >> d;
    Stiva c(d);
    c.citireD();
    c.afisare();
    

    return 0;
}

