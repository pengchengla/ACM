#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void PrintfVectorInt(vector<int> &vet)
{
    for (vector<int>::iterator pos = vet.begin(); pos != vet.end(); pos++)
        printf("%d ", *pos);
    putchar('\n');
}
int main()
{
    const int MAXN = 10;
    int a[MAXN];
    int i;
    for (i = 0; i < MAXN; ++i)
        a[i] = rand() % (MAXN * 2);

    //动态申请vector 并对vector建堆
    vector<int> *pvet = new vector<int>(40);
    pvet->assign(a, a + MAXN);
    printf("--------init--------\n");
    PrintfVectorInt(*pvet);
    printf("front=%d\n",pvet->front());

    //建堆
    make_heap(pvet->begin(), pvet->end());
    printf("--------make heap--------\n");
    PrintfVectorInt(*pvet);
    printf("fornt=%d\n",pvet->front());

    //加入新数据 先在容器中加入，再调用push_heap()
    pvet->push_back(25);
    push_heap(pvet->begin(), pvet->end());
    printf("--------after push heap----------\n");
    PrintfVectorInt(*pvet);

    //删除数据  要先调用pop_heap()，再在容器中删除
    pop_heap(pvet->begin(), pvet->end());
    printf("-------------------------\n");
    PrintfVectorInt(*pvet);
    printf("---------after pop heap----------\n");
    pvet->pop_back();
    pop_heap(pvet->begin(), pvet->end());
    pvet->pop_back();
    printf("--------after pop heap-----------\n");
    PrintfVectorInt(*pvet);

    //堆排序
    sort_heap(pvet->begin(), pvet->end());
    printf("--------after sort heap-----------\n");
    PrintfVectorInt(*pvet);

    delete pvet;
    return 0;
}
