mkdir test
cd test; pwd #/test
echo hello;echo my;echo shell
# hello /n my /n shell
echo hello | echo my |echo shell
#shell
#管道中的命令是并行执行的，ps执行时，sleep命令可能已经结束，也可能还没有
sleep 0.01|sleep 0.01|sleep 0.01|ps|grep sleep
echo next_test
sleep 0.02|sleep 0.02|sleep 0.02|ps|grep sleep
#重定向
echo hello>a>>b>c
ls
cat a
cat b
cat c
echo 当出现多个输出重定向时，所有文件爱你都会被建立，但只有一个文件真正被写入
rm a
rm b
exit 8
rm c
ls

> out2 echo hello;cat out2
