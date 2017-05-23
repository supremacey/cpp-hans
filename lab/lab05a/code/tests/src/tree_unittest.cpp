#include "../../src/tree.h"
#include "../../src/string.h"
#include "gtest/gtest.h"


//TEST(TreeTest, CopyConstr)
//{
	//tree t1 { string{"Drzewo"} };
	//tree t2 = t1;
	//EXPECT_EQ(t1, t2);
//}

TEST(TreeTest, Functor)
{
	string s{"Drzewo"};
	tree t1 { string{"Drzewo"} };
	EXPECT_EQ(s, t1.functor());
}

TEST(TreeTest, SubtreesNumber)
{
	tree t1 { string{"Drzewo"} };
	tree t2 { string{"Drzewko"} };
	tree t3{ string{"Lasek"}, {t1,t2}};
	ASSERT_EQ(2, t3.nrsubtrees());
}

TEST(TreeTest, RandomAccess)
{
	tree t1 { string{"Drzewo"} };
	tree t2 { string{"Drzewko"} };
	tree t3{ string{"Lasek"}, {t1,t2}};
	ASSERT_EQ(t3[0].functor(), t1.functor());
	ASSERT_EQ(t3[1].functor(), t2.functor());
}

TEST(TreeTest, FunctorNotSharing)
{
	tree t1 { string{"Drzewo"} };
	tree t2 = t1;
	ASSERT_EQ(t1.functor(), t2.functor());

	t2.functor() = string{"Drzewko"};
	ASSERT_NE(t1.functor(), t2.functor());
}

TEST(TreeTest, AccessNotSharing)
{
	tree t1 { string{"Drzewo"} };
	tree t2 { string{"Drzewko"} };
	tree t3{ string{"Lasek"}, {t1,t2}};

	t3[0] = tree{ string{"Sosna"} };
	ASSERT_NE(t1.functor(), t3[0].functor());
	ASSERT_EQ(t2.functor(), t3[1].functor());

}
