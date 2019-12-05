#ifndef STACK_H
#define STACK_H

template <typename T>
class stack
{
public:
    stack(int size = 10);
    stack(stack<T> &);
    ~stack();
    void push(T value);
    T pop();
    int getTop();
    int getSize();
    T getPtr();
private:
T *ptr;
int size;
int top;
};

template <typename T>
stack<T>::stack(int size)
{
  this->ptr=new T[size];
  this->top=0;
}
template <typename T>
stack<T>::stack(stack<T> & otherst)
{
    size=otherst.getSize();
    top=otherst.getTop();
    ptr=new T[size];
    for(int i=0;i<size;i++)
       ptr[i]=otherst.getPtr()[i];
}
template <typename T>
stack<T>::~stack()
{
    delete[] ptr;
}
template <typename T>
void stack<T>::push(T value)
{
    ptr[top++]=value;
}

template <typename T>
T stack<T>::pop()
{
  //T temp;
  //temp=ptr[top];
  //ptr[--top];
  return ptr[top--];
}
template <typename T>
int stack<T>::getTop()
{
 return top;
};
template <typename T>
int stack<T>::getSize()
{
 return size;
};
template <typename T>
T stack<T>::getPtr()
{
 return ptr;
};

#endif // STACK_H
