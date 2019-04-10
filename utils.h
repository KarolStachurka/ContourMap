#ifndef UTILS_H
#define UTILS_H

#include <vector>

//!  Definition of class Utils.
/*!
  Template class for operations on container
*/
template <class T>
class Utils
{
private:
    /// Field with container for operations
    std::vector<T> container;
public:
    //! Default constructor
        /*!
        */
    Utils();
    //! Constructor:
        /*!
          \param container - container for operations.
        */
    Utils(std::vector<T> container);
    //! Returns element of maximum value in container
        /*!
          \returns max value in container
        */
    T getMaxValue ();
    //! Returns element of minimal value in container
        /*!
          \returns min value in container
        */
    T getMinValue();

};



#endif // UTILS_H
