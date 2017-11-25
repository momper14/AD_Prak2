#pragma once
class EVKD{
public:
	EVKD(const char*, EVKD*);
	EVKD(const char*);
	EVKD(const EVKD&);

	char* getDaten() const;
	int getAnz() const;
	void setNext(EVKD*);
	EVKD* getNext() const;

	int operator> (const EVKD&);
	int operator== (const EVKD&);

	~EVKD();

private:
	char *daten;
	int anz;
	EVKD *next;

};

