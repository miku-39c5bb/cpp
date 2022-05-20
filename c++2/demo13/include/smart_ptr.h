/*
智能指针
*/

class U_Ptr {
    friend class BHasPtr;

private:
    int* ip;
    size_t use;  // 计数，当use==0时，就把智能制造删掉，否则就无法删除智能指针

    explicit U_Ptr(int* p) : ip(p), use(1) {}  // 智能指针new一次，就代表被一个对象指向了一次，所以use=1
    ~U_Ptr() {
        delete ip;
    }
};

class BHasPtr {
private:
    int val;
    U_Ptr* ptr;

public:
    explicit BHasPtr(int* p, int i) : ptr(new U_Ptr(p)), val(i) {}
    // 智能指针还是指向同一个对象，所以拷贝构造函数和赋值运算符不需要new，但是use要++
    explicit BHasPtr(const BHasPtr& other) : ptr(other.ptr), val(other.val) {
        ++this->ptr->use;
    }
    BHasPtr& operator=(const BHasPtr& other) {
        /***
         * 关于这里的++和--
         * 若=左右两边的智能指针指向的U_Ptr不是同一个对象，那么 左边BHasPtr对象(*this)的ptr原本指向某一个U_Ptr对象, 现在赋值后左边的那个ptr就指向了和 右边BHasPtr对象(other)的ptr指向的同一个U_Ptr对象
         * 因此右边的other.ptr->use要+1，左边的this->ptr->use要-1
         * 若=左右两边的智能指针指向的U_Ptr是同一个对象，那么这个U_Ptr的use就不会变，++和--之后也确实没有改变
         */
        ++other.ptr->use;       // 右边的++
        if (--ptr->use == 0) {  // 左边的--
            delete ptr;
        }
        this->ptr = other.ptr;
        this->val = other.val;
        return *this;
    }
    ~BHasPtr() {
        if (--ptr->use == 0) {
            delete this->ptr;
        }
    }

    int* get_ptr() const {
        return ptr->ip;
    }
    int get_int() const {
        return val;
    }
    void set_ptr(int* p) {
        ptr->ip = p;
    }
    void set_int(int i) {
        val = i;
    }

    int get_ptr_val() const {
        return *ptr->ip;
    }
    void set_ptr_val(int val) {
        *ptr->ip = val;
    }
};
