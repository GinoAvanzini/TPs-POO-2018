

/* El usuario ingresa un numero. Se calcula una serie de valores hasta el 
 * término n ingresado por el usuario. Se suman todos los términos hasta n.
 * Se imprimen la suma y los valores de la serie.
 */


#include <iostream>
using namespace std;
        
#include <cmath>
using namespace std;


double obtener_termino(int termino){
    
    double valor;
   
    valor = (pow(cos(M_PI/2 - (termino + 1)), 2) + cos(2*termino))/(pow(2, termino));
    
    return valor;
}

double calcular_suma(double serie[], int termino){
    
    double suma = 0;
    
    for (int i = 0; i<termino; i++){
        
        suma = suma + serie[i];
                
    }
    
    
    return suma;
}


void ej_1(){
   
   int n;
   cout << "Ingrese hasta qué término quiere la serie y la sumatoria" << endl;
   cin >> n;
   
   double serie [n];
   
   int i;
   for (i = 0; i < n; i++){
       serie[i] = obtener_termino(i+1);
   }
   
   double suma = calcular_suma(serie, n);
   
   cout << "La sumatoria es igual a: " << suma << endl;
   
   cout << "La serie es: " << endl;
   
   for (i = 0; i < n; i++){
       cout << serie[i] << " ";
   }
}
