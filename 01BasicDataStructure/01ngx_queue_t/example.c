//����ṹ��
typedef struct {
	u_char *str;
	ngx_queue_t qEle;
	int num;
} TestNode;

//�������򷽷�
ngx_int_t compTestNode(const ngx_queue_t *a,const ngx_queue_t *b){
	TestNode *aNode=ngx_queue_data(a,TestNode,qEle);
	TestNode *bNode=ngx_queue_data(b,TestNode,qEle);
	return aNode->num > bNode->num;
} 

//����������ʼ��
ngx_queue_t queueContainer;
ngx_queue_t_init(&queueContainer);

//��������
ngx_queue_t *q;
for(q=ngx_queue_head(&queueContainer);q!=ngx_queue_sentinel(&queueContainer);q=ngx_queue_next(q))
{
	//��ȡ�ṹ��
	TestNode *eleNode=ngx_queue_data(q,TestNode,qEle);
	//�ٽ��д��� 
} 

//����
ngx_queue_sort(&queueContainer,compTestNode); 