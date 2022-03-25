#include<iostream>
#include <fstream>
#include <chrono>
using namespace std;

int contador = 0; //global que cuenta las apariciones.

struct Timer{
std::chrono::system_clock::time_point m_start;

Timer(){
     m_start = std::chrono::system_clock::now();
}

~Timer(){
     auto end = std::chrono::system_clock::now();
     std::chrono::duration<float,std::milli> duration = end - m_start;
     cout << endl << endl<<"Tiempo: "<< duration.count() << endl;
     
}

};

//LISTA PARA GUARDAR LAS PALABRAS

struct NodoString{
	string  str;
	NodoString * siguiente;
	
	NodoString(string  _medio){
		str = _medio;
		siguiente = NULL;
	}
};

struct ListaPalabras{
	NodoString * primerNodo, *ultimoNodo;

	ListaPalabras (){
		primerNodo = ultimoNodo = NULL;
	}
	void imprimir();
	void insertar(string);		
};

void ListaPalabras::insertar (string str){
     if (primerNodo == NULL){
          ultimoNodo = primerNodo = new NodoString(str);
     }
     else{
         NodoString *nuevo = new NodoString(str);
          nuevo->siguiente = primerNodo;
          primerNodo = nuevo; 
     }    
}

void ListaPalabras::imprimir(void)
{
     NodoString *tmp = primerNodo;
     
     while (tmp != NULL){
          cout<<tmp->str<<" ";
          tmp = tmp->siguiente;
     }
}

//Me indica si aparece la palabra en el texto
bool estaPalabra(string texto, string buscar){
size_t posicion;
posicion = texto.find(buscar);
bool control = false;

if(texto[0] == buscar[0]){
     while((posicion=texto.find(buscar))!= string::npos){
          contador++;
          control = true;
          texto.erase(0,posicion+1);
     }
}
return control;
}

//Algorito que cuenta e imprime las cantidad de apariciones de una palabra o palabras que inician con esa 
//"palabra"
ListaPalabras freeTxt(ifstream &a, string buscado){

ListaPalabras *_medios = new ListaPalabras();
string palabra;
string s, contenido;

Timer t;
while (a >> palabra) {
     if (estaPalabra(palabra,buscado) == true){
          _medios->insertar(palabra);
     }
}
return *_medios;
}


int main(){

//Datos que se deben cambiar
string buscar = "a"; //La palabra que buscamos
ListaPalabras *palabras = new ListaPalabras();

/*
EXPERIMENTOS: Se hacen pruebas con 1MB, 3MB, 5MB, 7MB y 10MB buscando la misma palabra e indicando el tiempo
*/

//***************************************************************************************************
//-----------Con 1MB 
ifstream archivo_1("1MB.txt"); //aquì escribimos el nombre del archivo, debe estar dentro de la carpeta;
if (!archivo_1.is_open()){
     cout<<"Error. No se pudo abrir el archivo"<<endl;
     return 1;
}
cout<<"*** Prueba con 1MB: ";
* palabras = freeTxt(archivo_1, buscar);
//palabras->imprimir(); //Imprime las palabras encontradas
cout<<endl<<"Cantidad: "<<contador<<endl<<endl; //Imprime la cantidad encontrada
contador = 0;

//***************************************************************************************************
//-----------Prueba con 3MB 
ifstream archivo_2("3MB.txt"); //aquì escribimos el nombre del archivo, debe estar dentro de la carpeta;
if (!archivo_2.is_open()){
     cout<<"Error. No se pudo abrir el archivo"<<endl;
     return 1;
}
cout<<"*** Prueba con 3MB: ";
* palabras = freeTxt(archivo_2, buscar);
//palabras->imprimir(); //Imprime las palabras encontradas
cout<<endl<<"Cantidad: "<<contador<<endl<<endl; //Imprime la cantidad encontrada
contador = 0;

//***************************************************************************************************
//-----------Prueba con 5MB 
ifstream archivo_3("5MB.txt"); //aquì escribimos el nombre del archivo, debe estar dentro de la carpeta;
if (!archivo_3.is_open()){
     cout<<"Error. No se pudo abrir el archivo"<<endl;
     return 1;
}
cout<<"*** Prueba con 5MB: ";
* palabras = freeTxt(archivo_3, buscar);
//palabras->imprimir(); //Imprime las palabras encontradas
cout<<endl<<"Cantidad: "<<contador<<endl<<endl; //Imprime la cantidad encontrada
contador = 0;

//***************************************************************************************************
//-----------Prueba con 7MB 
ifstream archivo_4("7MB.txt"); //aquì escribimos el nombre del archivo, debe estar dentro de la carpeta;
if (!archivo_4.is_open()){
     cout<<"Error. No se pudo abrir el archivo"<<endl;
     return 1;
}
cout<<"*** Prueba con 7MB: ";
* palabras = freeTxt(archivo_4, buscar);
//palabras->imprimir(); //Imprime las palabras encontradas
cout<<endl<<"Cantidad: "<<contador<<endl<<endl; //Imprime la cantidad encontrada
contador = 0;

//***************************************************************************************************
//-----------Prueba con 10MB 
ifstream archivo_5("10MB.txt"); //aquì escribimos el nombre del archivo, debe estar dentro de la carpeta;
if (!archivo_5.is_open()){
     cout<<"Error. No se pudo abrir el archivo"<<endl;
     return 1;
}
cout<<"*** Prueba con 10MB: ";
* palabras = freeTxt(archivo_5, buscar);
//palabras->imprimir(); //Imprime las palabras encontradas
cout<<endl<<"Cantidad: "<<contador<<endl<<endl; //Imprime la cantidad encontrada
contador = 0;


/*
RESULTADOS DEL EXPERIMENTO: VAMOS A COMPARAR LA TASA DE CRECIMIENTO DE LOS TIEMPOS CON 0(n) 

Tamaño         Tiempos        O(n) "L"
  1MB           30,9591         1
  3MB           83,7706         3
  5MB           138,372         5
  7MB           200,569         7
  10MB          242,709         10


Tasa crecimiento Tn/Tn+1                 Tasa de crecimiento O(n)
T1/T2     0,36                           L1/L2    0,33
T2/T3     0,60                           L2/L3    0,60
T3/T4     0,68                           L3/L4    0,71
T4/T5     0,82                           L4/L5    0,70      

Con estas comparaciones entre tasas de crecimiento, podemos notar que la funciòn es lineal tiene O(n).
La primera tiene una diferencia de 3.
La segunda ninguna diferencia
La tercera de tres 
La ultima una diferencia de 12, en este caso la diferencia entre ambas tasas es màs alta pero esto se
puede deber a varios factores que no se pueden controlar, pero 3 de 4 cumplen un tiempo aproximado muy
similar entre sì.

Se concluye entonces que el algoritmo implementado es lineal, cumple un O(n).

*/
return 0;
}
