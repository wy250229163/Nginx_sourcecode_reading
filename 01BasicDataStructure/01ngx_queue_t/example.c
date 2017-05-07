//定义结构体
typedef struct {
	u_char *str;
	ngx_queue_t qEle;
	int num;
} TestNode;

//定义排序方法
ngx_int_t compTestNode(const ngx_queue_t *a,const ngx_queue_t *b){
	TestNode *aNode=ngx_queue_data(a,TestNode,qEle);
	TestNode *bNode=ngx_queue_data(b,TestNode,qEle);
	return aNode->num > bNode->num;
} 

//定义链表并初始化
ngx_queue_t queueContainer;
ngx_queue_t_init(&queueContainer);

//遍历链表
ngx_queue_t *q;
for(q=ngx_queue_head(&queueContainer);q!=ngx_queue_sentinel(&queueContainer);q=ngx_queue_next(q))
{
	//获取结构体
	TestNode *eleNode=ngx_queue_data(q,TestNode,qEle);
	//再进行处理 
} 

//排序
ngx_queue_sort(&queueContainer,compTestNode); 