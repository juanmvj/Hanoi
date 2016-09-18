/**
	
	Nombres(s): Altamirnao Leal Jose ALfonso
	Nombres(s): Vázquez Jiménez Juan Manuel
	
*/
#include "Hanoi.h"

int main()
{
	int i =3;
	std::cout<<"Torres de Hanoi"<<std::endl;
	std::cout<<"Pasos"<<std::endl;
	Hanoi H(i);
	H.LlenarTorre();
	if (i%2 == 0){
		H.Resolverpar();
	}else{
		H.Resolverinpar();
	}
	std::cout<<"Imprimiendo Pilas Hanoi"<<std::endl;
	H.MostrarTorres();
	return 0;
}
