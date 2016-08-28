/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
** ��   ��   ��: test_framework.h / test_framework.c
** ��   ��   ��: �ܽ���
** ����޸�����: 2015/1/24 15:42:27
** ��        ��: 
**  
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: �ܽ���
** ��  ��: v1.0
** �ա���: 2015/1/24 15:42:27
** �衡��: ԭʼ�汾
**
**--------------��ǰ�汾�޶�----------------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: wind_os��ϵͳ�Ĳ��Կ���ļ����ڿ���¼̳��˸��ֹ��ܵĵ�Ԫ����
** ���ļ���C����Դ�ļ�ģ��������ɡ�------------��纣����Ʒ��������Ʒ��------------
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
#ifndef __TEST_FRAMEWORK_H__
#define __TEST_FRAMEWORK_H__
#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/*********************************************ͷ�ļ�����***********************************************/
//#include "port/wind_config.h"
//#include "port/wind_types.h"



/***********************************************�궨��*************************************************/
#define TEST_CASE_NAME_LEN 24
#define TEST_SUITE_NAME_LEN 24
#define TEST_FAIL_LIST_CNT 100
extern void test_suite_err(unsigned line);

#define FAIL_EXPECT_OUT(x,y,than) printf("failed expection:FILE:%s,LINE:%d:which expected "#x" %s "#y"\r\n",__FILE__,__LINE__,than)

//����x == y
#define EXPECT_EQ(x,y) \
	do{if((x) != (y)) \
	{FAIL_EXPECT_OUT(x,y,"==");test_suite_err(__LINE__);}\
	}while(0)

//����x != y
#define EXPECT_NE(x,y) \
	do{if((x) == (y)) \
	{FAIL_EXPECT_OUT(x,y,"!=");test_suite_err(__LINE__);}\
	}while(0)

//����x > y
#define EXPECT_GREATER(x,y) \
	do{if((x) <= (y)) \
	{FAIL_EXPECT_OUT(x,y,">");test_suite_err(__LINE__);}\
	}while(0)

//����x < y
#define EXPECT_SMALLER(x,y) \
	do{if((x) <= (y)) \
	{FAIL_EXPECT_OUT(x,y,"<");test_suite_err(__LINE__);}\
	}while(0)

//����x <= y
#define EXPECT_NOT_GREATER(x,y) \
	do{if((x) <= (y)) \
	{FAIL_EXPECT_OUT(x,y,"<=");test_suite_err(__LINE__);}\
	}while(0)

//����x >= y
#define EXPECT_NOT_SMALLER(x,y) \
	do{if((x) <= (y)) \
	{FAIL_EXPECT_OUT(x,y,">=");test_suite_err(__LINE__);}\
	}while(0)

//#define EXPECT_EQ(x,y) printf("FILE:%s,LINE:%d,expected %s,in fact %s\r\n",__FILE__,__LINE__,#x,#y)
/**********************************************ö�ٶ���************************************************/
#include <stdio.h>
typedef unsigned int u32_t;
typedef int s32_t;
#ifndef NULL
#define NULL (void*)0
#endif
#define err_t u32_t
#define ERR_OK 0
#define ERR_COMMAN 1
#define WIND_ASSERT_RETURN(x,y)
#define TEST_STDOUT printf

/*********************************************�ṹ�嶨��***********************************************/
//���������ṹ
typedef struct 
{
    char name[TEST_CASE_NAME_LEN];
    void (*setup)(void);
    void (*teardown)(void);
    void (*test)(void);
}test_case_s;

//�����׽ṹ
typedef struct __test_suite_s
{
    char name[TEST_SUITE_NAME_LEN];
    u32_t case_cnt;//��������������
    test_case_s *tcase;
    //void (*init)(void);
    void (*setup)(void);
    void (*teardown)(void);
    struct __test_suite_s *next;
}test_suite_s;

//ȫ�ֵ�test suite�б�
typedef struct __test_suite_global
{
    test_suite_s *head;
    test_suite_s *tail;
    u32_t cnt;
}test_suite_global_s;

//����ִ�н��ͳ����Ϣ
typedef struct __test_stati_s
{
	u32_t tot_suite;
	u32_t tot_case;
	u32_t passed_suite;
	u32_t failed_suite;
	u32_t passed_case;
	u32_t failed_case;
}test_stati_s;

//ִ��ʧ�ܵ���Ϣ
typedef struct __fail_info_s
{
	test_suite_s *suite;
	test_case_s *tcase;
	u32_t line;
	struct __fail_info_s *next;
}fail_info_s;



typedef struct __test_info_s
{
	test_stati_s stat;
	fail_info_s *faillist;
	fail_info_s *lastfail;
	u32_t failcnt;

	test_suite_s *suite;
	test_case_s *tcase;
	u32_t case_err;
	u32_t suite_err;

}test_info_s;

/********************************************ȫ�ֱ�������**********************************************/
extern test_suite_s testsuite;
extern test_suite_s testsuite1;
extern test_suite_s testsuite2;
extern test_suite_s testsuite3;



/********************************************ȫ�ֺ�������**********************************************/
err_t test_suite_register(test_suite_s *test_suite);
//void test_framework_init(void);
//void test_start(void);
void test_framework_entry(void);


#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
#endif // #ifndef __TEST_FRAMEWORK_H__
