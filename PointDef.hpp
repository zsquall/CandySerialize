#ifndef __POINT_DEF_HPP__
#define __POINT_DEF_HPP__

#define ToHostP(type, var)\
    if((*(U8*)netBuffer == 1)){\
        netBuffer+= 1;\
        type* p = (type*)malloc(sizeof(type));\
        host.var = p;\
        netBuffer = type##ToHost((type&)(*p), netBuffer);}\
    else{\
        host.var = NULL;\
        netBuffer += 1;}

#define ToNetP(type, var)\
    if(host.var != NULL){\
        (*(U8*)netBuffer) = 1;\
        netBuffer += 1;\
        netBuffer = type##ToNet((type&)(*(host.var)), netBuffer);}\
    else{\
        (*(U8*)netBuffer) = 0;\
        netBuffer += 1;}

#define PrintNetP(type, var)\
    PA_printf("%s:{", #var);\
    if((*(U8*)netBuffer) == 1){\
        netBuffer += 1;\
        netBuffer = type##PrintNet(netBuffer);}\
    else{\
        PA_printf("NULL");\
        netBuffer += 1;\
    }\
    PA_printf("}\r\n");

#define PrintHostP(type, var)\
    PA_printf("%s:{", #var);\
    if(host.var != NULL)\
        type##PrintHost(*(host.var));\
    else PA_printf("NULL");\
    PA_printf("}\r\n");

#endif
