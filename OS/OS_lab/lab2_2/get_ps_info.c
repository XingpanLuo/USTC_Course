#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct task{
	int pid;
	int is_running;
	char comm[16];
	double cpu_time;
};
int cmp_func(const void *a,const void *b){
	int a_pid=((struct task *)a)->pid;
	int b_pid=((struct task *)b)->pid;
	int a_time=(int)(((struct task*)a)->cpu_time*100);
	int b_time=(int)(((struct task*)b)->cpu_time*100);
	int a_run=((struct task*)a)->is_running;
	int b_run=((struct task*)b)->is_running;
	if(a_run||b_run)
		return a_run>b_run?-1:1;
	else 
		if(a_time==b_time) 
			return a_pid>b_pid?1:-1;
		else
			return a_time>b_time?-1:1;
}
int main(void){
int num=0;
int index=0;
int pid=1;
int is_running=0;
int pre_time=0;
int cur_time=0;
char comm[16];
int flag=1;
double cpu_time=0;
struct task list[100];
int list_num=0;
int loop_num=0;
time_t start;
time_t end;
double dpre_time[100];
const char default_comm[16]="DEFAULT_COMM";
for(int i=0;i<20;i++){
	syscall(333,&pid,&is_running,&comm,&pre_time,&i);
	dpre_time[i]=pre_time;
	list[i].pid=1;
	list[i].is_running=0;
	list[i].cpu_time=(double)pre_time/1e7;
	strcpy(list[i].comm,default_comm);
}
start=time(NULL);
sleep(1);
while(flag){
	loop_num++;
	syscall(332,&num);
	list_num=0;
	printf("[Syscall] get_ps_info\n");
	printf("PID		COMM		%%CPU		ISRUNNING\n");
	for(index=0;index<num;index++){		
		syscall(333,&pid,&is_running,&comm,&cur_time,&index);
		end=time(NULL);
		double sum_time=end-start;
		list[list_num].pid=pid;
		list[list_num].is_running=is_running;
		if(strlen(comm)<8){
			int j=0;
			for(j=strlen(comm);j<9;j++) comm[j]=' ';
			comm[j-1]='\0';
		}
		strcpy(list[list_num].comm,comm);
		list[list_num].cpu_time=((double)cur_time-dpre_time[index])/1e7;
		dpre_time[index]=(double)cur_time/1e7;
		list[list_num].cpu_time/=sum_time;
		list_num++;
		int pre_num=num;
		syscall(332,&num);
		if(pre_num!=num){
			index=0;
		}
	}
	qsort(list,num,sizeof(struct task),cmp_func);
	for(int i=0;i<21;i++){
		printf("%d		%s		%.2f %%			%d\n",
		      list[i].pid,list[i].comm,list[i].cpu_time,list[i].is_running);
	}	
	sleep(1);
	syscall("clear");
	flag=1;
}
return 0;
}
