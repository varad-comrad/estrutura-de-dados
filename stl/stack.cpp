#include <iostream>


using namespace std;

template <typename T>
class stack{
    private:
        size_t cp;
        size_t len;
        T *arr;
    public:
        stack(){
            cp = 20;
            arr = new T[cp];
            len = 0;
        }

        ~stack(){
            delete[] arr;
        }

        stack(const stack& source): len{source.len}, cp{source.cp}{
            arr = new T[cp];
            for(size_t i{}; i < source.len;i++){
                arr[i] = source.arr[i];
            }
        }

        stack(stack&& source): len{source.len}, cp{source.cp}{
            arr = source.arr;
            source.arr = nullptr;
        }

        T top(){
            if(len){
                return arr[len-1];
            } else throw std::length_error("stack is empty");
        }

        T pop(){
            if(len){
                len--;
                return arr[len];
            } else throw std::length_error("stack is empty");
        }

        void push(T element){
            if(len == cp){
                cp *= 2;
                T *aux = new T[cp];
                for(size_t i = 0; i < len; i++) aux[i] = arr[i];
                delete[] arr;
                arr = aux;
            }   
            len++;
            arr[len-1] = element;
        }
        
        size_t capacity(){return cp;}
        
        size_t length(){return len;}

        stack& operator<<(T element){
            this->push(element);
            return *this;
        }

};

int main(){
    stack<int> st;
    st.push(1);
    // cout << st.top() << endl;
    st.push(2);
    st << 3 << 4 << 5;
    cout << st.pop()<< endl;
    cout << st.pop()<< endl;
    cout << st.pop()<< endl;
    cout << st.pop()<< endl;
    return 0;
}