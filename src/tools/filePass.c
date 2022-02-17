/*
 *  Copyright 2014, China UnionPay Co., Ltd.  All right reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF CHINA UNIONPAY CO.,
 *  LTD.  THE CONTENTS OF THIS FILE MAY NOT BE DISCLOSED TO THIRD
 *  PARTIES, COPIED OR DUPLICATED IN ANY FORM, IN WHOLE OR IN PART,
 *  WITHOUT THE PRIOR WRITTEN PERMISSION OF CHINA UNIONPAY CO., LTD.
 *
 *  
 *
 *  filePass������ģ��.
 *
 *  Edit History:
 *
 */

 /** @file
      @brief  filePass������ģ��.

      @ingroup tools

      @section sec12_4_1     12.4.1 ����˵��
        ���ܹ���

      @section sec12_4_2     12.4.2 ����˵��
        @li "string.h"
        @li "stdio.h"

      @section sec12_4_3     12.4.3 �ؼ��������ڲ��ṹ����
        ��

      @author pengbao
*/

static char * _file_pass_c_ID="$Id: filePass.c,v 1.8 2017/06/05 11:25:08 zhenwang Exp $";


#include <stdio.h>
#include <string.h>

int enCrypt(char *key, int keyLen, char *data, int dataLen);
int deCrypt(char *key, int keyLen, char *data, int dataLen);
void printHelp();

/** @brief  ������

      @par ��������: 
          ������

      @param
        @li void

      @return  ��

      @par �㷨����:
        ��

      @par �ؼ��������ڲ��ṹ����:      
        ��

      @par ������������: 
        ������
        
      @par ���ݿ��ʹ�ã�  
        @li ��

      @par�ļ�ʹ�ã�   
        @li "string.h"
        @li "stdio.h"

      @par IPCʹ��  
        ��

      @exception 
        ��
        
*/
int main(int argc, char ** argv)
{
    int ret = 0;

    if (argc != 4) {
        printHelp();

        return -1;
    }

    printf("\n");

    if (argv[1][0] == '0')
    {
        ret = enCrypt(argv[3], strlen(argv[3]), argv[2], strlen(argv[2]));
        if (0 != ret)
        {
            printHelp();

            return -1;
        }

        printf("\n\t----------------------------------------\n");
        printf("\t    ���ܺ�����Ϊ:[%s]\n", argv[2]);
        printf("\t----------------------------------------\n\n");
    }
    else if (argv[1][0] == '1')
    {
        ret = deCrypt(argv[3], strlen(argv[3]), argv[2], strlen(argv[2]));
        if (0 != ret)
        {
            printHelp();

            return -1;
        }

        printf("\n\t----------------------------------------\n");
        printf("\t    ���ܺ�����Ϊ:[%s]\n", argv[2]);
        printf("\t----------------------------------------\n\n");
    }
    else
    {
        printf("\n\t--�����������------------\n");
        printHelp();

        return -1;
    }

     return 0;
}


/** @brief  ��Կ���ܺ���

      @par ��������: 
          ��Կ���ܺ���

      @param
        @li void

      @return  ��

      @par �㷨����:
        ��

      @par �ؼ��������ڲ��ṹ����:      
        ��

      @par ������������: 
        ��Կ���ܺ���
        
      @par ���ݿ��ʹ�ã�  
        @li ��

      @par�ļ�ʹ�ã�   
        @li "string.h"
        @li "stdio.h"

      @par IPCʹ��  
        ��

      @exception 
        ��
        
*/

int enCrypt(char *key, int keyLen, char *data, int dataLen)
{
    int i = 0;

    if (NULL == key || NULL == data) {
        printf("\t  ��ָ�����\n\n");

        return -1;
    }
    
    if (keyLen < 1 || dataLen < 1) {
        printf("\t  ��Կ�����볤�ȴ���,�������0,keyLen:[%d], dataLen:[%d]\n\n", keyLen, dataLen);

        return -1;
    }
    
    if (keyLen != dataLen) {
        printf("\t  ��Կ����[%d]�����볤��[%d]��ͬ,������ͬ!\n\n", keyLen, dataLen);

        return -1;
    }

    for (i = 0; i < keyLen; i++) {
        if ( key[i] < '0'                  || 
            (key[i] > '9' && key[i] < 'A') || 
            (key[i] > 'Z' && key[i] < 'a') ||
             key[i] > 'z'                 ) {
            printf("\t  ��Կ[%s]�����Ƿ��ַ�!\n\n", key);

            return -1;
        }
    }

    for (i = 0; i < dataLen; i++) {
        if ((data[i] < '0'                   || 
            (data[i] > '9' && data[i] < 'A') || 
            (data[i] > 'Z' && data[i] < 'a') ||
             data[i] > 'z'                  ) &&
             data[i] != '_'                 ) {
            printf("\t����[%s]�����Ƿ��ַ�!\n\n", data);

            return -1;
        }
    }

    for (i = 0; i < keyLen; i++) {
        if (key[i] >= '0' && key[i] <= '9') {
            key[i] -= 48; 

        } else if (key[i] >= 'A' && key[i] <= 'Z') {
            key[i] -= 55; 

        } else if (key[i] >= 'a' && key[i] <= 'z') {
            key[i] -= 61; 
        }
    }

    for (i = 0; i < dataLen; i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            data[i] -= 48; 
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] -= 55; 
        } else if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] -= 61; 
        } else if (data[i] == '_') {
            data[i] = '_';
        }    
    }    
    
    for (i = 0; i < dataLen ; i++) {
        if (data[i] != '_') {
            data[i] += key[i];
            if (data[i] > 61) {
                data[i] -= 62;
            }

            if (data[i] >= 0 && data[i] < 10) {
                data[i] += 48;
            
            } else if (data[i] >= 10 && data[i] <= 35) {
                data[i] += 55;
                
            } else if (data[i] > 35 && data[i] <= 61) {
                data[i] += 61;
            }
        }
    }
    
    return 0;
}

/** @brief  ��Կ���ܺ���

      @par ��������: 
          ��Կ���ܺ���

      @param
        @li void

      @return  ��

      @par �㷨����:
        ��

      @par �ؼ��������ڲ��ṹ����:      
        ��

      @par ������������: 
        ��Կ���ܺ���
        
      @par ���ݿ��ʹ�ã�  
        @li ��

      @par�ļ�ʹ�ã�   
        @li "string.h"
        @li "stdio.h"

      @par IPCʹ��  
        ��

      @exception 
        ��
        
*/
int deCrypt(char *key, int keyLen, char *data, int dataLen)
{
    int i = 0;

    if (NULL == key || NULL == data) {
        printf("��ָ�����\n");

        return -1;
    }

    if (keyLen < 1 || dataLen < 1) {
        printf("������Կ/���ݳ��ȴ���,�������0,keyLen:[%d],dataLen:[%d]\n",
                                    keyLen,
                                    dataLen);

        return -1;
    }

    if (keyLen != dataLen) {
        printf("������Կ����[%d]�����ݳ���[%d]�����,�������\n",
                                    keyLen,
                                    dataLen);

        return -1;
    }

    for (i = 0; i < keyLen; i++) {
        if ( key[i] < '0' ||
              (key[i] > '9' && key[i] < 'A') ||
            (key[i] > 'Z' && key[i] < 'a') ||
             key[i] > 'z') {

            printf("��Կ[%s]�����Ƿ�����,�Ϸ����ݷ�Χ[0-9, a-z, A-Z]\n", key);

            return -1;
        }
    }

    for (i = 0; i < dataLen; i++)
    {
        if ((data[i] < '0'                   ||
            (data[i] > '9' && data[i] < 'A') ||
            (data[i] > 'Z' && data[i] < 'a') ||
             data[i] > 'z'                  ) &&
             data[i] != '_') 
        {
            printf("����[%s]�����Ƿ�����,�Ϸ����ݷ�Χ[0-9, a-z, A-Z, _]\n", data);

            return -1;
        }
    }

    for (i = 0; i < keyLen; i++)
    {
        if (key[i] >= '0' && key[i] <= '9')
        {
            key[i] -= 48;
        } else if (key[i] >= 'A' && key[i] <= 'Z')
        {
            key[i] -= 55;
        } else if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] -= 61;
        }
    }

    for (i = 0; i < dataLen; i++) 
    {
        if (data[i] >= '0' && data[i] <= '9')
        {
            data[i] -= 48;
        } else if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] -= 55;
        } else if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] -= 61; 
        } else if (data[i] == '_')
        {
            data[i] = '_';
        }
    }

    for (i = 0; i < dataLen; i++) 
    {
        if (data[i] != '_') {
            data[i] -= key[i];
            if (data[i] < 0) 
            {
                data[i] += 62;
            }
            
            if (data[i] >= 0 && data[i] < 10) 
            {
                data[i] += 48;        
            } else if (data[i] >= 10 && data[i] <= 35) 
            {
                data[i] += 55;
            
            } else if (data[i] > 35 && data[i] <= 61) 
            {
                data[i] += 61;
            }
        }
    }

    printf("��������ɹ�\n");

    return 0;
}

/** @brief  ��ӡ������Ϣ

      @par ��������: 
          ��ӡ������Ϣ

      @param
        @li void

      @return  ��

      @par �㷨����:
        ��

      @par �ؼ��������ڲ��ṹ����:      
        ��

      @par ������������: 
        ��ӡ������Ϣ
        
      @par ���ݿ��ʹ�ã�  
        @li ��

      @par�ļ�ʹ�ã�   
        @li "string.h"
        @li "stdio.h"

      @par IPCʹ��  
        ��

      @exception 
        ��
        
*/
void printHelp()
{
    printf("\t----------------------------------------\n");
    printf("\t  �����������, �����ʽ:\n");
    printf("\t  filePass 0 ��������  ������Կ\n\n");
    printf("\t  filePass 1 ��������  ������Կ\n\n");
    printf("\t  ע�⣺\n");
    printf("\t    1. ��Կ���Ⱥ����볤�ȱ���һ��\n");
    printf("\t    2. ��Կ�������ֵ����[0-9,A-Z,a-z��_]\n");
    printf("\t----------------------------------------\n");
}
