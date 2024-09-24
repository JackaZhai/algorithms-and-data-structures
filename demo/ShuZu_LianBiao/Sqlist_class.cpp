#include <iostream>
#include <cstdlib>

#define MaxSize 50

typedef int ElemType;

class SqList {
private:
    ElemType data[MaxSize]; // 用于存储顺序表中的数据元素
    int length; // 用于记录顺序表中的元素个数

public:
    // 构造函数
    SqList() {
        length = 0;
    }

    // 析构函数
    ~SqList() {
        // 不需要显式释放内存，因为没有使用动态分配
    }

    // 建立顺序表
    void CreateList(ElemType a[], int n) {
        int i = 0, k = 0;
        while (i < n) {
            data[k] = a[i];
            i++;
            k++;
        }
        length = k;
    }

    // 初始化顺序表
    void InitList() {
        length = 0;
    }

    // 判断顺序表是否为空
    bool ListEmpty() const {
        return (length == 0);
    }

    // 求顺序表的长度
    int ListLength() const {
        return length;
    }

    // 输出顺序表
    void DispList() const {
        for (int i = 0; i < length; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // 求顺序表中的某个元素值
    bool GetElem(int i, ElemType &e) const {
        if (i < 1 || i > length) {
            return false;
        }
        e = data[i - 1];
        return true;
    }

    // 按元素值查找
    int LocateElem(ElemType e) const {
        int i = 0;
        while (i < length && data[i] != e) {
            i++;
        }
        if (i >= length) {
            return 0;
        }
        return i + 1;
    }

    // 插入元素
    bool ListInsert(int i, ElemType e) {
        if (i < 1 || i > length + 1) {
            return false;
        }
        i--;
        for (int j = length; j > i; j--) {
            data[j] = data[j - 1];
        }
        data[i] = e;
        length++;
        return true;
    }

    // 删除元素
    bool ListDelete(int i, ElemType &e) {
        if (i < 1 || i > length) {
            return false;
        }
        i--;
        e = data[i];
        for (int j = i; j < length - 1; j++) {
            data[j] = data[j + 1];
        }
        length--;
        return true;
    }
};

int main() {
    SqList list;
    ElemType arr[] = {1, 2, 3, 4, 5};
    list.CreateList(arr, 5);
    list.DispList();

    ElemType e;
    if (list.GetElem(3, e)) {
        std::cout << "Element at position 3: " << e << std::endl;
    }

    list.ListInsert(3, 10);
    list.DispList();

    list.ListDelete(4, e);
    list.DispList();

    return 0;
}