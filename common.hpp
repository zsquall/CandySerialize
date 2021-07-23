#ifndef __CANDY_COMMON_HPP__
#define __CANDY_COMMON_HPP__

#ifndef PA_printf
#define PA_printf(fmt...) printf(fmt)
#define PA_log_output()
#endif

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

//define a ID for every structure for error check
#define DefEnum(NET_TYPE) NET_TYPE##TypeId,
inline U16 getTypeTypeId(char* netBuffer)
{
    U16 typeId = 0;
    U16ToHost(typeId, netBuffer);
    return typeId;
}

//define function
#define FunctionDef(NET_TYPE) \
    char* NET_TYPE##ToNet(NET_TYPE& host, char* netBuffer){\
        U16 typeId = (NET_TYPE##TypeId );\
        netBuffer = U16ToNet(typeId, netBuffer);\
        NET_TYPE##_pack(ToNet)\
        return netBuffer;\
    }\
    char* NET_TYPE##ToHost(NET_TYPE& host, char* netBuffer){\
        U16 typeId = 0;\
        netBuffer = U16ToHost(typeId, netBuffer);\
        if(typeId != (NET_TYPE##TypeId)){\
            PA_printf("err decode function: %d %d\r\n", typeId, NET_TYPE##TypeId);\
            return netBuffer;}\
        NET_TYPE##_pack(ToHost)\
        return netBuffer;\
    }\
    char* NET_TYPE##PrintNet(char* netBuffer){\
        U16 typeId = 0;\
        netBuffer = U16ToHost(typeId, netBuffer);\
        if(typeId != (NET_TYPE##TypeId)){\
            PA_printf("err print function: %d %d\r\n", typeId, NET_TYPE##TypeId);\
            return netBuffer;}\
        NET_TYPE##_pack(PrintNet)\
        return netBuffer;\
    }\
    void NET_TYPE##PrintHost(NET_TYPE& host){\
        NET_TYPE##_pack(PrintHost)\
    }

//For include the function
#define IMPORT(NET_TYPE)\
    extern char* NET_TYPE##ToNet(NET_TYPE& host, char* netBuffer);\
    extern char* NET_TYPE##ToHost(NET_TYPE& host, char* netBuffer);\
    extern char* NET_TYPE##PrintNet(char* netBuffer);\
    extern void NET_TYPE##PrintHost(NET_TYPE& host);

//C-structure define
#define DefStructure(type, var) type var
#define DefStructureStr(var) std::string var
#define CStrDef(NET_TYPE)\
    typedef struct{\
        NET_TYPE##_pack(DefStructure)\
    }NET_TYPE;

#endif
