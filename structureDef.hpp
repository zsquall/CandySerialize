#ifndef __STRUCTURE_DEF_H__
#define __STRUCTURE_DEF_H__
#include "common.hpp"
#include "IntegerDef.hpp"
#include "StringDef.hpp"
//add extra def here

//DEFINE STRUCTURE BEGIN
#define capMsgHeader_pack(m)\
    m(U16, msg_id);

//Define the transfer struct here
#define sipNsmProfile_set_req_t_pack(m)\
    m(capMsgHeader, header);\
    m(U32,   nsmIndex);\
    m##Str(nsmName);\
    m(U8,    outFrom_noInvNbr);\
    m(U8,    outPrivacy);\
    m(U8,    outFrom_pi);\
    m##Str(incFrom_noclip);\
    m##Str(incFrom_clipPrivate);\
    m##Str(incFrom_cliUa);\
    m(U8,    npi_to_user);\
    m(U8,    ton_to_user);\
    m(U8,    cdpn_ton_to_user);\
    m##Str(internation_prefix);\
    m##Str(nation_prefix);\
    m##Str(country_code);\
    m(U8,    cgpn_nbr_length);

//Add the struct here
#define net_str_reg(add)\
    add(capMsgHeader)\
    add(sipNsmProfile_set_req_t)

//For use
enum {\
    TYPE_START = 0xAC00,
    net_str_reg(DefEnum)\
};

net_str_reg(CStrDef);
net_str_reg(IMPORT);

#endif
