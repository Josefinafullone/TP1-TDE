#ifndef GALE_SHAPLEY_PLAYER_H
#define GALE_SHAPLEY_PLAYER_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class player {
    size_t ranking;
    std::string name, file_dir, couple;
    std::vector<std::string> player_preferences;
    bool matched;

	public:
	    int getRanking() const;
	    const std::string &getName() const;
	    player();
	    player(size_t nPlayers);
		player(const int & rank, const std::string & str);
	    ~player();
	    void setPreferences();
	    bool isMatched();

	    friend istream& operator>>(istream& is, player & p){
	    	//falta parsear o decidir si tomar solo una linea o varias, si usamos una entrada por linea -> usar stringstream
			std::string file_dir, name;
			size_t ranking;
			char ch;

			if(is >> ranking && is.good()){
				if(is >> ch && ch == ',' ){
					std::getline(is,name,',');
					if(!is.good())
						return is;
					std::getline(is,file_dir);
					if(!is.good())
						return is;
				}
			}
			else
				return is;

			p.file_dir = file_dir;
			p.name = name;
			p.ranking = ranking;

			return is;
		}
};
#endif //GALE_SHAPLEY_PLAYER_H
