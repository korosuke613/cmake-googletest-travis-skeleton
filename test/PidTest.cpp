/**
 * PidTest.cpp
 */

/* コンパイル(平木場) 
$ g++-7 -w ../apps/commons/Pid.cpp PidTest.cpp gtest_main.o gtest-all.o -I. -I.. -I../googletest/googletest/include
$ ./a.out
*/

#include "Pid.hpp" // このヘッダファイルのcppファイルをテスト
#include "gtest/gtest.h"

// Pidのtarget以下の数字を入力すると負の数を出力する
TEST( detectBarrierTest, CalculateTest1 )
{
    Pid pid(0.5, 0.5, 0.5, 30.0);
    
    // コンストラクタの引数targetに30を入れる
    pid.setPid(0.5, 0.5, 0.5, 30.0);
    // calculateにtarget以下の値を入力する
    pid.calculate(20.0);
    // アウトプットは負の数になる
    ASSERT_LT( pid.get_output(), 0.0 );
}
