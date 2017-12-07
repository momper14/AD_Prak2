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


// hÃ¤ngt ein neues Element hinten an die Liste an
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

void TEXT::einfuegenSortiert(EVKD *in, int max){
	// start-Element vorhanden ?
	if(this->start == nullptr){
		//start-Element ersetzen
		this->start = in;
		this->anz++;

	}else if(max >= 1){
		// 1. Element grÃ¶ÃŸer ?
		if(*this->start > *in){
			//start-Element ersetzen
			in->setNext(this->start);
			this->start = in;
			this->anz++;

		} else{
			int drin = 0;
			EVKD *vorg = this->start, *vergl = vorg->getNext();

			// suchen nach Position und einfÃ¼gen
			for(int i = 2; drin == 0 && i < max; i++){
				if(*vergl > *in){
					in->setNext(vergl);
					vorg->setNext(in);
					this->anz++;
					drin = 1;
				}
				vorg = vergl;
				vergl = vorg->getNext();
			}

			// hinten anhÃ¤ngen, falls grÃ¶ÃŸer als grÃ¶ÃŸtes Element der Liste
			if(!drin){
				if(max < this->anz){
                                        vorg = vergl;
                                        vergl = vorg->getNext();
					in->setNext(vergl);
					vorg->setNext(in);
					this->anz++;	
				}else{
				vorg->setNext(in);
				this->anz++;
                                        
                                    
                                }
			}
		}
	}
}



EVKD * TEXT::loesche(int pos){
	int h=1;
	EVKD *tmp, *tmpvor;
	if (pos > this->anz){
		return nullptr;
	}else{
		if (pos == 1){
			tmp = this->start;
			this->anz--;
			this->start = tmp->getNext();			
			return tmp;
		}else{
			tmpvor = this->start;
			tmp = tmpvor->getNext();
			while(h!=pos-1){
				tmpvor = tmp;
				tmp = tmpvor->getNext();
				h++;
			}
			tmpvor->setNext(tmp->getNext());
			this->anz--;
			return tmp;
			}
		
	}
	
}

void TEXT:: zeigeDich(){
    int h=1;
	EVKD *tmp = this->start; 
		while(tmp->getNext() != nullptr){
			cout<<h<<": Adresse: "<<tmp<<"  Inhalt:  "<<tmp->getDaten()<<" Next: "<<tmp->getNext()<<" \n";
			h++;
			tmp = tmp->getNext();
		}
	cout<<h<<": Adresse: "<<tmp<<"  Inhalt:  "<<tmp->getDaten()<<" Ich bin das Letzte\n";
	
}

void TEXT:: iSort(){
	int h=2;
	EVKD *tmp;
	if (this->anz > 1){
		while(h <= this->anz){
			tmp = loesche(h);
			einfuegenSortiert(tmp,h-1);
			h++;
		}
	}
}	





// lÃ¶scht alle Elemente der Liste
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