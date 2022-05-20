/*
深复制
*/

class CHasPtr {
private:
    int val;
    int* ptr;

public:
    explicit CHasPtr(const int& p, int i) : ptr(new int(p)), val(i) {}
    explicit CHasPtr(const CHasPtr& other) : ptr(new int(*other.ptr)), val(other.val) {}
    CHasPtr& operator=(const CHasPtr& other) {
        this->ptr = new int(*other.ptr);
        this->val = other.val;
        return *this;
    }
    ~CHasPtr() {
        delete ptr;
    }

    int* get_ptr() const {
        return ptr;
    }
    int get_int() const {
        return val;
    }
    void set_ptr(int* p) {
        ptr = p;
    }
    void set_int(int i) {
        val = i;
    }

    int get_ptr_val() const {
        return *ptr;
    }
    void set_ptr_val(int val) {
        *ptr = val;
    }
};