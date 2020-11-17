#include<iostream>
#include<pthread.h>
#include<unistd.h>
#define print(x) std::cout<<x<<std::endl
class single
{
	private:
	static single* ptr;
	single(){}
	int n;

	public:

	static void* fun(void* arg)
	{
		print("in thread function");
		sleep(2);
		return 0;

	}

	static single* getinstance()
	{
		if(!ptr)
		ptr=new single();
		return ptr;
	}

	void set()
	{
		ptr->n=10;
	}
};
single* single::ptr=0;
int main()
{
	single* p=single::getinstance();
	p->set();
	pthread_t tid;
	pthread_create(&tid,0,p->fun,0);
	pthread_join(tid,0);
}



