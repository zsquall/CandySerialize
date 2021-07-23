#ifndef __INTERGER_DEF_HPP__
#define __INTERGER_DEF_HPP__

//Define for 8bit number
inline char* U8ToNet(U8& host, char* netBuffer)
{
    (*(U8*)netBuffer) = host;
    netBuffer += 1;
    return netBuffer;
}

inline char* U8ToHost(U8& host, char* netBuffer)
{
    host = (*(U8*)netBuffer);
    netBuffer += 1;
    return netBuffer;
}

inline char* U8PrintNet(char* netBuffer)
{
    PA_printf("%u", (*(U8*)netBuffer));
    netBuffer += 1;
    return netBuffer;
}

inline void U8PrintHost(U8 var)
{
    if (sizeof(U8) != 1)
    {
        PA_printf("<err type U8 %d>", sizeof(U8));
    }
    PA_printf("%u", (U8)var);
}


//Define for 16bit number
inline char* U16ToNet(U16& host, char* netBuffer)
{
    (*(U16*)netBuffer) = htons(host);
    netBuffer += 2;
    return netBuffer;
}

inline char* U16ToHost(U16& host, char* netBuffer)
{
    host = ntohs(*(U16*)netBuffer);
    netBuffer += 2;
    return netBuffer;
}

inline char* U16PrintNet(char* netBuffer)
{
    PA_printf("%u(%u)", (*(U16*)netBuffer), ntohs(*(U16*)netBuffer));
    netBuffer += 2;
    return netBuffer;
}

inline void U16PrintHost(U16 var)
{
    if (sizeof(U16) != 2)
    {
        PA_printf("<err type U16 %d>", sizeof(U16));
    }
    PA_printf("%u", (U16)var);
}

//Define for 32bit number
inline char* U32ToNet(U32& host, char* netBuffer)
{
    (*(U32*)netBuffer) = htonl(host);
    netBuffer += 4;
    return netBuffer;
}

inline char* U32ToHost(U32& host, char* netBuffer)
{
    host = ntohl(*(U32*)netBuffer);
    netBuffer += 4;
    return netBuffer;
}

inline char* U32PrintNet(char* netBuffer)
{
    PA_printf("%u(%u)", (*(U32*)netBuffer), ntohl(*(U32*)netBuffer));
    netBuffer += 4;
    return netBuffer;
}

inline void U32PrintHost(U32 var)
{
    if (sizeof(U32) != 4)
    {
        PA_printf("<err type U32 %d>", sizeof(U32));
    }
    PA_printf("%u", (U32)var);
}


//transfer mecro
#define PrintNet(type, var)\
    PA_printf("%s:{", #var);\
    netBuffer = type##PrintNet(netBuffer);\
    PA_printf("}\r\n");

#define PrintHost(type, var)\
    PA_printf("%s:{", #var);\
    if(sizeof(type) != sizeof(host.var)){\
        PA_printf("<len error %d-%d>\r\n", sizeof(type), sizeof(host.var));}\
    type##PrintHost((type&)host.var);\
    PA_printf("}\r\n");

#define ToHost(type, var)\
    netBuffer = type##ToHost((type&)host.var, netBuffer)

#define ToNet(type, var)\
    netBuffer = type##ToNet((type&)host.var, netBuffer);

#endif
