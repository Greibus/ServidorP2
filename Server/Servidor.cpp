
#include "Servidor.h"
#include <iostream>
#include <fstream>
#include <vector>
//#include <nlohmann/json.hpp>
#include <rapidxml/rapidxml.hpp>
#include "../UserData/LinkedListUser.cpp"
#include "../Json/SaveJson.h"
#include "../MusicManager/MusicManager.h"
#include "../UserData/Hash.h"
#include "../Raid5/Controller/Controller.h"
#include "../Huffman/huffmandecoder.h"
#include "../Raid5/File/File.h"
#include "../MySQL/meinSQL.h"

using namespace std;
string prueba = "";
LinkedListUser<string> listaUser = LinkedListUser<string>();
SaveJson data = SaveJson();
MusicManager *manager = new MusicManager();
json jsonUser;
json songs;
Hash hash1 = Hash();
Controller controller = Controller();
File file1 = File();
HuffmanDecoder huffDecoder = HuffmanDecoder();
bool arbol = false;
string userConnected;
meinSQL m;

bool path1Bool = false;
bool path2Bool = false;
bool path3Bool = false;
bool path4Bool = false;
bool path5Bool = false;



//AGREGAR DEL JSON A LA LISTA CUANDO INICIA EL SERVER

/*
void archivoBakcUp(json jsonUser){
    jsonUser.;
}*/
/**
 * Inicializa el servidor
 */
void Servidor::iniciar() {
    manager->init();
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: No se puede crear el socket");
    }
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(9090);
    if (bind(sock, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
        cout << "Error: No se pudo iniciar el servidor" << endl;
    }
    listen(sock, 3);
    c = sizeof(struct sockaddr_in);
    cout << "Esperando nuevas conexiones" << endl;
    while ((sockCliente = accept(sock, (struct sockaddr *) &cliente, (socklen_t *) &c))) {
        cout << "Nueva conexion aceptada" << endl;

        pthread_t sniffer_thread;
        sockTemp = new int;
        *sockTemp = sockCliente;

        if (pthread_create(&sniffer_thread, NULL, hiloConexion, (void *) sockTemp) < 0) {
            cout << "Error: No se pudo inicializar el hilo" << endl;
        }

    }
}


/**
 * Elimina posibles ruidos en los mensajes y recorta el mensaje utiizando el delimitador
 * @param men
 * @return
 */
string Servidor::cleanMensaje(char* men) {
    string temp;
    for (unsigned int i = 0; i < strlen(men); i++) {
        if (men[i] == delimitador) {
            break;
        } else {
            temp += men[i];
        }
    }
    return temp;
}

void addSong(string album, string artist, string genre, string lyris, string name, string path, string rating, string year){

}

/**
 * Se encarga de manejar individualmente cada cliente conectado
 * @param socket
 * @return
 */
void *Servidor::hiloConexion(void *socket) {
    int sockPtr = *(int *) socket;
    int read_size;
    char client_message[100000];
    string limpio;

    //Forma correcta de enviar datos
    //string dato = "USUARIO Regist" + delimitador; //delimitador
    //int io = write(sockPtr, dato.c_str(), dato.length());
    //write(sockPtr, dato.c_str(),dato.length());
    //if (io < 0) {
    //  cout << "Error: No se pudo enviar el dato" << endl;
    //}
    bzero(client_message,100000);
    while ((read_size = recv(sockPtr, client_message, 100000, 0)) > 0) {
        limpio = cleanMensaje(client_message);
        cout << "CONTENIDO" << endl;
        cout << limpio << endl;


        if (arbol) {


            string decodeMessage = huffDecoder.Decode(limpio);
            cout << decodeMessage << endl;
            arbol = false;
            //****************************Nuevo parseo string xml*******************
            rapidxml::xml_document<> doc;
            char *cstr = new char[decodeMessage.size() + 1];  // Create char buffer to store string copy
            strcpy(cstr, decodeMessage.c_str());             // Copy string into char buffer
            doc.parse<0>(cstr);                     // Pass the non-const char* to parse()
            //**********************************************************************


            //test the xml_document
            string nombre = doc.first_node()->name();

            if (nombre == "EnviarCancion") {
                string albumCancion = doc.first_node()->first_node()->first_attribute()->value();
                string anoCancion = doc.first_node()->first_node()->first_attribute()->next_attribute()->value();
                string crudoCancion = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->value();
                string generoCancion = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string letraCancion = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string nombreCancion = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string pathCancion = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();


                controller.saveF(pathCancion, nombreCancion);
                if (pathCancion == "/home/deiber/Desktop/Songs/Kansas - Dust in the Wind - Point of Know Return.mp3") {
                    path1Bool = true;
                } else if (pathCancion == "/home/deiber/Desktop/Songs/Switchfoot - Awakening - Oh! Gravity.mp3") {
                    path2Bool = true;
                } else if (pathCancion == "/home/deiber/Desktop/Songs/The Lumineers - Ophelia - Cleopatra.mp3") {
                    path3Bool = true;
                } else if (pathCancion == "/home/deiber/Desktop/Songs/The Paper Kites - Bloom - Woodland - EP.mp3") {
                    path4Bool = true;
                } else if (pathCancion == "/home/deiber/Desktop/Songs/profe.mp4") {
                    path5Bool = true;
                }


                manager->addNewSong(nombreCancion);
                /*manager.encoder(crudoCancion, nombreCancion);*/
                songs = {{"Nombre", nombreCancion},
                         {"genero", generoCancion},
                         {"año",    anoCancion},
                         {"Album",  albumCancion},
                         {"Letra",  letraCancion},
                         {"crude",  crudoCancion}};
                manager->saveSongs();
                string data = "true\n";
                write(sockPtr, data.c_str(), data.length());
                //data.saveInFile(1, songs);
            } else if (nombre == "VerificarUsuarios") {
                //string user = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string user = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                if (!listaUser.search(user)) {
                    string age = doc.first_node()->first_node()->first_attribute()->value();
                    string genders = doc.first_node()->first_node()->first_attribute()->next_attribute()->value();
                    string name = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->value();
                    string password = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                    listaUser.addLast(user, name, "", age, genders, hash1.hash(password), "");
                    m.addUser(genders,age,name,hash1.hash(password),user);
//                    json
//                    jsonUser.push_back(listaUser.toJson());
//                    data.saveInFile(0, jsonUser);
//                    cout << "JSON USER ES " << jsonUser << endl;

                    string datoUser = "true\n";
                    write(sockPtr, datoUser.c_str(), datoUser.length());
                    jsonUser.clear();
                } else {
                    string datoUser = "false\n";
                    write(sockPtr, datoUser.c_str(), datoUser.length());
                }
            } else if (nombre == "EnviarUsuarios") {
                string user = doc.first_node()->first_node()->first_attribute()->next_attribute()->value();
                if (listaUser.search(user)) {
                    string password = doc.first_node()->first_node()->first_attribute()->value();
                    if (listaUser.verifyPass(user, hash1.hash(password))) {
                        userConnected = user;
                        string datoUser = "true\n";
                        write(sockPtr, datoUser.c_str(), datoUser.length());

                    } else {
                        string datoUser = "false\n";
                        write(sockPtr, datoUser.c_str(), datoUser.length());
                    }
                } else {
                    string datoUser = "false\n";
                    write(sockPtr, datoUser.c_str(), datoUser.length());
                }
            } else if (nombre == "EnviarPlay") {
                controller.CheckDisks();
                string pathMusic = doc.first_node()->first_node()->first_attribute()->value();
                if (pathMusic == "/home/deiber/Desktop/Songs/Kansas - Dust in the Wind - Point of Know Return.mp3") {
                    string nombreMusic = "Kansas - Dust in the Wind - Point of Know Return";
                    if (path1Bool) {
                        char *y = new char[nombreMusic.length() + 1]; // or
                        std::strcpy(y, nombreMusic.c_str());
                        if (!file1.existFile((y), 1)) {
                            file1.reBuildFile(y, 1);
                        } else if (!file1.existFile(y, 2)) {
                            file1.reBuildFile(y, 2);
                        }

                        delete[] y;
                    }

                } else if (pathMusic == "/home/deiber/Desktop/Songs/Switchfoot - Awakening - Oh! Gravity.mp3") {
                    string nombreMusic = "Switchfoot - Awakening - Oh! Gravity";
                    if (path2Bool) {
                        char *y = new char[nombreMusic.length() + 1]; // or
                        std::strcpy(y, nombreMusic.c_str());
                        if (!file1.existFile(y, 1)) {
                            file1.reBuildFile(y, 1);
                        } else if (!file1.existFile(y, 2)) {
                            file1.reBuildFile(y, 2);
                        }

                        delete[] y;

                    }

                } else if (pathMusic == "/home/deiber/Desktop/Songs/The Lumineers - Ophelia - Cleopatra.mp3") {
                    string nombreMusic = "The Lumineers - Ophelia - Cleopatra";
                    if (path3Bool) {
                        char *y = new char[nombreMusic.length() + 1]; // or
                        std::strcpy(y, nombreMusic.c_str());
                        if (!file1.existFile(y, 1)) {
                            file1.reBuildFile(y, 1);
                        } else if (!file1.existFile(y, 2)) {
                            file1.reBuildFile(y, 2);
                        }

                        delete[] y;

                    }
                } else if (pathMusic == "/home/deiber/Desktop/Songs/The Paper Kites - Bloom - Woodland - EP.mp3") {
                    string nombreMusic = "The Paper Kites - Bloom - Woodland - EP";
                    if (path4Bool) {
                        char *y = new char[nombreMusic.length() + 1]; // or
                        std::strcpy(y, nombreMusic.c_str());
                        if (!file1.existFile(y, 1)) {
                            file1.reBuildFile(y, 1);
                        } else if (!file1.existFile(y, 2)) {
                            file1.reBuildFile(y, 2);
                        }

                        delete[] y;
                    }
                } else if (pathMusic == "/home/deiber/Desktop/Songs/profe.mp4") {
                    string nombreMusic = "profe";
                    if (path5Bool) {
                        char *y = new char[nombreMusic.length() + 1]; // or
                        std::strcpy(y, nombreMusic.c_str());
                        if (!file1.existFile(y, 1)) {
                            file1.reBuildFile(y, 1);
                        } else if (!file1.existFile(y, 2)) {
                            file1.reBuildFile(y, 2);
                        }

                        delete[] y;

                    }
                }
                string datoUser = "true\n";
                write(sockPtr, datoUser.c_str(), datoUser.length());
            } else if (nombre == "EnviarVideo") {
                string nombreVideo = doc.first_node()->first_node()->first_attribute()->value();
                string pathVideo = doc.first_node()->first_node()->first_attribute()->next_attribute()->value();
                controller.saveF(pathVideo, nombreVideo);
                string datoUser = "true\n";
                write(sockPtr, datoUser.c_str(), datoUser.length());

            }
            if (read_size == 0) {
                cout << "Error: Cliente desconectado" << endl;
                fflush(stdout);
            } else if (read_size == -1) {
                cout << "Error: No se recibio un dato valido" << endl;
            }
            //---------------------------------------------------------
//        remove("/home/tony/CLionProjects/almacenar.xml");
            //---------------------------------------------------------

            delete[] cstr;

        } else {
            huffDecoder.xmlToCodes(limpio);
            bzero(client_message, 100000);
            string datoUser = "recibido\n";
            write(sockPtr, datoUser.c_str(), datoUser.length());
            arbol = true;
            limpio = "";
        }


        if (read_size == 0) {
            cout << "Error: Cliente desconectado" << endl;
            fflush(stdout);
        } else if (read_size == -1) {
            cout << "Error: No se recibio un dato valido" << endl;
        }
    }
}

void Servidor::saveData(json json1, int cond) {
    saveJson.saveInFile(cond, json1);
}

void Servidor::getInformation(string name) {
    const char *stringChar = name.c_str();
    string album;
    string rating;
    string namex;
    string genero;
    string year;
    string lyris;
    string artist;
    string friends = "";
    string path = "";
    if (name == "Kansas - Dust in the Wind - Point of Know Return") {
        string namex = "Dust in the Wind";
        string rating = "5";
        string album = "Point of Know Return";
        string genero = "Soft Rock";
        string year = "1997";
        string lyris = "TEC Deiber, [17.06.18 22:51]"
                       "I close my eyes"
                       "Only for a moment"
                       "And the moment's gone"
                       "All my dreams"
                       "Pass before my eyes, in curiosity"
                       "Dust in the wind";
        string artist = "Kansas";
        //songs = {{"album", album} ,{"artist", artist},{"genre",genero},{"lyric",lyris},{"name",namex},{"path",path},{"rate",rating},{"year",year}};
        addSong(album, artist, genero, lyris, namex, path, rating, year);
    } else if (name == "Switchfoot - Awakening - Oh! Gravity") {
        string namex = "Awakening";
        string rating = "4";
        string album = "Oh! Gravity";
        string genero = "Rock-Pop";
        string year = "2006";
        string lyris = "Face down with the LA curbside endings "
                       "And the ones in zeros."
                       "Downtown was the perfect place to hide."
                       "The first star that I saw last night was a headlight";
        string artist = "Switchfoot";
        addSong(album, artist, genero, lyris, namex, path, rating, year);
    } else if (name == "The Lumineers - Ophelia - Cleopatra") {
        string namex = "Ophelia";
        string rating = "4";
        string album = "Cleopatra";
        string genero = "Folk";
        string year = "2016";
        string lyris = "Oh, oh, when I was younger, oh, oh, should have known better"
                       "And I can't feel no remorse, and you don't feel nothing back"
                       "Oh, oh, got a new girlfriend, he feels like he's on top"
                       "And I don't feel no remorse, and you can't see past my blinders";
        string artist = "The Luminners";
        addSong(album, artist, genero, lyris, namex, path, rating, year);
    } else if (name == "The Paper Kites - Bloom - Woodland - EP") {
        string namex = "Bloom";
        string rating = "5";
        string album = "Woodland";
        string genero = "Folk";
        string year = "2011";
        string lyris = "Take a trip into my garden"
                       "I've got so much to show ya"
                       "The fountains and the waters"
                       "Are begging just to know ya";
        string artist = "The Paper Kites";
        addSong(album, artist, genero, lyris, namex, path, rating, year);
    }

}

