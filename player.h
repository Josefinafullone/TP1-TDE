#ifndef GALE_SHAPLEY_PLAYER_H
#define GALE_SHAPLEY_PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


class player {
    std::string name, file_dir;
    std::vector< std::pair<size_t,std::string> > player_preferences; //pares <preferencia - nombre>
	player * partner;

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
	   	std::stringstream ss;
		std::string file_dir, name, aux;
		size_t ranking;
		char ch;

		if(is >> ch && !is.eof()){
			if(!iscntrl(ch))
				is.putback(ch);
			std::getline(is,aux);
			if(is.fail()){
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			if(aux[aux.length()-1] == 0x0d)
	       		aux.resize(aux.length()-1);//to delete carriage return
			ss << aux;
			if(ss >> ranking){
				if(ss >> ch && ch == ',' ){
					std::getline(ss,name,',');
					if(ss.fail()){
						std::cerr << "Error" << std::endl;
						exit(1);
					}	
					std::getline(ss,file_dir);
					if(ss.fail()){
						std::cerr << "Error" << std::endl;
						exit(1);
					}
				}
			}
		}

		if(is.fail() && !is.eof()){
			std::cerr << "Error" << std::endl;
			exit(1);
		}

		p.file_dir = file_dir;
		p.name = name;

		return is;
	}
};
#endif //GALE_SHAPLEY_PLAYER_H
