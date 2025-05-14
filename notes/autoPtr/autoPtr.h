#ifndef AUTOPTR_H
#define AUTOPTR_H

template <class T>
class autoPtr {
   public:
    autoPtr(T *new_ptr = nullptr) : ptr(new_ptr) {}
    ~autoPtr() { delete ptr; }

    T &operator*() { return *ptr; }
    T *operator->() { return ptr; }

   private:
    T *ptr;
};

#endif
