#pragma once

#include <utility>

template <class ContainerType>
class ReverseIterator
{
public:
    ReverseIterator(ContainerType &container) :
        mContainer(container) {}

    auto begin()
    {
        return std::reverse_iterator(mContainer.end());
    }

    auto end()
    {
        return std::reverse_iterator(mContainer.begin());
    }

private:
    ContainerType &mContainer;
};

/*
template <class ContainerType>
auto operator~(ContainerType &container)
    -> decltype(std::declval<ContainerType &>().begin(), std::declval<ContainerType &>().end(), ReverseIterator<ContainerType>(container))
{
    return ReverseIterator<ContainerType>(container);
}
*/

// for (auto& data : ~container)
template <class ContainerType>
    requires requires(ContainerType p) { p.begin(); p.end(); }
ReverseIterator<ContainerType> operator~(ContainerType &container)
{
    return ReverseIterator<ContainerType>(container);
}
