//待清理项是文件，就用这个结构 
typedef struct {
    ngx_fd_t              fd;
    u_char               *name;
    ngx_log_t            *log;
} ngx_pool_cleanup_file_t;

//挂载pool上的clearnup链的一个项 
struct ngx_pool_cleanup_s {
    ngx_pool_cleanup_pt   handler;  //回调函数，负责清理工作 
    void                 *data;  //送给回调函数的参数，void*是为了进行指针类型转换 
    ngx_pool_cleanup_t   *next;
};

//以下是清理过程
//创建一项cleanup 
ngx_pool_cleanup_t *cln=ngx_pool_cleanup_add(r->pool,sizeof(ngx_pool_cleanup_file_t));
if(cln==NULL) return NGX_ERROR;

cln->handler=ngx_pool_cleanup_file;
ngx_pool_cleanup_file_t *clnf=cln->data; //指针类型转换

clnf->fd=b->file->fd;
clnf->name=b->file->name.data;
clnf->log=r->pool->log;

//上边的两个函数如下:
 ngx_pool_cleanup_t *ngx_pool_cleanup_add(ngx_pool_t *p, size_t size);
 void ngx_pool_cleanup_file(void *data);