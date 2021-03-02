void (*f)(int);             //f是指向函数的指针
void *bb(int);               //void* 返回类型的函数
float (*c(void))[6];        //无参指针函数，指向数组float ss[6]
double (*d[6])(void);       //元素指向double sss(void){} 函数的数组，有6个元素
float (**def)[10];          //指向float sss[10]的二级指针
double *(gh)[10];           //gh是一个指向数组的指针 数组的元素都是double*
double (*fx[10])(void);      //数组，其元素是指向函数的指针
int *((*b)[10]);            //等价于：int *(*b)[10]   指向一为数组 int sss[10]的指针
long (*fun)(int);           //函数指针
int (*((*fh)(int,int)))(int);//函数指针 所指向的函数的返回值为函数指针
