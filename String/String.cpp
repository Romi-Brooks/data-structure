#include<iostream>
#define D_MAX_SIZE 255

class String {
    private:
        char data[D_MAX_SIZE]; // 串数据
        unsigned int length; // 字符长度

    public:
        // Defualt Constractor
        // 默认构造函数
        String() {
            length = 0; // 设定默认长度
            for(int i=0;i<D_MAX_SIZE;i++) {
                data[i] = '\0'; // 防止涉及到内存安全问题，将所有的块初始化为'\0'
            }
        }

        // 当用户有输入的构造一个字符串的时候
        String(const char* _str) {
            unsigned int t_len = 0; // 用于交接字符串长度
            while(_str[t_len] != '\0' && t_len < D_MAX_SIZE) { //  交接字符串直到用户输入的字符串停止
                data[t_len] = _str[t_len];
                t_len++;
            }
            length = t_len; // 交接字符串长度
            // 重要一点，为了安全的构造一个字符串，同默认构造函数
            // 需要把后面的空位置填满'\0'
            for(int i=length;i<D_MAX_SIZE;i++) {
                data[i] = '\0'; // 防止涉及到内存安全问题，将所有的块初始化为'\0'
            }
        }

        // 串长
        auto getStrlength() const {
            return length;
        }

        // 比较串
        int cmpStr(const String& Str2) const {
            unsigned int minLen; // 依据短字符串的长度进行比较，防止一短一长造成溢出
            if(this->length < Str2.length) {
                minLen = this->length;
            }else {
                minLen = Str2.length;
            }
            // 判断
            for(auto i=0;i<minLen;i++) {
                if(this->data[i] != Str2.data[i]) {
                    return this->data[i] - Str2.data[i]; // 返回ASCII
                } // 如果没有触发这个return，则说明两个字符串相等
            }
            return this->length - Str2.length; // 两个字符串相等的话，比较的依据就是字符串长短
        }

        // 连接串
        String catStr(const String& Str2) const {
            String CatRes;
            auto total_len =  this->length + Str2.length; // 计算连接后的字符串的总长度
            auto str2_len = Str2.length; // 计算第二个字符串的长度，用于处理第二次复制
            if(total_len > D_MAX_SIZE) {
                total_len = D_MAX_SIZE; // 防止操作溢出的内存
            }
            // 第一个字符串
            for(int i=0;i<this->length;i++) {
                CatRes.data[i] = this->data[i]; // 复制
            }
            // 这个判断是为了防止第二段内容过长导致超出了字符串数据能支持的最大的值
            // 直接切掉多出来的部分(非常暴力的解决方案)
            if(total_len > D_MAX_SIZE) {
                str2_len = D_MAX_SIZE - this->length; // 防止操作溢出的内存
            }
            // 第二个字符串
            for(int i=0;i<str2_len;i++) {
                CatRes.data[this->length+i] = Str2.data[i]; // 复制
            }
            CatRes.length = std::min(static_cast<int>(total_len),D_MAX_SIZE);
            for(int i=total_len;i<D_MAX_SIZE;i++) { // 为了防止总长度小于当前串的最大值，为了内存安全，填充为'\0'
                CatRes.data[i] = '\0'; // 防止涉及到内存安全问题，将连接完后没有占位的字符初始化为'\0'
            }
            return CatRes;
        }

        // 复制串
        void copy(const String& Str) {
            for (int i = 0; i < Str.length && i < D_MAX_SIZE; i++) {
                this->data[i] = Str.data[i]; // 复制内容
            }
            length = std::min(static_cast<int>(Str.length), D_MAX_SIZE); // 更新长度
            for (int i = length; i < D_MAX_SIZE; i++) {
                data[i] = '\0'; // 防止涉及到内存安全问题，将复制完后没有占位的字符初始化为'\0'
            }
        }

        // // 子串索引
        // // Using BF Algo
        // int getIndexOfSub(const String& SubString) const {
        //     int i=0, j=0; // i是母串的指针，j是子串的指针，使用双指针暴力遍历字符串
        //     while(i< this->getStrlength() && j < SubString.getStrlength()) { // 确保不会越界
        //         if(this->data[i] == SubString.data[j]) { // 如果当前位字符相同就继续下一位
        //             i++; j++; // 指针+1
        //         }else {
        //             i=i-j+1; j=0; // 如果不相同，i就回溯到下一位位置，j重置为0 即为从下一位开始重新匹配字符串
        //         }
        //     }
        //     if(j == SubString.getStrlength()) { // 当当前匹配位置等于子串长度就结束匹配
        //         return i-SubString.getStrlength(); // 返回子串在中的母串位置
        //     }else {
        //         return -1; // 润
        //     }
        // }
        //
        // // 抽离子串
        // String SpliteSub(int pos_b, int pos_e) {
        //     int SubLen = pos_e-pos_b+1; // 获取抽离字符串的长度
        //     String SpliteSub; // 无参数构造，不指定长度
        //     SpliteSub.length = SubLen; // 赋予长度，避免后续操作问题
        //     for(int i=0;i<SubLen;i++) {
        //         SpliteSub.data[i] = this->data[pos_b+i]; // 抽离到SpliteSub
        //     }
        //     return SpliteSub;
        // }

        // 输出流
        void Printer() const {
            for(auto i=0;i<this->length;i++) {
                std::cout << this->data[i];
            }
        }
};

int main() {
    String s1("Hello,");
    String s2("World!");
    std::cout << "Str1:";
    s1.Printer();
    std::cout << "Str2:";
    s2.Printer();
    std::cout << std::endl;
    std::cout << std::endl << "The Str1's length is: " << s1.getStrlength() << std::endl
                << "The Str2's length is: " << s2.getStrlength() << std::endl;

    if (s1.cmpStr(s2) > 0) {
        std::cout << "Str1 is bigger than str2." << std::endl;
    }else if(s1.cmpStr(s2) ==0){
        std::cout << "Str1 is equals to str2." << std::endl;
    }else {
        std::cout << "Str2 is bigger than str1." << std::endl;
    }

    const String CatRes = s1.catStr(s2);
    std::cout<< std::endl << "Str1 and str2's cat str:";
    CatRes.Printer();

    std::cout<< "Copied Str2 to Str1:";
    s1.copy(s2);
    s1.Printer();

    // String sub1("llo");
    //
    // std::cout << "sub1(";
    // sub1.Printer();
    // std::cout << ") in str1(";
    // s1.Printer();
    // std::cout << "):" << s1.getIndexOfSub(sub1) << std::endl;

    // String SpliteSub = s1.SpliteSub(0,3);
    // std::cout << "Splited SubSting(length:" << SpliteSub.getStrlength() << ") form s1(0,3):";
    // SpliteSub.Printer();
    // std::cout << std::endl;


    return 0;
}