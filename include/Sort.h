#include <list>
#include "Shapes.h"

class Sort 
{
public:
    static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);
    static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);
    static void sortByIncreasingArea(std::list<Shape *> * shapeList);
    static void sortByDecreasingArea(std::list<Shape *> * shapeList);
    static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);
  
};
void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList)
{
    shapeList->sort(
            [&](Shape const *a,Shape const *b) -> bool
            {
               return a->perimeter() < b->perimeter(); 
            }
            );
}
void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
{
    shapeList->sort(
            [&](Shape const *a,Shape const *b) -> bool
            {
               return a->perimeter() > b->perimeter(); 
            }
            );
}
void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList)
{
    shapeList->sort(
            [&](Shape const *a,Shape const *b) -> bool
            {
               return a->area() < b->area(); 
            }
            );
}
void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList)
{
    shapeList->sort(
            [&](Shape const *a,Shape const *b) -> bool
            {
               return a->area() > b->area(); 
            }
            );
}
void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList)
{
    shapeList->sort(
            [&](Shape const *a,Shape const *b) -> bool
            {
               return a->compactness() < b->compactness(); 
            }
            );
}
