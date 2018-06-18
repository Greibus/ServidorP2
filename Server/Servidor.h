
#ifndef CLIENTESERVIDORSOCKETS_SERVIDOR_H
#define CLIENTESERVIDORSOCKETS_SERVIDOR_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>
#include "../Json/SaveJson.h"
#include "../MusicManager/MusicManager.h"

static char delimitador = '*';

/**
 * Servidor multi hilos
 */
class Servidor {

private:
    int sock, sockCliente, io, c, *sockTemp;
    struct sockaddr_in servidor, cliente;

    static Servidor instancia;

    SaveJson saveJson;

public:
    Servidor() {}

    void iniciar();

    static void *hiloConexion(void *);

    static std::string cleanMensaje(char*);

    void saveData(json, int);
};


#endif //CLIENTESERVIDORSOCKETS_SERVIDOR_H
