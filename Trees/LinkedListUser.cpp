//
// Created by tony on 13/05/18.
//

#include "LinkedListUser.h"
/*
template<class T>
void LinkedListUser<T>::addLast(T user, T name, T age, T genders, T password, T friends) {
    if (counter==0){
        first ->setValor(num);
        counter += 1;
    } else {
        LLNode<T> *head = first;
        for (int i=1; i<counter;i++) {
            head = head->getRight();
        }
        head ->setRight(new LLNode<T>(num));
        head = new LLNode<int>();
        delete head;
        counter += 1;
    }
}*/










/*
template <typename TIPONODO>
json ListaSimple <TIPONODO>::ToJson(){
    string tipo,etiqueta,valor;


    struct nodo {
        std::string tipo;
        std::string etiqueta;
        std::string valor ;
        std::string referencias;
        std::string espacio;
    };



    NodoSimple<TIPONODO> *temptr = primeroPtr;
    json tipoJ;
    json etiquetaJ;
    json valorJ;

    json lista;
    json total;



    while (temptr != nullptr){
        tipo = temptr->tipo;
        etiqueta = temptr->etiqueta;
        valor = temptr->valor;



        lista["tipo"] = temptr->obtenerTipo();
        lista["etiqueta"] = temptr->obtenerEtiqueta();
        lista["valor"] = temptr->obtenerDatos();
        lista["cantidadReferencias"] = temptr->obtenerCantidadReferencias();
        lista["espacioEnMemoria"] = temptr->obtenerEspacioMemoria();
        lista["numeroEnMemoria"] = temptr->obtenerNumeroEnMemoria();

        //json array_not_object = json::array({lista});



        total.push_back(lista);



        temptr = temptr->siguientePtr;


    }


    //cout<<total<<endl;
    return total;
}
*/