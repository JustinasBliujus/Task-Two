#include <cstddef>
#include <iterator>
template <typename T>
class CustomVector
{
private:
    T *data_;
    size_t size_;
    size_t capacity_;

public:
    // Constructor
    CustomVector() : data_(nullptr), size_(0), capacity_(0) {}

    // Constructor with size and initial value argument
    CustomVector(size_t size, const T &initialValue) : size_(size), capacity_(size)
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = initialValue;
        }
    }

    CustomVector(std::initializer_list<T> values) : size_(values.size()), capacity_(values.size())
    {
        data_ = new T[capacity_];
        size_t i = 0;
        for (const T &value : values)
        {
            data_[i++] = value;
        }
    }
    // Destructor
    ~CustomVector()
    {
        delete[] data_;
    }

    // Copy assignment operator
    CustomVector &operator=(const CustomVector &other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    // Assigns values to the container
    void assign(const T &value, size_t count)
    {
        clear();
        reserve(count);
        for (size_t i = 0; i < count; ++i)
        {
            data_[i] = value;
        }
        size_ = count;
    }

    T &at(size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // Access specified element
    T &operator[](size_t index)
    {
        return data_[index];
    }

    T &front()
    {
        return data_[0];
    }

    T &back()
    {
        return data_[size_ - 1];
    }

    T *data()
    {
        return data_;
    }

    T *begin()
    {
        return data_;
    }

    T *end()
    {
        return data_ + size_;
    }

    // Checks whether the container is empty
    bool empty() const
    {
        return size_ == 0;
    }

    // Returns the number of elements
    size_t size() const
    {
        return size_;
    }

    // Returns the number of elements that can be held in currently allocated storage
    size_t capacity() const
    {
        return capacity_;
    }

    void shrink_to_fit()
    {
        if (size_ < capacity_)
        {
            T *newData = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
            capacity_ = size_;
        }
    }

    void reserve(size_t newCapacity)
    {
        if (newCapacity > capacity_)
        {
            T *newData = new T[newCapacity];
            for (size_t i = 0; i < size_; ++i)
            {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
            capacity_ = newCapacity;
        }
    }

    void clear()
    {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }

    void insert(size_t pos, const T &value)
    {
        if (pos > size_)
        {
            throw std::out_of_range("Index out of range");
        }

        if (size_ == capacity_)
        {
            reserve(size_ == 0 ? 1 : size_ * 2);
        }

        for (size_t i = size_; i > pos; --i)
        {
            data_[i] = data_[i - 1];
        }

        data_[pos] = value;
        ++size_;
    }

    template <typename InputIterator>
    void insert_range(size_t pos, InputIterator first, InputIterator last)
    {
        if (pos > size_)
        {
            throw std::out_of_range("Index out of range");
        }

        size_t count = last - first;
        if (count == 0)
        {
            return;
        }

        size_t newSize = size_ + count;
        if (newSize > capacity_)
        {
            reserve(newSize);
        }

        for (size_t i = size_; i > pos; --i)
        {
            data_[i] = data_[i - count];
        }

        for (size_t i = 0; i < count; ++i)
        {
            data_[pos + i] = *(first + i);
        }

        size_ = newSize;
    }

    void erase(T *first, T *last)
    {
        if (first >= last || first < data_ || last > data_ + size_)
        {
            throw std::out_of_range("Invalid range");
        }

        size_t count = last - first;
        size_t numElementsToMove = size_ - (first - data_) - count;
        for (size_t i = first - data_; i < first - data_ + numElementsToMove; ++i)
        {
            data_[i] = data_[i + count];
        }

        size_ -= count;
    }

    // Adds an element to the end
    void push_back(const T &value)
    {
        if (size_ == capacity_)
        {
            reserve(size_ == 0 ? 1 : size_ * 2);
        }

        data_[size_] = value;
        ++size_;
    }

    // Removes the last element
    void pop_back()
    {
        if (size_ > 0)
        {
            --size_;
        }
    }

    void resize(size_t newSize)
    {
        if (newSize < size_)
        {
            size_ = newSize;
        }
        else if (newSize > size_)
        {
            if (newSize > capacity_)
            {
                reserve(newSize);
            }

            for (size_t i = size_; i < newSize; ++i)
            {
                new (&data_[i]) T();
            }

            size_ = newSize;
        }
    }

    void swap(CustomVector &other)
    {
        T *tempData = data_;
        size_t tempSize = size_;
        size_t tempCapacity = capacity_;

        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = tempData;
        other.size_ = tempSize;
        other.capacity_ = tempCapacity;
    }

    bool operator==(const CustomVector<T> &other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (size_t i = 0; i < size; ++i)
        {
            if ((*this)[i] != other[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const CustomVector<T> &other) const
    {
        return !(*this == other);
    }

    bool operator<(const CustomVector<T> &other) const
    {
        size_t minSize = std::min(size, other.size);
        for (size_t i = 0; i < minSize; ++i)
        {
            if ((*this)[i] < other[i])
            {
                return true;
            }
            else if ((*this)[i] > other[i])
            {
                return false;
            }
        }
        return size < other.size;
    }

    bool operator<=(const CustomVector<T> &other) const
    {
        return !(*this > other);
    }

    bool operator>(const CustomVector<T> &other) const
    {
        return other < *this;
    }

    bool operator>=(const CustomVector<T> &other) const
    {
        return !(*this < other);
    }
};
