#include "TEXT.h"
#include "iostream"
#include "EVKD.h"
#include "Util.h"
using namespace std;
// initialisiert die Variablen
TEXT::TEXT(){
	anz = 0;
	start = nullptr;
}


// hängt ein neues Element hinten an die Liste an
void TEXT::anhaengen(const char *in){
	if(this->start == nullptr){
		this->start = new EVKD(in);
		this->anz++;
	} else{
		EVKD *tmp = this->start;
		while(tmp->getNext() != nullptr){
			tmp = tmp->getNext();
		}
		tmp->setNext(new EVKD(in));
		this->anz++;
	}
}

// fügt das Element lexikalisch sortiert in die Liste ein
void TEXT::einfuegenSortiert(EVKD *in, int max){
	// start-Element vorhanden ?
	if(this->start == nullptr){
		//start-Element ersetzen
		this->start = in;
		this->anz++;

	} else if(max >= 1){
		// 1. Element größer ?
		if(*this->start > *in){
			//start-Element ersetzen
			in->setNext(this->start);
			this->start = in;
			this->anz++;

		} else{
			int drin = 0;
			EVKD *vorg = this->start, *vergl = vorg->getNext();

			// suchen nach Position und einfügen
			for(int i = 2; drin == 0 && i <= max; i++){
				if(*vergl > *in){
					in->setNext(vergl);
					vorg->setNext(in);
					this->anz++;
					drin = 1;
				}
				vorg = vergl;
				vergl = vorg->getNext();
			}

			// hinten anhängen, falls größer als größtes Element der Liste
			if(!drin){
				in->setNext(vorg->getNext());
				vorg->setNext(in);
				this->anz++;



			}
		}
	}
}

// löscht element an position x
// @return gelöschtes Element
EVKD * TEXT::loesche(int pos){
	// laufindex
	int i = 1;
	EVKD *tmp, *tmpvor;

	// Posiiton gültig ?
	if(pos > this->anz || pos < 1){
		return nullptr;
	} else{
		// erstes Element ?
		if(pos == 1){
			// start = 2. Element
			tmp = this->start;
			this->anz--;
			this->start = tmp->getNext();
			return tmp;
		} else{
			tmpvor = this->start;
			tmp = tmpvor->getNext();
			i++;
			while(i <= pos - 1){
				tmpvor = tmp;
				tmp = tmpvor->getNext();
				i++;
			}
			tmpvor->setNext(tmp->getNext());
			this->anz--;
			return tmp;
		}

	}

}

// alles ausgeben
void TEXT::zeigeDich(){
	if(this->start != nullptr){
		int i = 1;
		EVKD *tmp = this->start;
		while(tmp->getNext() != nullptr){
			cout << i << ": Adresse: " << tmp << "  Inhalt:  " << tmp->getDaten() << " Next: " << tmp->getNext() << endl;
			i++;
			tmp = tmp->getNext();
		}
		cout << i << ": Adresse: " << tmp << "  Inhalt:  " << tmp->getDaten() << " Ich bin das Letzte" << endl;
	}
}

//insertion sort
void TEXT::iSort(){
	int i = 2;
	EVKD *tmp;
	if(this->anz > 1){
		while(i <= this->anz){
			tmp = loesche(i);
			einfuegenSortiert(tmp, i - 1);
			i++;
		}
	}
}





// löscht alle Elemente der Liste
TEXT::~TEXT(){
	if(start != nullptr){
		EVKD *tmp, *tmpvor;

		while(this->start->getNext() != nullptr){
			tmpvor = this->start;
			tmp = tmpvor->getNext();

			while(tmp->getNext() != nullptr){
				tmpvor = tmp;
				tmp = tmpvor->getNext();
			}

			tmpvor->setNext(nullptr);
			delete tmp;
		}

		delete this->start;
	}
}