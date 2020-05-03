

#ifndef RASTRO_BOT_H
#define RASTRO_BOT_H

#include "dados.h"
#include "listas.h"

LISTA lista_cor_pos(ESTADO *e, COORDENADA c);
COORDENADA jog_random(ESTADO *e);
COORDENADA jog(ESTADO *e);
#endif //RASTRO_BOT_H
