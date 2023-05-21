#pragma once

typedef struct faktura {
	char datum[20]; //08.10.2017
	char typ; // P/V
	char faktura[20];
	int castka;
}tFaktura;

enum fakturaEnum {
	vydana='V',
	prijata='P'
};
enum mesicEnum {
	leden=1,unor,brezen,duben,kveten,cerven,cerevenc,zari,rijen,listopad,prosinec
};
typedef struct fakturaList {
	tFaktura faktura;
	struct fakturaList* dalsi;

}tFakturaList;
tFakturaList* nactiFaktury(char* jmSoub, enum fakturaEnum typFaktury, enum mesicEnum mesic);
void vypisFaktury(tFakturaList* fakturaList);