#include "include/Sort.h"
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
