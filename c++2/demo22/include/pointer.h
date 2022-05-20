#ifndef __POINTER_H__
#define __POINTER_H__

class String;

// 智能指针：对指针使用进行计数（这里忽略）
class Pointer {
public:
    Pointer();
    Pointer(const String& str);
    ~Pointer();

    String& operator*();
    String* operator->() const;

private:
    String* ptr;
    static String errorMessage;
};

#endif  // __POINTER_H__