#ifndef UTTERM_H
#define UTTERM_H
#include <gtest/gtest.h>
#include "number.h"
#include "atom.h"
//test Number.value()
TEST (Number,ctor)
{
    Number x("10");
    ASSERT_EQ(10,x.value());
}
//test Number.symbol()
TEST (Number, symbol)
{
    Number x("10");
    ASSERT_EQ("10",x.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess)
{
    Number x("25"),y("25");
    ASSERT_TRUE(x.match(y));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue)
{
    Number x("25"),y("0");
    ASSERT_FALSE(x.match(y));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant)
{
    Atom tom("tom");
    Number x("25");
    ASSERT_FALSE(tom.match(x));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar)
{
    Number x("25");
    Variable X("X");
    ASSERT_TRUE(x.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant)
{
    Atom tom("tom");
    Number x("25");
    ASSERT_FALSE(tom.match(x));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar)
{
    Atom tom("tom");
    Variable X("X");
    tom.match(X);
    ASSERT_EQ(X.value(),tom.symbol());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant)
{
    Variable X("X");
    Atom tom("tom");
    ASSERT_TRUE(X.match(tom) && tom.match(X));
    ASSERT_EQ(X.value(),tom.symbol());
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant)
{
    Variable X("X");
    Atom tom("tom");
    Atom jerry("jerry");
    ASSERT_FALSE(X.match(jerry) && tom.match(X));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber)
{
    Variable X("X");
    Number x("5");
    ASSERT_TRUE(X.match(x));
    ASSERT_EQ(X.value(),x.symbol());
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers)
{
    Variable X("X");
    Number x("5");
    Number y("100");
    ASSERT_FALSE(X.match(x) && X.match(y));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber)
{
    Variable X("X");
    Atom tom("tom");
    Number x("25");
    ASSERT_FALSE(X.match(tom) && X.match(x));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2)
{
    Variable X("X");
    Atom tom("tom");
    Number x("25");
    ASSERT_FALSE(tom.match(X) && x.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom)
{
    Variable X("X");
    Atom tom("tom");
    ASSERT_TRUE(X.match(tom) && X.match(tom));
}
#endif
