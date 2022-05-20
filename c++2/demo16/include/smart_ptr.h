/*
智能指针
*/

class U_Ptr {
    friend class BHasPtr;

private:
    int* ip;
    int use;

    // explicit U_Ptr(int* p) : ip(new int(*p)), use(1) {}
    explicit U_Ptr(int* p) : ip(p), use(1) {}
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
    explicit BHasPtr(const BHasPtr& other) : ptr(other.ptr), val(other.val) {
        ++this->ptr->use;
    }
    BHasPtr& operator=(const BHasPtr& other) {
        ++other.ptr->use;
        if (--this->ptr->use == 0) {
            delete this->ptr;
        }
        this->ptr = other.ptr;
        this->val = other.val;
        return *this;
    }
    ~BHasPtr() {
        if (--this->ptr->use == 0) {
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