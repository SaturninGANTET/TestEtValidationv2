#include "controlleur.h"

#define FREQ_BASE 2.0
#define VITESSE_BASE 2.0

#define PRESSION_BASE 1.0
#define TEMP_BASE 293,15 // 20 degres

bool tab[50][50];
bool notInit = true;
int x = 25;
int y = 25;
int direction = 0;

void init(){
    memset(tab,0,sizeof(tab));
    tab[x][y] = true;
}


void controlleur(float tabRadar[5], float pression, float temperature, bool urgence, float batterie,
                 int position[2], float *vitesse, float *frequanceEchantillon, bool *demande_secours, bool *active_capteur_supp)
{
    if(notInit){
        init();
    }

    direction = rand() % 4;



    *active_capteur_supp = true;
    *frequanceEchantillon = FREQ_BASE;
    *vitesse = VITESSE_BASE;

    bool secure = false;
    for (int i = 0; i < 5; i++)
        if (tabRadar[i] < 1.0)
            secure = true;
    if (secure)
    {
        *frequanceEchantillon *= 2;
        *vitesse *= 0.5;
    }

    switch(direction){
        case 0: x+= secure ? 1 : 2;
            break; 
        case 1: y+=secure ? 1 : 2;
            break;
        case 2: x-=secure ? 1 : 2;
            break;
        case 3: y-=secure ? 1 : 2;
            break;
    }
    position[0] = (x - 25)*50;
    position[1] = (y - 25)*50;
    tab[x][y] = true;



    *frequanceEchantillon *= (pression/PRESSION_BASE) * (temperature/TEMP_BASE);
}