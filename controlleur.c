#include "controlleur.h"

#define FREQ_BASE 2.0
#define VITESSE_BASE 2.0

void controlleur(float tabRadar[5], float pression, float temperature, bool urgence, float batterie,
                 int position[2], float *vitesse, float *fréquanceEchantillon, bool *demande_secours, bool *active_capteur_supp)
{
    *fréquanceEchantillon = FREQ_BASE;
    *vitesse = VITESSE_BASE;

    bool secure = false;
    for (int i = 0; i < 5; i++)
        if (tabRadar[i] < 1.0)
            secure = true;
    if(secure)
        *fréquanceEchantillon *= 2;
    
}