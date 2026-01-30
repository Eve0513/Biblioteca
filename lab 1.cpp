#include <iostream>
#include<string>
using namespace std;

class Carte{
    private:
    string titlu;
    string autor;
    int anPublic;
    int nrPag;
    string gen;
    string editura;
    
    public:
    Carte(){
        cout<<"Constructor implicit, creata cu valori implicite...";
        titlu="Uknown";
        autor="Uknown";
        anPublic=0;
        nrPag=0;
        gen="Uknown";
        editura="Uknown";
    }
    
    Carte(string t, string a, int an, int pag, string g, string e){
        cout<<"Constructor parametrizat, carte creata... "<<endl;
        titlu=t;
        autor=a;
        anPublic=an;
        nrPag=pag;
        gen=g;
        editura=e;
    }
    
    Carte(const Carte& alta){
        cout<<"constructor de copiat"<<endl;
        titlu=alta.titlu;
        autor=alta.autor;
        anPublic=alta.anPublic;
        nrPag=alta.nrPag;
        gen=alta.gen;
        editura=alta.editura;
    }
    ~Carte(){
        cout<<"Destructor aparut. Din pacate carte distrusa((: "<<titlu<<endl;
    }
    
    string getTitlu(){ 
        return titlu; 
    }
    void setTitlu(string t){ 
        titlu=t; 
    }

    string getAutor(){
        return autor; 
    }
    void setAutor(string a){ 
        autor=a; 
    }

    int getanPublic(){
        return anPublic; 
    }
    void setanPublic(int an){ 
        anPublic=an; 
    }

    int getnrPag(){
        return nrPag; 
    }
    void setnrPag(int p){ 
        nrPag=p; 
        }

    string getGen(){
        return gen; 
    }
    void setGen(string g){ 
        gen=g; 
    }
    
    
    void afiseazaInfo() const{
        cout<<"\n---- "<<titlu<<" ----\n";
        cout<<"Titlu: "<<titlu<<endl;
        cout<<"Autor: "<<autor<<endl;
        cout<<"An publicare: "<<anPublic<<endl;
        cout<<"Numar pagini: "<<nrPag<<endl;
        cout<<"Gen: "<<gen<<endl;
        cout<<"Editura: "<<editura<<endl;
        cout<<"-----------------------------\n";
    }

    bool esteVeche(int anCurent){
        if(anPublic <= 0)return false;
       return (anCurent - anPublic) > 20;
    }

    bool esteVolu(){
       return nrPag > 350;
    }
    
     int estimeazaMinuteCitire(){
        if(nrPag <= 0)return 0;
       return (nrPag/2);  
    }
    
    string estimeazaGrosime(){
        if(nrPag < 150) return "subțire";
        if(nrPag < 300) return "medie";
        if(nrPag < 500) return "voluminoasă";
       return "foarte groasă";
    }
};
 int main(){
    Carte c1;
    c1.afiseazaInfo(); 
    cout<<endl;

    Carte c2("Crima Perfecta", "Holly Jackson", 2020, 448, "Thriller", "Corint");
    c2.afiseazaInfo();  
    cout<<endl;

    Carte c3("1984", "George Orwell", 1949, 328, "Distopie", "Secker & Warburg");
    c3.afiseazaInfo(); 
    cout<<endl;

    Carte c4=c3;
    c4.setTitlu("Animal Farm");
    c4.setanPublic(1945);    
    c4.afiseazaInfo();   
    cout<<endl;

  
    int anCurent=2026; 
    cout<<"Cartea '"<<c3.getTitlu()<<"' este veche? "<<(c3.esteVeche(anCurent) ? "Da" : "Nu")<<endl;
    cout<< "Este cartea "<<c3.getTitlu()<<"' Voluminoasa? "<< (c3.esteVolum() ? "Da" : "Nu")<<endl;
    cout<<"Grosime estimata: "<<c3.estimeazaGrosime()<<endl;
    cout<<"Timp estimat de citire : ~ "<< c3.estimeazaMinuteCitire()<<" minute"<<endl;
    cout<<endl;

   return 0;
}


