
#include <iostream>
using namespace std;

class Fractie
{
private:int numarator, numitor;
public:
    Fractie()
    {
        numarator = 1;
        numitor = 1;
    }
    Fractie(const Fractie& f2)
    {
        numarator = f2.numarator;
        numitor = f2.numitor;
    }
    ~Fractie()
    {
    numarator = NULL;
    numitor = NULL;
    }
    int getNumarator()
    {
        return numarator;
    }
    int getNumitor()
    {
        return numitor;
    }
    void setNumarator(int a)
    {
        numarator = a;
    }
    void setNumitor(int a)
    {
        numitor = a;
    }
    void simplificare()
    {
    int a = numarator;
    int b = numitor;
    while (b)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    numarator = numarator / a;
    numitor = numitor / a;
    if (numitor < 0 && numarator > 0)
    {
        numitor *= -1;
        numarator *= -1;
    }
    }
    void afis()
    {
    
    if (numitor == 1)
        std::cout<<numarator<<'\n';
    else
        if (numitor < 0 && numarator > 0)
        {
            numitor *= -1;
            numarator *= -1;
            std::cout << numarator << "/" << numitor << '\n';
        }
        else
            std::cout << numarator << "/" << numitor << '\n';
    }
    Fractie operator + (Fractie const& obj)
    {
        Fractie rez;
        rez.numarator = numarator * obj.numitor + obj.numarator * numitor;
        rez.numitor = numitor * obj.numitor;
        rez.simplificare();
        return rez;
    }

    Fractie operator - (Fractie const& obj)
    {
        Fractie rez;
        rez.numarator = numarator * obj.numitor - obj.numarator * numitor;
        rez.numitor = numitor * obj.numitor;
        rez.simplificare();
        return rez;
    }

    Fractie operator * (Fractie const& obj)
    {
        Fractie rez;
        rez.numarator = numarator * obj.numarator;
        rez.numitor = numitor * obj.numitor;
        rez.simplificare();
        return rez;
    }

    Fractie operator / (Fractie const& obj)
    {
        Fractie rez;
        rez.numarator = numarator * obj.numitor;
        rez.numitor = numitor * obj.numarator;
        rez.simplificare();
        return rez;
    }

    Fractie operator * (int x)
    {
        Fractie rez;
        rez.numarator = numarator * x;
        rez.numitor = numitor;
        rez.simplificare();
        return rez;
    }

    void  citesteN(int n)
    {
        int i;
        Fractie *v;
        v = new Fractie[n];
        for (i = 0; i < n; i++)
        {
            int a, b;
            std::cin >> a >> b;
            v[i].numarator = a;
            v[i].numitor = b;
        }
        for (i = 0; i < n; i++)
        {
            v[i].afis();
        }
    }
};

ostream& operator<<(ostream& os, Fractie& f )
{
    if (f.getNumitor() == 1)
        os << f.getNumarator();
    else if (f.getNumarator() == 0)
        os << 0;
    else
        os << f.getNumarator() << '/' << f.getNumitor();
    return os;
}

Fractie operator>>(istream& is, Fractie& f)
{
    string fr;
    int n = 1, k = 0;
    is >> fr;
    f.setNumarator(0);
    f.setNumitor(1);
    int numarator = f.getNumarator();
    int numitor = f.getNumitor();
    for (int i = 0; i < fr.length(); i++)
    {
       
        
        if (fr[i] == '/')
        {
            if (k == 1)
                numarator *= -1;
            n = 2;
            k = 0;
            numitor = 0;
            continue;
        }
        if (fr[i] == '-')
        {
            k = 1;
            continue;
        }
        if (n == 1)
        {
            numarator *= 10;
            numarator += int(fr[i]) -48;
            
        }
        else
        {
            numitor *= 10;
            numitor += int(fr[i]) -48;
            
        }
        

    }
    if (k == 1)
        numitor *= -1;
    f.setNumarator(numarator);
    f.setNumitor(numitor);
    f.simplificare();
    return f;


}

void rezsistem(Fractie x1, Fractie x2, Fractie y1, Fractie y2, Fractie rez1, Fractie rez2)
{
    Fractie y12;
    y12 = y1*x2 - y2 * x1;
    Fractie rezy = (rez1 * x2 - rez2 * x1) / y12;
    Fractie rezx = (rez2 - (y2 * rezy)) / x2;
    
    cout << "x="<<rezx<<'\n'<< "y=" << rezy;
    
}

int main()
{
    
    Fractie x1,y1,r1,x2,y2,r2;
    cout << "Introduceti coeficientul lui x din prima ecuatie(a/b) \n";
    cin >> x1;
    cout << x1;
    cout << "Introduceti coeficientul lui y din prima ecuatie(a/b) \n";
    cin >> y1;
    cout << y1;
    cout << "Introduceti rezultatul primei ecuatii(a/b) \n";
    cin >> r1;
    cout << r1;
    cout << "Introduceti coeficientul lui x din a doua ecuatie(a/b) \n";
    cin >> x2;
    cout << x2;
    cout << "Introduceti coeficientul lui y din a doua ecuatie(a/b) \n";
    cin >> y2;
    cout << y2;
    cout << "Introduceti rezultatul celei de a doua ectuatii(a/b) \n";
    cin >> r2;
    cout << r2;
    std::cout << "Solutia sistemului este: \n";
    rezsistem(x1, x2, y1, y2, r1, r2);
    int x;
    cout << " \nPress any key to exit...";
    cin >> x;
    
    return 0;
}