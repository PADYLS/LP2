#include <iostream>
#include <string>
using namespace std;

class Tienda{
    string TipoTienda, nombre, direccion;
    int stock;

    //contructor
    public:
    Tienda(string t, string n, string d,int s):TipoTienda(t),nombre(n),direccion(d),stock(s){}

    //venta producto
    void venderP(){
        if (stock>0){
            stock--;
            cout<<"Se ha vendido un producto en la tienda "<<nombre<<"\nStock restante: "<<stock<<endl;
        }else{
            cout<<"No se puede vender producto en "<<nombre<<" porque no hay stock."<<endl;
        }
    };

    void agregarP(int cantidad){
        stock += cantidad;
        cout<<"Se agregaron "<<cantidad<< " productos a "<<nombre<<"\nStock actual: "<<stock<<" unidades."<<endl;
    };
};
int main(){
    Tienda t1("Tienda de electronicos","compuTienda","Narnia",20);
    Tienda t2("Tienda de ropa","RopaRota Store","Marte",15);

    //ventas y agregar 
    t1.venderP();
    t1.agregarP(10);
    t1.venderP();
    t2.venderP();

    return 0;
};