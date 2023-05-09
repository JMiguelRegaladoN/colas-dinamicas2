#include <iostream>
//Juan Miguel Regalado Nuño
/*
En la Direccion escolar de una escuela se reciben solicitudes de constancias de estudio de los
alumnos. Cada constancia lleva el nombre del alumno, nombre de la carrera que cursa, total de
materias aprobadas y promedio general.
*/
class Constancia{
private:
    std::string nombre;
    std::string carrera;
    int materias_apro;
    float promedio;
public:
    persona(){};
    friend std::ostream & operator<<(std::ostream &O, Constancia &x){
            O<< "----------------------------------------------------------------------------------------------------------------------------------------"<< std::endl 
				<< "						       Constancia de Estudios" << std::endl<< std::endl <<"A QUIEN CORRESPONDA: " << std::endl
            	<< "El que suscribe (Nombre del rector), Rector de la escuela CENTRO UNIVERSITARIO DE CIENCIAS EXACTAS E INGENIERIAS" << std::endl << std::endl
            	<< "      							 HACE CONSTAR" << std::endl << std::endl
            	<< "Que el alumno(a) "<<x.nombre <<" de este plantel esta inscrito(a) en la carrera "<<x.carrera<<" durante el ciclo escolar 2023A"<< std::endl
				<<"comprendido del 15 de enero al 10 de junio del 2023, Con un promedio de "<<x.promedio<<" y un numero de "<<x.materias_apro<<" materias aprobadas"<< std::endl
				<<"A peticion del interesado y para fines legales que le convengan," << std::endl <<"se extiende la presente en la ciudad de Guadalajara, Jalisco a los 10 dias del mes de Marzo del 2023. " << std::endl << std::endl 
              <<"----------------------------------------------------------------------------------------------------------------------------------------"<< std::endl << std::endl; 
			return O;
    }
    friend std::istream & operator>>(std::istream &O, Constancia &x){
            std::cout<<"Digite los datos: "<< std::endl;
			std::cout<<"Digite su Nombre: "; 
			O.ignore();
            getline(O,x.nombre);
            std::cout<<"Digite la Carrera: ";
            getline(O,x.carrera);
            std::cout<<"Digite las Materias aprobadas: ";
            O>>x.materias_apro;
            std::cout<<"Digite su Promedio: ";
            O>>x.promedio;
            std::cout << std::endl;
            return O;
    }
    bool operator == (std::string x){
		if(nombre == x){
			return true;
		}    	
		else{
			return false;
		}
	}
};

template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(nullptr){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->data;
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int main()
{
    Cola<Constancia> Cola;
    Constancia Alumno;
    int salir = 0;
    do{
    	int opc;
    	std::cout << "Menu para crear constancias \n\n" 
    		<< "1) Peticion de constancias \n2) Hacer una constancia (Primera en la fila) \n3) Salir\n";
    	std::cout << "Digite un numero: ";
    	std::cin >> opc;
    	std::cout << std::endl;
    	switch(opc){
    		case 1:
    			std::cin>>Alumno;
    			Cola.Enqueue(Alumno);
    			break;
    		case 2:
    			Alumno = Cola.Front();
    			std::cout<<Alumno;
    			Cola.Dequeue();
    			break;
    		case 3:
    			salir = 1;
    			break;
    		default:
    			std::cout << "El Dato es invalido \n\n";
    			break;
		}
	}
	while(salir == 0);
    return 0;
}
