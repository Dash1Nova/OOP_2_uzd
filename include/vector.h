#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t newCapacity) {
        T* newData = new T[newCapacity];

        for(size_t i = 0; i < size_; i++)
        {
            newData[i] = data_[i];
        }

        delete[] data_;

        data_ = newData;
        capacity_ = newCapacity;
    }

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

    size_t size() const {
        return size_;
    }

    void push_back(const T& value) {
        if(size_ >= capacity_) {
            size_t newCapacity;
            if (capacity_ == 0) { newCapacity = 1; }
            else { newCapacity = capacity_ * 2; }
            reallocate(newCapacity);
        }

        data_[size_] = value;
        size_++;
    }

    void insert(size_t index, const T& value) {
        if(index > size_)
        {
            throw std::out_of_range("Index out of range");
        }

        if(size_ >= capacity_)
        {
            size_t newCapacity;
            if (capacity_ == 0) { newCapacity = 1; }
            else { newCapacity = capacity_ * 2; }
            reallocate(newCapacity);
        }

        for(size_t i = size_; i > index; i--)
        {
            data_[i] = data_[i - 1];
        }

        data_[index] = value;
        size_++;
    }

    void pop_back()
    {
        if(size_ > 0)
        {
            size_--;
        }
    }



};

#endif