#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include <iterator>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

/* Lets Assume Graph G is:

         1
      2__|__3
   4__|__5

Depth First Traversals: 
Inorder (Left, Root, Right) : 4 2 5 1 3 
Preorder (Root, Left, Right) : 1 2 4 5 3 
Postorder (Left, Right, Root) : 4 5 2 3 1
*/
TEST_CASE("Float/Double Tree Build")
{
    BinaryTree<float> floatTree;
    CHECK_THROWS(floatTree.add_left(5.0, 10.0));  // NO ROOT TO ADD
    CHECK_THROWS(floatTree.add_right(5.0, 10.0)); // NO ROOT TO ADD
    CHECK_NOTHROW(floatTree.add_root(2.0));       // Should not throw - Valid Root Addition
    CHECK_NOTHROW(floatTree.add_root(3.0));       // Should not throw - Allow Override
    CHECK_THROWS(floatTree.add_left(5.0, 8.0));   // Should Throw - No Parent
    CHECK_THROWS(floatTree.add_right(5.0, 10.0)); // Should Throw - No Parent
    // Valid Additions - Nothing Should Throw
    CHECK_NOTHROW(floatTree.add_left(3.0, 4.0));
    CHECK_NOTHROW(floatTree.add_right(3.0, 6.0));
    CHECK_NOTHROW(floatTree.add_left(4.0, 7.0));
    CHECK_NOTHROW(floatTree.add_right(4.0, 1.0));
}
TEST_CASE("Int Tree Build")
{
    BinaryTree<int> intTree;
    CHECK_THROWS(intTree.add_left(5, 10));  // NO ROOT TO ADD
    CHECK_THROWS(intTree.add_right(5, 10)); // NO ROOT TO ADD
    CHECK_NOTHROW(intTree.add_root(2));     // Should not throw - Valid Root Addition
    CHECK_NOTHROW(intTree.add_root(3));     // Should not throw - Allow Override
    CHECK_THROWS(intTree.add_left(5, 8));   // Should Throw - No Parent
    CHECK_THROWS(intTree.add_right(5, 8));  // Should Throw - No Parent
    // Valid Additions - Nothing Should Throw
    CHECK_NOTHROW(intTree.add_left(3, 4));
    CHECK_NOTHROW(intTree.add_right(3, 6));
    CHECK_NOTHROW(intTree.add_left(4, 7));
    CHECK_NOTHROW(intTree.add_right(4, 1));
}
TEST_CASE("String Tree Build")
{
    BinaryTree<string> tree_of_strings;

    BinaryTree<string> stringTree;
    CHECK_THROWS(stringTree.add_left("5", "10"));  // NO ROOT TO ADD
    CHECK_THROWS(stringTree.add_right("5", "10")); // NO ROOT TO ADD
    CHECK_NOTHROW(stringTree.add_root("2"));       // Should not throw - Valid Root Addition
    CHECK_NOTHROW(stringTree.add_root("3"));       // Should not throw - Allow Override
    CHECK_THROWS(stringTree.add_left("5", "8"));   // Should Throw - No Parent
    CHECK_THROWS(stringTree.add_right("5", "8"));  // Should Throw - No Parent
    // Valid Additions - Nothing Should Throw
    CHECK_NOTHROW(stringTree.add_left("3", " 4"));
    CHECK_NOTHROW(stringTree.add_right("3", "6"));
    CHECK_NOTHROW(stringTree.add_left("4", "7"));
    CHECK_NOTHROW(stringTree.add_right("4", "1"));
}

TEST_CASE("BinaryTree - Char")
{
    BinaryTree<char> charTree;
    CHECK_THROWS(charTree.add_left('5', '5'));  // NO ROOT TO ADD
    CHECK_THROWS(charTree.add_right('5', '5')); // NO ROOT TO ADD
    CHECK_NOTHROW(charTree.add_root('2'));       // Should not throw - Valid Root Addition
    CHECK_NOTHROW(charTree.add_root('3'));       // Should not throw - Allow Override
    CHECK_THROWS(charTree.add_left('5', '8'));   // Should Throw - No "1" To Add 9
    CHECK_THROWS(charTree.add_right('5', '8'));  // Should Throw - No "1" To Add 9
    // Valid Additions - Nothing Should Throw
    CHECK_NOTHROW(charTree.add_left('3', '4'));
    CHECK_NOTHROW(charTree.add_right('3', '6'));
    CHECK_NOTHROW(charTree.add_left('4', '7'));
    CHECK_NOTHROW(charTree.add_right('4', '1'));
}

TEST_CASE("Tree Scan - Print - Operators")
{
    BinaryTree<char> charTree;
    // Valid Graph
    CHECK_NOTHROW(charTree.add_root('3'));
    CHECK_NOTHROW(charTree.add_left('3', '4'));
    CHECK_NOTHROW(charTree.add_right('3', '6'));
    CHECK_NOTHROW(charTree.add_left('4', '7'));
    CHECK_NOTHROW(charTree.add_right('4', '1'));

    BinaryTree<string> stringTree;
    // Valid Graph
    CHECK_NOTHROW(stringTree.add_root("3"));
    CHECK_NOTHROW(stringTree.add_left("3", " 4"));
    CHECK_NOTHROW(stringTree.add_right("3", "6"));
    CHECK_NOTHROW(stringTree.add_left("4", "7"));
    CHECK_NOTHROW(stringTree.add_right("4", "1"));
    CHECK_NOTHROW(cout << stringTree << endl;);

    BinaryTree<int> intTree;
    // Valid Graph
    CHECK_NOTHROW(intTree.add_root(3));
    CHECK_NOTHROW(intTree.add_left(3, 4));
    CHECK_NOTHROW(intTree.add_right(3, 6));
    CHECK_NOTHROW(intTree.add_left(4, 7));
    CHECK_NOTHROW(intTree.add_right(4, 1));

    BinaryTree<float> floatTree;
    // Valid Graph
    CHECK_NOTHROW(floatTree.add_root(3.0));
    CHECK_NOTHROW(floatTree.add_left(3.0, 4.0));
    CHECK_NOTHROW(floatTree.add_right(3.0, 6.0));
    CHECK_NOTHROW(floatTree.add_left(4.0, 7.0));
    CHECK_NOTHROW(floatTree.add_right(4.0, 1.0));

    // Char Pre + Post + IN
    char charpreOrder[] = {'7', '4', '1', '3', '6'};
    char charinOrder[] = {'3', '4', '7', '1', '6'};
    char charpostOrder[] = {'7', '1', '4', '6', '3'};

    // String Pre + Post + IN
    string strpreOrder[] = {"7", "4", "1", "3", "6"};
    string strinOrder[] = {"3", "4", "7", "1", "6"};
    string strpostOrder[] = {"7", "1", "4", "6", "3"};

    // Int Pre + Post + IN
    int intpreOrder[] = {7, 4, 1, 3, 6};
    int intinOrder[] = {3, 4, 7, 1, 6};
    int intpostOrder[] = {7, 1, 4, 6, 3};

    // Int Pre + Post + IN
    float floatpreOrder[] = {7.0, 4.0, 1.0, 3.0, 6.0};
    float floatinOrder[] = {3.0, 4.0, 7.0, 1.0, 6.0};
    float floatpostOrder[] = {7.0, 1.0, 4.0, 6.0, 3.0};

    // Check Valid Prints - Should not Throw
    CHECK_NOTHROW(cout << intTree << endl;);
    CHECK_NOTHROW(cout << floatTree << endl;);
    CHECK_NOTHROW(cout << stringTree << endl;);
    CHECK_NOTHROW(cout << charTree << endl;);

    //Logic: I shall use ForEach And Execute a Tree Scan - Then I Compare With Premade Arrays the Output
    // Arrays are Above
    // Scans Below:

    // CHAR SCAN CHECK
    int arayCounter = 0;
    for (auto it = charTree.begin_preorder(); it != charTree.end_preorder(); ++it)
    {
        CHECK_EQ((*it), charpreOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = charTree.begin_postorder(); it != charTree.end_postorder(); ++it)
    {
        CHECK_EQ((*it), charpostOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = charTree.begin_inorder(); it != charTree.end_inorder(); ++it)
    {
        CHECK_EQ((*it), charinOrder[arayCounter]);
        arayCounter++;
    }
    // String Scan Check
    arayCounter = 0;
    for (auto it = stringTree.begin_preorder(); it != stringTree.end_preorder(); ++it)
    {
        CHECK_EQ((*it), strpreOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = stringTree.begin_postorder(); it != stringTree.end_postorder(); ++it)
    {
        CHECK_EQ((*it), strpostOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = stringTree.begin_inorder(); it != stringTree.end_inorder(); ++it)
    {
        CHECK_EQ((*it), strinOrder[arayCounter]);
        arayCounter++;
    }
    // Float Scan Check
    arayCounter = 0;
    for (auto it = floatTree.begin_preorder(); it != floatTree.end_preorder(); ++it)
    {
        CHECK_EQ((*it), floatpreOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = floatTree.begin_postorder(); it != floatTree.end_postorder(); ++it)
    {
        CHECK_EQ((*it), floatpostOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = floatTree.begin_inorder(); it != floatTree.end_inorder(); ++it)
    {
        CHECK_EQ((*it), floatinOrder[arayCounter]);
        arayCounter++;
    }

    // Int Scan Check
    arayCounter = 0;
    for (auto it = intTree.begin_preorder(); it != intTree.end_preorder(); ++it)
    {
        CHECK_EQ((*it), intpreOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = intTree.begin_postorder(); it != intTree.end_postorder(); ++it)
    {
        CHECK_EQ((*it), intpostOrder[arayCounter]);
        arayCounter++;
    }

    arayCounter = 0;
    for (auto it = intTree.begin_inorder(); it != intTree.end_inorder(); ++it)
    {
        CHECK_EQ((*it), intinOrder[arayCounter]);
        arayCounter++;
    }
}