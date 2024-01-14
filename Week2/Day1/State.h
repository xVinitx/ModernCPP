#ifndef STATE_H
#define STATE_H

#include <vector>
#include <array>
#include <functional>
class State
{
private:
    std::array<int, 3> _data;    
    std::array<FnType, 3> _functions;
public:
    State() = default;
    State(std::array<int, 3>&& data, const std :: array<FnType, 3>& functions);
    ~State() = default;    
    
    int operator()(int );
};

#endif // STATE_H
