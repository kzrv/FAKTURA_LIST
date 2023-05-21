#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "faktury.h"

tFakturaList* nactiFaktury(char* jmSoub, enum fakturaEnum typFaktury, enum mesicEnum mesic) {
	tFakturaList* t = NULL;
	tFakturaList* pos = NULL;
	FILE* f = fopen(jmSoub, "rb");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return 1;
	}
	tFaktura buf;

	while (fread(&buf, sizeof(tFaktura), 1, f)==1) {
		char buf1[20];
		strcpy(&buf1, buf.datum);
		char* str = strchr(buf1, '.');
		str = str + 1;
		char* st1 = strchr(str, '.');
		*st1 = '\0';
		int cislo = atoi(str);
		if (buf.typ == typFaktury && cislo == mesic) {
			if (t == NULL) {
				t = malloc(sizeof(tFakturaList));
				if (t == NULL) {
					printf("CHYBA ALLOKOVANI");
					return 1;
				}
				t->faktura = buf;
				t->dalsi = NULL;
				pos = t;
			}
			else {
				pos->dalsi = malloc(sizeof(tFakturaList));
				pos = pos->dalsi;
				pos->faktura = buf;
				pos->dalsi = NULL;
			}
		}
	}
	return t;
}
void vypisFaktury(tFakturaList* fakturaList) {
	while (fakturaList != NULL) {
		tFaktura t = fakturaList->faktura;
		printf("%s %s, %d CZK, %c\n", t.faktura, t.datum, t.castka, t.typ);
		fakturaList = fakturaList->dalsi;
	}
}