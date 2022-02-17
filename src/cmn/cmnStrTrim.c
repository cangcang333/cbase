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
 *    �ַ�����������.
 *
 *  Edit History:
 *
 *    2014/02/27    - Created by qzfan.
 */


/** @file  
      @brief  �ַ���TRIMԭ�Ӻ���

      @ingroup cmn 

      @section 4_11_1     4.11.1 ����˵��
         �����ַ������ҿո����ԭ�Ӻ���

      @section 4_11_2     4.11.2 ����˵��
        @li ��


      @section 4_11_3     4.11.3 �ؼ��������ڲ��ṹ����
        @li  ��

      @author qzfan
*/

#ifndef __CMNSTRTRIM_C__
#define __CMNSTRTRIM_C__

static char _cmnStrTrim_c_ID[] = "$Id: cmnStrTrim.c,v 1.8 2017/06/05 11:25:05 zhenwang Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



/** @brief  ԭ�Ӳ�����ȥ���ַ����ұ߿ո�

      @par ��������: 
          ȥ���ַ����ұ߿ո�

      @param 
        @li pStr - �������ַ���

      @return  
      @retval pStr

      @par �㷨����:
         ���ַ���β����ʼ���ˣ�
         ������һ���ǿո���ַ���
         ��0x00�������ַ����׵�ַָ��
        

      @par �ؼ��������ڲ��ṹ����:      
        @li  ��

      @par ������������: 
            ����������
            �����㷨��ȡ�������ַ���

      @par ���ݿ��ʹ�ã�  
        @li  ��

      @par�ļ�ʹ�ã�   
        @li ��


      @par IPCʹ��
        @li  ��

      @exception
        @li  ��
*/
/*
 *  Function:  cmnStrRTrim
 *
 *      ȥ���ַ������ҿո�
 *   ע�⣺Ӧ�þ���ʹ�øú���
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


/** @brief  ԭ�Ӳ�����ȥ���ַ����ұ߿ո�

      @par ��������: 
          ȥ���ַ����ұ߿ո�

      @param 
        @li pStr - �������ַ���

      @return  
      @retval ������ַ�������

      @par �㷨����:
         ���ַ���β����ʼ���ˣ�
         ������һ���ǿո���ַ���
         ��0x00��
         �������ַ�������
        

      @par �ؼ��������ڲ��ṹ����:      
        @li  ��

      @par ������������: 
            ����������
            �����㷨��ȡ�������ַ���
            �����ش�����ַ����ĳ���

      @par ���ݿ��ʹ�ã�  
        @li  ��

      @par�ļ�ʹ�ã�   
        @li ��


      @par IPCʹ��
        @li  ��

      @exception
        @li  ��
*/

/*
 *  Function:  cmnStrRTrimLen
 *
 *      ȥ���ַ������ҿո�,
 *      ������ȥ���ո�֮����ַ�������
 *   ע�⣺Ӧ�þ���ʹ�øú���
 *
 *  Parameters:
 *
 *      cpStr - the inpurt string
 *
 *  Return Value:
 *
 *      ����ȥ���ո�֮����ַ�������
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



/** @brief  ԭ�Ӳ�����ȥ���ַ�����߿ո�

      @par ��������: 
          ȥ���ַ�����߿ո�

      @param 
        @li pStr - �������ַ���

      @return  
      @retval pStr

      @par �㷨����:
         ���ַ�����ָ�뿪ʼ���ˣ�
         �����ո�ָ�������ƣ�
         ����һ���ǿո���ַ��󷵻ص�ǰָ��
        

      @par �ؼ��������ڲ��ṹ����:      
        @li  ��

      @par ������������: 
            ����������
            �����㷨��ȡ�������ַ���

      @par ���ݿ��ʹ�ã�  
        @li  ��

      @par�ļ�ʹ�ã�   
        @li ��


      @par IPCʹ��
        @li  ��

      @exception
        @li  ��
*/
/*
 *  Function:  cmnStrLTrim
 *
 *      ȥ���ַ�������ո�
 *   ע�⣬�ú���Ч��һ��
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


/** @brief  ԭ�Ӳ�����ȥ���ַ����������߿ո�

      @par ��������: 
          ȥ���ַ����������߿ո�

      @param 
        @li pStr - �������ַ���

      @return  
      @retval pStr

      @par �㷨����:
         ���ַ���β����ʼ���ˣ�
         ������һ���ǿո���ַ���0x00
         ���Ҵ��ַ�����ָ�뿪ʼ���ˣ������ո�ָ�������ƣ�
         ��������һ���ǿո���ַ��󷵻ص�ǰָ��
        

      @par �ؼ��������ڲ��ṹ����:      
        @li  ��

      @par ������������: 
            ����������
            �����㷨��ȡ�������ַ���

      @par ���ݿ��ʹ�ã�  
        @li  ��

      @par�ļ�ʹ�ã�   
        @li ��


      @par IPCʹ��
        @li  ��

      @exception
        @li  ��
*/
/*
 *  Function:  cmnStrTrim
 *
 *      ȥ���ַ��������ҿո�
 *   ע�⣬�ú���Ч����ߣ���ʵ����δɾ����ߵĿո�
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



/** @brief  ԭ�Ӳ�����ȥ���ַ����������߿ո�������з�

      @par ��������: 
          ȥ���ַ����������߿ո�,�������з���

      @param 
        @li pStr - �������ַ���

      @return  
      @retval pStr

      @par �㷨����:
         ���ַ���β����ʼ���ˣ�
         ������һ���ǿո��뻻�з����ַ���0x00
         ���Ҵ��ַ�����ָ�뿪ʼ���ˣ������ո�ָ�������ƣ�
         ��������һ���ǿո���ַ��󷵻ص�ǰָ��
        

      @par �ؼ��������ڲ��ṹ����:      
        @li  ��

      @par ������������: 
            ����������
            �����㷨��ȡ�������ַ���

      @par ���ݿ��ʹ�ã�  
        @li  ��

      @par�ļ�ʹ�ã�   
        @li ��


      @par IPCʹ��
        @li  ��

      @exception
        @li  ��
*/
/*
 *  Function:  cmnStrSTrim
 *
 *      ǿ��ȥ�ַ��������ҿո���س����������
 *      ������һ���Ҳ�ᱻ���˵�
 *   ע�⣺����ʹ���� memmove ϵͳ���ã����ʺ�����������ʹ��
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
