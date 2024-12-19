
#include <gtest/gtest.h>
#include "library_code.h" 
#include <tuple>

// Fixture 클래스 정의 (1)트리가 생성만 되고 비어있는 경우
class AVLTreeTestFixture_Empty : public ::testing::Test
{
public:
    void SetUp() override;
    void TearDown() override;
    AVLTreeTestFixture_Empty();
    virtual ~AVLTreeTestFixture_Empty();

protected:
    AVLTree tree; // AVLTree 객체 사용
};

// Fixture 클래스 생성자
AVLTreeTestFixture_Empty::AVLTreeTestFixture_Empty()
{
    std::cout << "AVLTreeTestFixture_Empty Constructor called\n";
}

AVLTreeTestFixture_Empty::~AVLTreeTestFixture_Empty()
{
    std::cout << "AVLTreeTestFixture_Empty Destructor called\n";
}

void AVLTreeTestFixture_Empty::SetUp()
{
    std::cout << "Setup called\n";
}

void AVLTreeTestFixture_Empty::TearDown()
{
    std::cout << "Teardown called\n";
}

// Fixture 클래스 정의 (2)노드가 3개인 포화이진트리
class AVLTreeTestFixture_3node : public ::testing::Test
{
public:
    void SetUp() override;
    void TearDown() override;
    AVLTreeTestFixture_3node();
    virtual ~AVLTreeTestFixture_3node();

protected:
    AVLTree tree; // AVLTree 객체 사용
};

AVLTreeTestFixture_3node::AVLTreeTestFixture_3node()
{
    std::cout << "AVLTreeTestFixture_3node Constructor called\n";
}
AVLTreeTestFixture_3node::~AVLTreeTestFixture_3node()
{
    std::cout << "AVLTreeTestFixture_3node Destructor called\n";
}
void AVLTreeTestFixture_3node::SetUp()
{
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30);
    std::cout << "Setup called\n";
}

void AVLTreeTestFixture_3node::TearDown()
{
    std::cout << "Teardown called\n";
}
/*
            20
         /   \
       10     30
*/

// Fixture 클래스 정의 (3)노드가 7개인 포화 이진 트리
class UtilityTestFixture_7node : public ::testing::Test {
public:
void SetUp() override;
void TearDown() override;
UtilityTestFixture_7node();
virtual ~UtilityTestFixture_7node();

protected:
    AVLTree tree; // AVLTree 객체 사용
    Utility util; // Utility 객체 사용
};

// Fixture 클래스 생성자 
UtilityTestFixture_7node::UtilityTestFixture_7node() {
    std::cout << "UtilityTestFixture_7node_7node Constructor called\n";
}

// Fixture 클래스 소멸자
UtilityTestFixture_7node::~UtilityTestFixture_7node() {
    std::cout << "UtilityTestFixture_7node_7node Destructor called\n";
}

void UtilityTestFixture_7node::SetUp() {
    std::cout << "Setup called\n";

    // 노드 추가 (초기 트리 구성)
    tree.Insert(50);
    tree.Insert(25);
    tree.Insert(15);
    tree.Insert(35);
    tree.Insert(75);
    tree.Insert(65);
    tree.Insert(80);
}

// 트리를 비움 
void UtilityTestFixture_7node::TearDown() {
    std::cout << "Teardown called\n";
}
/*
           50
         /   \
       25     75
      /  \    / \
    15   35  65  80
*/


// **Utility 1번 테스트** 생성자와 소멸자 테스트
TEST(UtilityTest, ConstructorAndDestructor) {
    {
        Utility utility;  // 생성자 호출
    }  // 소멸자 호출
}

// AVLTree 생성자/소멸자자 Test
TEST_F(AVLTreeTestFixture_Empty, Constructor)
{
    EXPECT_EQ(tree.Empty(), 1);   // 비어 있는 상태 확인
    EXPECT_EQ(tree.Height(), -1); // 트리의 높이 확인
    EXPECT_EQ(tree.Size(), 0);    // 트리의 크기 확인
} // 소멸자 호출

// Find 함수 Test
TEST_F(AVLTreeTestFixture_3node, Find_NoExist)
{                                // Case 1: 트리에 없는 노드의 키 값 입력
    EXPECT_EQ(tree.Find(40), 0); // 0 반환
}

TEST_F(AVLTreeTestFixture_3node, Find_Exist)
{                                // Case 2: 트리에 존재하는 노드의 키 값 입력
    EXPECT_EQ(tree.Find(30), 2); // Height(1) + Depth(1) = 2
}

class AVLTreeTestFixture_Param : public testing::TestWithParam<std::tuple<int, int>>
{
protected:
    AVLTree tree;

    void SetUp() override
    {
        tree.Insert(10);
        tree.Insert(20);
        tree.Insert(30);
        tree.Insert(35);
        tree.Insert(50);
    }
};

INSTANTIATE_TEST_CASE_P(
    FindTests, AVLTreeTestFixture_Param,
    testing::Values(
        std::make_tuple(10, 2), // 존재하는 값
        std::make_tuple(20, 3), // 존재하는 값
        std::make_tuple(30, 3), // 존재하는 값
        std::make_tuple(5, 0),  // 존재하지 않는 값
        std::make_tuple(40, 0)  // 존재하지 않는 값
        ));

TEST_P(AVLTreeTestFixture_Param, TestFind)
{
    std::tuple<int, int> param = GetParam();
    int key = std::get<0>(param);
    int expected_value = std::get<1>(param);

    // 트리에서 값 찾기
    int result = tree.Find(key);

    // 디버깅 출력
    std::cout << "Testing key = " << key << ", Expected = " << expected_value
              << ", Result = " << result << '\n';

    // 값 확인
    ASSERT_EQ(expected_value, result);
}

// Insert 함수 Test
TEST_F(AVLTreeTestFixture_3node, Insert)
{                                  // Case 1: 트리에 없는 노드 키 삽입
    EXPECT_EQ(tree.Insert(25), 3); // 예상: 높이(1) + 깊이(2) = 3
}

// Empty 함수 Test
TEST_F(AVLTreeTestFixture_Empty, Empty_Empty)
{ // Case 1: 트리가 비어있을 때
    EXPECT_EQ(tree.Empty(), 1);
}

TEST_F(AVLTreeTestFixture_3node, Empty_NoEmpty)
{ // Case 2: 트리가 비어있지 않을 때
    EXPECT_EQ(tree.Empty(), 0);
}

// Height 함수 Test
TEST_F(AVLTreeTestFixture_Empty, Height_Empty)
{                                 // Case 1: 비어있는 트리의 높이 확인
    EXPECT_EQ(tree.Height(), -1); // 트리가 비었을 시 -1 반환환
}

TEST_F(AVLTreeTestFixture_3node, Height_NoEmpty)
{                                // Case 2: 여러 노드를 가진 트리의 높이 확인
    EXPECT_EQ(tree.Height(), 2); // 트리의 높이: 2
}

// Size 함수 Test
TEST_F(AVLTreeTestFixture_Empty, Size_Empty)
{                              // Case 1: 비어있는 트리에서 Size 호출
    EXPECT_EQ(tree.Size(), 0); // 트리의 크기 : 9
}

TEST_F(AVLTreeTestFixture_3node, Size_NoEmpty)
{                              // Case 2: 여러 노드가 있는 트리에서 Size 호출
    EXPECT_EQ(tree.Size(), 3); // 트리의 크기 : 3
}

// Average 함수 Test
TEST_F(AVLTreeTestFixture_3node, Average_SingleNode)
{ // Case 1: 단일 노드
    testing::internal::CaptureStdout();
    tree.Average(30);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "30\n"); // 최소값과 최대값이 같으므로 평균도 30
}

TEST_F(AVLTreeTestFixture_3node, Average_NormalSubtree)
{ // Case 2: 양쪽 자식이 있는는 서브트리
    testing::internal::CaptureStdout();
    tree.Average(20);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "20\n"); // 최소값 10, 최대값 30 -> 20
}

TEST_F(AVLTreeTestFixture_3node, Average_LeftOnly)
{                   // Case 3: 왼쪽 자식만 있는 경우
    tree.Insert(5); // 10의 왼쪽 자식 추가
    testing::internal::CaptureStdout();
    tree.Average(10);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "7\n"); // 최소값 5, 최대값 10 -> 7
}

TEST_F(AVLTreeTestFixture_3node, Average_RightOnly)
{                    // Case 4: 오른쪽 자식만 있는 경우
    tree.Insert(35); // 30의 왼쪽 자식 추가
    testing::internal::CaptureStdout();
    tree.Average(30);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "32\n"); // 최소값 30, 최대값 35 -> 32
}

// Ancestor 함수 Test
TEST_F(AVLTreeTestFixture_3node, Ancestor_RootNode)
{ // Case 1: 루트 노드 입력
    testing::internal::CaptureStdout();
    tree.Ancestor(20);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 0\n"); // Height(1) + Depth(1) = 1, 조상 합 = 0
}

TEST_F(AVLTreeTestFixture_3node, Ancestor_LeftChild)
{ // Case 2: 루트의 왼쪽 자식 입력
    testing::internal::CaptureStdout();
    tree.Ancestor(10);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 20\n"); // Height(1) + Depth(1) = 1, 조상 합 = 20
}

TEST_F(AVLTreeTestFixture_3node, Ancestor_RightChild)
{ // Case 3: 루트의 오른쪽 자식 입력
    testing::internal::CaptureStdout();
    tree.Ancestor(30);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 20\n"); // Height(1) + Depth(1) = 2, 조상 합 = 20
}

TEST_F(AVLTreeTestFixture_3node, Ancestor_DeepLeftChild)
{                   // Case 4: 더 깊은 자식 입력
    tree.Insert(5); // 10의 왼쪽 자식 추가
    testing::internal::CaptureStdout();
    tree.Ancestor(5);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3 30\n"); // Height(1) + Depth(2) = 3, 조상 합 = 10 + 20 = 30
}

// Rank 함수 Test
TEST_F(AVLTreeTestFixture_3node, Rank_NoExist)
{
    testing::internal::CaptureStdout();
    tree.Rank(40);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0\n"); // 트리에 없는 값은 0 출력
}

TEST_F(AVLTreeTestFixture_3node, Rank_Exist)
{
    testing::internal::CaptureStdout();
    tree.Rank(20);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 2\n"); // 20은 set에서 2번쨰로 작은 수, 높이(2) + 깊이(0) = 2
}

// Erase 함수 Test
TEST_F(AVLTreeTestFixture_3node, Erase_NoExist)
{ // Case 1: 트리에 없는 노드의 키 값을 삭제하려고 할 때
    testing::internal::CaptureStdout();
    tree.Erase(40); // 트리에 없는 노드 40을 삭제하려 할 때
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0\n"); // 0출력력
}

TEST_F(AVLTreeTestFixture_3node, Erase_Exist)
{ // Case 2: 노드를 삭제 / 높이와 깊이의 합 출력
    testing::internal::CaptureStdout();
    tree.Erase(20); // 트리에 존재하는 노드 20을 삭제

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2\n");    // 높이(2) + 깊이(0) = 2
    EXPECT_EQ(tree.Find(20), 0); // 20 노드는 찾을 수 없음
}

// InsertNode 함수 Test (private 함수여서 접근할 수 없어서 Insert로 간접적으로로 진행)
TEST_F(AVLTreeTestFixture_Empty, InsertNode_Empty)
{                    // Case 1: 빈 트리에 삽입입
    tree.Insert(20); // 20삽입 높(1) + 깊(0) = 1
    ASSERT_EQ(tree.Find(20), 1);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_LeftSubtree)
{                    // Case 2: 왼쪽 서브트리에 삽입입
    tree.Insert(20); // 20삽입 높(1) + 깊(0) = 1
    tree.Insert(10); // 10삽입 높(1) + 깊(1) = 2
    ASSERT_EQ(tree.Find(10), 2);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_RightSubtree)
{                    // Case 3: 왼쪽 서브트리에 삽입입
    tree.Insert(20); // 20삽입 높(1) + 깊(0) = 1
    tree.Insert(30); // 30삽입 높(1) + 깊(1) = 2
    ASSERT_EQ(tree.Find(30), 2);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_NoRotate)
{                    // Case 4: 왼쪽 자식 노드 추가, 균형 유지, 회전X
    tree.Insert(20); // 20삽입 높(1) + 깊(0) = 1
    tree.Insert(10); // 10삽입 높(1) + 깊(1) = 2
    tree.Insert(30); // 30삽입 높(1) + 깊(1) = 2
    tree.Insert(5);  // 5삽입 높(1) + 깊(2) = 3
    ASSERT_EQ(tree.Find(5), 3);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_LeftRotate)
{                    // Case 5: LeftRotate
    tree.Insert(30); // 30삽입 높(1) + 깊(0) = 1
    tree.Insert(20); // 20삽입 높(1) + 깊(1) = 2
    tree.Insert(10); // 10삽입 -> L회전 높(1) + 깊(1) = 2
    ASSERT_EQ(tree.Find(10), 2);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_RightRotate)
{                    // Case 6: RightRotate
    tree.Insert(10); // 10삽입 높(1) + 깊(0) = 1
    tree.Insert(20); // 20삽입 높(1) + 깊(1) = 2
    tree.Insert(30); // 30삽입 -> R회전 높(1) + 깊(1) = 2
    ASSERT_EQ(tree.Find(30), 2);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_LeftRightRotate)
{                    // Case 7: Left and RightRotate
    tree.Insert(20); // 20삽입 높(1) + 깊(0) = 1
    tree.Insert(10); // 10삽입 높(1) + 깊(1) = 2
    tree.Insert(15); // 15삽입 -> LR회전 높(2) + 깊(0) = 2
    ASSERT_EQ(tree.Find(15), 2);
}

TEST_F(AVLTreeTestFixture_Empty, InsertNode_RightLeftRotate)
{                    // Case 8: Right and LeftRotate
    tree.Insert(20); // 20삽입 높(1) + 깊(0) = 1
    tree.Insert(30); // 30삽입 높(1) + 깊(1) = 2
    tree.Insert(25); // 25삽입 -> RL회전 높(2) + 깊(0) = 2
    ASSERT_EQ(tree.Find(25), 2);
}

// DeleteNode 함수 Test (Erase 함수로 간접 테스트)
//  Case 1: 단일 노드 삭제 (루트 노드)
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_SingleNode)
{
    tree.Insert(20);
    ASSERT_EQ(tree.Find(20), 1); // 삭제 전: 존재 확인
    tree.Erase(20);
    ASSERT_EQ(tree.Find(20), 0); // 삭제 후: 존재하지 않음
}

// Case 2: 왼쪽 자식이 있는 노드 삭제
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_LeftChild)
{
    tree.Insert(20);
    tree.Insert(10);
    ASSERT_EQ(tree.Find(20), 2);
    ASSERT_EQ(tree.Find(10), 2);

    tree.Erase(10); // 왼쪽 자식 노드 삭제
    ASSERT_EQ(tree.Find(10), 0);
    ASSERT_EQ(tree.Find(20), 1);
}

// Case 3: 오른쪽 자식이 있는 노드 삭제
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_RightChild)
{
    tree.Insert(20);
    tree.Insert(30);
    ASSERT_EQ(tree.Find(20), 2);
    ASSERT_EQ(tree.Find(30), 2);

    tree.Erase(30); // 오른쪽 자식 노드 삭제
    ASSERT_EQ(tree.Find(30), 0);
    ASSERT_EQ(tree.Find(20), 1);
}

// Case 4: 두 자식이 있는 노드 삭제
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_TwoChildren)
{
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30);
    ASSERT_EQ(tree.Find(20), 2);
    ASSERT_EQ(tree.Find(10), 2);
    ASSERT_EQ(tree.Find(30), 2);

    tree.Erase(20); // 두 자식이 있는 노드 삭제
    ASSERT_EQ(tree.Find(20), 0);
    ASSERT_EQ(tree.Find(10), 2);
    ASSERT_EQ(tree.Find(30), 2);
}

// Case 5: 삭제 후 균형 유지 (LeftRotate)
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_LeftRotate)
{
    tree.Insert(20);
    tree.Insert(30);
    tree.Insert(10);
    tree.Insert(5);
    ASSERT_EQ(tree.Find(30), 2);

    tree.Erase(30); // 삭제 후 균형 유지 확인

    ASSERT_EQ(tree.Find(30), 0);
    ASSERT_EQ(tree.Find(5), 2);
    ASSERT_EQ(tree.Find(10), 2); // 새로운 루트
    ASSERT_EQ(tree.Find(20), 2);
}

// Case 6: 삭제 후 균형 유지 (RightRotate)
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_RightRotate)
{
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30); // RightRotate 발생
    tree.Insert(35);
    ASSERT_EQ(tree.Find(10), 2);

    tree.Erase(10); // 삭제 후 균형 유지 확인
    ASSERT_EQ(tree.Find(10), 0);
    ASSERT_EQ(tree.Find(20), 2);
    ASSERT_EQ(tree.Find(30), 2); // 새로운 루트
    ASSERT_EQ(tree.Find(35), 2);
}

// Case 7: 삭제 후 Left-RightRotate 발생
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_LeftRightRotate)
{
    tree.Insert(20);
    tree.Insert(30);
    tree.Insert(10);
    tree.Insert(15);
    ASSERT_EQ(tree.Find(30), 2);

    tree.Erase(30); // 균형 유지 확인
    ASSERT_EQ(tree.Find(30), 0);
    ASSERT_EQ(tree.Find(10), 2);
    ASSERT_EQ(tree.Find(15), 2); // 새로운 루트트
    ASSERT_EQ(tree.Find(20), 2);
}

// Case 8: 삭제 후 Right-LeftRotate 발생
TEST_F(AVLTreeTestFixture_Empty, DeleteNode_RightLeftRotate)
{
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30);
    tree.Insert(25);
    ASSERT_EQ(tree.Find(10), 2);

    tree.Erase(10); // 균형 유지 확인
    ASSERT_EQ(tree.Find(10), 0);
    ASSERT_EQ(tree.Find(20), 2); // 1
    ASSERT_EQ(tree.Find(25), 2); // 새로운 루트
    ASSERT_EQ(tree.Find(30), 2);
}


// **Utility 2번 테스트** GetHeight 테스트
// Case 1: A - B, nullptr이 아닌 노드
TEST_F(UtilityTestFixture_7node, GetHeight_Insert_Normal_Node) {
    tree.Insert(55);

    int height = util.GetHeight(tree.GetRoot());

    EXPECT_EQ(4, height); // node->height와 동일해야 함
}

// Case 2: nullptr 노드를 추가
TEST_F(UtilityTestFixture_7node, GetHeight_Insert_Nullptr) {
    AVLNode* node = nullptr;

    int height = util.GetHeight(tree.GetRoot());

    EXPECT_EQ(3, height); // nullptr일 경우 원래 높이인 3 반환
}

// **Utility 3번 테스트** GetSize 테스트
// case 1: 트리에 노드를 추가한 후 크기 확인
TEST_F(UtilityTestFixture_7node, GetSize_Insert_Normal_Node) {
    tree.Insert(55); // AVLTree에 노드 추가

    // 트리 크기 확인
    int size = util.GetSize(tree.GetRoot());

    EXPECT_EQ(8, size); // 초기 7개 + 1개 = 8
}

// case 2: nullptr 입력 시 크기 확인
TEST_F(UtilityTestFixture_7node, GetSize_Insert_Nullptr) {
    AVLNode* InputNode = nullptr;

    int size = util.GetSize(tree.GetRoot());

    EXPECT_EQ(7, size); // nullptr을 추가해도 size는 변화없음  #7
}

// **Utility 4번 테스트** GetBalance 테스트
// case 1: 트리에 노드를 추가한 후 왼쪽 노드와 오른쪽 노드의 높이 차 확인
TEST_F(UtilityTestFixture_7node, GetBalance_Insert_Normal_Node) {
    tree.Insert(55); // AVLTree에 노드 추가

    int Balance = util.GetBalance(tree.GetRoot());

    EXPECT_EQ(-1, Balance); // 예상 출력값 -1
}

// case 2: nullptr 입력 후 왼쪽 노드와 오른쪽 노드의 높이 차 확인
TEST_F(UtilityTestFixture_7node, GetBalance_Insert_Nullptr) {
    AVLNode* InputNode = nullptr;

    int Balance = util.GetBalance(tree.GetRoot());

    EXPECT_EQ(0, Balance); // 예상 출력값 0
}

// **Utility 5번 테스트** GetDepth 테스트
// Case 1: 노드가 Empty상태인 경우
TEST(GetDepthTest, Empty_Tree) {
    Utility util;
    AVLNode* node = nullptr;

    int depth = util.GetDepth(node, 10, 0);  // key값은 아무 정수 입력 

    EXPECT_EQ(-1, depth); // 예상 결과 -1
}

// Case 2: 루트만 존재하는 트리
TEST(GetDepthTest, Single_Node) {
    Utility util;
    AVLNode node(10);

    int depth = util.GetDepth(&node, 10, 0);  

    EXPECT_EQ(0, depth); // 예상 결과 0
}

// Case 3: 왼쪽 자식 노드의 Depth
TEST(GetDepthTest, LeftNode_Depth) {
    Utility util;

    AVLNode node(20);
    AVLNode leftChild(10); // 왼쪽 자식 추가

    node.right = nullptr; 
    node.left = &leftChild;        

    int depth = util.GetDepth(&node, 10, 0);  

    EXPECT_EQ(1, depth);  // 예상 결과 1
}

// Case 4: 오른쪽 자식 노드의 Depth
TEST(GetDepthTest, RightNode_Depth) {
    Utility util;
    
    AVLNode node(10);
    AVLNode rightChild(20); // 오른쪽 자식 추가

    node.left = nullptr; 
    node.right = &rightChild;        

    int depth = util.GetDepth(&node, 20, 0);

    EXPECT_EQ(1, depth); // 예상 결과 1
}

// Case 5: 서브트리 이동이 복잡할때
TEST_F(UtilityTestFixture_7node, Complex_Move_Depth) {

    int depth = util.GetDepth(tree.GetRoot(), 65, 0);

    EXPECT_EQ(2, depth); // 예상 결과 2
}

// Case 6: 트리에 존재 하지않는 노드일 경우
TEST_F(UtilityTestFixture_7node, NoT_Exist_Depth) {

    int depth = util.GetDepth(tree.GetRoot(), 100, 0);

    EXPECT_EQ(-1, depth); // 예상 결과 -1
}

// **Utility 6번 테스트** UpdateHeight 테스트
// case 1: 왼쪽 서브트리의 높이가 더 큰 노드
TEST_F(UtilityTestFixture_7node, UpdateHeight_LeftSubTree_Higher) {

    tree.Insert(1);  

    int height = util.UpdateHeight(tree.GetRoot());  // 높이 업데이트  

    EXPECT_EQ(4, height); // 예상 결과는 4
}

// case 2: 오른쪽 서브트리의 높이가 더 큰 노드
TEST_F(UtilityTestFixture_7node, UpdateHeight_RightSubTree_Higher) {
    tree.Insert(100);  

    int height = util.UpdateHeight(tree.GetRoot());  // 높이 업데이트  

    EXPECT_EQ(4, height); // 예상 결과는 4
}

// case 3: 단일 노드 
TEST(UpdateHeightTest, SingleNode) {
    Utility util;
    AVLNode node(10);

    int height = util.UpdateHeight(&node);

    EXPECT_EQ(1, height); // 예상 결과는 1
}

// case 4: 왼쪽 자식만 nullptr
TEST(UpdateHeightTest, LeftChild_Nullptr) {
    Utility util;
    AVLNode node(10);
    AVLNode rightChild(15); // 오른쪽 자식만 추가

    node.left = nullptr;
    node.right = &rightChild;

    int height = util.UpdateHeight(&node);  // 높이 업데이트 

    
    EXPECT_EQ(2, height); // 예상 결과는 2
}

// case 5: 오른쪽 자식만 nullptr
TEST(UpdateHeightTest, RightChild_Nullptr) {\
    Utility util;
    AVLNode node(10);
    AVLNode leftChild(5); // 왼쪽 자식만 추가

    node.left = &leftChild;
    node.right = nullptr;

    int height = util.UpdateHeight(&node);  // 높이 업데이트  

    
    EXPECT_EQ(2, height); // 예상 결과는 2
}

// **Utility 7번 테스트** UpdateSize 테스트
// case 1: 왼쪽 서브트리 높이가 더 큰 노드
TEST_F(UtilityTestFixture_7node, UpdateSize_LeftSubTree_Higher) {
    tree.Insert(1);  

    int height = util.UpdateSize(tree.GetRoot());  // 크기 업데이트  

    EXPECT_EQ(8, height); // 예상 결과는 8
}

// case 2: 오른쪽 서브트리의 높이가 더 큰 노드
TEST_F(UtilityTestFixture_7node, UpdateSize_RightSubTree_Higher) {
    tree.Insert(100);  

    int height = util.UpdateSize(tree.GetRoot());  // 크기 업데이트  

    EXPECT_EQ(8, height); // 예상 결과는 8
}

// case 3: 단일 노드 
TEST(UpdateSizeTest, SingleNode) {
    Utility util;
    AVLNode node(10);

    int Size = util.UpdateSize(&node);  // 크기 업데이트

    EXPECT_EQ(1, Size); // 예상 결과는 1
}

// case 4: 왼쪽 자식만 nullptr
TEST(UpdateSizeTest, LeftChild_Nullptr) {
    Utility util;
    AVLNode node(10);
    AVLNode rightChild(15); // 오른쪽 자식만 추가

    node.left = nullptr;
    node.right = &rightChild;

    int Size = util.UpdateSize(&node);  // 크기 업데이트 

    EXPECT_EQ(2, Size); // 예상 결과는 2
}

// case 5: 오른쪽 자식만 nullptr
TEST(UpdateSizeTest, RightChild_Nullptr) {\
    Utility util;
    AVLNode node(10);
    AVLNode leftChild(5); // 왼쪽 자식만 추가

    node.left = &leftChild;
    node.right = nullptr;

    int Size = util.UpdateSize(&node);  // 크기 업데이트  

    EXPECT_EQ(2, Size); // 예상 결과는 2
}

// **Utility 8번 테스트** FindNode 테스트
// case 1: 트리가 비어있는 경우
TEST(FindNodeTest, Empty_Tree) {
    Utility util;

    AVLNode* result = util.FindNode(nullptr, 0);

    EXPECT_EQ(nullptr, result); // 예상 출력값 nullptr

}

// case 2: 탐색 키가 루트와 일치하는 경우
TEST_F(UtilityTestFixture_7node, FindNode_Root) {

    AVLNode* result = util.FindNode(tree.GetRoot(), 50);
    
    EXPECT_EQ(50, result->key);  // 예상 출력 값 50(루트 키값과 일치)
}

// case 3: 정상적으로 작동하는경우(왼쪽 오른쪽 동시 탐색)
TEST_F(UtilityTestFixture_7node, FindNode_Normal_Operation) {
    AVLNode* resultLeft = util.FindNode(tree.GetRoot(), 25);
    AVLNode* resultRight = util.FindNode(tree.GetRoot(), 75);
    
    EXPECT_EQ(25, resultLeft->key);  // 예상 출력 값 25
    EXPECT_EQ(75, resultRight->key);  // 예상 출력 값 75
}

// case 4: 탐색 키가 루트보다 작아서 왼쪽 서브트리를 탐색
TEST_F(UtilityTestFixture_7node, FindNode_LeftSubtree) {

    AVLNode* result = util.FindNode(tree.GetRoot(), 15);
    
    EXPECT_EQ(15, result->key);  // 예상 출력 값 15(Tree의 가장 왼쪽에 있는 노드)
}

// case 5: 탐색 키가 루트보다 커서 오른쪽 서브트리를 탐색
TEST_F(UtilityTestFixture_7node, FindNode_RightSubtree) {

    AVLNode* result = util.FindNode(tree.GetRoot(), 80);
    
    EXPECT_EQ(80, result->key);  // 예상 출력 값 80(Tree의 가장 오른쪽에 있는 노드)
}

// case 6: 탐색 키가 트리에 존재하지 않는 경우
TEST_F(UtilityTestFixture_7node, FindNode_Not_Exist) {

    AVLNode* result = util.FindNode(tree.GetRoot(), 100);
    
    EXPECT_EQ(nullptr, result);  // 예상 출력 값 nullptr
}

// **Utility 9번 테스트** MinValueNode 테스트
// case 1: 트리가 비어있는 경우
TEST(MinValueNodeTest, Empty_Tree) {
    Utility util;

    AVLNode* minValue = nullptr;

    EXPECT_EQ(nullptr, minValue); // 예상 출력값 nullptr

}

// case 2: 왼쪽 서브트리가 비어있는 경우
TEST(MinValueNodeTest, Empty_Left_Subtree) {
    Utility util;
    AVLNode node(10);
    AVLNode rightChild(15); // 오른쪽 자식만 추가

    node.left = nullptr;
    node.right = &rightChild;

    AVLNode* minValue = util.MinValueNode(&node);

    EXPECT_EQ(10, minValue->key); // 예상 출력값 10(root값)

}

// case 3: 왼쪽 자식이 하나만 있는 경우
TEST(MinValueNodeTest, Only_One_LeftNode) {
    Utility util;
    AVLNode node(10);
    AVLNode leftChild(5); // 왼쪽 자식 추가

    node.left = &leftChild;
    node.right = nullptr;

    AVLNode* minValue = util.MinValueNode(&node);

    EXPECT_EQ(5, minValue->key); // 예상 출력값 5
}

// case 4: 왼쪽 자식 노드가 여러개 있는 경우
TEST_F(UtilityTestFixture_7node, MinValueNode_Normal_Operation) {

    AVLNode* minValue = util.MinValueNode(tree.GetRoot());
    
    EXPECT_EQ(15, minValue->key);  // 예상 출력 값 15(가장 왼쪽에 있는 노드)
}

// **Utility 10번 테스트** MaxValueNode 테스트
// case 1: 트리가 비어있는 경우
TEST(MaxValueNodeTest, Empty_Tree) {
    Utility util;

    AVLNode* maxValue = nullptr;

    EXPECT_EQ(nullptr, maxValue); // 예상 출력값 nullptr

}

// case 2: 오른쪽 서브트리가 비어있는 경우
TEST(MaxValueNodeTest, Empty_Right_Subtree) {
    Utility util;
    AVLNode node(10);
    AVLNode leftChild(5); // 왼쪽 자식만 추가

    node.left = &leftChild;
    node.right = nullptr;
    AVLNode* maxValue = util.MaxValueNode(&node);

    EXPECT_EQ(10, maxValue->key); // 예상 출력값 10(root값)

}

// case 3: 오른쪽 자식이 하나만 있는 경우
TEST(MaxValueNodeTest, Only_One_RightNode) {
    Utility util;
    AVLNode node(10);
    AVLNode rightChild(15); // 오른쪽 자식 추가

    node.left = nullptr;
    node.right = &rightChild;

    AVLNode* maxValue = util.MaxValueNode(&node);

    EXPECT_EQ(15, maxValue->key); // 예상 출력값 15
}

// case 4: 오른쪽 자식 노드가 여러개 있는 경우
TEST_F(UtilityTestFixture_7node, MaxValueNode_Normal_Operation) {

    AVLNode* maxValue = util.MaxValueNode(tree.GetRoot());
    
    EXPECT_EQ(80, maxValue->key);  // 예상 출력 값 15(가장 오쪽에 있는 노드)
}

// **Utility 11번 테스트** LeftRotate 테스트
// Case 1: 오른쪽 자식이 nullptr인 노드
TEST(LeftRotateTest, Empty_RightSubtree) {
    Utility util;

    AVLNode node(10);
    AVLNode leftChild(5); // 왼쪽 자식만 추가

    node.left = &leftChild; 
    node.right = nullptr;        

    AVLNode* new_root = util.LeftRotate(&node);  // LeftRotate 실행

    EXPECT_EQ(10, new_root->key); // 예상 결과 10(변화없음)
}

// Case 2: 루트만 존재하는 트리
TEST(LeftRotateTest, Single_Node) {
    Utility util;

    AVLNode node(10);

    AVLNode* new_root = util.LeftRotate(&node);  // LeftRotate 실행

    EXPECT_EQ(10, new_root->key); // 예상 결과 10(변화없음)
}

// Case 3: 오른쪽 자식의 왼쪽 서브트리가 있는 경우
TEST(LeftRotateTest, Unbalanced_RightSubtree) {
    Utility util;

    AVLNode node(10);
    AVLNode right1_Child(20); // 오른쪽 자식 추가
    AVLNode right2_Child(15); // 오른쪽 자식의 왼쪽 자식 추가

    node.left = nullptr; 
    node.right = &right1_Child;        
    right1_Child.left = &right2_Child; 

    AVLNode* new_root = util.LeftRotate(&node);  // LeftRotate 실행

    EXPECT_EQ(20, new_root->key);              // 예상 결과 20
    EXPECT_EQ(10, new_root->left->key);        // 예상 결과 10
    EXPECT_EQ(15, new_root->left->right->key); // 예상 결과 15
}

// Case 4: 오른쪽 자식의 왼쪽 서브트리가 없는 경우
TEST(LeftRotateTest, Only_RightNode) {
    Utility util;

    AVLNode node(10);
    AVLNode rightChild(20); // 오른쪽 자식 추가

    node.left = nullptr; 
    node.right = &rightChild;        

    AVLNode* new_root = util.LeftRotate(&node);  // LeftRotate 실행

    EXPECT_EQ(20, new_root->key);              // 예상 결과 20
    EXPECT_EQ(10, new_root->left->key);        // 예상 결과 10
}

// **Utility 12번 테스트** RightRotate 테스트
// Case 1: 왼쪽 자식이 nullptr인 노드
TEST(RightRotateTest, Empty_LeftSubtree) {
    Utility util;

    AVLNode node(10);
    AVLNode rightChild(20); // 오른쪽 자식만 추가

    node.left =  nullptr; 
    node.right = &rightChild;        

    AVLNode* new_root = util.RightRotate(&node);  // RightRotate 실행

    EXPECT_EQ(10, new_root->key); // 예상 결과 10(변화없음)
}

// Case 2: 루트만 존재하는 트리
TEST(RightRotateTest, Single_Node) {
    Utility util;

    AVLNode node(10);

    AVLNode* new_root = util.RightRotate(&node);  // RightRotate 실행

    EXPECT_EQ(10, new_root->key); // 예상 결과 10(변화없음)
}

// Case 3: 왼쪽 자식이 있는 균형 깨진 노드
TEST(RightRotateTest, Unbalanced_LeftSubtree) {
    Utility util;

    AVLNode node(20);
    AVLNode left1_Child(10); // 왼쪽 자식 추가
    AVLNode left2_Child(15); // 왼쪽 자식의 오른쪽 자식 추가

    node.right = nullptr; 
    node.left = &left1_Child;        
    left1_Child.right = &left2_Child; 

    AVLNode* new_root = util.RightRotate(&node);  // RightRotate 실행

    EXPECT_EQ(10, new_root->key);              // 예상 결과 10
    EXPECT_EQ(20, new_root->right->key);       // 예상 결과 20
    EXPECT_EQ(15, new_root->right->left->key); // 예상 결과 15
}

// Case 4: 왼쪽 자식이 있는 균형 깨진 노드
TEST(RightRotateTest, Only_LeftNode) {
    Utility util;
    
    AVLNode node(20);
    AVLNode leftChild(10); // 왼쪽 자식 추가

    node.right = nullptr; 
    node.left = &leftChild;        

    AVLNode* new_root = util.RightRotate(&node);  // RightRotate 실행

    EXPECT_EQ(10, new_root->key);              // 예상 결과 10
    EXPECT_EQ(20, new_root->right->key);       // 예상 결과 20
}

// **Utility 13번 테스트** RankNode 테스트
// Case 1: 노드가 Empty상태인 경우
TEST(RankNode, Empty_Tree) {
    Utility util;

    AVLNode* node = nullptr;

    int rank = util.RankNode(node, 10);  // key값은 아무 정수 입력 

    EXPECT_EQ(0, rank); // 예상 결과 0
}

// Case 2: 루트만 존재하는 트리
TEST(RankNode, Single_Node) {
    Utility util;

    AVLNode node(10);

    int rank = util.RankNode(&node, 10);  

    EXPECT_EQ(0, rank); // 예상 결과 0
}

// Case 3: 왼쪽 서브트리의 노드 Rank
TEST(RankNode, LeftSubtree_Rank) {
    Utility util;

    AVLNode node(20);
    AVLNode left1_Child(10); // 왼쪽 자식 추가
    AVLNode left2_Child(15); // 왼쪽 자식의 오른쪽 자식 추가

    node.right = nullptr; 
    node.left = &left1_Child;        
    left1_Child.right = &left2_Child;

    int rank = util.RankNode(&node, 15);  

    EXPECT_EQ(1, rank);  // 예상 결과 1
}

// Case 4: 오른쪽 서브트리의 노드 Rank
TEST(RankNode, RightNode_Depth) {
    Utility util;

    AVLNode node(10);
    AVLNode right1_Child(20); // 오른쪽 자식 추가
    AVLNode right2_Child(15); // 오른쪽 자식의 왼쪽 자식 추가

    node.left = nullptr; 
    node.right = &right1_Child;        
    right1_Child.left = &right2_Child;

    int rank = util.RankNode(&node, 15);  

    EXPECT_EQ(1, rank);  // 예상 결과 1
}

// Case 5: 서브트리 이동이 복잡할때
TEST_F(UtilityTestFixture_7node, Complex_Move_Rank) {

    int rank = util.RankNode(tree.GetRoot(), 65);

    EXPECT_EQ(4, rank); // 예상 결과 4
}

// 통합테스트 노드(20 30 10)이 들어가 있는 Fixture
TEST_F(AVLTreeTestFixture_3node, Integration_Testing)
{
    ASSERT_EQ(tree.Find(10), 2);
    ASSERT_EQ(tree.Size(), 3);
    ASSERT_EQ(tree.Empty(), 0);
    ASSERT_EQ(tree.Height(), 2);

    tree.Insert(40);
    tree.Insert(35); // RL회전
    tree.Insert(45); // L회전전
    tree.Erase(20);
    tree.Erase(45);
    tree.Erase(40); // LR회전
    tree.Insert(5);

    ASSERT_EQ(tree.Find(5), 3);   //높(1) 깊(2)
    ASSERT_EQ(tree.Find(10), 3);  //높(2) 깊(1)
    ASSERT_EQ(tree.Find(35), 2);  //높(1) 깊(1)
    ASSERT_EQ(tree.Find(30), 3);  //높(3) 깊(0)
    ASSERT_EQ(tree.Size(), 4);   
    ASSERT_EQ(tree.Height(), 3);

    testing::internal::CaptureStdout();
    tree.Rank(10);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3 2\n"); // 높(2) 깊(1)  전체 set 오름차순 2번쨰
    
    testing::internal::CaptureStdout();
    tree.Ancestor(5);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "3 40\n"); // 높(1) 깊(2)  부모: 10 + 30

    testing::internal::CaptureStdout();
    tree.Average(30);
    std::string output3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output3, "20\n"); // 최소 5 최대 35
}

// main 함수
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}