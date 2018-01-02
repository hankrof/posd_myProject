#ifndef UTEXP_H
#define UTEXP_H

#include "atom.h"
#include "variable.h"
#include "exp.h"
#include "parser.h"

TEST(Exp, matchExp) {
  Atom tom("tom");
  Variable X("X");
  MatchExp mExp(&tom, &X);
  ASSERT_TRUE(mExp.evaluate());
  ASSERT_EQ("tom", X.value());
}

TEST(Exp, buildExp) {
  Scanner s("tom=X.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_TRUE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildConjunctionExp) {
  Scanner s("Y = 2, Z = 3.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_TRUE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildConjunctionExpFail) {
  Scanner s("Y = 2, 1 = 3.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_FALSE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildDisjunctionExp) {
  Scanner s("X = 1; Y = 2, 1 = 3.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_TRUE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildDisjunctionExpFail) {
  Scanner s("2 = 1; Y = 2, 1 = 3.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_FALSE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildDisjunctionExpSuc1) {
  Scanner s("2 = 1; Y = 2, Z = 3.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_TRUE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildDisjunctionExpSuc2) {
  Scanner s("tom=marry_aasd.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_FALSE(p.getExpressionTree()->evaluate());
}

TEST(Exp, buildDisjunctionExpSuc3) {
  Scanner s("X=1,X=2.");
  Parser p(s);
  p.buildExpression();
  ASSERT_TRUE(p.getExpressionTree());
  ASSERT_FALSE(p.getExpressionTree()->evaluate());
}

#endif
