#ifndef __STRING_DEF_HPP__
#define __STRING_DEF_HPP__

//define str for char*
inline char* charToHost(char* host, char* netBuffer)
{
    U16 len;
    netBuffer = U16ToHost(len, netBuffer);
    strncpy(host, netBuffer, len);
    host[len] = '\0';
    return netBuffer + len;
}

inline char* charToNet(char* host, char* netBuffer)
{
    U32 len = strlen(host);
    if (len >= 65535)
    {
        PA_printf("error char size\r\n");
    }
    U16 length = (U16)len;
    netBuffer = U16ToNet(length, netBuffer);
    strcpy(netBuffer, host);
    return netBuffer + length;
}

inline void charPrintHost(char* var)
{
    PA_printf("%s", var);
}

inline char* charPrintNet(char* netBuffer)
{
    U16 len;
    netBuffer = U16ToHost(len, netBuffer);
    PA_printf("<%d> %s", len,  netBuffer);
    return netBuffer + len;
}

//define str for unsigned char*
inline char* charToHost(unsigned char* host, char* netBuffer)
{
    U16 len;
    netBuffer = U16ToHost(len, netBuffer);
    strncpy((char*)host, netBuffer, len);
    host[len] = '\0';
    return netBuffer + len;
}

inline char* charToNet(unsigned char* host, char* netBuffer)
{
    U32 len = strlen((char*)host);
    if (len >= 65535)
    {
        PA_printf("error char size, use lstr\r\n");
    }
    U16 length = (U16)len;
    netBuffer = U16ToNet(length, netBuffer);
    strcpy(netBuffer, (char*)host);
    return netBuffer + length;
}

inline void charPrintHost(unsigned char* var)
{
    PA_printf("%s", var);
}

//define str for std::string 
inline char* charToHost(std::string& host, char* netBuffer)
{
    U16 len;
    netBuffer = U16ToHost(len, netBuffer);
    host = std::string(netBuffer, len);
    return netBuffer + len;
}

inline char* charToNet(std::string& host, char* netBuffer)
{
    U32 len = host.length();
    if (len >= 65535)
    {
        PA_printf("error char size, use lstr\r\n");
    }
    U16 length = (U16)len;
    netBuffer = U16ToNet(length, netBuffer);
    strncpy(netBuffer, host.c_str(), length);
    return netBuffer + length;
}


inline void charPrintHost(std::string& var)
{
    PA_printf("%s", var.c_str());
}

//transfer mecro
#define ToHostStr(var)\
    netBuffer = charToHost(host.var,netBuffer);

#define ToNetStr(var)\
    netBuffer = charToNet(host.var,netBuffer);

#define PrintNetStr(var)\
    PA_printf("%s:{", #var);\
    netBuffer = charPrintNet(netBuffer);\
    PA_printf("}\r\n");

#define PrintHostStr(var)\
    PA_printf("%s:{", #var);\
    charPrintHost(host.var);\
    PA_printf("}\r\n");

#endif
