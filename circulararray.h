#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray(int _capacity = 10);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T& operator[](int);    
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete [] this->array;
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if(this->is_empty()){
        this->front=this->back=0;
    }
    if(this->is_full()){
        throw("Lleno");
    }
    if(this->back=this->capacity-1){
        this->back=0;
    }
    else{
        this->back=this->next(this->back);
    }
    this->array[back]=data;
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if(this->is_empty()){
        this->front=this->back=0;
    }
    if(this->is_full()){
        throw("Lleno");
    }
    else if(this->front=0){
        this->front=this->capacity-1;
    }
    else{
        this->front=this->prev(this->front);
    }
    this->array[this->front]=data;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    //throw("Falta implementar");
    if (this->is_empty())
    {
        return "";
    }
    std::ostringstream oss;
    int i = this->front;
    do
    {
        oss << this->array[i] << sep;
        i = this->next(i);
    } while (i != this->next(this->back));
    return oss.str();
}

template <class T>
void CircularArray<T>::clear()
{
    this->front = this->back = -1;//empty
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if (this->front==-1 && this->back==-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
int CircularArray<T>::size()
{
    if(this->front==this->back==-1){
        return 0;
    }
    else{
        if(this->back>=this->front){
            return (this->back + 1 - this->front);
        }
        else{
            return (this->capacity - this->front + this->back + 1);
        }
    }
}

template <class T>
bool CircularArray<T>::is_full()
{
    if(this->front==0 && this->back==this->capacity-1){
        return true;
    }
    else if(this->back==this->front-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
T CircularArray<T>::pop_back()
{
    if(this->front==-1 && this->back==-1){
        throw("No se puede eliminar");
    }
    T dato=array[this->back];
    if(this->back==this->front){
        this->front = this->back = -1;//empty
    }
    else{
        this->back=prev(this->back);
    }
    return dato;
}

template <class T>
T CircularArray<T>::pop_front()
{
    if(this->front==-1 && this->back==-1){
        throw("No se puede eliminar");
    }
    T data=array[this->front];
    if(this->back==this->front){
        this->front = this->back = -1;//empty
    }
    else{
        this->front=next(this->front);
    }
    return data;

}

template <class T>
int CircularArray<T>::next(int i)
{
    return (i + 1) % this->capacity;
}

template <class T>
int CircularArray<T>::prev(int i)
{
    return (i+this->capacity-1) % this->capacity;
}

template <class T>
void CircularArray<T>::sort()
{
    throw("Falta implementar");
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    throw("Falta implementar");
}

template <class T>
bool CircularArray<T>::is_sorted()
{
    throw("Falta implementar");
}

template <class T>
void CircularArray<T>::reverse()
{
    throw("Falta implementar");
}

template <class T>
T &CircularArray<T>::operator[](int i)
{
    throw("Falta implementar");
}
