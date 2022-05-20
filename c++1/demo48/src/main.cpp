#include <stdio.h>

class BadSrcFile {
};
class BadDestFile {
};
class BadCopy {
};

int my_cp(const char* src_file, const char* dest_file)
{
    FILE *in_file, *out_file;

    in_file = fopen(src_file, "rb");
    if (in_file == NULL) {
        return 1;
    }

    out_file = fopen(dest_file, "wb");
    if (out_file == NULL) {
        return 2;
    }

    char rec[256];
    size_t bytes_in, bytes_out;
    while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) {
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if (bytes_in != bytes_out) {
            return 3;
        }
    }
    fclose(in_file);
    fclose(out_file);

    return 0;
}

void my_cp2(const char* src_file, const char* dest_file)
{
    FILE *in_file, *out_file;

    in_file = fopen(src_file, "rb");
    if (in_file == NULL) {
        // return 1;
        throw 1; // throw 抛出异常
    }

    out_file = fopen(dest_file, "wb");
    if (out_file == NULL) {
        // return 2;
        throw 2;
    }

    char rec[256];
    size_t bytes_in, bytes_out;
    while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) {
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if (bytes_in != bytes_out) {
            // return 3;
            throw 3;
        }
    }
    fclose(in_file);
    fclose(out_file);

    // return 0;
}

void my_cp3(const char* src_file, const char* dest_file)
{
    FILE *in_file, *out_file;

    in_file = fopen(src_file, "rb");
    if (in_file == NULL) {
        // return 1;
        throw "打开源文件出错";
    }

    out_file = fopen(dest_file, "wb");
    if (out_file == NULL) {
        // return 2;
        throw "打开目标文件出错";
    }

    char rec[256];
    size_t bytes_in, bytes_out;
    while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) {
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if (bytes_in != bytes_out) {
            // return 3;
            throw "拷贝文件出错";
        }
    }
    fclose(in_file);
    fclose(out_file);
}

void my_cp4(const char* src_file, const char* dest_file)
{
    FILE *in_file, *out_file;

    in_file = fopen(src_file, "rb");
    if (in_file == NULL) {
        // return 1;
        throw BadSrcFile();
    }

    out_file = fopen(dest_file, "wb");
    if (out_file == NULL) {
        // return 2;
        throw BadDestFile();
    }

    char rec[256];
    size_t bytes_in, bytes_out;
    while ((bytes_in = fread(rec, 1, 256, in_file)) > 0) {
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if (bytes_in != bytes_out) {
            // return 3;
            throw BadCopy();
        }
    }
    fclose(in_file);
    fclose(out_file);
}

int main()
{
    int result;
    if ((result = my_cp("..\\test\\1.txt", "..\\test\\2.txt")) != 0) {
        switch (result) {
        case 1:
            printf("打开源文件出错\n");
            break;
        case 2:
            printf("打开目标文件出错\n");
            break;
        case 3:
            printf("拷贝出错文件出错\n");
            break;

        default:
            printf("发生未知错误\n");
            break;
        }
    }

    try {
        my_cp2("..\\test\\1.txt", "..\\test\\3.txt");
        my_cp3("..\\test\\1.txt", "..\\test\\4.txt");
        my_cp4("..\\test\\1.txt", "..\\test\\5.txt");
    } catch (int e) {
        // 如果这里catch了异常，则在try{}里面对应的my_cp2后面的代码都不会执行
        // 也就是越过了之后的catch
        printf("发生异常：%d\n", e);
    } catch (const char* e) {
        printf("%s\n", e);
    } catch (BadSrcFile e) {
        printf("打开源文件出错\n");
    } catch (BadDestFile e) {
        printf("打开目标文件出错\n");
    } catch (BadCopy e) {
        printf("拷贝异常\n");
    } catch (...) { // 抓住所有异常
        printf("发生了未知异常\n");
    }

    printf("OK!\n");

    return 0;
}