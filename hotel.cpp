#include <iostream>
#include "hotel.h"
#include <string>
#include <time.h>

/*******************************************client******************************************************/

void client ::affichecli(){
	cout<<"infos client:"<<endl;
	cout<<"id:"<<idc<<endl;
	cout<<"nom:"<<nom<<endl;
	cout<<"prenom:"<<prenom<<endl;
	cout<<"adress:"<<adress<<endl;
	cout<<"**********************************"<<endl;
}

void client::saisiecli(){
	cout<<"infos client:"<<endl;
	cout<<"entrer id : ";
	cin>>idc;
	cout<<"entrer nom : ";
	cin>>nom;
	cout<<"entrer prenom : ";
	cin>>prenom;
	cout<<"entrer adress: ";
	cin>>adress;
}
//getters
int client::getidc(){
	return idc;
}
string client:: getnom(){
	return nom;
}
string client:: getprenom(){
	return prenom;
}
string client:: getadress(){
	return adress;
}

//setters
	void client::setidc(int id){
		idc=id;
	}
	void client::setnom(string nomm){
	    nom=nomm;
	}
	void client::setprenom(string prenomm){
		prenom=prenomm;
	}
	void client::setadress(string adresss){
		adress=adresss;
	}
/*******************************************chambre******************************************************/

//methodes

void chambre::affichech(){
	cout<<"infos chambre:"<<endl;
	cout<<"id:"<<idch<<endl;
	cout<<"num tel:"<<numtel<<endl;
	cout<<"*************************************"<<endl;
}
void chambre::saisiech(){
    cout<<"entrer id : ";
	cin>>idch;
	cout<<"entrer num de tel: ";
	cin>>numtel;
	}
    //getters
	int chambre::getidch(){
		return idch;
	}
	string chambre::getnum(){
		return numtel;
	}
	//setters
	void chambre::setidch(int id){
		idch=id;
	}
	void chambre::setnum(string numte){
		numtel=numte;
	}
	//comparaison
	bool chambre::comparech(int id){
		if (idch==id)
		return true;
		return false;
	}

/*******************************************reservation******************************************************/
bool reservation::verifierres(int id){ // test chambre
	for(int i=0;i<nbchr;i++){
		if(t[i].comparech(id))
		return true;
	}
	return false;
}

void reservation::ajoutchambre(int id){
	
	if(nbchr==7){
		cout<<"toutes les chambres sont occupee"<<endl;
		return;
	}
	if(verifierres(id)==true){
		cout<<"cette chambre existe deja"<<endl;
		return;
	}
	else{
		string num;
		cout<<"entrez le num de tel: "<<endl;
		cin>>num;	
		t[nbchr].setidch(id);
		t[nbchr].setnum(num);
		nbchr++;
	}  
}
void reservation::afficheres(){
	cout<<"id reservation: "<<idr<<endl;
    cout<<"nombre de chambre: "<<nbchr<<endl;
	for(int i=0;i<nbchr;i++){
		cout<<"chambre n="<<i+1<<endl;
		t[i].affichech();
	}
	cout<<"client:"<<endl;
	cli.affichecli();
	cout<<"date de reservation: ";
	 dateres.affichdate();
	cout<<"date de fin reservation: ";
	 datefinres.affichdate();
	if(etatres){
		cout<<"reservation active"<<endl;
	}
	else{
		cout<<"reservation non active"<<endl;
	}
}

void reservation::durreres(){
	
}
void reservation::suppchambre(chambre ch){
	if(verifierres(ch.getidch())==false){
		cout<<"la chambre n'est pas reserve"<<endl;
		return;
	}
	else{
		int i,j;
		for(i=0;i<nbchr;i++){
			if(t[i].getidch()==ch.getidch()){
				break;
			}
		}
		for(j=i;j<nbchr;j++){
			t[j]=t[j+1];
		}
		cout<<"chambre supprimee avec succes"<<endl;
	}
	nbchr--;
}
   void reservation::setetat(bool a){
	etatres=a;
}

int reservation:: getnbchr(){
	return nbchr;
}
	void reservation::modifetat(){
		if(etatres){
			setetat(false);
		}else{
			setetat(true);
		}
	}
	
	client reservation::getclient(){
		return cli;
	}
	
	int reservation::getidr(){
		return idr;
	}
	
	
	chambre reservation::getcha(){
		return *t;
	}
	
	date reservation::getdr(){
		return dateres;
	}
	date reservation::getdfr(){
		return datefinres;
	}
	void reservation:: setchambre(chambre t[7]){
		
		for(int i=0;i<nbchr;i++)
		this->t[i]=t[i];
		
	}
/*******************************************fonctions(fx)******************************************************/
reservation tab[100];
int nb_res=0;

bool verifclires(int c){  //verifier un client dans un tab de reservation
	for(int i=0;i<nb_res;i++){
		if(tab[i].getclient().getidc()==c)
		return true;
	}
	return false;
}

bool verifres(int id){ //verifier si une reservation est effectue ou non 
	for(int i=0;i<nb_res;i++){
		if(tab[i].getidr()==id)
		return true;
	}
	return false;
}


void ajoutres(reservation res){ //ajouter une reservation
	for(int i=0;i<nb_res;i++){
		if(tab[i].getidr()==res.getidr()){	
		cout<<"la reservation existe deja"<<endl;
		return;
		}
	}
	tab[nb_res]=reservation(res);//constructeur de copie 
	cout<<"reservation ajoutee avec succes"<<endl;
	nb_res++;
}

void modifreserva(int id){//Modifier chambre
int i,j,x=0,y=0;
	for(i=0;i<nb_res;i++){
		if(tab[i].getidr()==id) //chercher id reservation
		x=1;break;
	}
	if(x==1){
	int idch;
	cout<<"entrez l id de la chambre que vous voullez modifier dans cette reservation"<<endl;
	cin>>idch;
		
	for(j=0;j<tab[i].nbchr;j++){
		if(tab[i].t[j].getidch() == idch) {
		y=1;break;
		}
	}
	if(y==1){string numtel;
		cout<<"entrez le nouveau num de tel: "; 
		cin>>numtel; 
		tab[i].t[j].setnum(numtel);
		cout<<"reservation modifie avec succes"<<endl;
	}else{
		cout<<"chambre introuvable";
	}
	}
	else{
		cout<<"reservation introuvable !!"<<endl;
	}	}


void suppres(int id){int i,x=0;
	for(i=0;i<nb_res;i++){
	if(tab[i].getidr()==id)
	x=1;break;
	}
	if(x==1){
		for(int j=i;j<nb_res;j++){
			tab[j]=tab[j+1];
		}
		cout<<"reservation supprimee avec succes"<<endl;
		nb_res--;
	}
	else cout<<"reservation introuvable !!"<<endl;	
}
void afficheress(){
	for(int i=0;i<nb_res;i++){
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |              reservation n="<<i+1<<"                   |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
		tab[i].afficheres();
		cout<<"*****************************************"<<endl;
	}
}
  



void resaujour(date dateactuel){
for(int i=0;i<nb_res;i++){
	if(tab[i].getdr()==dateactuel){
		tab[i].afficheres();
	}
}
}



void resexpaujour(date dateactuel){
for(int i=0;i<nb_res;i++){
	if(tab[i].getdfr()==dateactuel){
		tab[i].afficheres();
	
	}
}
}

void anulresexpaujour(date dateactuel){
for(int i=0;i<nb_res;i++){
	if(tab[i].getdfr()==dateactuel){
		tab[i].modifetat();
	}
}
}

int menu(){
	int m;
	system("cls");
	system("color 30");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |      MARWA ALIBOUCH---------LAAOUANE TARIK       |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |                   GESTION HOTEL                  |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |1-tester si un client a effectue une reservation  |"<<endl;
	cout<<"\t \t |2-tester si une reservation a ete deja effectue   |"<<endl;
	cout<<"\t \t |3-ajouter une reservation                         |"<<endl;
	cout<<"\t \t |4-modifier une chambre d'une reservation          |"<<endl;
	cout<<"\t \t |5-suprimmer une reservation                       |"<<endl;
	cout<<"\t \t |6-afficher toutes les reservations                |"<<endl;
	cout<<"\t \t |7-afficher les reservations d'aujourd'hui         |"<<endl;
	cout<<"\t \t |8-afficher les reservations qui expire aujourd'hui|"<<endl;
	cout<<"\t \t |9-annuler les reservations qui expire aujourd'hui |"<<endl;
	cout<<"\t \t |0-quitter                                         |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |       taper le numero qui vous convient :        |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cin >>m;
	return m;
}



