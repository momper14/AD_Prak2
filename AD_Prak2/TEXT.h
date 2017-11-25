#pragma once

#include "EVKD.h"

class TEXT{
public:
	int anz;

	TEXT();

	void anhaengen(const char*);
	void einfuegenSortiert(EVKD*, int);

	~TEXT();
private:
	EVKD* start;
};