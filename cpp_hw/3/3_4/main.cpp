// #include<iostream>
// #include<vector>
// #include<string>
// #include <cmath>
// using namespace std;

// int gcd(int a, int b)
// {
// 	if (a % b == 0) return b;
// 	else return gcd(b, a % b);
// }
// int all_gcd(vector<int> a){
//     int len=a.size();
//     int m=a[0];
//     for(int i=1;i<len;i++){
//         m=gcd(m,a[i]);
//     }
//     return m;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     while(n!=0){
//         //cout<<endl;
//         vector<int> a;
//         int a_temp=0;
//         int M=1;
//         bool no_result=false;
//         for(int i=0;i<n;i++){
//             cin>>a_temp;
//             a.push_back(a_temp);
//         }
//         int m=all_gcd(a);
//         for(int i=0;i<n;i++){
//             a[i]/=m;
//             M*=a[i];
//         }
//         #ifdef _DEBUG_
//         for(auto i:a) cout<<i;
//         cout<<endl;
//         cout<<"M:"<<M;
//         #endif
//         vector<int> M_vec;
//         for(int i=0;i<n;i++){
//             M_vec.push_back(M/a[i]);
//         }
//         #ifdef _DEBUG_
//         for(auto i:M_vec) cout<<i;
//         cout<<endl;
//         #endif 
//         vector<int> b; 
//         for(int i=0;i<n;i++){
//             int k=0;
//             double temp_b=double(a[i]*k+1)/double(M_vec[i]);
//             while(abs(temp_b-int(temp_b))>1e-10&&k<10000000){
//                 k++;
//                 temp_b=double(a[i]*k+1)/double(M_vec[i]);
//             }
//             if(int(temp_b)==temp_b) {
//                 b.push_back(int(temp_b)*M_vec[i]);
//             }
//             else
//                 no_result=true;
//         }
//         if(no_result) cout<<"NO";
//         else {
//             for(auto i:b) cout<<i<<" ";
//         }
//         cout<<endl;
//         //for(auto i:b) cout<<i<<" ";
//         cin>>n;
//     }
//     return 0;
// }
#include <stdio.h>
long EE(long a,long b,long* x,long* y)
{
	if(b==0)
    {
		*x=1;*y=0;
		return a;
	}
    long d = EE(b,a%b,x,y);
	long temp=*x;
	*x=*y;
	*y=temp-a/b*(*y);
	return d;
}
//大衍求一术的关键在于保证衍和元数互质
//所以我们只需要为每个ai找到这样的数：是其他ai的公倍数，且与对应的元数互质
//但是由于ai不互质，所以上面两个条件相互矛盾
//所以我们应该做一个与这个方程组等价的方程组
//直接用大衍求一术那一套等价方法好像不行，确定恰当的t是死穴
//还有其他的等价方法
//简单看了一下，推断等价之后的元数还是原来的元数，衍是按照互质情况求得衍，那么这个乘率的求解就相当有意思了
//所以这种推断还是不对
//运用大衍求一术，问题的关键有两个：1，如何确定ai，2，如何计算ui
int main()
{
	long lcm,gcd,r,rem,x,y,a[10],k[10],p[10],q[10],gc[10],gd[10],res[10];
	int n,i;
	scanf("%d",&n);
	while(n)
    {
		for(i = 0;i < n;i++) scanf("%ld",&a[i]);
		lcm = a[0];
		for(i = 1;i < n;i++) lcm = lcm * a[i] / EE(lcm,a[i],&x,&y);
		for(i = 0;i < n;i++) p[i] = q[i] = lcm/a[i];//Mi
		gc[n-1] = lcm;
		for(i = n-1;i > 0;i--) gc[i-1] = EE(gc[i],p[i],&x,&y);
		//
		for(i = 0;i < n;i++) gd[i] = gc[i];
		rem = 1;
		for(i = 0;i < n;i++)
        {
			gcd = EE(p[i],gc[i],&x,&y);//
			q[i] /= gcd;//
			gd[i] /= gcd;//
			//逐个求解，既然所有的bi=ui*Mi之和为一，那么我们先解u1*M1 = 1 (mod M)
			//然后解 u2*M2 = 1 - u1*m1 (mod M)
			//u2*M2 = r (mod M)
			r = rem;
			while(r < 0) r += lcm;//同余类
			r /= gcd;//
			r %= gd[i];
			EE(q[i],gd[i],&x,&y);//
			//如果所有的素因子都被覆盖，则ai取1，这是因为对应的余数应该是0，所以除数就是1
			k[i] = r * x;//
			//上面都是求ui
			while(k[i] <= 0) k[i] += a[i];//同余类
			//ui不能为负且为mi的同余类，如果ui为0，说明不需要这一位，直接加最小公倍数的倍数就行了
            res[i] = p[i] * k[i];//pi是对应的Mi,ki是对应的ui
			rem -= res[i];//rem最后总会变成最小公倍数的倍数，也就是说所有的bi总和都是1+gM
			//如果是这样的话，ki就是对应的ui
		}
		for(i = 0;i < n;i++) printf("%ld ",res[i]);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
