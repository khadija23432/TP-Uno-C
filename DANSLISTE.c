#include "DANSLISTE.h"
#include "egal.c"

int DANSLISTE(char val, char liste[], int ignorerCasse) {
	int r = 0;
	for (int i = 0; (r == 0) && (i < sizeof(liste)); i++) {
		if (val == liste[i]) {
			r = 1;
		}
		else if ((ignorerCasse == 1) && EGAL(&val, &liste[i])) {
			r = 1;
		}
	}
	return r;
}