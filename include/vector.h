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

    
    T& operator[](size_t index) { return data_[index]; }
    
    const T& operator[](size_t index) const { return data_[index]; }
    
    T& at(size_t index) {
        if (index >= size_) { throw std::out_of_range("Index out of range"); }
        return data_[index];
    }
    
    const T& at(size_t index) const {
        if (index >= size_) { throw std::out_of_range("Index out of range"); }
        return data_[index];
    }
    
    size_t size() const { return size_; }
    
    void pop_back()
    {
        if(size_ > 0)
        {
            size_--;
        }
    }

    T* begin() { return data_; }

    T* end() { return data_ + size_; }

    void erase(size_t index) {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }

        for (size_t i = index; i < size_ - 1; i++)
        {
            data_[i] = data_[i + 1];
        }

        size_--;
    }

    bool empty() const { return size_ == 0; }

    size_t capacity() const { return capacity_; }

    void reserve(size_t newCapacity) {
        if (newCapacity > capacity_)
        {
            reallocate(newCapacity);
        }
    }

    void resize(size_t newSize) {
        if (newSize > capacity_)
        {
            size_t newCapacity;

            if (capacity_ == 0)
            {
                newCapacity = 1;
            }
            else
            {
                newCapacity = capacity_;
            }

            while (newCapacity < newSize)
            {
                newCapacity *= 2;
            }

            reallocate(newCapacity);
        }

        for (size_t i = size_; i < newSize; i++)
        {
            data_[i] = T();
        }

        size_ = newSize;
    }

};

#endif