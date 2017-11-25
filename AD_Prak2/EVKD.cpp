#include "Util.h"
#include "EVKD.h"
#include "string"



EVKD::EVKD(const char* lpszDaten, EVKD* n){
	anz = std::string(lpszDaten).length();
	next = n;
	daten = new char[anz];

	for(int i = 0; i < anz; i++){
		daten[i] = lpszDaten[i];
	}
}

EVKD::EVKD(const char *lpszDaten) : EVKD(lpszDaten, nullptr){
}

EVKD::EVKD(const EVKD &obj){
	this->anz = obj.anz;
	this->daten = new char[obj.anz];
	charcpy(this->daten, obj.daten, this->anz);
	this->next = obj.next;
}

char * EVKD::getDaten() const{
	char *ret = new char[anz + 1];

	charcpy(ret, this->daten, this->anz);
	ret[anz] = '\0';

	return ret;
}

int EVKD::getAnz() const{
	return anz;
}

void EVKD::setNext(EVKD *obj){
	next = obj;
}

EVKD * EVKD::getNext() const{
	return next;
}

int EVKD::operator>(const EVKD &obj){
	return (compchar(this->daten, this->anz, obj.daten, obj.anz) > 0) ? 1 : 0;
}

int EVKD::operator==(const EVKD &obj){
	if(this->anz != obj.anz){
		return 0;
	} else{
		for(int i = 0; i < this->anz; i++){
			if(this->daten[i] != obj.daten[i]){
				return 0;
			}
		}
		return 1;
	}
}


EVKD::~EVKD(){
	delete daten;
	if(next != nullptr)
		delete next;
}