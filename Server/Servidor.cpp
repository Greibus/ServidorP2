
#include "Servidor.h"
#include <iostream>
#include <fstream>
#include <vector>
//#include <nlohmann/json.hpp>
#include <rapidxml/rapidxml.hpp>
#include "../UserData/LinkedListUser.cpp"
#include "../Json/SaveJson.h"
#include "../MusicManager/MusicManager.h"

using namespace std;
string prueba = "";
LinkedListUser<string> listaUser = LinkedListUser<string>();
SaveJson data = SaveJson();
//SongManager manager = SongManager();
json jsonUser;
json songs;

/**
 * Inicializa el servidor
 */
void Servidor::iniciar() {
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

/**
 * Se encarga de manejar individualmente cada cliente conectado
 * @param socket
 * @return
 */
void *Servidor::hiloConexion(void *socket) {
    int sockPtr = *(int *) socket;
    int read_size;
    char client_message[1000000];
    string limpio;

    //Forma correcta de enviar datos
    //string dato = "USUARIO Regist" + delimitador; //delimitador
    //int io = write(sockPtr, dato.c_str(), dato.length());
    //write(sockPtr, dato.c_str(),dato.length());
    //if (io < 0) {
      //  cout << "Error: No se pudo enviar el dato" << endl;
    //}

    while ((read_size = recv(sockPtr, client_message, 1000, 0)) > 0) {
        limpio = cleanMensaje(client_message);
        cout << limpio << endl;
        //Repetidor de mensajes y enviar
        //limpio += "hola";
        //write(sockPtr, limpio.c_str(), limpio.length());

        //------------Parsero de string a xml--------------
//        rapidxml::xml_document<> doc;
//        ofstream file;
//        file.open("/home/tony/CLionProjects/almacenar.xml", ios::out);
//        if (file.fail()) {
//            cout << "NO SE CREO" << endl;
//        }
//        file << limpio << endl;
//        file.close();
//        ifstream myfile("/home/tony/CLionProjects/almacenar.xml");
//        //"Read file into vector<char>"  See linked thread above
//        vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));
//        buffer.push_back('\0');
//        cout<<&buffer[0]<<endl; //test the buffer
//        doc.parse<0>(&buffer[0]);
        //-------------------------------------------------------------------------------------

        //****************************Nuevo parseo string xml*******************
        rapidxml::xml_document<> doc;
        char* cstr = new char[limpio.size() + 1];  // Create char buffer to store string copy
        strcpy (cstr, limpio.c_str());             // Copy string into char buffer
        doc.parse<0>(cstr);                     // Pass the non-const char* to parse()
        //**********************************************************************


        //test the xml_document
        string nombre = doc.first_node()->name();
        if (nombre == "EnviarCancion"){
            string nombreCancion = doc.first_node()->first_node()->first_attribute()->value();
            string generoCancion = doc.first_node()->first_node()->next_sibling()->first_attribute()->value();
            string anoCancion = doc.first_node()->first_node()->next_sibling()->first_attribute()->next_attribute()->value();
            string albumCancion = doc.first_node()->first_node()->next_sibling()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
            string letraCancion = doc.first_node()->first_node()->next_sibling()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
            string crudoCancion = doc.first_node()->first_node()->next_sibling()->next_sibling()->first_attribute()->value();
            //manager.addNewSong(nombreCancion);
            songs = {{"Nombre", nombreCancion} ,{"genero", generoCancion},{"año",anoCancion},{"Album",albumCancion},{"Letra",letraCancion},{"crude",crudoCancion}};
            data.saveInFile(1, songs);
        } else if(nombre == "EnviarUsuarios") {
            string user = doc.first_node()->first_node()->first_attribute()->value();
            if (!listaUser.search(user)){
                string name = doc.first_node()->first_node()->first_attribute()->next_attribute()->value();
                string lastName = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->value();
                string age = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string genders = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string password = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                string friends = doc.first_node()->first_node()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value();
                listaUser.addLast(user, name, lastName, age, genders, password, friends);
                jsonUser.push_back(listaUser.toJson());
                data.saveInFile(0, jsonUser);
                cout << "JSON USER ES " << jsonUser << endl;
                string datoUser = "Usuario registrado\n";
                write(sockPtr,datoUser.c_str(), datoUser.length());
                jsonUser.clear();
            } else {
                string datoUser = "Elija otro usuario\n";
                write(sockPtr,datoUser.c_str(), datoUser.length());
            }
        }

        //---------------------------------------------------------
//        remove("/home/tony/CLionProjects/almacenar.xml");
        //---------------------------------------------------------

        delete [] cstr;
    }

    if (read_size == 0) {
        cout << "Error: Cliente desconectado" << endl;
        fflush(stdout);
    } else if (read_size == -1) {
        cout << "Error: No se recibio un dato valido" << endl;
    }
}

void Servidor::saveData(json json1, int cond) {
    saveJson.saveInFile(cond, json1);
}
