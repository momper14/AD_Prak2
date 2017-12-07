#pragma once

#include "Util.h"
#include "EVKD.h"


class TEXT{
public:
	// Anzahl an Elementen der Liste
	int anz;


	// initialisiert die Variablen
	TEXT();


	// hängt ein neues Element hinten an die Liste an
	void anhaengen(const char*);

	// fügt das Element lexikalisch sortiert in die Liste ein
	void einfuegenSortiert(EVKD*, int);
	
	// löscht element an position x
	EVKD * loesche(int);
	
	// alles ausgeben
	void zeigeDich();
	
	//insertion sort
	void iSort(); 
	
	
	// löscht alle Elemente der Liste
	~TEXT();
private:
	// anfang der Liste
	EVKD* start;
};