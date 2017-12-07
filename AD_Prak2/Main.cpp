#include "TEXT.h"
#include "EVKD.h"
#include "Util.h"
#include "iostream"

using namespace std;

int main(int argc, const char* argv[]){
int auswahl,ein;
char *eingabe[1];	
 TEXT *text;
 EVKD *evkd;
 //const char * name[] ={"Anna","Berta","Klaus"};
const char * name[] = {"Schmitz, Josef","Mueller, Josi","Schmitz, Anna", 
                    "Mueller, Josef","Schmitz, Josi","Mueller, Anna", 
                    "Meier, Josef","Zacher, Josi","Anker, Anna"}; 
					
					
do{
		
		 cout << "\nBitte waehlen:\n"
            "1 - Listenobjekt erstellen\n"
            "2 - Liste anzeigen\n"
            "3 - Element anhaengen\n"
			"4 - Element sortiert einfuegen\n"
			"5 - Element loeschen\n"
			"6 - Liste sortieren\n"
			"12 - Ende\n";
    cin >> auswahl;


    switch(auswahl){

        case 1:  cout << "\nListenobjekt wird erstellt\n"<<endl;
		 
				text = new TEXT();
				for (int i=0;i<9;i++){
					text->anhaengen(name[i]);
				}
				break;
				
        case 2:  cout << "\nInhalt der Liste\n\n";
				text->zeigeDich();
				break;
        case 3:  cout << "\nBitte Wort eingeben, das angehaenget werden soll\n";
				cin >> eingabe[0];				
				text->anhaengen(eingabe[0]);
				break;
		case 4:  cout << "\nBitte Wort eingeben\n";
				cin >> eingabe[0];
				evkd = new EVKD(eingabe[0]);
				text->einfuegenSortiert(evkd,text->anz);
				break;
		case 5:  cout << "\nWelches Element soll geloescht werden?\n";
				cin>>ein;
				text->loesche(ein);
				break;
		case 6:  cout << "\nListe wird sortiert\n";
				text->iSort();
				break;
        
    }

	} while(auswahl !=12 );
}
