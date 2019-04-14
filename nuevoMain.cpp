/*
 * nuevoMain.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: andres
 */
#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <iterator>
#include <algorithm>
#include <math.h>

using namespace std;



void swap(int *p,int *q) {
	   int t;
	   t=*p;
	   *p=*q;
	   *q=t;
}

void imprimirLista(list<int> lista){
	list<int>::iterator it = lista.begin();

    for (it = lista.begin(); it != lista.end(); ++it)
    {
        for (list<int>::iterator s = lista.begin(); s != lista.end(); s++) {
            cout << *s << ' ';
        }
        cout << endl;
    }
    }

int buscarMaximoEnVectorDesordenado(int sizeargv, int argv[]){
// O(n)
	int maximo = argv[0];
	for(int i = 1; i < sizeargv; i++){
		if(maximo < argv[i]){
			maximo = argv[i];
		}
	}

	return maximo;
}

float buscarPromedioENVectorDesordenado(int sizeargv, int argv[]){
// O(n)
	int suma = 0;
	for(int i = 0; i < sizeargv; i++){
			suma = suma + argv[i];
	}
	float promedio = (suma/(float)sizeargv);

	return promedio;
}

int buscarMedianaEnVectorDesordenado(int sizeargv, int argv[]){
	// O(n^2)
	int mediana;
	sort(argv, argv + sizeargv);
	mediana = (sizeargv+1) / 2 - 1;      // -1 as array indexing in C starts from 0
	return argv[mediana];
	}

float buscarMediaEnVectorDesordenado(int sizeargv, int argv[]){
	//O(n)
	int sumaTotal = 0;

	for(int i = 0; i < sizeargv; i++){
		sumaTotal = sumaTotal + argv[i];
		cout<<sumaTotal<<endl;

	}


	return float(sumaTotal)/float(sizeargv);
	}


int buscarModaEnVectorDesordenado(int sizeargv, int argv[]){

	//O(n^2)
	int valorModa;
	int contadorMaximo;

	for (int i = 0; i < sizeargv; i++){
		int contador = 0;

		for(int j = 0; j<sizeargv; j++){
			if(argv[j] == argv[i]){
				contador++;
			}
		}
		if (contador > contadorMaximo){
			contadorMaximo = contador;
			valorModa = argv[i];
		}


	}
		return valorModa;
	}


float buscarDesviacionEstandarEnVectorDesordenado(int sizeargv, int argv[]) {
    float desviacion = 0.0;

    float promedio = buscarPromedioENVectorDesordenado(sizeargv, argv);

    for(int i = 0; i < sizeargv; ++i) {
        desviacion += pow((float)argv[i] - promedio, 2);
    }

    return sqrt(desviacion/sizeargv);
}

void VariacionesRepeticiónConRelementosEnVectorDesordenado(int sizeargv, int argv[]){
	//O(n^2)

    int pow_set_size = pow(2, sizeargv);


    for(int i = 0; i < pow_set_size; i++)
    {
    for(int j = 0; j < sizeargv; j++)
    {
        if(i & (1 << j))
            cout << argv[j];
    }
    cout << endl;
    }
}


void buscarPermutacionesDeConjuntoEnVectorDesordenado(int sizeargv, int argv[]){


	for (int i = 0; i < sizeargv; i++){
		for(int j = 0; j < sizeargv; j++){
			if(argv[i] != argv[j]){
				cout<<"("<<argv[i]<<","<<argv[j]<<")"<<endl;
			}
		}
	}


}


void buscaSubconjuntosEnVectorDesordenadoAPartirDeRElementos(int sizeargv, int argv[], int r) {

	list<int> listaAux;

	for (int i = 0; i < sizeargv; i++){

		listaAux.push_back(argv[i]);

		if(listaAux.size() == 1){
		imprimirLista(listaAux);
		}


		for(int j = 0; j < sizeargv; j++){
			if(argv[i] != argv[j]){
			listaAux.push_back(argv[j]);
			imprimirLista(listaAux);
			listaAux.pop_back();
			}
		}
		listaAux.clear();

	}


	}

int buscarMaximoEnList(list<int> listaDeInts){

	int maximo = 0;
	list<int>::iterator it = listaDeInts.begin();
	while(it != listaDeInts.end()){
		if(*it > maximo){
			maximo = *it;
		}
	       it++;
	}
	return maximo;
}

float buscarPromedioEnLista(list<int> listaDeInts){

	int tamanoLista = listaDeInts.size();
	float suma = 0.0;
	list<int>::iterator it = listaDeInts.begin();
	while(it != listaDeInts.end()){
		suma = suma + *it;
	       it++;
	}
	return (suma/tamanoLista);
}

int buscarModaEnLista(list<int> listaDeInts){
	//o(n^2)
    int contador = 0;
    int contador_ant = 0;


    list<int>::iterator it2 = listaDeInts.begin();
    list<int>::iterator it  = listaDeInts.begin();

    int moda = 0;

    while (it2 != listaDeInts.end() ){
    		while(it != listaDeInts.end()){
    			if(*it2 == *it){
    				contador += 1;
    			}
    		it++;
    		}

    		if(contador > contador_ant){
    			moda = *it2;
    			contador_ant = contador;
    			contador = 0;
    		}

    		it2++;
    		it  = listaDeInts.begin();
    }
	return moda;

}


float buscarDesviacionEstandarEnLista(list<int> listaDeInts) {
    float desviacion = 0.0;

    int tamano = listaDeInts.size();


    float promedio = buscarPromedioEnLista(listaDeInts);

    list<int>::iterator it  = listaDeInts.begin();

	while(it != listaDeInts.end()){
			desviacion += pow((float)*it - promedio, 2);
			it++;
		}

    return sqrt(desviacion/tamano);
}


float buscarMediaEnLista(list<int> listaDeInts){
    list<int>::iterator it  = listaDeInts.begin();
    float sumaTotal = 0.0;
    int tamano = listaDeInts.size();

	while(it != listaDeInts.end()){
			sumaTotal += (float)(*it);
			it++;
		}

	return sumaTotal/tamano;
}


void buscaPermutacionesEnLista(list<int> listaDeInts){
    list<int>::iterator it2 = listaDeInts.begin();
    list<int>::iterator it  = listaDeInts.begin();
    while (it2 != listaDeInts.end() ){
    		while(it != listaDeInts.end()){
    		{
    			if(*it != *it2){
    				cout<<"("<<*it2<<","<<*it<<")"<<endl;
    			}
    			}
    		it++;
    		}
    		it2++;
    		it  = listaDeInts.begin();
}
}





void buscaSubconjuntosEnListaAPartirDeRElementos(list<int> lista, int r){
    list<int>::iterator it2 = lista.begin();
    list<int>::iterator it  = lista.begin();
    list<int> listaAux;
    int contador = 0;


    while (it2 != lista.end() ){
    		if(contador == 0){
    		listaAux.push_back(*it2);
    		}

    		while(it != lista.end()){
    		{
    			if(*it != *it2){
    	    			listaAux.push_back(*it);
    			}

    		contador++;
    		imprimirLista(listaAux);
    			if(contador == r){
    				contador = 0;
    			}
    			}
    		it++;
    		}
    		it2++;
    		it  = lista.begin();
}
}

int buscarMaximoEnVectorOrdenado(int sizeargv, int argv[]){
	// O(1)
	return argv[0];
	}


float buscarPromedioEnVectorOrdenado(int sizeargv, int argv[]){
	//O(n)
	int suma = 0;
	for(int i = 0; i < sizeargv; i++){
			suma = suma + argv[i];
	}
	float promedio = (suma/(float)sizeargv);

	return promedio;
	}


int buscarModaEnVectorOrdenado(int sizeargv, int argv[]){
	//O(n^2)
		int valorModa;
		int contadorMaximo;

		for (int i = 0; i < sizeargv; i++){
			int contador = 0;

			for(int j = 0; j<sizeargv; j++){
				if(argv[j] == argv[i]){
					contador++;
				}
			}
			if (contador > contadorMaximo){
				contadorMaximo = contador;
				valorModa = argv[i];
			}


		}
			return valorModa;
		}

float buscarMediaEnVectorOrdenado(int sizeargv, int argv[]){
	//O(n)
	int sumaTotal = 0;

	for(int i = 0; i < sizeargv; i++){
		sumaTotal = sumaTotal + argv[i];
		cout<<sumaTotal<<endl;

	}


	return float(sumaTotal)/float(sizeargv);
	}


float buscarDesviacionEstandarEnVectorOrdenado(int sizeargv, int argv[]) {
    float desviacion = 0.0;

    float promedio = buscarPromedioENVectorDesordenado(sizeargv, argv);

    for(int i = 0; i < sizeargv; ++i) {
        desviacion += pow((float)argv[i] - promedio, 2);
    }

    return sqrt(desviacion/sizeargv);
}

void buscarPermutacionesDeConjuntoEnVectorOrdenado(int sizeargv, int argv[]){


	for (int i = 0; i < sizeargv; i++){
		for(int j = 0; j < sizeargv; j++){
			if(argv[i] != argv[j]){
				cout<<"("<<argv[i]<<","<<argv[j]<<")"<<endl;
			}
		}
	}


}


void VariacionesRepeticiónConRelementosEnVectorOrdenado(int sizeargv, int argv[]){
	//O(n^2)

    int pow_set_size = pow(2, sizeargv);


    for(int i = 0; i < pow_set_size; i++)
    {
    for(int j = 0; j < sizeargv; j++)
    {
        if(i & (1 << j))
            cout << argv[j];
    }
    cout << endl;
    }
}


int main()
{
	std::list<int> listaDeInts;

	listaDeInts.push_front(23);
	listaDeInts.push_front(29);
	listaDeInts.push_front(20);



    return 0;
}

//int main() {
	//std::list<int> listaDeInts;

	//listaDeInts.push_front(23);
	//listaDeInts.push_front(29);
	//listaDeInts.push_front(20);


//	int vector[] = {23,29,20};


  //  printPowerset(vector, 2);

    //return 0;

//}


