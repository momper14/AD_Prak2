#include "TEXT.h"
#include "EVKD.h"
#include "Util.h"
#include "iostream"

using namespace std;

void cinclear(){
	cin.clear();
	cin.ignore(10000, '\n');
}

int main(int argc, const char* argv[]){
	int auswahl, ein;
	char *eingabe;
	TEXT *text = new TEXT();
	EVKD *evkd;
	const char * name[] = { "Schmitz, Josef","Mueller, Josi","Schmitz, Anna",
						"Mueller, Josef","Schmitz, Josi","Mueller, Anna",
						"Meier, Josef","Zacher, Josi","Anker, Anna" };


	do{

		cout << endl << "Bitte waehlen:" << endl
			<< "1 - Listenobjekt erstellen" << endl
			<< "2 - Liste anzeigen" << endl
			<< "3 - Element anhaengen" << endl
			<< "4 - Element sortiert einfuegen" << endl
			<< "5 - Element loeschen" << endl
			<< "6 - Liste sortieren" << endl
			<< "12 - Ende" << endl;
		cin >> auswahl;
		cinclear();


		switch(auswahl){

			case 1:  cout << endl << "Listenobjekt wird erstellt" << endl;
				text = new TEXT();
				for(int i = 0; i < 9; i++){
					text->anhaengen(name[i]);
				}
				break;

			case 2:  cout << endl << "Inhalt der Liste" << endl << endl;
				text->zeigeDich();
				break;
			case 3:  cout << endl << "Bitte Wort eingeben, das angehaenget werden soll" << endl;
				eingabe = new char[20];
				cin >> eingabe;
				cinclear();
				text->anhaengen(eingabe);
				delete[] eingabe;
				break;
			case 4:  cout << endl << "Bitte Wort eingeben" << endl;
				eingabe = new char[20];
				cin >> eingabe;
				cinclear();
				evkd = new EVKD(eingabe);
				text->einfuegenSortiert(evkd, text->anz);
				delete[] eingabe;
				break;
			case 5:  cout << endl << "Welches Element soll geloescht werden?" << endl;
				cin >> ein;
				cinclear();
				text->loesche(ein);
				break;
			case 6:  cout << endl << "Liste wird sortiert" << endl;
				text->iSort();
				break;

		}

	} while(auswahl != 12);
}
