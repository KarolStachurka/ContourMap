#include "utils.h"

template<typename T>
Utils<T>::Utils()
{

}

template<typename T>
Utils<T>::Utils(std::vector<T> container)
{
    this->container = container;
}


template <class T>
T Utils<T>::getMaxValue()
{
    T first = this->container.begin();
    T last = this-container.end();
    if (first == last)
    {
        return last;
    }

    T largest = first;
    ++first;
    for (; first != last; ++first)
    {
        if (*largest < *first)
        {
            largest = first;
        }
    }
    return largest;
}

template <class T>
T Utils<T>::getMinValue()
{
    T first = this->container.begin();
    T last = this-container.end();
    if (first == last)
    {
        return last;
    }

    T lowest = first;
    ++first;
    for (; first != last; ++first)
    {
        if (*lowest > *first)
        {
            lowest = first;
        }
    }
    return lowest;
}
