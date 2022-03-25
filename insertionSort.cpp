#include <iostream>
// #include <ctime>
// #include <cstdlib>

#include <chrono>


struct Timer{
    std::chrono::system_clock::time_point m_start;

    Timer(){
        m_start = std::chrono::system_clock::now();
    }

    ~Timer(){
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float,std::milli> duration = end - m_start;
        std::cout << duration.count() << std::endl;
        
    }

};

void InsertionSort(int arreglo[], int elementos){

    int siguiente, llave, ultimo;
    int cambios = 0;
    int reinsert = 0;
    int inner_loop = 0;
    int iteraciones = 0;

    Timer t;

    for (siguiente = 1; siguiente < elementos; siguiente++)
    {   
        llave = arreglo[siguiente];
        ultimo = siguiente - 1; 
        iteraciones = iteraciones+1;
        
        while (ultimo >= 0 && arreglo[ultimo] > llave)
        {
            arreglo[ultimo + 1] = arreglo[ultimo];
            ultimo = ultimo - 1;
            inner_loop = inner_loop+1;
            cambios = cambios + 1;
        }
        if (arreglo[ultimo+1]!= llave){
            reinsert = reinsert+1;
        }
        arreglo[ultimo + 1] = llave;
    }
}


int main()
{   

    /*Mejores escenarios

    Los mejores escenarios serían aquellos que los nùmeros estàn ordenados de manera ascendente o bien
    que solo tengan el mismo nùmero

    */
    int arreglo_1[] = {1,2,3,4,5,6,7,8,9,10}; //10
    int arreglo_2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //20
    int arreglo_3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; //30
    int arreglo_4[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}; //40
    int arreglo_5[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
    31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}; //50

    int n_1 = sizeof(arreglo_1) / sizeof(arreglo_1[0]);
    int n_2 = sizeof(arreglo_2) / sizeof(arreglo_2[0]);
    int n_3 = sizeof(arreglo_3) / sizeof(arreglo_3[0]);
    int n_4 = sizeof(arreglo_4) / sizeof(arreglo_4[0]);
    int n_5 = sizeof(arreglo_5) / sizeof(arreglo_5[0]);

    //Pruebas del mejor escenario
    std::cout<<"************************Mejor escenario*****************************************************"<<std::endl;
        std::cout<<"N: "<<n_1<<std::endl;
    InsertionSort(arreglo_1, n_1);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n_2<<std::endl;
    InsertionSort(arreglo_2, n_2);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n_3<<std::endl;
    InsertionSort(arreglo_3, n_3);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n_4<<std::endl;
    InsertionSort(arreglo_4, n_4);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n_5<<std::endl;
    InsertionSort(arreglo_5, n_5);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;

    /*Peor escenario

    Abarca aquellos que tienen un orden descendente

    */
    int arreglo1[] = {20,19,18,17,16,15,14,13,12,11}; //10
    int arreglo2[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; //20
    int arreglo3[] = {30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; //30
    int arreglo4[] = {40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,
    13,12,11,10,9,8,7,6,5,4,3,2,1}; //40
    int arreglo5[] = {50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,
    20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; //50

    int n1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    int n2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    int n3 = sizeof(arreglo3) / sizeof(arreglo3[0]);
    int n4 = sizeof(arreglo4) / sizeof(arreglo4[0]);
    int n5 = sizeof(arreglo5) / sizeof(arreglo5[0]);

    //Pruebas del peor escenario
    std::cout<<"************************Peor escenario*****************************************************"<<std::endl;
        std::cout<<"N: "<<n1<<std::endl;
    InsertionSort(arreglo1, n1);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n2<<std::endl;
    InsertionSort(arreglo2, n2);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n3<<std::endl;
    InsertionSort(arreglo3, n3);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n4<<std::endl;
    InsertionSort(arreglo4, n4);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;
        std::cout<<"N: "<<n5<<std::endl;
    InsertionSort(arreglo5, n5);
    //std::cout<<"TIEMPO: "<<fixed<<float(t)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"**************************************************************************************"<<std::endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                            RESULTADOS FINALES Y ANÁLISIS

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
Tabla comparativa de tiempos en milisegundos:

Peor tiempo: (Usando arreglos con nùmeros ordenados de manera descendente) para que me haga un On²
Mejor tiempo: (Usando arreglos con números ordenados de manera ascendente) para que me haga un On
**Se utiliza la misma cantidad de números para las pruebas, arreglos de: 10, 20, 30, 40, 50.

                    Peor(On²)           Mejor(On)           Cantidad           
                    0,000711            0,000253                10
                    0,001153            0,000311                20
                    0,002094            0,000335                30
                    0,003466            0,000371                40
                    0,006332            0,000391                50

Opiniones:
1: El peor caso muestra un crecimiento enorme en comparacion con el mejor caso. Teniendo la misma cantidad de 
elementos.

2: El crecimiento del "mejor caso" es muy poco entre todas las pruebas, pero igualmente se puede notar 
que crece de manera progresiva sin dar un golpe brusco en el aumento del tiempo entre el primero y el último.

3: El peor caso se puede notar un crecimiento abrupto entre la primera prueba y la última. Todas las pruebas
se les nota un crecimiento bastante notorio entre la anterior.

Para ilustrar mejor el análisis, adjunto dos gráficos. Demostrando que el On² tiene una curva muy similar
a las funciones cuadràticas y el On demuestra un aumento progresivo como las funciones lineales
(Pues depende unicamente de la cantidad de elementos en el array).

*/

    return 0;
}

