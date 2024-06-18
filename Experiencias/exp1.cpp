#include <iostream>
#include <cmath> // Para la función sqrt

using namespace std;

// Template de función para calcular la distancia entre dos puntos
template<typename T>
T calcularDistancia(T x1, T y1, T x2, T y2) {
    T dx = x2 - x1; // Calcular la diferencia en coordenadas x
    T dy = y2 - y1; // Calcular la diferencia en coordenadas y
    T distancia = sqrt(dx * dx + dy * dy); // Calcular la distancia euclidiana
    return distancia; // Devolver la distancia calculada
}

// Función template para generar un informe de entrega
template<typename T>
void generarInforme(T x1, T y1, T x2, T y2) {
    T distancia = calcularDistancia(x1, y1, x2, y2); // Calcular la distancia entre los puntos
    cout << "Informe de entrega:" << endl;
    cout << "-------------------" << endl;
    cout << "Coordenadas del punto inicial: (" << x1 << ", " << y1 << ")" << endl; // Mostrar coordenadas del punto inicial
    cout << "Coordenadas del punto final: (" << x2 << ", " << y2 << ")" << endl; // Mostrar coordenadas del punto final
    cout << "Distancia recorrida: " << distancia << endl; // Mostrar la distancia calculada
}

int main() {
    int opcion;
    do {
        // Mostrar menú de opciones
        cout << "Menu:" << endl;
        cout << "1. Calcular distancia entre dos puntos (double)" << endl;
        cout << "2. Calcular distancia entre dos puntos (int)" << endl;
        cout << "3. Generar informe de entrega (double)" << endl;
        cout << "4. Generar informe de entrega (int)" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese opción: ";
        cin >> opcion; // Leer la opción del usuario

        switch (opcion) {
            case 1: {
                // Calcular distancia entre dos puntos (double)
                double x1, y1, x2, y2;
                cout << "Ingrese las coordenadas del punto inicial (x y): ";
                cin >> x1 >> y1; // Leer las coordenadas del punto inicial
                cout << "Ingrese las coordenadas del punto final (x y): ";
                cin >> x2 >> y2; // Leer las coordenadas del punto final
                double distanciaDouble = calcularDistancia(x1, y1, x2, y2); // Calcular la distancia para tipo double
                cout << "Distancia (double): " << distanciaDouble << endl; // Mostrar la distancia calculada
                break;
            }
            case 2: {
                // Calcular distancia entre dos puntos (int)
                int x1, y1, x2, y2;
                cout << "Ingrese las coordenadas del punto inicial (x y): ";
                cin >> x1 >> y1; // Leer las coordenadas del punto inicial
                cout << "Ingrese las coordenadas del punto final (x y): ";
                cin >> x2 >> y2; // Leer las coordenadas del punto final
                int distanciaInt = calcularDistancia(x1, y1, x2, y2); // Calcular la distancia para tipo int
                cout << "Distancia (int): " << distanciaInt << endl; // Mostrar la distancia calculada
                break;
            }
            case 3: {
                // Generar informe de entrega (double)
                double x1, y1, x2, y2;
                cout << "Ingrese las coordenadas del punto inicial (x y): ";
                cin >> x1 >> y1; // Leer las coordenadas del punto inicial
                cout << "Ingrese las coordenadas del punto final (x y): ";
                cin >> x2 >> y2; // Leer las coordenadas del punto final
                generarInforme(x1, y1, x2, y2); // Generar y mostrar informe de entrega para tipo double
                break;
            }
            case 4: {
                // Generar informe de entrega (int)
                int x1, y1, x2, y2;
                cout << "Ingrese las coordenadas del punto inicial (x y): ";
                cin >> x1 >> y1; // Leer las coordenadas del punto inicial
                cout << "Ingrese las coordenadas del punto final (x y): ";
                cin >> x2 >> y2; // Leer las coordenadas del punto final
                generarInforme(x1, y1, x2, y2); // Generar y mostrar informe de entrega para tipo int
                break;
            }
            case 0:
                cout << "Saliendo del programa..." << endl; // Mensaje de salida del programa
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl; // Mensaje por opción inválida
                break;
        }

    } while (opcion != 0); // Repetir el ciclo hasta que el usuario elija salir

    return 0;
}
