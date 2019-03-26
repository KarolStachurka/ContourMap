#ifndef UTILS_H
#define UTILS_H

#include <vector>

template <class T>
class Utils
{
private:
    std::vector<T> container;
public:
    Utils();
    Utils(std::vector<T> container);
    T getMaxValue ();

    T getMinValue();

};
template <class T>
T getPositionInRange(T min, T max, T element){
    T range = max - min;
    return (element - min)/range;
}


#endif // UTILS_H
