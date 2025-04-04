commands--
cd Gtest/
g++ -g -O0 -fprofile-arcs -ftest-coverage     State_Mapper.cpp State_Mapper_Test.cpp     -o test_StateMapper     -lgtest -lgtest_main -lgmock -pthread
 
 
$ ./test_State_Mapper //all testcases
$ ./test_State_Mapper --gtest_filter=FailedMappings.* //Run testcases based on testsuiteName
 
Command to run gcov
$ gcov -o . test_State_Mapper-State_Mapper.gcda
$ gcov -o . test_State_Mapper-State_Mapper.gcno
$ cat State_Mapper.cpp.gcov
 
 
Command to run lcov
$ lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
$ genhtml coverage.info --output-directory coverage_report
$ xdg-open coverage_report/index.html
//output
shivam278@INBSWN195368:~/Gtest$ ./test_State_Mapper
Running main() from /home/shivam278/googletest/googletest/src/gtest_main.cc
[==========] Running 7 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 7 tests from StateMapperTest
[ RUN      ] StateMapperTest.ExactMatchMappings
[       OK ] StateMapperTest.ExactMatchMappings (0 ms)
[ RUN      ] StateMapperTest.FailedMappings
[       OK ] StateMapperTest.FailedMappings (0 ms)
[ RUN      ] StateMapperTest.DirectEnumMapping
[       OK ] StateMapperTest.DirectEnumMapping (0 ms)
[ RUN      ] StateMapperTest.MixedCaseMappings
[       OK ] StateMapperTest.MixedCaseMappings (0 ms)
[ RUN      ] StateMapperTest.WhitespaceMappings
[       OK ] StateMapperTest.WhitespaceMappings (0 ms)
[ RUN      ] StateMapperTest.SpecialCharacterMappings
[       OK ] StateMapperTest.SpecialCharacterMappings (0 ms)
[ RUN      ] StateMapperTest.EnumMappingWithInvalidState
[       OK ] StateMapperTest.EnumMappingWithInvalidState (0 ms)
[----------] 7 tests from StateMapperTest (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 7 tests.



