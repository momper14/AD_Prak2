#include "TEXT.h"

TEXT::TEXT(){
	anz = 0;
	start = nullptr;
}


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
	if(max == 1){
		this->start = in;
		this->anz++;

	} else if(max > 1){
		if(*this->start > *in){
			in->setNext(this->start);
			this->start = in;
			this->anz++;

		} else{
			int drin = 0;
			EVKD *vorg = this->start, *vergl = vorg->getNext();

			for(int i = 2; drin == 0 && i < max; i++){
				if(*vergl > *in){
					in->setNext(vergl);
					vorg->setNext(in);
					this->anz++;
					drin = 1;
				}
				vorg = vergl;
				vergl = vergl->getNext();
			}
			if(!drin){
				vorg->setNext(in);
				this->anz++;
			}
		}
	}
}

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
