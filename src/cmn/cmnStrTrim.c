/*
 *  Copyright 2014, China Union Pay Co., Ltd.  All right reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOUretValE CODE OF CHINA UNION PAY CO.,
 *  LTD.  THE CONTENTS OF THIS FILE MAY NOT BE DISCLOSED TO THIRD
 *  PARTIES, COPIED OR DUPLICATED IN ANY FORM, IN WHOLE OR IN PART,
 *  WITHOUT THE PRIOR WRITTEN PERMISSION OF CHINA UNION PAY CO., LTD.
 *
 *  $Id: cmnStrTrim.c,v 1.8 2017/06/05 11:25:05 zhenwang Exp $
 *
 *    字符串公共函数.
 *
 *  Edit History:
 *
 *    2014/02/27    - Created by qzfan.
 */


/** @file  
      @brief  字符串TRIM原子函数

      @ingroup cmn 

      @section 4_11_1     4.11.1 程序说明
         包括字符串左右空格处理的原子函数

      @section 4_11_2     4.11.2 引用说明
        @li 无


      @section 4_11_3     4.11.3 关键变量和内部结构定义
        @li  无

      @author qzfan
*/

#ifndef __CMNSTRTRIM_C__
#define __CMNSTRTRIM_C__

static char _cmnStrTrim_c_ID[] = "$Id: cmnStrTrim.c,v 1.8 2017/06/05 11:25:05 zhenwang Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



/** @brief  原子操作：去掉字符串右边空格

      @par 函数功能: 
          去掉字符串右边空格。

      @param 
        @li pStr - 待处理字符串

      @return  
      @retval pStr

      @par 算法描述:
         从字符串尾部开始过滤，
         遇到第一个非空格的字符后，
         补0x00并返回字符串首地址指针
        

      @par 关键变量及内部结构定义:      
        @li  无

      @par 函数处理流程: 
            检查输入参数
            根据算法获取处理后的字符串

      @par 数据库表使用：  
        @li  无

      @par文件使用：   
        @li 无


      @par IPC使用
        @li  无

      @exception
        @li  无
*/
/*
 *  Function:  cmnStrRTrim
 *
 *      去掉字符串的右空格
 *   注意：应用尽量使用该函数
 *
 *  Parameters:
 *
 *      cpStr - the inpurt string
 *
 *  Return Value:
 *
 *      SUCCESS - success
 *      FAILURE - failure
 */
 
char   *cmnStrRTrim(char   *pStr)
{
    char *pOrig = NULL;
    
    if (!pStr)
    {
        return NULL;
    }
    
    if (*pStr == 0x00)
    {
        return pStr;
    }

    for (pOrig = pStr + strlen(pStr) - 1; pOrig >= pStr; --pOrig)
    {
        if (*pOrig != ' ')
            break;
    }

    *(pOrig + 1) = '\0';

    return pStr;
}


/** @brief  原子操作：去掉字符串右边空格

      @par 函数功能: 
          去掉字符串右边空格。

      @param 
        @li pStr - 待处理字符串

      @return  
      @retval 处理后字符串长度

      @par 算法描述:
         从字符串尾部开始过滤，
         遇到第一个非空格的字符后，
         补0x00，
         并返回字符串长度
        

      @par 关键变量及内部结构定义:      
        @li  无

      @par 函数处理流程: 
            检查输入参数
            根据算法获取处理后的字符串
            并返回处理后字符串的长度

      @par 数据库表使用：  
        @li  无

      @par文件使用：   
        @li 无


      @par IPC使用
        @li  无

      @exception
        @li  无
*/

/*
 *  Function:  cmnStrRTrimLen
 *
 *      去掉字符串的右空格,
 *      并返回去掉空格之后的字符串长度
 *   注意：应用尽量使用该函数
 *
 *  Parameters:
 *
 *      cpStr - the inpurt string
 *
 *  Return Value:
 *
 *      返回去掉空格之后的字符串长度
 *      
 */
 
int cmnStrRTrimLen(char   *pStr)
{
    char *pOrig = NULL;
    
    if (!pStr)
    {
        return 0;
    }
    
    if (*pStr == 0x00)
    {
        return 0;
    }

    for (pOrig = pStr + strlen(pStr) - 1; pOrig >= pStr; --pOrig)
    {
        if (*pOrig != ' ')
            break;
    }

    *(pOrig + 1) = '\0';
    
    return (pOrig - pStr + 1);
}



/** @brief  原子操作：去掉字符串左边空格

      @par 函数功能: 
          去掉字符串左边空格。

      @param 
        @li pStr - 待处理字符串

      @return  
      @retval pStr

      @par 算法描述:
         从字符串首指针开始过滤，
         遇到空格指针往后移，
         当第一个非空格的字符后返回当前指针
        

      @par 关键变量及内部结构定义:      
        @li  无

      @par 函数处理流程: 
            检查输入参数
            根据算法获取处理后的字符串

      @par 数据库表使用：  
        @li  无

      @par文件使用：   
        @li 无


      @par IPC使用
        @li  无

      @exception
        @li  无
*/
/*
 *  Function:  cmnStrLTrim
 *
 *      去掉字符串的左空格
 *   注意，该函数效率一般
 *
 *  Parameters:
 *
 *      cpStr - the inpurt string
 *
 *  Return Value:
 *
 *      SUCCESS - success
 *      FAILURE - failure
 */
 
char   *cmnStrLTrim(char   *pStr)
{
    char    *pOrig  = pStr;
    char    *p      = pOrig;
    int     trimmed = 0;

    if (!pStr)
    {
        return NULL;
    }
        
    do
    {
        if (*pOrig != ' ' || trimmed)
        {
            trimmed = 1;
            *p++ = *pOrig;
        }
    } while (*pOrig++ != '\0');
    
    return pOrig;
}


/** @brief  原子操作：去掉字符串左右两边空格

      @par 函数功能: 
          去掉字符串左右两边空格。

      @param 
        @li pStr - 待处理字符串

      @return  
      @retval pStr

      @par 算法描述:
         从字符串尾部开始过滤，
         遇到第一个非空格的字符后补0x00
         并且从字符串首指针开始过滤，遇到空格指针往后移，
         当遇到第一个非空格的字符后返回当前指针
        

      @par 关键变量及内部结构定义:      
        @li  无

      @par 函数处理流程: 
            检查输入参数
            根据算法获取处理后的字符串

      @par 数据库表使用：  
        @li  无

      @par文件使用：   
        @li 无


      @par IPC使用
        @li  无

      @exception
        @li  无
*/
/*
 *  Function:  cmnStrTrim
 *
 *      去掉字符串的左右空格
 *   注意，该函数效率最高，但实际上未删除左边的空格
 *
 *  Parameters:
 *
 *      cpStr - the inpurt string
 *
 *  Return Value:
 *
 *      SUCCESS - success
 *      FAILURE - failure
 */

char   *cmnStrTrim(char *cpStr) 
{
    char        *p1 = NULL;
    char        *p2 = NULL;

    if (cpStr == NULL) 
    {
        return NULL;
    }

    p1 = cpStr;
    while (*p1 ==' ') 
    {
        p1++;
    }
    
    p2 = cpStr + strlen(cpStr) - 1;
    while (*p2 == ' ') 
    {
        p2--;
    }
    
    p2++;
    *p2 = 0;

    strcpy(cpStr, p1);

    return cpStr;
}



/** @brief  原子操作：去掉字符串左右两边空格包括换行符

      @par 函数功能: 
          去掉字符串左右两边空格,包括换行符。

      @param 
        @li pStr - 待处理字符串

      @return  
      @retval pStr

      @par 算法描述:
         从字符串尾部开始过滤，
         遇到第一个非空格与换行符的字符后补0x00
         并且从字符串首指针开始过滤，遇到空格指针往后移，
         当遇到第一个非空格的字符后返回当前指针
        

      @par 关键变量及内部结构定义:      
        @li  无

      @par 函数处理流程: 
            检查输入参数
            根据算法获取处理后的字符串

      @par 数据库表使用：  
        @li  无

      @par文件使用：   
        @li 无


      @par IPC使用
        @li  无

      @exception
        @li  无
*/
/*
 *  Function:  cmnStrSTrim
 *
 *      强力去字符串的左右空格与回车等特殊符号
 *      如果左右换行也会被过滤掉
 *   注意：由于使用了 memmove 系统调用，不适合联机交易中使用
 *
 *  Parameters:
 *
 *      cpStr - the inpurt string
 *
 *  Return Value:
 *
 *      SUCCESS - success
 *      FAILURE - failure
 */

char   *cmnStrSTrim(char *cpStr) 
{
    char        *hp = NULL;
    char        *tp = NULL;

    if (cpStr == NULL) 
    {
        return NULL;
    }

    hp = cpStr;
    tp = cpStr + strlen(cpStr) - 1;

    while (hp <= tp && *hp <= 0x20)
    {
        hp++;
    }

    if (hp < tp) 
    {
        while (*tp <= 0x20)
        {
            tp--;
        }

        *(tp+1) = 0x00;
        memmove(cpStr, hp, tp - hp + 2);
    }
    else if (hp == tp) 
    {

        if (*tp <= 0x20) 
        {
            cpStr[0] = 0x00;
        } 
        else 
        {
            cpStr[0] = *hp;
            cpStr[1] = 0x00;
        }
    }
    else 
    {
        cpStr[0] = 0x00;
    }

    return cpStr;
}

#endif
