#include <iostream>
using namespace std;

int main()
{
    string restart;
    do
    {
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        cout << " \n";
        cout << "Buenas tardes inge, me llamo Walter Benjamín Vaquera Reyes y estoy cursando el tercer semestre de la carrera\n";
        cout << "'ingeniería en tecnologías de la informacíon y seguridad'.\n";
        cout << " \n";
        cout << "nací el 17 de junio del 2003 en Sucre, fuí criado por una familia cariñosa de cuatro integrantes, actualmente vivo\n";
        cout << "con mi madre y mi hermano. Comencé a estudiar en el kinder Vaca Guzman a una edad de 3 años (creo), lo único que\n";
        cout << "recuerdo es haberme mordido la lengua y ser mordido en la mano por un perro, aunque según mi madre, aveces era\n";
        cout << "castigado por quitarles el cuaderno a mis compañeros y hacerles las tareas que no entendian.\n";
        cout << " \n";
        cout << "más adelante ingresé al colegio Don Bosco, el mismo lugar donde estudió mi hermano. Al principio alcancé buenas\n";
        cout << "notas gracias al apoyo de mi madre, no hice muchas amistades y me daba miedo lo grande que era el colegio en\n";
        cout << "comparación a mi kinder; años más tarde conocí a varios amigos, siempre jugábamos y reíamos mucho, fue desde ahí\n";
        cout << "que empecé a relacionarme más con mis compañeros, descubrir nuevos intereses y nuevos problemas.\n";
        cout << " \n";
        cout << "Los últimos años de mi vida colegial participé en varias actividades y viajes, conocí muchas personas importantes\n";
        cout << "para mí, desarrollé algo de ansiedad, bajaron mis notas, tube algunas relaciones románticas y todas salieron mal,\n";
        cout << "muchas cosas cambiaron y continuan cambiando en mi entorno, pero a pesar del distanciamiento social y el cambio\n";
        cout << "de etapa entre el colegio y la universidad, siempre he contado con la compañía de mis amigos y mi familia.\n";
        cout << " \n";
        cout << "para volver a imprimir la bibliografía escriba 'r', para terminar el programa ingrese cualquier otra letra\n";
        cout << " \n";
        cin >> restart;
        cout << " \n";
    } while (restart == "r");
}
