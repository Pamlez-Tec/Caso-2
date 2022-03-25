# Caso-2

                                          Experimentos y resultados del QUICKSORT


P R U E B A S P A R A NLOG(N)

1- Se hacen con un pivote central, parte a la mitad el array para sacar el pivote.
2- Los elementos del array están ordenados de forma ascendente

Experimentos con arreglos ordenados de forma ascendente.

double a1[] = {10,20,30,40,50,60,70,80,90,100}; //10 elementos
double a2[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150}; //15 elementos
double a3[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200}; //20 elementos
double a4[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,201,202,203,204,
205,206,207,208,209,210}; //30 elementos
double a5[] = {0,1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,
201,202,203,204,205,206,207,208,209,210};//40 elementos

Los tiempos que aparecen son los de la recursividad. 
Resultado aproximado de la suma de los tiempos en mili segundos:

quicksort(a1,0,10); //0,11908 
quicksort(a2,0,15); //0,28 
quicksort(a3,0,20); //0,42 
quicksort(a4,0,30); //0,80 
quicksort(a5,0,40); //2,36291 

Nos damos cuenta que el aumento del tiempo es gradual conforme la cantidad de elementos aumenta

T1 = 0,11908 	L1 = 10log(10) = 33,21
T2 = 0,28 	L2 = 15log(15) = 58,60
T3 = 0,42 	L3 = 20log(20) = 86,44
T4 = 0,80 	L4 = 30log(30) = 147,20
T5 = 2,36291 	L5 = 40log(40) = 212,87

Calculamos la tasa de crecimiento y nos damos cuenta que la diferencia es muy poca comparándolas entre si. 
Por lo que se considera que la función cumple el nlogn

T1/T2 = 0,42529 	L1/L2 = 0,56 
T2/T3 = 0,66667 	L2/L3 = 0,67
T3/T4 = 0,52500 	L3/L4 = 0,5872
T4/T5 = 0,333857 	L4/L5 = 0,69 //La diferencia es muy notoria en este caso, pero se intuye que es causado 
por el equipo en donde se está probando.



P R U E B A S P A R A On² 

En este caos es más complicado probar el n^2, pero se toma en cuenta lo siguiente para que se cumpla:

1- Que el arreglo esté ordenado de manera descendente
2- Se toma el primer término (el más grande) como pivote

Experimentos se hacen con arreglos ordenados de forma descendente

double c1[] = {125,124,123,122,121,120,119,118,117,116}; // 10 elementos
double c2[] = {125,124,123,122,121,120,119,118,117,116,115,114,113,112,111}; //15 elementos
double c3[] = {125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106};//20 elementos
double c4[] = {125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,
104,103,102,101,100,90,80,70,60}; //30 elementos
double c5[] = {125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,
104,103,102,101,100,90,80,70,60,50,40,30,20,10,9,8,7,6,5}; //40 elementos

Resultado aproximado de la suma de los tiempos en mili segundos:

quicksort(c1,0,10); //0,60
quicksort(c2,0,15); //0,73 
quicksort(c3,0,20); //1,77 
quicksort(c4,0,30); //2,24 
quicksort(c5,0,40); //5,82
*/

Con respecto al análisis del On² se me dificultó bastante hacer una comparativa con la tasa de crecimiento pues para que sea On² es complicado que suceda, pero por los tiempos anteriores nos damos cuenta que dura mucho más dando el resultado comparado con el nlog(n). Para ilustrar mejor la comparativa, añadí un gráfico donde se ve ambos tiempos y la diferencia. 


INFLUENCIA DEL PIVOTE FIJO Y ALEATORIO 


PARA EL FIJO, se toman los arreglos de peor tiempo que fueron los del On²

Con pivote fijo tenemos estos tiempos. En estos arreglos se trata de que sea un On². Estos experimentos se hacen con arreglos con orden decreciente y pivote fijo en el primer elemento

// quicksort2(c1,0,10); //0,60
// quicksort2(c2,0,15); //0,73 
// quicksort2(c3,0,20); //1,77 
// quicksort2(c4,0,30); //2,24 
// quicksort2(c5,0,40); //5,82

Con pivote aleatorio y los mismo arreglos anteriores, los tiempos aproximados son: 

//quicksort3(c1,0,10); // 0,12
//quicksort3(c2,0,15); // 0,22043
//quicksort3(c3,0,20); // 0,38029
//quicksort3(c4,0,30); // 0,42792
//quicksort3(c5,0,40); // 0,62973

Tabla comparativa de tasa de crecimiento calculada Tiempo1/ Tiempo2:

Tasa del P.fijo    Tasa del P.aleatorio    Tasa de crecimiento nlogn
   0,82192 			0,5443 					0,56
   0,4124                0,57964                      0,67
   0,79                  0,88869                      0,59
   0,38                  0,67953                      0,69

En conclusión, considero que el pivote aleatorio logra un mejor desempeño en listas "con desventaja"
crea facilmente un nlog(n). 


                                Experimentos y resultados del INSERTIONSORT
