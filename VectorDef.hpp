#ifndef __VECTOR_DEF_HPP__
#define __VECTOR_DEF_HPP__

#define ToHostV(type, var, size)\
    for(unsigned int i=0; i < size; i++){\
        ToHost(type, var[i]);}

#define ToNetV(type, var, size)\
    for(unsigned int i=0; i < size; i++){\
        ToNet(type, var[i]);}

#define PrintNetV(type, var, size)\
    PA_printf("%s: [", #var);\
    for(unsigned int i = 0; i < size; i++){\
        PA_printf("%s[%d]:{", #var, i);\
        netBuffer = type##PrintNet(netBuffer);\
        PA_printf("},\r\n");}\
    PA_printf("]\r\n");

#define PrintHostV(type, var, size)\
    PA_printf("%s: [", #var);\
    for(unsigned int i = 0; i < size; i++){\
        PA_printf("%s[%d]:{", #var, i);\
        type##PrintHost(host.var[i]);\
        PA_printf("},\r\n");}\
    PA_printf("]\r\n");

#endif
