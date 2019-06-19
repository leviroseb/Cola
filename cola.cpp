#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v, nodo *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    int valor;
    nodo *siguiente;

   friend class cola;
};


class cola {
   public:
    cola() : primero(NULL), ultimo(NULL) {}
    void Anadir(int v);
    int quitar();

   private:
    nodo *primero;
    nodo *ultimo;
};

void cola::Anadir(int v)
{
   nodo *nuevo;
   nuevo = new nodo(v);
   if(ultimo) ultimo->siguiente = nuevo;
   ultimo = nuevo;
   if(!primero) primero = nuevo;
}

int cola::quitar()
{
   nodo *nodo;
   int v;
   nodo = primero;
   if(!nodo) return 0;
   primero = nodo->siguiente;
   v = nodo->valor;
   delete nodo;
   if(!primero) ultimo = NULL;
   return v;
}

int main()
{
   cola Cola;

   Cola.Anadir(20);
   Cola.Anadir(10);
   cout << Cola.quitar() << endl;
   Cola.Anadir(40);
   Cola.Anadir(30);
   cout << Cola.quitar() << endl;
   cout << Cola.quitar() << endl;
   Cola.Anadir(90);
   cout <<Cola.quitar() << endl;
   return 0;
}

