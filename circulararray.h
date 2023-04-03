#include <iostream>
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
void CircularArray<T>::clear()
{
    this->front = this->back = -1;//empty
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if (this->front=-1 && this->back=-1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
int CircularArray<T>::size()
{
    if(this->is_empty=true){
        return 0;
    }
    else{
        if(this->back>=this->front){
            return (this->back + 1 - this->front);
        }
        else{
            return (this->capacity - this->front + this->back + 1);;
        }
    }
}

template <class T>
bool CircularArray<T>::is_full()
{
    if(this->capacity==this->size){
        return true;
    }
    else{
        return false;
    }
}


template <class T>
T CircularArray<T>::pop_back()
{
    if(this->is_empty=true){
        return 0;
    }
    else{
            this->back=this->back-1;
            this->size=this->size-1;
    }
}

template <class T>
T CircularArray<T>::pop_front()
{
    if(this->is_empty=true){
        return 0;
    }
    else{
            this->front=this->front-1;
            this->size=this->size-1;
    }
}

template <class T>
void CircularArray<T>::sort()
{

}

template <class T>
bool CircularArray<T>::is_sorted()
{

}