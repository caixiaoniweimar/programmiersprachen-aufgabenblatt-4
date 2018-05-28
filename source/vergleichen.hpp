#ifndef VERGLEICHEN_HPP
#define VERGLEICHEN_HPP
#include "circle.hpp"

class vergleichen {
    public:
    bool operator() (Circle const& r,Circle const& s){ // Funktor
    return ( (r.radius_ > s.radius_) ? true:
            ( (r.radius_ == s.radius_)?
             (r.radius_ > s.radius_) : false ) );
    }
};
#endif
