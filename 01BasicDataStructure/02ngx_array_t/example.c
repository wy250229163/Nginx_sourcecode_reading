//定义结构体
typedef struct {
	u_char *str;
	ngx_queue_t qEle;
	int num;
} TestNode;

//创建array
ngx_array_t dynamicArray=ngx_array_create(cf->pool,1,sizeof(TestNode));

//添加元素
TestNode *a=ngx_array_push(dynamicArray);
a->num=1;
TestNode *a=ngx_array_push(dynamicArray);
a->num=2;

TestNode *b=ngx_array_push_n(dynamicArray,3);
b->num=3;
(b+1)->num=4;
(b+2)->num=5;

//遍历
TestNode *nodeArray=dynamicArray->elts;
ngx_uint_t arraySeq=0;

for(;arraySeq < dynamicArray->nelts;++arraySeq)
{
	a=nodeArray+arraySeq;
	//继续处理a元素 
} 

//销毁
ngx_array_destory(dynamicArray); 