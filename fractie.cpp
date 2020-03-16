#include "Complex.h"
#include <cmath>
#include <bits/stdc++.h>
Fractie::Fractie(int numarator,int numitor){
    this->numitor=numitor;
    this->numarator=numarator;
    }

Fractie::Fractie(){
    this->numarator=1;
    this->numitor=1;
    }

Fractie::Fractie(Fractie& f){
    this->numitor=f.numitor;
    this->numarator=f.numarator;
    }

Fractie::operator+(Fractie &f){
    int a,b,cmmmc;
        a=abs(this->numitor);
        b=abs(f.numitor);
        while(a!=b)
            if(a>b)
                a=a-b;
            else b=b-a;
        cmmmc=(this->numitor*f.numitor)/a;
        Fractie c((this->numarator*(cmmmc/this->numitor))+(f.numarator*(cmmmc/f.numitor)), cmmmc );
        return c ;

    }

Fractie::operator-(Fractie &f){
    int a,b,cmmmc;
        a=abs(this->numitor);
        b=abs(f.numitor);
        while(a!=b)
            if(a>b)
                a=a-b;
            else b=b-a;
        cmmmc=(this->numitor*f.numitor)/a;
        Fractie c((this->numarator*(cmmmc/this->numitor))-(f.numarator*(cmmmc/f.numitor)), cmmmc );
        return c ;
    }

Fractie::operator/(Fractie &f){
        Fractie c(this->numarator*f.numitor,this->numitor*f.numarator);
        return c;
        }

Fractie::operator*(Fractie &f){
        Fractie c(this->numarator*f.numarator,this->numitor*f.numitor);
        return c;
        }

Fractie::operator*(int &f){
        Fractie c(this->numarator*f,this->numitor);
        return c;
        }

int Fractie::getNumarator(){
    return this->numarator;
    }


int Fractie::getNumitor(){
    return this->numitor;
    }

void Fractie::setNumarator(int numarator){
    this->numarator=numarator;
    }

 void Fractie::setNumitor(int numitor){
    this->numitor=numitor;
    }

void Fractie::afisare(){
    if (numitor==0)
            cout<<"Nu se poate";
        else if (numarator==0)
            cout<<0;
        else if (numitor*numarator<0){
            if(abs(numitor*numarator)==abs(numarator))
                cout<< -abs(numarator);
            else
                cout<<-abs(numarator)<<"/"<<abs(numitor);
        }
        else if(numitor*numarator>0){
            if (abs(numitor*numarator)==abs(numarator))
                cout<<abs(numarator);
            else
                cout<<abs(numarator)<<"/"<<abs(numitor);
    }

void Fractie::simplificareFormaIreductibila(){
    int a,b;
    a=abs(numitor);
    b=abs(numarator);

    while(a!=b)
        if(a>b)
            a=a-b;
        else b=b-a;

    if(a==1)
        cout<<"Fractia este deja ireductibila"<<endl;
    else {
        numitor=numitor/a;
        numarator=numarator/a;
        }
    }

void Fractie::simplificare(int a){
        if(numitor%a==0 && numarator%a==0){
            numitor=numitor/a;
            numarator=numarator/a;
        }
        else
            cout<<"Fractia nu se poate simplifica prin "<<a<<endl;

    }