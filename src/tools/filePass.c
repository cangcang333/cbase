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
 *  filePass主函数模块.
 *
 *  Edit History:
 *
 */

 /** @file
      @brief  filePass主函数模块.

      @ingroup tools

      @section sec12_4_1     12.4.1 程序说明
        解密工具

      @section sec12_4_2     12.4.2 引用说明
        @li "string.h"
        @li "stdio.h"

      @section sec12_4_3     12.4.3 关键变量和内部结构定义
        无

      @author pengbao
*/

static char * _file_pass_c_ID="$Id: filePass.c,v 1.8 2017/06/05 11:25:08 zhenwang Exp $";


#include <stdio.h>
#include <string.h>

int enCrypt(char *key, int keyLen, char *data, int dataLen);
int deCrypt(char *key, int keyLen, char *data, int dataLen);
void printHelp();

/** @brief  主函数

      @par 函数功能: 
          主函数

      @param
        @li void

      @return  无

      @par 算法描述:
        无

      @par 关键变量及内部结构定义:      
        无

      @par 函数处理流程: 
        主函数
        
      @par 数据库表使用：  
        @li 无

      @par文件使用：   
        @li "string.h"
        @li "stdio.h"

      @par IPC使用  
        无

      @exception 
        无
        
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
        printf("\t    加密后密码为:[%s]\n", argv[2]);
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
        printf("\t    解密后密码为:[%s]\n", argv[2]);
        printf("\t----------------------------------------\n\n");
    }
    else
    {
        printf("\n\t--参数输入错误------------\n");
        printHelp();

        return -1;
    }

     return 0;
}


/** @brief  密钥加密函数

      @par 函数功能: 
          密钥加密函数

      @param
        @li void

      @return  无

      @par 算法描述:
        无

      @par 关键变量及内部结构定义:      
        无

      @par 函数处理流程: 
        密钥加密函数
        
      @par 数据库表使用：  
        @li 无

      @par文件使用：   
        @li "string.h"
        @li "stdio.h"

      @par IPC使用  
        无

      @exception 
        无
        
*/

int enCrypt(char *key, int keyLen, char *data, int dataLen)
{
    int i = 0;

    if (NULL == key || NULL == data) {
        printf("\t  空指针错误\n\n");

        return -1;
    }
    
    if (keyLen < 1 || dataLen < 1) {
        printf("\t  密钥或密码长度错误,必须大于0,keyLen:[%d], dataLen:[%d]\n\n", keyLen, dataLen);

        return -1;
    }
    
    if (keyLen != dataLen) {
        printf("\t  密钥长度[%d]与密码长度[%d]不同,必须相同!\n\n", keyLen, dataLen);

        return -1;
    }

    for (i = 0; i < keyLen; i++) {
        if ( key[i] < '0'                  || 
            (key[i] > '9' && key[i] < 'A') || 
            (key[i] > 'Z' && key[i] < 'a') ||
             key[i] > 'z'                 ) {
            printf("\t  密钥[%s]包含非法字符!\n\n", key);

            return -1;
        }
    }

    for (i = 0; i < dataLen; i++) {
        if ((data[i] < '0'                   || 
            (data[i] > '9' && data[i] < 'A') || 
            (data[i] > 'Z' && data[i] < 'a') ||
             data[i] > 'z'                  ) &&
             data[i] != '_'                 ) {
            printf("\t密码[%s]包含非法字符!\n\n", data);

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

/** @brief  密钥加密函数

      @par 函数功能: 
          密钥加密函数

      @param
        @li void

      @return  无

      @par 算法描述:
        无

      @par 关键变量及内部结构定义:      
        无

      @par 函数处理流程: 
        密钥加密函数
        
      @par 数据库表使用：  
        @li 无

      @par文件使用：   
        @li "string.h"
        @li "stdio.h"

      @par IPC使用  
        无

      @exception 
        无
        
*/
int deCrypt(char *key, int keyLen, char *data, int dataLen)
{
    int i = 0;

    if (NULL == key || NULL == data) {
        printf("空指针错误\n");

        return -1;
    }

    if (keyLen < 1 || dataLen < 1) {
        printf("传入密钥/数据长度错误,必须大于0,keyLen:[%d],dataLen:[%d]\n",
                                    keyLen,
                                    dataLen);

        return -1;
    }

    if (keyLen != dataLen) {
        printf("传入密钥长度[%d]与数据长度[%d]不相等,必须相等\n",
                                    keyLen,
                                    dataLen);

        return -1;
    }

    for (i = 0; i < keyLen; i++) {
        if ( key[i] < '0' ||
              (key[i] > '9' && key[i] < 'A') ||
            (key[i] > 'Z' && key[i] < 'a') ||
             key[i] > 'z') {

            printf("密钥[%s]包含非法数据,合法数据范围[0-9, a-z, A-Z]\n", key);

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
            printf("数据[%s]包含非法数据,合法数据范围[0-9, a-z, A-Z, _]\n", data);

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

    printf("解密密码成功\n");

    return 0;
}

/** @brief  打印帮助信息

      @par 函数功能: 
          打印帮助信息

      @param
        @li void

      @return  无

      @par 算法描述:
        无

      @par 关键变量及内部结构定义:      
        无

      @par 函数处理流程: 
        打印帮助信息
        
      @par 数据库表使用：  
        @li 无

      @par文件使用：   
        @li "string.h"
        @li "stdio.h"

      @par IPC使用  
        无

      @exception 
        无
        
*/
void printHelp()
{
    printf("\t----------------------------------------\n");
    printf("\t  输入参数错误, 输入格式:\n");
    printf("\t  filePass 0 密码明文  加密密钥\n\n");
    printf("\t  filePass 1 密码密文  加密密钥\n\n");
    printf("\t  注意：\n");
    printf("\t    1. 密钥长度和密码长度必须一致\n");
    printf("\t    2. 密钥和密码的值仅限[0-9,A-Z,a-z和_]\n");
    printf("\t----------------------------------------\n");
}
