#ifndef CONTROLLEUR
#define CONTROLLEUR

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <getopt.h>
#include <ctype.h>
#include <errno.h>


void controlleur(float tabRadar[5], float pression, float temperature, bool urgence, float batterie,
            int position[2],float* vitesse, float* fréquanceEchantillon, bool* demande_secours, bool* active_capteur_supp);

#endif

