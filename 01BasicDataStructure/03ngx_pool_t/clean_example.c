//�����������ļ�����������ṹ 
typedef struct {
    ngx_fd_t              fd;
    u_char               *name;
    ngx_log_t            *log;
} ngx_pool_cleanup_file_t;

//����pool�ϵ�clearnup����һ���� 
struct ngx_pool_cleanup_s {
    ngx_pool_cleanup_pt   handler;  //�ص����������������� 
    void                 *data;  //�͸��ص������Ĳ�����void*��Ϊ�˽���ָ������ת�� 
    ngx_pool_cleanup_t   *next;
};

//�������������
//����һ��cleanup 
ngx_pool_cleanup_t *cln=ngx_pool_cleanup_add(r->pool,sizeof(ngx_pool_cleanup_file_t));
if(cln==NULL) return NGX_ERROR;

cln->handler=ngx_pool_cleanup_file;
ngx_pool_cleanup_file_t *clnf=cln->data; //ָ������ת��

clnf->fd=b->file->fd;
clnf->name=b->file->name.data;
clnf->log=r->pool->log;

//�ϱߵ�������������:
 ngx_pool_cleanup_t *ngx_pool_cleanup_add(ngx_pool_t *p, size_t size);
 void ngx_pool_cleanup_file(void *data);