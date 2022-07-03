#include <iostream>
#include"hotel.h"
#include <string>
#include <ctime>

using namespace std;


main(){int m;
int id;bool x;
int idr;
int nbchr;
chambre t[7];
date dateres;
date datefinres;
int etat;
bool etatres;
reservation res;
string num;
string nom;
string prenom;
string adress;

date dateactuel;
time_t actuel = time(0);
tm *ltm = localtime(&actuel);
dateactuel.a=1900 + ltm->tm_year;
dateactuel.m=1 + ltm->tm_mon;
dateactuel.j= ltm->tm_mday ;
//date actuel
	do{

	do{
	m=menu();
	}	while(m>9 || m<0);
	
	switch(m){
		case 1:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t | GESTION HOTEL   :    test d'un client            |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
			cout<<"entrez l'id du client:";
			cin>>id;
			x=verifclires(id);
			if(x)
			cout<<"le client a deja effectue une reservation"<<endl;
			else
			cout<<"le client n'a pas effectue une reservation"<<endl;
			system("pause");
			break;
		}
		case 2:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t | GESTION HOTEL   :    test d'une reservation      |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
			cout<<"entrez l'id du reservation:";
			cin>>id;
			x=verifres(id);
			if(x)
			cout<<"la reservation a ete deja effectue"<<endl;
			else
			cout<<"la reservation n'est pas effectue "<<endl;
			system("pause");
			break;
		}
		case 3:{system("cls");


			 do{
				 system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t | GESTION HOTEL  :        ajout d'une reservation  |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;	
			cout<<"entrez le id du reservation :";
			cin>>idr;
			 }while(verifres(idr)); //parcourir le tableau et definir l'existance a vec la fonction verifres
			 // le programme n'accepte que les id qui nexiste pas
			  // a chaque fois l'utilisateur il entre un id le programme test si il existe 
			  //il demande unr autre fois d'entrer  
			
			do{
			cout<<"entrez le nombre de chambre du reservation :";
			cin>>nbchr;	
			}while(nbchr<1 || nbchr>7);
			  // a chaque fois l'utilisateur il entre un nbchr  le programme test si il est valide il termine
			  //sinon il demande unr autre fois d'entrer  
			
			cout<<"infos chambre:"<<endl;
				int test1=0,i;
			for(i=0;i<nbchr;i++){
			cout<<"chambre n"<<i+1<<endl;
            	do{		
			t[i].saisiech();
            test1=0;
            for(int j=0;j<i;j++){     //parcourir le tableau et definir l'existance a vec la variable test1
            	if(t[j].getidch()==t[i].getidch())  //en test si la chambre saisie existe ou pas dans le tableau
            	test1++;
					}}while (test1); 
					}
			
			
			client cli;
			cli.saisiecli();
			
			
			cout<<"entrez la date de reservation:";
			cout<<"jour:";cin>>dateres.j; 
			cout<<"mois:";cin>>dateres.m; 
			cout<<"annee:";cin>>dateres.a; 
			
			
			cout<<"entrez la date de fin de reservation:";
			cout<<"jour:";cin>>datefinres.j; 
			cout<<"mois:";cin>>datefinres.m; 
			cout<<"annee:";cin>>datefinres.a; 
			
			
			cout<<"etat de reservation (ecriver 1 si active sinon 0) :";
         	cin>>etat;
         	if(etat)
         	etatres=true;
         	else
         	etatres=false; 
			//creer une reservation et l'initialiser avec les parametres decalré
         	reservation s(idr,nbchr,t,cli,dateres,datefinres,etatres); 
			 // ajouter la dans le tableau en utilisant la fonction d'ajout
			 ajoutres(s);  
			 system("pause");
			break;
		}
		case 4:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t | GESTION HOTEL  : modification d'une reservation  |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
		cout<<"enter l'id du reservation que vous chercher: ";
		int id;
		cin>>id;
		modifreserva(id);
		system("pause");
			break;
		}		
		case 5:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t | GESTION HOTEL   : suppression d'une reservation  |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
		cout<<"enter l'id du reservation que vous voullez supprimmer: ";
		int id;
		cin>>id;
		suppres(id);
		system("pause");
			break;
		}
		case 6:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |     GESTION HOTEL  :  affichage des reservations |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
		afficheress();
		system("pause");
			break;
		}
		case 7:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |     GESTION HOTEL  :  reservations d'aujourd'hui |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	resaujour(dateactuel);
	system("pause");
			break;
		}
		case 8:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |  GESTION HOTEL  :  reservations fini aujourd'hui |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	resexpaujour(dateactuel);
	system("pause");
			break;
		}	
		case 9:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |GESTION HOTEL:annuler reservations fin aujourd'hui |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	anulresexpaujour(dateactuel);
	system("pause");
			break;
		}
		case 0:{system("cls");
	cout<<"\t \t ----------------------------------------------------"<<endl;
	cout<<"\t \t |     GESTION HOTEL  :  AU REVOIR ;)               |"<<endl;
	cout<<"\t \t ----------------------------------------------------"<<endl;
	
	system("pause");
			break;
		}					
	}
	
	
	}while (m!=0);

}
