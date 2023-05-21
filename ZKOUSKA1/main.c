#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "faktury.h"

int main(void) {
	tFakturaList* t = nactiFaktury("faktury.bin", vydana, cerven);
	vypisFaktury(t);
	return 0;
}