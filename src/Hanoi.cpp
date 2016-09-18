/**
	
	Nombres(s): Altamirnao Leal Jose ALfonso
	Nombres(s): Vázquez Jiménez Juan Manuel
	
*/
#include "Hanoi.h"
/**
Constructor calcula el numero 
de movimientos
@params Discos 
@result void
*/
Hanoi::Hanoi(int Discos)
{
	this->Discos= Discos;
	this->NumMovimientos=pow(2,this->Discos);
}

/**
Resuelve el juego de las Torres 
de Hanoi con N discos cuadndo es par
@params void
@result void
*/
void Hanoi::Resolverpar(){

	for (int i = 1; i < this->NumMovimientos; ++i){
			
			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();
			ImprimePasos(A,O,D);
			if(i%3==1){//movimento entre origen y auxiliar
				if(O>A){
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
				}
			}if(i%3==2){//movimento entre origen y destino
				if( O>D){
					this->origen.push(this->destino.top());
					this->destino.pop();
				}else{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	
			}if(i%3==0){//movimento entre destino y auxiliar
				if(A>D){
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
				}
			}
		}
}
/**
Resuelve el juego de las Torres 
de Hanoi con N discos cuando es impar
@params void
@result void
*/
void Hanoi::Resolverinpar(){
	
	for (int i = 1; i < this->NumMovimientos; ++i){

		int O=(this->origen.empty())?INFINITY:this->origen.top();
		int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
		int D=(this->destino.empty())?INFINITY:this->destino.top();
		ImprimePasos(A,O,D);
		if(i%3==1){//movimento entre origen y destino		
			if(O>D){
			this->origen.push(this->destino.top());
			this->destino.pop();
		}else{
			this->destino.push(this->origen.top());
			this->origen.pop();
		}	
		}if(i%3==2){//movimento entre origen y auxiliar
			if(O>A){
				this->origen.push(this->auxiliar.top());
				this->auxiliar.pop();
			}else{
				this->auxiliar.push(this->origen.top());
				this->origen.pop();
			}
		}if(i%3==0){//movimento entre destino y auxiliar
			if(A>D){
				this->auxiliar.push(this->destino.top());
				this->destino.pop();
			}else{
				this->destino.push(this->auxiliar.top());
				this->auxiliar.pop();
			}
		}
	}
}
/**
Llenamos la torre de hanoi
@params void
@result void
*/
void Hanoi::LlenarTorre(){
	for(int i= this->Discos; i>0 ; --i){
		this->origen.push(i);
	}
}
/**
Mostramos las Torres(stacks)
@params void
@result void
*/
void Hanoi::MostrarTorres()
{
	std::stack<int> auxO;
	std::stack<int> auxA;	
	std::stack<int> auxD;
	int mayor;
	if(this->origen.size() > this->auxiliar.size() && this->origen.size() > this->destino.size()){
		mayor=origen.size();
	}else if(this->auxiliar.size() > this->origen.size() && this->auxiliar.size() > this->destino.size()){
		mayor=auxiliar.size();
	}else{
		mayor=destino.size();	
	}
	for(int i=mayor; i>0 ;--i){
		if(i<=origen.size()){
			std::cout<<origen.top()<<" ";
			auxO.push(origen.top());
			origen.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=auxiliar.size()){
			std::cout<<auxiliar.top()<<" ";
			auxA.push(auxiliar.top());
			auxiliar.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=destino.size()){
			std::cout<<destino.top()<<std::endl;
			auxD.push(destino.top());
			destino.pop();	
		}else{
			std::cout<<"*"<<std::endl;
		}	
	}
}
/**
Imprimimos los pasos para resolver la torre
@params A, O , D
@result void
*/
void Hanoi::ImprimePasos(int A, int O, int D){
	if(Discos>=O){
		std::cout<<O<<" ";
	}else{
		std::cout<<"*"<<" ";
	}if(Discos>=A){
		std::cout<<A<<" ";
	}else{
		std::cout<<"*"<<" ";	
	}if(Discos>=D){
		std::cout<<D<<std::endl;
	}else{
		std::cout<<"*"<<std::endl;
	}
std::cout<<"_______________________________________________"<<std::endl;
}
