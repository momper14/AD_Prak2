#include "TEXT.h"

TEXT::TEXT(){
	anz = 0;
	start = nullptr;
}

TEXT::~TEXT(){
	if(start != nullptr){
		delete start;
	}
}

void TEXT::anhaengen(const char *in){
	if(this->start == nullptr){
		this->start = new EVKD(in, nullptr);
		this->anz++;
	} else{
		EVKD *tmp = this->start;
		while(tmp->getNext() != nullptr){
			tmp = tmp->getNext();
		}
		tmp->setNext(new EVKD(in, nullptr));
		this->anz++;
	}
}

void TEXT::einfuegenSortiert(EVKD *in, int max){
	if(max > 1){
		int drin = 0;
		EVKD *tmp1 = this->start, *tmp2 = tmp1->getNext();

		for(int i = 1; drin == 0 && i < max; i++){
			
		}
	}
}
