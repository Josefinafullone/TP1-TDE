#include "tournament.h"
#include <string>
#include <fstream>
#include <map>

tournament::tournament() {}

tournament::~tournament(){}

void tournament::addPlayer(player aPlayer) {
    players.insert(std::pair<std::string, player>(aPlayer.getName(),aPlayer));
}

void tournament::findPartner(player * aPlayer) {
	for (auto p : aPlayer->getPlayer_preferences()) {
		player candidate = players[p.second];	//chequear que objeto player en mapa sea mismo que el vector!
		if (candidate.isFree()) {
			aPlayer->partnerUp(&candidate);
			return;
		} else {
			std::string actual_partner = candidate.getPartner()->getName();
			if (candidate.prefers(p)) { //revisar o consultar
				candidate.losePartner();
				aPlayer->partnerUp(&candidate);
				return;
			}
		}
	}
}

tournament::tournament(size_t nPlayers, std::string fileName) : players_file(fileName){
   	player * aPlayer = new player;
    std::fstream * file = players_file.getStream();	//lo arme con el safeStream (ex parser) pa chequear que
    												//funcionaba con eso (de curioso), en la lectura del otro archivo
    												// no lo hice, de cualqueria de las 2 formas me da igual
    size_t i = 0;

    while (*file >> *aPlayer) {
    	if(file->fail()){
    		std::cerr << "Error while reading players ranking" << std::endl;
    	}
        aPlayer->setPreferences();
        addPlayer(*aPlayer);
        if (i < nPlayers/2)   //guardo solo la mitad mejor rankeada
            proposers.push_back(aPlayer);
        i++;
        aPlayer = new player;
	}
}

bool tournament::allMatched() { //manda la complejidad a la mierda porque se ejecuta por cada jugador, es decir que lo que deberia ser O(n) termina siendo O(n²)
	for (const auto &each : proposers){
		if (!each->getPartner())
			return false;
	}
	return true;
} //seria mas simple crear una variable acumuladora en la que sumemos de a 1 cada vez que se arma una pareja y que se reste 1 cada vez que se rompa una pareja
// y verificar simplemente si el numero del acumulador coincide con el numero de parejas esperadas porque hacer la comparacion con una variable es O(1)

const std::vector<player*>& tournament::getProposers(){
   	return proposers;
}

