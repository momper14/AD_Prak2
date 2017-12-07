#pragma once


class EVKD{
public:

	// initialisiert die Lokalen variablen
	EVKD(const char*, EVKD*);

	// runf Initialisierung-Konstruktor mit nullprt auf
	EVKD(const char*);

	// Copy-konstruktor
	EVKD(const EVKD&);

	// gibt daten als String zurück
	// @return daten + '\0'
	char* getDaten() const;

	// getter für anz
	int getAnz() const;

	// setter für next
	void setNext(EVKD*);

	// getter für next
	EVKD* getNext() const;

	// überladen von Operatoren
	int operator> (const EVKD&);
	int operator== (const EVKD&);

	// löscht daten und next
	~EVKD();

private:
	// beinhaltet den Text
	char *daten;
	// Anzahl an Elementen in daten
	int anz;
	// nächstes Element der Liste
	EVKD *next;

};