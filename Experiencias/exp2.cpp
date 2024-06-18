#include <iostream>
#include <cmath> // Para la función sqrt

using namespace std;

// Clase Ruta que utiliza templates de método
template<typename T>
class Ruta {
private:
    T distancia;
    T tiempoEstimado;

public:
    Ruta(T dist, T tiempo) : distancia(dist), tiempoEstimado(tiempo) {}

    // Método template para asignar vehículos
    template<typename U>
    void asignarVehiculo(U vehiculo) {
        cout << "Asignando vehiculo " << vehiculo << " a la ruta." << endl;
    }

    // Método template para planificación de horarios
    template<typename U, typename V>
    void planificarHorarios(U inicio, U fin, V duracion) {
        cout << "Planificando horarios para la ruta desde " << inicio << " hasta " << fin;
        cout << " con duracion estimada de " << duracion << " horas." << endl;
    }

    // Método para obtener la distancia de la ruta
    T obtenerDistancia() const {
        return distancia;
    }

    // Método para obtener el tiempo estimado de la ruta
    T obtenerTiempoEstimado() const {
        return tiempoEstimado;
    }
};

int main() {
    // Ejemplo de uso con tipo de datos double
    Ruta<double> rutaDouble(150.5, 5.5);
    rutaDouble.asignarVehiculo("Camion");
    rutaDouble.planificarHorarios("08:00", "13:30", 5.5);
    cout << "Distancia de la ruta: " << rutaDouble.obtenerDistancia() << " km" << endl;
    cout << "Tiempo estimado de la ruta: " << rutaDouble.obtenerTiempoEstimado() << " horas" << endl;

    // Ejemplo de uso con tipo de datos int
    Ruta<int> rutaInt(100, 4);
    rutaInt.asignarVehiculo(12345);
    rutaInt.planificarHorarios("09:00", "13:00", 4);
    cout << "Distancia de la ruta: " << rutaInt.obtenerDistancia() << " km" << endl;
    cout << "Tiempo estimado de la ruta: " << rutaInt.obtenerTiempoEstimado() << " horas" << endl;

    return 0;
}
