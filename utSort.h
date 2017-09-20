#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <iostream>
using std::cout;
using std::endl;
TEST (Sort, sortByIncreasingPerimeter)
{
    std::list<Shape *> shapeList;
    
    //Rectangle Perimeter = 2 * 10 + 2 * 10       = 40
    //Circle    Perimeter = 2 * 3.14159 * 5       = 31.42
    //Triangle  Perimeter = 2 + sqrt(2) + sqrt(2) = 4.828 
    //
    //            Perimeter:    4.828     31.42     40
    //The order should be like Triangle, Circle, Rectangle in increasing.
    
    Rectangle rect(0,0,10,10); 
    Circle    cir(0,0,5);
    Triangle  tri(vertex{-1.0,0.0},vertex{1.0,0.0},vertex{0.0,1.0});
  
    shapeList.push_back(&tri);
    shapeList.push_back(&rect);
    shapeList.push_back(&cir);

    Sort::sortByIncreasingPerimeter(&shapeList);
    auto iter = shapeList.begin();
    ASSERT_EQ(tri.toString() ,(*iter)->toString());
    iter++;
    ASSERT_EQ(cir.toString() ,(*iter)->toString());
    iter++;
    ASSERT_EQ(rect.toString(),(*iter)->toString());
}

TEST (Sort, sortByDecreasingPerimeter) 
{
    std::list<Shape *> shapeList;
    
    //Rectangle Perimeter = 2 * 10 + 2 * 10       = 40
    //Circle    Perimeter = 2 * 3.14159 * 5       = 31.42
    //Triangle  Perimeter = 2 + sqrt(2) + sqrt(2) = 4.828 
    //
    //            Perimeter:     40       31.42     4.828
    //The order should be like Rectangle, Circle, Triangle in decreasing.
    
    Rectangle rect(0,0,10,10); 
    Circle cir(0,0,5);
    Triangle tri(vertex{-1.0,0.0},vertex{1.0,0.0},vertex{0.0,1.0});

    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
    shapeList.push_back(&tri);

    Sort::sortByDecreasingPerimeter(&shapeList);

    auto iter = shapeList.begin();
    ASSERT_EQ(rect.toString(),(*iter)->toString());
    iter++;
    ASSERT_EQ(cir.toString() ,(*iter)->toString());
    iter++;
    ASSERT_EQ(tri.toString() ,(*iter)->toString());
}


TEST (Sort, sortByIncreasingArea) 
{
    std::list<Shape *> shapeList;
    
    //Rectangle Area = 5  * 5                =    25
    //Circle    Area = 3.14159 * 5^2         = 78.53
    //Triangle  Area =                      ~=     1 
    //
    //            Area:            1       25       78.52
    //The order should be like Triangle, Rectangle, Circle in increasing.
    
    Rectangle rect(0,0, 5, 5); 
    Circle cir(0,0,5);
    Triangle tri(vertex{-1.0,0.0},vertex{1.0,0.0},vertex{0.0,1.0});

    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
    shapeList.push_back(&tri);

    Sort::sortByIncreasingArea(&shapeList);

    auto iter = shapeList.begin();

    ASSERT_EQ(tri.toString() ,(*iter)->toString());
    iter++;
    ASSERT_EQ(rect.toString(),(*iter)->toString());
    iter++;
    ASSERT_EQ(cir.toString() ,(*iter)->toString());

}

TEST (Sort, sortByDecreasingArea) 
{
    std::list<Shape *> shapeList;
    
    //Rectangle Area = 5  * 5                =    25
    //Circle    Area = 3.14159 * 5^2         = 78.53
    //Triangle  Area =                      ~=     1 
    //
    //            Area:         78.53     25         1  
    //The order should be like Circle, Rectangle, Triangle in increasing.
    
    Rectangle rect(0,0, 5, 5); 
    Circle cir(0,0,5);
    Triangle tri(vertex{-1.0,0.0},vertex{1.0,0.0},vertex{0.0,1.0});

    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
    shapeList.push_back(&tri);

    Sort::sortByDecreasingArea(&shapeList);

    auto iter = shapeList.begin();

    ASSERT_EQ(cir.toString() ,(*iter)->toString());
    iter++;
    ASSERT_EQ(rect.toString(),(*iter)->toString());
    iter++;
    ASSERT_EQ(tri.toString() ,(*iter)->toString());
}
TEST (Sort, sortByIncreasingCompactness)
{
    std::list<Shape *> shapeList;
   
    //Compactness = Area / Perimeter
    //
    //Rectangle Compactness = 5 * 5 / 20 = 0.8
    //Circle    Compactness =
    //          3.14159 * 25 / 2 * 3.14159 * 5 = 2.5
    //Triangle  Compactness = 0.207
    //            Compactness    0.207     0.8        2.5
    //The order should be like Triangle, Rectangle, Circle in increasing.
    
    Rectangle rect(0,0, 5, 5); 
    Circle cir(0,0,5);
    Triangle tri(vertex{-1.0,0.0},vertex{1.0,0.0},vertex{0.0,1.0});

    shapeList.push_back(&rect);
    shapeList.push_back(&cir);
    shapeList.push_back(&tri);

    Sort::sortByIncreasingCompactness(&shapeList);

    auto iter = shapeList.begin();

    ASSERT_EQ(tri.toString() ,(*iter)->toString());
    iter++;
    ASSERT_EQ(rect.toString(),(*iter)->toString());
    iter++;
    ASSERT_EQ(cir.toString() ,(*iter)->toString());
}
#endif
