#include <utility>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include "matcher.h"

matcher::matcher(size_t nPlayers, std::string players_file) {
    my_tournament = tournament(nPlayers, players_file);
}

matcher::~matcher() = default;

void matcher::gale_shapley(){
    //std::cout << "--- Finding best match... ---" << std::endl;
    for (auto it = my_tournament.getProposers().begin(); ; ++it){
        if (my_tournament.allMatched()){
            return;
        }
        else if (it == my_tournament.getProposers().end())
            it = my_tournament.getProposers().begin();
        if ((*it)->isFree())
            my_tournament.findPartner((*it));
    }
}



bool matcher::is_stable(){
    size_t i = 0;
    player * player_aux;

    for(auto each : my_tournament.getProposers()){//O(n)
        i = each->getPartnerPref();//O(n)
        for(auto it = each->getPlayer_preferences().begin(); i; i--){//O(n)
            player_aux = my_tournament.getPlayer(it->second);
            if(player_aux->getPriorityOf(each) < player_aux->getPartnerPref())//O(n)
                return false;
        }
    }
    return true;
}//O(n³)

void matcher::printResults(){

    ofstream outputFile;
    outputFile.open ("resultados.txt");

    for (size_t i=0; i < my_tournament.getProposers().size();i++){

        outputFile << (my_tournament.getProposers()[i])->getName() << "," << (my_tournament.getProposers()[i])->getPartner()->getName() << std::endl;
        
    }
    outputFile.close(); 

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

