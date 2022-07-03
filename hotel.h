#include <iostream>
#include <string>


// classe date
using namespace std;
class date{
	public:
	int j,m,a; //jour/mois/annee
	
	date(){} //constructeur par defaut
	
	//methodes 
	
	affichdate(){ //afficher la date format jj/mm/aaaa
		cout<<j<<"/"<<m<<"/"<<a<<endl; 
	}
	//surcharge d'operateur egale
	bool operator ==(date datetest){
		if(j==datetest.j && m==datetest.m && a==datetest.a) //if 
		return true;
		
		return false;
	}
};

// class client
class client{
	private:
	int idc;
	string nom;
	string prenom;
	string adress;
	
	public:
	//constructeur par defaut	
	client(){}
	//constructeur initialisation
	client(int idc,string nom,string prenom,string adress){
	this->idc=idc;
	this->nom=nom;
	this->prenom=prenom;
	this->adress=adress;
	}
	//methodes
	void affichecli();
	void saisiecli();
	//getters
	int getidc();
	string getnom();
	string getprenom();
	string getadress();
	//setters
	void setidc(int);
	void setnom(string);
	void setprenom(string);
	void setadress(string);
	
};

class chambre{
	private:
	int idch;
	string numtel;	
	public:
	//constructeur par defaut
	chambre(){} 
	//methodes
	void affichech();
	void saisiech();
    //getters
	int getidch();
	string getnum();
	//setters
	void setidch(int);
	void setnum(string);
	//comparaison
	bool comparech(int);
};

class reservation{
	private:
	int idr;
	int nbchr;
	chambre t[7];
	client cli;
	date dateres;
	date datefinres;
	bool etatres;
	public:
	//constructeur par defaut
	reservation(){
	nbchr=0;
	}
	//constructeur de copie
	reservation(reservation &a){
	idr=a.idr;
	nbchr=a.nbchr;
	cli=a.cli;
	for(int i=0;i<nbchr;i++)
		this->t[i]=a.t[i];
	
	dateres=a.dateres;
	datefinres=a.datefinres;
	etatres=a.etatres;
	}
	//construteur d'initialisation
	reservation(int idr,int nbchr,chambre t[7],client cli,date dateres,date datefinres,bool etatres){
	this->idr=idr;
	this->nbchr=nbchr;
	for(int i=0;i<nbchr;i++){
		this->t[i]=t[i];
	}
	this->cli=cli;
	this->dateres=dateres;
	this->datefinres=datefinres;
	this->etatres=etatres;
	}
	//methode
	bool verifierres(int id);
	void ajoutchambre(int);
	void afficheres();
	void durreres();
	void suppchambre(chambre ch);
	void modifetat();
	void setetat(bool);
	void setchambre(chambre t[7]);
	client getclient();
	int getidr();
	int getnbchr();
	chambre getcha();
	date getdr();
	date getdfr();
	friend void modifreserva(int id);
};
void modifreserva(int id);
bool verifclires(int c);
bool verifres(int res);
void ajoutres(reservation res);
void suppres(int id);
void afficheress();
void resaujour(date);
void resexpaujour(date);
void anulresexpaujour(date);
int menu();
bool verifch(chambre t[7],int id,int nbch);
 
