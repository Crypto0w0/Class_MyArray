#include <iostream>
using namespace std;

template<class T>
class MyArray
{
    T* arr;
    int count;
public:
    MyArray();
    MyArray(int size);
    MyArray(const MyArray<T>& mas);

    void Input();
    void Print();
    ~MyArray();
    
    auto operator+(int j);
    auto operator-(int j);
    auto operator++();
    auto operator--();
    auto operator+(const MyArray<T>& mas);
};

template<class T>
auto MyArray<T>::operator+(int j){
    T* newArr = new T[count+j];
    for (int i = 0; i < count+j; i++){
        if (i < count) newArr[i] = arr[i];
        else newArr[i] = 0;
    }
    arr = new T[count+j];
    for (int i = 0; i < count+j; i++){
        arr[i] = newArr[i];
    }
    delete[] newArr;
    count = count+j;
    return this;
}

template<class T>
auto MyArray<T>::operator-(int j){
    T* newArr = new T[count-j];
    for (int i = 0; i < count-j; i++){
        newArr[i] = arr[i];
    }
    arr = newArr->arr;
    count = count - j;
    delete[] newArr;
    return this;
    
}

template<class T>
auto MyArray<T>::operator++(){
    T* newArr = new T[count++];
    for (int i = 0; i < count++; i++){
        if (i < count) newArr[i] = arr[i];
        else newArr[i] = 0;
    }
    arr = newArr->arr;
    count++;
    delete[] newArr;
    return this;
}

template<class T>
auto MyArray<T>::operator--(){
    T* newArr = new T[count--];
    for (int i = 0; i < count--; i++){
        newArr[i] = arr[i];
    }
    arr = newArr->arr;
    count--;
    delete[] newArr;
    return this;
}

template<class T>
auto MyArray<T>::operator+(const MyArray<T>& mas){
    T* newArr = new T[count + mas.count];
    for (int i = 0; i < count + mas.count; i++){
        if (i <= this->count) newArr->arr[i] = this->arr[i];
        else newArr->arr[i] = mas.arr[i];
    }
    this->arr = newArr->arr;
    this->count = newArr->count;
    delete[]  newArr;
    return this;
    
}

template<class T>
MyArray<T>::MyArray(){
    arr = nullptr;
    count = 0;
}

template<class T>
MyArray<T>::MyArray(int size){
    count = size;
    arr = new T[count];
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& obj2){
    count = obj2.count;
    arr = new T[count];
    for (int i = 0; i < count; i++){
        arr[i] = obj2.arr[i];
    }
}

template<class T>
void MyArray<T>::Input(){
    for (int i = 0; i < count; i++){
        arr[i] = rand() % 100*2.5;
    }
}

template<class T>
void MyArray<T>::Print(){
    for (int i = 0; i < count; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

template<class T>
MyArray<T>::~MyArray(){
    delete[]arr;
    count = 0;
}

int main(){
    srand((unsigned)time(0));
    MyArray<int> arrint(5);
    arrint.Input();
    arrint.Print();

    MyArray<double> arrdouble(10);
    arrdouble.Input();
    arrdouble.Print();


    MyArray<char> arrchar(3);
    arrchar.Input();
    arrchar.Print();


}
