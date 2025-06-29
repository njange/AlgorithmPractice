#include "setlst.hpp"

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/dictionary.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"

#include "../../../zlasdtest/set/set.hpp"
#include "../../../list/list.hpp"
#include "../../../vector/vector.hpp"

namespace zmytest {

void zMyTestSetLstInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<int> set;
    InsertC(testnum, testerr, set, true, 4);
    InsertC(testnum, testerr, set, true, 5);
    InsertC(testnum, testerr, set, true, 2);
    InsertC(testnum, testerr, set, true, 6);
    InsertC(testnum, testerr, set, true, 1);
    InsertC(testnum, testerr, set, true, 3);
    InsertC(testnum, testerr, set, false, 2);
    InsertC(testnum, testerr, set, false, 3);
    InsertC(testnum, testerr, set, false, 6);
    InsertC(testnum, testerr, set, false, 1);

    Remove(testnum, testerr, set, true, 4);
    Min(testnum, testerr, set, true, 1);
    Max(testnum, testerr, set, true, 6);
    Predecessor(testnum, testerr, set, true, 3, 2);
    Successor(testnum, testerr, set, true, 3, 5);
    Predecessor(testnum, testerr, set, false, 1, 0);

    Exists(testnum, testerr, set, true, 3);
    Exists(testnum, testerr, set, false, 4);

    MinNRemove(testnum, testerr, set, true, 1);
    MaxNRemove(testnum, testerr, set, true, 6);
    Min(testnum, testerr, set, true, 2); // Verify Min changed
    Max(testnum, testerr, set, true, 5); // Verify Max changed

    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3); // Verify Min changed
    Max(testnum, testerr, set, true, 3); // Verify Max changed

    InsertC(testnum, testerr, set, true, 1);
    InsertC(testnum, testerr, set, true, 5);
    InsertC(testnum, testerr, set, true, 2);
    InsertC(testnum, testerr, set, true, 7);

    PredecessorNRemove(testnum, testerr, set, true, 3, 2);
    SuccessorNRemove(testnum, testerr, set, true, 3, 5);

    RemovePredecessor(testnum, testerr, set, true,7);
    RemoveSuccessor(testnum, testerr, set, true, 1);

    GetAt(testnum, testerr, set, true, 0, 1);
    GetAt(testnum, testerr, set, false,1, 7);

    lasd::SetLst<int> set2;
    InsertC(testnum, testerr, set2, true, 1);
    InsertC(testnum, testerr, set2, true, 7);
    InsertC(testnum, testerr, set, true, 7);
    EqualSetLst(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, 9);
    EqualSetLst(testnum, testerr, set, set2, false);

    lasd::SetLst<int> setCopy(set);
    EqualSetLst(testnum, testerr, set, setCopy, true);

    lasd::SetLst<int> setMove(std::move(setCopy));
    EqualSetLst(testnum, testerr, set, setMove, true);

    lasd::SetLst<int> setCopyAssign;
    setCopyAssign = set;
    EqualSetLst(testnum, testerr, set, setCopyAssign, true);

    lasd::SetLst<int> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetLst(testnum, testerr, set, setMoveAssign, true);

    set.Clear();
    Min(testnum, testerr, set, false, 0); // Should fail as set is empty

    lasd::Vector<int> vec(5);
    vec[0] = 10;
    vec[1] = 30;
    vec[2] = 20;
    vec[3] = 30;
    vec[4] = 40;

    const lasd::SetLst<int> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4); // Should have 4 elements (no duplicates)
    Exists(testnum, testerr, setFromVec, true, 10);
    Exists(testnum, testerr, setFromVec, true, 20);
    Exists(testnum, testerr, setFromVec, true, 30);
    Exists(testnum, testerr, setFromVec, true, 40);
}

void zMyTestSetLstDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<double> set;
    InsertC(testnum, testerr, set, true, 4.5);
    InsertC(testnum, testerr, set, true, 5.2);
    InsertC(testnum, testerr, set, true, 2.1);
    InsertC(testnum, testerr, set, true, 6.7);
    InsertC(testnum, testerr, set, true, 1.3);
    InsertC(testnum, testerr, set, true, 3.9);
    InsertC(testnum, testerr, set, false, 2.1);
    InsertC(testnum, testerr, set, false, 3.9);
    InsertC(testnum, testerr, set, false, 6.7);
    InsertC(testnum, testerr, set, false, 1.3);

    Remove(testnum, testerr, set, true, 4.5);
    Min(testnum, testerr, set, true, 1.3);
    Max(testnum, testerr, set, true, 6.7);
    Predecessor(testnum, testerr, set, true, 3.9, 2.1);
    Successor(testnum, testerr, set, true, 3.9, 5.2);
    Predecessor(testnum, testerr, set, false, 1.3, 0.0);

    Exists(testnum, testerr, set, true, 3.9);
    Exists(testnum, testerr, set, false, 4.5);

    MinNRemove(testnum, testerr, set, true, 1.3);
    MaxNRemove(testnum, testerr, set, true, 6.7);
    Min(testnum, testerr, set, true, 2.1); // Verify Min changed
    Max(testnum, testerr, set, true, 5.2); // Verify Max changed

    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3.9); // Verify Min changed
    Max(testnum, testerr, set, true, 3.9); // Verify Max changed

    InsertC(testnum, testerr, set, true, 1.3);
    InsertC(testnum, testerr, set, true, 5.2);
    InsertC(testnum, testerr, set, true, 2.1);
    InsertC(testnum, testerr, set, true, 7.8);

    PredecessorNRemove(testnum, testerr, set, true, 3.9, 2.1);
    SuccessorNRemove(testnum, testerr, set, true, 3.9, 5.2);

    RemovePredecessor(testnum, testerr, set, true, 7.8);
    RemoveSuccessor(testnum, testerr, set, true, 1.3);

    GetAt(testnum, testerr, set, true, 0, 1.3);
    GetAt(testnum, testerr, set, false, 1, 7.8);

    lasd::SetLst<double> set2;
    InsertC(testnum, testerr, set2, true, 1.3);
    InsertC(testnum, testerr, set2, true, 7.8);
    InsertC(testnum, testerr, set, true, 7.8);
    EqualSetLst(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, 9.9);
    EqualSetLst(testnum, testerr, set, set2, false);

    lasd::SetLst<double> setCopy(set);
    EqualSetLst(testnum, testerr, set, setCopy, true);

    lasd::SetLst<double> setMove(std::move(setCopy));
    EqualSetLst(testnum, testerr, set, setMove, true);

    lasd::SetLst<double> setCopyAssign;
    setCopyAssign = set;
    EqualSetLst(testnum, testerr, set, setCopyAssign, true);

    lasd::SetLst<double> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetLst(testnum, testerr, set, setMoveAssign, true);

    set.Clear();
    Min(testnum, testerr, set, false, 0.0); // Should fail as set is empty

    lasd::Vector<double> vec(5);
    vec[0] = 10.1;
    vec[1] = 30.3;
    vec[2] = 20.2;
    vec[3] = 30.3;
    vec[4] = 40.4;

    const lasd::SetLst<double> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4); // Should have 4 elements (no duplicates)
    Exists(testnum, testerr, setFromVec, true, 10.1);
    Exists(testnum, testerr, setFromVec, true, 20.2);
    Exists(testnum, testerr, setFromVec, true, 30.3);
    Exists(testnum, testerr, setFromVec, true, 40.4);
}

void zMyTestSetLstString(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<std::string> set;
    InsertC(testnum, testerr, set, true, std::string("Alpha"));
    InsertC(testnum, testerr, set, true, std::string("Beta"));
    InsertC(testnum, testerr, set, true, std::string("Gamma"));
    InsertC(testnum, testerr, set, true, std::string("Delta"));
    InsertC(testnum, testerr, set, true, std::string("Epsilon"));
    InsertC(testnum, testerr, set, false, std::string("Alpha"));
    InsertC(testnum, testerr, set, false, std::string("Beta"));

    Remove(testnum, testerr, set, true, std::string("Gamma"));
    Min(testnum, testerr, set, true, std::string("Alpha"));
    Max(testnum, testerr, set, true, std::string("Epsilon"));
    Predecessor(testnum, testerr, set, true, std::string("Delta"), std::string("Beta"));
    Successor(testnum, testerr, set, true, std::string("Beta"), std::string("Delta"));
    Predecessor(testnum, testerr, set, false, std::string("Alpha"), std::string(""));

    Exists(testnum, testerr, set, true, std::string("Delta"));
    Exists(testnum, testerr, set, false, std::string("Gamma"));

    MinNRemove(testnum, testerr, set, true, std::string("Alpha"));
    MaxNRemove(testnum, testerr, set, true, std::string("Epsilon"));
    Min(testnum, testerr, set, true, std::string("Beta"));
    Max(testnum, testerr, set, true, std::string("Delta"));

    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, false, std::string("Delta"));
    Max(testnum, testerr, set, false, std::string("Delta"));

    InsertC(testnum, testerr, set, true, std::string("Alpha"));
    InsertC(testnum, testerr, set, true, std::string("Epsilon"));
    InsertC(testnum, testerr, set, true, std::string("Beta"));
    InsertC(testnum, testerr, set, true, std::string("Zeta"));

    PredecessorNRemove(testnum, testerr, set, true, std::string("Delta"), std::string("Beta"));
    SuccessorNRemove(testnum, testerr, set, true, std::string("Delta"), std::string("Epsilon"));

    RemovePredecessor(testnum, testerr, set, true, std::string("Zeta"));
    RemoveSuccessor(testnum, testerr, set, true, std::string("Alpha"));

    GetAt(testnum, testerr, set, false, 0, std::string("Alpha"));
    GetAt(testnum, testerr, set, false, 1, std::string("Zeta"));

    lasd::SetLst<std::string> set2;
    InsertC(testnum, testerr, set2, true, std::string("Alpha"));
    InsertC(testnum, testerr, set, true, std::string("Alpha"));
    InsertC(testnum, testerr, set2, true, std::string("Zeta"));
    InsertC(testnum, testerr, set, true, std::string("Zeta"));
    EqualSetLst(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, std::string("Omega"));
    EqualSetLst(testnum, testerr, set, set2, false);

    lasd::SetLst<std::string> setCopy(set);
    EqualSetLst(testnum, testerr, set, setCopy, true);

    lasd::SetLst<std::string> setMove(std::move(setCopy));
    EqualSetLst(testnum, testerr, set, setMove, true);

    lasd::SetLst<std::string> setCopyAssign;
    setCopyAssign = set;
    EqualSetLst(testnum, testerr, set, setCopyAssign, true);

    lasd::SetLst<std::string> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetLst(testnum, testerr, set, setMoveAssign, true);

    set.Clear();
    Min(testnum, testerr, set, false, std::string(""));

    lasd::Vector<std::string> vec(5);
    vec[0] = std::string("Alpha");
    vec[1] = std::string("Gamma");
    vec[2] = std::string("Beta");
    vec[3] = std::string("Gamma");
    vec[4] = std::string("Delta");

    const lasd::SetLst<std::string> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4);
    Exists(testnum, testerr, setFromVec, true, std::string("Alpha"));
    Exists(testnum, testerr, setFromVec, true, std::string("Beta"));
    Exists(testnum, testerr, setFromVec, true, std::string("Gamma"));
    Exists(testnum, testerr, setFromVec, true, std::string("Delta"));
}

void zMyTestSetLst(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test SetLst Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing SetLst<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetLstInt(testnum, testerr);
    std::cout << "Integer set tests completed" << std::endl;

    std::cout << "\n[Test 1] Testing SetLst<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetLstDouble(testnum, testerr);
    std::cout << "Double set tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing SetLst<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetLstString(testnum, testerr);
    std::cout << "String set tests completed" << std::endl;

    std::cout << "\nAll set tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

}
