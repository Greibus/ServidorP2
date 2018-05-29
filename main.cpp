
#include <iostream>
#include <fstream>
#include <vector>
#include "Server/Servidor.h"
#include <rapidxml/rapidxml.hpp>

#include "Trees/BTree.h"
#include "Sort/QuickSort.h"
#include "MusicManager/Song.h"
#include "MusicManager/MusicManager.h"
#include "UserData/Hash.h"

using namespace std;

int main(){

//    MusicManager *musicManager = new MusicManager();
//    musicManager->init();
//
//    musicManager->modifySong("The House Of The Rising Sun","artist","The Animals");
//    musicManager->addNewSong("The House Of The Rising Sun");
//    musicManager->saveSongs();

    std::cout << "Iniciando Servidor" << std::endl;
    Servidor servidor = Servidor();
    servidor.iniciar();

    return 0;

}
