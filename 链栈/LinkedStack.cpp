#include <iostream>
/* Stack Node Struct
 * 这个结构体用来定义链栈节点
 * 结构体StackNode包含一个data整型用于存放数据
 * 并且拥有一个StackNode类型的next指针用于指向下一个节点
 */
struct StackNode {
    int data;
    StackNode* next; // The next Stack Node Pointer

    // Default constructor
    // 默认构造函数，用于创建时初始化data和指定next指针
    explicit StackNode(int _data) {
        data = _data;
        next = nullptr;
    }
};

class LinkedStack {
    private:
        StackNode* Top; // Top Pointer

    public:
        // Default constructor
        // 默认构造函数
        // 不需要Init函数，直接用构造函数创建链栈
        LinkedStack() {
            Top = nullptr;
        }

        bool isEmpty() {
            return Top == nullptr; // 如果Top元素为nullptr那就是没被压入元素，直接返回Boolean状态就行了
        }

        void Push(int _data) {
                auto* newNode = new StackNode(_data); // 创建一个用户输入值的节点用于 Push in
                newNode->next = Top; // 把要插入的节点的下一指向当前最顶端元素 (防止Top元素的数据因为直接插入而丢失)
                Top = newNode; // 把最顶端元素改为要插入的节点
                // std::cout << _data << " has been pushed!" << std::endl; // Logger
        }

        void Pop() {
            if(isEmpty()) {
                std::cout << "The Stack is empty!" << std::endl; // 如果栈为空，直接润
                return;
            }
            StackNode* Temp = Top; // 临时节点，用于get节点data
            Top = Top->next; // 直接移动指针到下一位
            // std::cout << "The top node " << Temp->data << " has been poped!" << std::endl; // Logger
            delete Temp; // 防止内存泄漏，优雅释放一下内存
        }

        int Peek() {
            if(isEmpty()) {
                std::cout << "The Stack is empty!" << std::endl; // 如果栈为空，无法获取top元素
                return -1; // Error flag
            }
            return Top->data; // 返回top元素data
        }

        // 标准遍历函数
        // 用于输出链栈数据
        void Printer() {
            if(isEmpty()) {
                std::cout << "The Stack is empty!" << std::endl; // 如果栈为空，直接润
                return;
            }
            std::cout << "Linked Stack (Top->last): ";
            StackNode* Current = Top;
            while(Current != nullptr) { // 一次简单的遍历
                std::cout << Current->data << " ";
                Current = Current->next; // 指向下一个节点
            }
            std::cout << std::endl; // 最后补一下换行
            delete Current;        }
        // Destructor
        // 析构函数，用于释放链栈所占用的内存
        ~LinkedStack() {
            while(!isEmpty()) {
                Pop(); // 一直Pop顶端元素直到链栈为空
            }
        }
};

int main() {
    // some simple eg
    LinkedStack S1;
    S1.Push(10);
    S1.Push(30);
    S1.Push(1);
    S1.Push(2);
    S1.Printer();
    std::cout << "Now top Node is: " << S1.Peek() << std::endl;
    std::cout << "debugger: Pop() until the stack is empty\n";
    S1.Pop();
    S1.Pop();
    S1.Pop();
    S1.Pop();
    S1.Pop();

    return 0;
}