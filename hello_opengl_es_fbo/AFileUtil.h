
#ifndef AFileUtil_h
#define AFileUtil_h

class AFileUtil {
public:
    AFileUtil();
    ~AFileUtil();

    static void save(const char *filePath, void *buffer, unsigned int len);
private:

};



#endif //AFileUtil_h
