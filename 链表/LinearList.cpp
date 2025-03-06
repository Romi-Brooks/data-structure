#include <iostream>

/* Node Struct
 * 这个结构体用来定义线性链表节点
 * 结构体Node包含一个data整型用于存放数据
 * 并且拥有一个Node类型的next指针用于指向下一个节点
 */
struct Node {
    int data;
    Node* next; // The next Node Pointer

    // Default constructor
    // 默认构造函数，用于创建时初始化data和指定next指针
    Node(int _data) {
        data = _data;
        next = nullptr;
    }
};

class LinearList {
    public:
        // Default constructor
        // 默认构造函数，用于创建链表
        LinearList() {
            head = nullptr;
        }

        // Destructor
        // 析构函数，用于释放线性链表所占用的内存
        ~LinearList() {
            Node* current = head; // 使得当前节点指向链表第一位
            while (current != nullptr) { // 循环直到走到链表最后一位
               Node* next = current->next; // 确保操作后指向下一个node
                delete current; // Free mem ，删除当前节点
                current = next; // 下一位
            }
        }

        // 公共接口
        // 自定义函数
        void Insert_Node(int _data) {
            Node* newNode = new Node(_data); // 创建一个节点
            if (head == nullptr) {
                head = newNode; // 如果头节点为空就直接插入
                std::cout << "Inserted data :" << _data << " from head." << std::endl; // Logger
            }else {
                Node* Current = head;
                while (Current->next != nullptr) { // 遍历节点直到为最后的节点
                    Current = Current->next; // Pointer Runner
                }
                Current->next = newNode; // 当为最后的节点的时候就插入
                std::cout << "Inserted data :" << _data << std::endl; // Logger
            }
        }

        void Delete_Node(int _data) {
            if(head == nullptr) {
                std::cout << "Empty!" << std::endl; // Logger
                return; // 空链表直接润
            }
            if(head->data == _data) {
                Node* Temp = head; // 临时节点，用于转移头节点指针
                head = head->next; // 把头结点指针转移给下一位
                delete Temp; // 删除
                std::cout << "Deleted from head" << std::endl; // Logger
                return;
            }
            Node* Current = head;
            while (Current->next != nullptr && Current->next->data != _data) { // 确定当前节点的data不是用户需要删除的，而且确保其当前位置不是空（最后）
                Current = Current->next; // Pointer Runner
            }
            // 筛选到用户想要删除的节点
            if(Current->next != nullptr) { // 确保当前节点不是空节点（最后）
                Node* Temp = Current->next; // 临时节点，用于转移节点指针
                Current->next = Current->next->next; // 转移当前节点的指针到下一个节点
                delete Temp; // 删除用户需要删除的节点
                std::cout << "Deleted." << std::endl; // Logger
            }
        }
        void Find_Node(int _data) {
            if(head == nullptr) {
                std::cout << "Empty!" << std::endl; // Logger
                return; // 空链表直接润
            }
            Node* Current = head;
            while (Current != nullptr) {
                if(Current->data == _data) {
                    std::cout << "Finded data: " << _data << " in the list." << std::endl; // output stream
                    return;
                }
                Current = Current->next;
            }
            std::cout << "Can not finded data: " << _data << " in the list." << std::endl;// output stream
        }
        void Modeify_Node(int s_data,int m_data) {
            if(head == nullptr) {
                std::cout << "Empty!" << std::endl; // Logger
                return; // 空链表直接润
            }
            if(head->data == s_data) {
                head->data = m_data;
                std::cout << "Modeified head data: " << s_data << " to: " << m_data  << "." << std::endl; // Logger
                return;
            }
            Node* Current = head;
            while (Current->next != nullptr && Current->next->data != s_data) { // 确定当前节点的data不是用户需要修改的，而且确保其当前位置不是空（最后）
                Current = Current->next; // Pointer Runner
            }
            // 筛选到用户想要修改的节点
            if(Current->next != nullptr) { // 确保当前节点不是空节点（最后）
                Current->next->data = m_data;
                std::cout << "Modeified data: " << s_data << " to " << m_data  << "." << std::endl; // Logger
            }
        }
        void Print_List() { // 标准遍历函数
            Node* Current = head;
            std::cout << "Linear List: ";
            while (Current != nullptr) {
                std::cout << Current->data;
                Current = Current->next;
                if (Current != nullptr) {
                    std::cout << " -> ";
                }else{
                    std::cout << " -> nullptr." << std::endl;
                }
            }
        }
    private:
        Node* head;

};
int main()
{
    // Some Test eg:
    LinearList L1;
    L1.Insert_Node(1);
    L1.Insert_Node(2);
    L1.Insert_Node(3);
    L1.Insert_Node(4);
    L1.Insert_Node(5);
    L1.Print_List();
    L1.Find_Node(1);
    L1.Find_Node(17);
    return 0;

}
