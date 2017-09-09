/****************************************Copyright (c)**************************************************
**                                       ��  ��  ��  ��
** ��   ��   ��: test_mode.h / test_mode.c
** ��   ��   ��: �ܽ���
** ����޸�����: 2015/1/24 16:29:55
** ��        ��: 
**  
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: �ܽ���
** ��  ��: v1.0
** �ա���: 2015/1/24 16:29:55
** �衡��: ԭʼ�汾
**
**--------------��ǰ�汾�޶�----------------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: ��Ԫ���������Ĳ���ģ��
** ���ļ���C����Դ�ļ�ģ��������ɡ�------------��纣����Ʒ��������Ʒ��------------
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus


/*********************************************ͷ�ļ�����***********************************************/
#include "test_framework.h"


/********************************************�ڲ���������**********************************************/



/********************************************�ڲ���������*********************************************/



/********************************************ȫ�ֱ�������**********************************************/



/********************************************ȫ�ֺ�������**********************************************/
static void test_case_setup(void)
{
    test_printf("test case setup\r\n");
}

static void test_case_teardown(void)
{
    test_printf("test case teardown\r\n");
}

static void test_suite_setup(void)
{
    test_printf("test suite setup\r\n");
}

static void test_suite_teardown(void)
{
    test_printf("test suite teardown\r\n");
}



static void test1(void)
{
    test_printf("test1 test\r\n");
	EXPECT_EQ(0,1);
}

static void test2(void)
{
	int res = 1;
    test_printf("test2 test\r\n");
	EXPECT_EQ(1,res);
	EXPECT_NE(0,res);
}


static test_case_s testcase[] = 
{
    {"Test1",test_case_setup,test_case_teardown,test1},
    {"Test2",test_case_setup,test_case_teardown,test2},
};


test_suite_s testsuite = 
{
    "TestSuite1",
    sizeof(testcase)/sizeof(test_case_s),
    testcase,
    test_suite_setup,
    test_suite_teardown,
    NULL
};

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
