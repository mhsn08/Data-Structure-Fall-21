#include "pch.h"
#include "Header.h"
using namespace std;

using namespace std;

///////////////////Singly LL/////////////////////
TEST(Insert, T1) {
    SLinkedList<int> obj;
    int arr[] = { 0,1,2,3,4,5,6,7 };
    for (int i = 0; i < 8; i++)
    {

        obj.insert(arr[i]);
    }
    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(arr[i], temp->data);
        temp = temp->next;
        i++;
    }

}

TEST(InsertatHead, T2) {
    SLinkedList<int> obj;
    int arr[] = { 0,1,2,3,4 };
    for (int i = 0; i < 5; i++)
    {
        obj.insert(arr[i]);
    }

    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[i]);
        temp = temp->next;
        i++;
    }
    temp = obj.head;
    obj.insertAtHead(66);
    EXPECT_EQ(66, obj.head->data);
    temp = obj.head->next;
    int j = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[j]);
        temp = temp->next;
        j++;
    }
}

TEST(InsertAtIndex, T3) {
    int arr[] = { 0,1,2,3 };
    SLinkedList<int> obj1;
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr[i]);
    }
    Node <int>* temp = obj1.head;
    int j = 0;
    obj1.InsertAtIndex(5, 4); // InsertAtIndex(5 is the value to be inserted, 4 is the Index.no);
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[j]);
        temp = temp->next;
        j++;
    }
}

TEST(Search, T4) {

    SLinkedList<int> obj1;
    for (int i = 0; i < 3; i++)
    {
        obj1.insert(i);
    }
    EXPECT_EQ(2, obj1.search(2));
    ASSERT_NE(3, obj1.search(2));
}


TEST(Update, T5) {
    SLinkedList<int> obj;
    for (int i = 0; i < 5; i++)
    {

        obj.insert(i);
    }
    obj.update(3, 67);
    Node<int>* temp = obj.head;
    int i = 0;
    int arr[] = { 0,1,2,67,4 };
    while (temp->next != NULL) {
        EXPECT_EQ(arr[i], temp->data);
        temp = temp->next;
        i++;
    }

}
TEST(Delete, T6) {
    SLinkedList<int> obj;

    for (int i = 0; i < 5; i++)
    {
        obj.insert(i);
    }
    obj.remove(3);
    int arr[] = { 0,1,2,4 };
    obj.print();
    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[i]);
        temp = temp->next;
        i++;
    }
}

////////////////////q2/////////////////////
TEST(mergeList, T1) {
    SLinkedList<int> obj1, obj2;
    int arr1[] = { 1,3,5,7 };
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr1[i]);
    }

    int arr2[] = { 2,4,6,8 };
    for (int i = 0; i < 4; i++)
    {
        obj2.insert(arr2[i]);
    }

    obj1.mergeLists(obj2);
    int arr3[] = { 1,2,3,4,5,6,7,8 };

    Node<int>* temp = obj1.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr3[i]);
        temp = temp->next;
        i++;
    }

    obj1.print();
}

////////////////////Doubly LL////////////
linkList<string, int> obj;
string id = "01";
string c = "45678-4535676-0";
string j = "18/10/2021";
int k = 50000;
int b = 5000;
string id2 = "02";
string c2 = "45778-4535676-0";
string j2 = "18/10/2020";
int k2 = 10000;
int b2 = 5000;
string id3 = "03";
string c3 = "45878-4535676-0";
string j3 = "18/10/2019";
int k3 = 20000;
int b3 = 5000;
TEST(Insert, T1) {
    obj.insert(id, c, j, k, b);
    node<string, int>* emp = new node<string, int>(id, c, j, k, b);
    EXPECT_EQ(emp->getId(), "01");
    EXPECT_EQ(emp->getCNIC(), "45678-4535676-0");
    EXPECT_EQ(emp->getJoinDate(), "18/10/2021");
    EXPECT_EQ(emp->getSal(), 50000);
    EXPECT_EQ(emp->getBonus(), 5000);
}

TEST(InsertAfterSearch, T1) {
    node<string, int>* s = obj.search("01");
    cout << s->getId();
    EXPECT_EQ("01", s->getId());

}
TEST(Remove, T1) {
    linkList<string, int> obj;
    string chk = "01";
    ASSERT_TRUE(true, obj.remove(chk));
    string chk1 = "02";
    ASSERT_FALSE(false, obj.remove(chk1));
}

TEST(Update, T1) {
    obj.insert(id, c, j, k, b);
    string i = "01";
    EXPECT_EQ(100000, obj.UpdateSalary(i, 100000));
}

TEST(Max, T1) {
    obj.insert(id2, c2, j2, k2, b2);
    obj.insert(id3, c3, j3, k3, b3);
    int a = obj.MaxSalary();
    EXPECT_EQ(100000, a);
}