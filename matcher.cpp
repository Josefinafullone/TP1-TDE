#include <utility>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "matcher.h"

void gale_shapley(std::vector<player*> & v){
    size_t i = 0;              //sea o e Oferente y p e Postulante
    while(!v[i]->isMatched()){ //mientras o no tenga pareja, recorrer lista de prefs hasta encontrar el primero sin pareja

    }

}


//una lista de oferentes y un mapa. lista de oferentes O(n/2) e O(n), mapa O(n)
//por cada n hay una lista de preferencias O(n-1) e O(n) -> espacialmente hay O(n²)
//armar vector de preferencias es O(n) (sin empates), buscar mejor forma de ordenar con empates, luego armar heap O(3n) -> O(n)
//supongo peor caso de lista de preferencias con empate O(nlogn). Si por cada participante (O(n)) armo  lista de pref (O(nlogn))) -> O(n²logn)
//
//dsp se ejecuta gs-> t(n) = f(n) + g(n)-> t(n) = O(n²logn) + g(n), siendo f(n) el preprocesamiento y g(n) el algoritmo GS
//
//recorro lista de oferentes O(n/2) e O(n)-> por cada oferente recorro su lista de preferencias hasta encontrar primer postulante libre O(n)
//-> O(n²). buscar a ese postulante libre en el mapa es O(logn)-> O(n²logn)
//Postulante debe recorrer lista para analizar propuesta -> recorrer lista de prefs es decir O(n)

//O(n) lista de oferentes{
//  buscar postulante libre O(n)
//      buscar en mapa O(logn)
//  analizar propuesta O(n)
//      buscar en mapa O(logn)
//}
//g(n) = O(n²logn)

//std::map<size_t,string> -> O(nlogn)