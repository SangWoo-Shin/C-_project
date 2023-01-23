/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#ifndef Collection_h
#define Collection_h
#include <iostream>
#include <string>
#include <iomanip>

namespace sdds
{
    template <typename T>
    class Collection
    {
    private:
        std::string _name;
        T* _item;
        size_t _size;
        void (*col_obs)(const Collection<T>&, const T&) {nullptr};
    public:
        Collection(const std::string& name)
        {
            _name = name;
            _item = nullptr;
            _size = 0;
        }
        
        const std::string& name() const
        {
            return _name;
        }
        
        size_t size() const
        {
            return _size;
        }
        
        ~Collection()
        {
            if(_item)
            {
                delete[] _item;
                _item = nullptr;
            }
        }
        
        void setObserver(void (*observer)(const Collection<T>&, const T&))
        {
            col_obs = observer;
        }
        
        Collection<T>& operator+=(const T& item)
        {
            for(size_t i = 0; i < _size; i++)
            {
                if(_item[i].title() == item.title())
                {
                    return *this;
                }
            }
            T* tem = new T[_size + 1];
            for(size_t i = 0; i < _size; i++)
            {
                tem[i] = _item[i];
            }
            tem[_size] = item;
            if(_size > 0)
            {
                delete[] _item;
                _item = nullptr;
            }
            _item = tem;
            _size++;
            if(col_obs)
            {
                col_obs(*this, item);
            }
            return *this;
        }
        
        T& operator[](size_t idx) const
        {
            if(idx >= _size)
            {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(_size) + "] items.");
            }
            return _item[idx];
        }
        
        T* operator[](const std::string& title) const
        {
            for(size_t i = 0; i < _size; i++)
            {
                if(_item[i].title() == title)
                {
                    return &_item[i];
                }
            }
            return nullptr;
        }
        
        std::ostream& display(std::ostream& os) const
        {
            for(size_t i = 0; i < _size; i++)
            {
                os << _item[i];
            }
            return os;
        }
        
        friend std::ostream& operator<< (std::ostream& os, const Collection& collection)
        {
            return collection.display(os);
        }
    };

}

#endif /* Collection_h */
