#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    Vector()
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    ~Vector()
    {
        delete[] data_;
    }

    void push_back(const T& value)
    {
    }

    size_t size() const
    {
        return size_;
    }
};

#endif