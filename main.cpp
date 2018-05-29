
#include <iostream>
#include <fstream>
#include <vector>
#include "Server/Servidor.h"
#include <rapidxml/rapidxml.hpp>

#include "Trees/LinkedList.h"
#include "Sort/QuickSort.h"
#include "MusicManager/Song.h"
#include "MusicManager/MusicManager.h"
#include "UserData/Hash.h"

using namespace std;

int main(){

<<<<<<< Updated upstream
//    MusicManager *musicManager = new MusicManager();
//    musicManager->init();
//
//    musicManager->modifySong("The House Of The Rising Sun","artist","The Animals");
//    musicManager->addNewSong("The House Of The Rising Sun");
//    musicManager->saveSongs();

=======
>>>>>>> Stashed changes
    std::cout << "Iniciando Servidor" << std::endl;
    Servidor servidor = Servidor();
    servidor.iniciar();

//    auto *lista = new LinkedList<Song*>();
//    Song* song = new Song("Hola","Marcos","Que suena","Rock","../Music/",2014);
//    Song* song1 = new Song("Marika","Marcos","Alv","Rock","../Music/",2014);
//    Song* song2 = new Song("Wellp","Marcos","Buena malla y malla","Rock","../Music/",2014);
//    Song* song3 = new Song("AGHHHH","Marcos","z","Rock","../Music/",2014);
//    lista->addLast(song);
//    lista->addLast(song1);
//    lista->addLast(song2);
//    lista->addLast(song3);
//
//    for (int i = 0; i < lista->getCount() ; i++){
//        cout<< lista->getIn(i)->getSongName()<< endl;
//    }
//
//
//    QuickSort bubbleSort;
//    bubbleSort.quickSort(lista,0,lista->getCount()-1);
//
//    for (int i = 0; i < lista->getCount() ; i++){
//        cout<< lista->getIn(i)->getSongName()<< endl;
//    }

    return 0;

}
