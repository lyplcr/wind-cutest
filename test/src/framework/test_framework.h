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
#include "test_port.h"


/***********************************************�궨��*************************************************/
#define TEST_CASE_NAME_LEN 24
#define TEST_SUITE_NAME_LEN 24
#define TEST_FAIL_LIST_CNT 100
extern void test_suite_err(unsigned line);

#define FAIL_EXPECT_OUT(x,y,than) test_printf("failed expection:FILE:%s,LINE:%d:which expected "#x" %s "#y"\r\n",__FILE__,__LINE__,than)


//#define EXPECT_EQ(x,y) test_printf("FILE:%s,LINE:%d,expected %s,in fact %s\r\n",__FILE__,__LINE__,#x,#y)

/**********************************************ö�ٶ���************************************************/
#include <stdio.h>

#ifndef NULL
#define NULL (void*)0
#endif
#define err_t ut_uint32_t
#define ERR_OK 0
#define ERR_COMMAN 1
#define WIND_ASSERT_RETURN(x,y)
#define TEST_STDOUT test_printf

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
    ut_uint32_t case_cnt;//��������������
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
    ut_uint32_t cnt;
}suite_list_s;

//����ִ�н��ͳ����Ϣ
typedef struct __test_stati_s
{
	ut_uint32_t tot_suite;
	ut_uint32_t tot_case;
	ut_uint32_t passed_suite;
	ut_uint32_t failed_suite;
	ut_uint32_t passed_case;
	ut_uint32_t failed_case;
}test_stati_s;

//ִ��ʧ�ܵ���Ϣ
typedef struct __fail_info_s
{
	test_suite_s *suite;
	test_case_s *tcase;
	ut_uint32_t line;
	struct __fail_info_s *next;
}fail_info_s;



typedef struct __test_info_s
{
	test_stati_s stat;
	fail_info_s *faillist;
	fail_info_s *lastfail;
	ut_uint32_t failcnt;

	test_suite_s *suite;
	test_case_s *tcase;
	ut_uint32_t case_err;
	ut_uint32_t suite_err;
}stati_info_s;

/********************************************ȫ�ֱ�������**********************************************/



/********************************************ȫ�ֺ�������**********************************************/
err_t test_suite_register(test_suite_s *test_suite);
void show_test_suites(void);
void cut_test_start(char* testsuite,char *testcase);


#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
#endif // #ifndef __TEST_FRAMEWORK_H__
