#ifndef GALE_SHAPLEY_PLAYER_H
#define GALE_SHAPLEY_PLAYER_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class player {
    std::string name, file_dir;
    std::vector< std::pair<size_t,std::string> > player_preferences; //pares <preferencia - nombre>
	player* partner;

public:
	player();
	explicit player(const std::string & str);
	const std::string& getName() const;
	player* getPartner() const;
	void setPartner(player *partner);
	void partnerUp(player *p);
	void losePartner();
	bool prefers(pair<size_t, string> p);
	const vector<pair<size_t, string>> &getPlayer_preferences() const;
	void setPreferences();
	bool isFree();
	~player();

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

			p.file_dir = file_dir.substr(0, file_dir.size()-1); //substr porque agarra el \r de final de linea
			p.name = name;
			return is;
		}
};
#endif //GALE_SHAPLEY_PLAYER_H
