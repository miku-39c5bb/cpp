#ifndef __STRING_H__
#define __STRING_H__

class String {
public:
    String(const char* chars);
    String(const String& str);
    ~String();
    void display() const;

private:
    char* ptrChars;
};

#endif  // __STRING_H__