#pragma once


// kopiert den 1. char-Array in den 2. mit der angegebenen anzahl Elemente
void charcpy(char*, const char*, int);

// vergleicht die angegebenen char-Arrays lexikalisch
// gibt die Differenz des 1. unterschiedlichen ASCII-Zeichens zurück (Array 1 - Array 2)
// @return 0 wenn gleich, sonst arr1 - arr2 an unterschied (ASCII)
int charcmp(const char*, int, const char*, int);