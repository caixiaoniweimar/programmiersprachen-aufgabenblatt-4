#ifndef COLOR_HPP
#define COLOR_HPP
#include <algorithm>
using namespace std;

//Aufgabe 2.7
struct  Color
{
	float r=0.0f;
	float h=0.0f;
	float g=0.0f;
	
	Color(float rhg):
		r{rhg},
		h{rhg},
		g{rhg} {
			rhg=min(rhg, 1.0f) || max(rhg, 0.0f);  // 0.5 || 0.5 -> true -> 1.0
// !!!!!!!!!!!!! Unterschied: min(rhg, 00.f) || max(rhg, 1.0f) 
		}
	Color(float r1, float h1, float g1):
		r{r1},
		h{h1},
		g{g1}  {
            r=min(r, 1.0f) || max(r, 0.0f); // r = std::max(0.0, std::min(r, 1.0));
			h=min(h, 1.0f) || max(h, 0.0f);
			g=min(g, 1.0f) || max(g, 0.0f);
		}
};

#endif

/*
float temp          = std::min(r, 1.0);
r             = std::max(0.0, temp);  // -5 < 0 < 5

[-inf, inf] -> [0.0, 1.0]

     if r > 1.0 -> 1.0
else if r < 0.0 -> 0.0
else            ->  r
*/
