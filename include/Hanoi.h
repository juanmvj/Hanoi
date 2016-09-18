/**
	
	Nombres(s): Altamirnao Leal Jose ALfonso
	Nombres(s): Vázquez Jiménez Juan Manuel
	Descripcion: Juego de las torres de Hanoi, donde usaremos un algoritmo para resolver el mismo.
	
*/

#include <iostream>
#include <stack>
#include <cmath>

class Hanoi
{
private:
	int Discos;
	int NumMovimientos;
	std::stack<int> origen;
	std::stack<int> auxiliar;
	std::stack<int> destino;
public:
	Hanoi(int Discos);
	void Resolverpar();
	void Resolverinpar();
	void LlenarTorre();
	void MostrarTorres();
	void ImprimePasos(int A, int O, int D);
};
