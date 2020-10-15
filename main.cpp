#include "sqlist.h"
#include <iostream>

using namespace std;

int main() {
    SqList L;
    int op = 1;//操作指令

    int i;//元素位序
    int e;//元素
    int e_ad;//元素前驱或后继
    int pos_res;//元素查找位序

    setbuf(stdout, 0);

    while (op) {
        system("cls");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       7. LocateElem\n");
        printf("    	  2. DestroyList    8. PriorElem\n");
        printf("    	  3. ClearList      9. NextElem \n");
        printf("    	  4. ListEmpty      10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem        12. ListTraverse\n");
        printf("    	  13.ListQSort      14. LoadList\n");
        printf("    	  15.SaveList       16. ListBiSearch\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~15]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
//                printf("\n----IntiList功能待实现！\n");
                if (InitList(L) == OK) printf("线性表创建成功！\n");
                else printf("线性表创建失败！\n");
                break;
            case 2:
//                printf("\n----DestroyList功能待实现！\n");
                if (DestroyList(L) == OK)printf("线性表销毁成功！\n");
                else printf("线性表销毁失败！\n");
                break;
            case 3:
//                printf("\n----ClearList功能待实现！\n");
                if (ClearList(L) == OK)printf("线性表清空成功！\n");
                else printf("线性表清空失败！\n");
                break;
            case 4:
//                printf("\n----ListEmpty功能待实现！\n");
                if (ListEmpty(L))printf("线性表为空！\n");
                else printf("线性表非空！\n");
                break;
            case 5:
//                printf("\n----ListLength功能待实现！\n");
                if (ListLength(L) == -1)printf("线性表尚未初始化！\n");
                else printf("线性表长度为%d\n", ListLength(L));
                break;
            case 6:
//                printf("\n----GetElem功能待实现！\n");
                printf("请输入欲获取元素的位序i:");
                scanf("%d", &i);
                switch (GetElem(L, i, e)) {
                    case OK:
                        printf("线性表中位序为i的元素值为%d\n", e);
                        break;
                    case ERROR:
                        printf("位序i输入不合法！\n");
                        break;
                    case INFEASIBLE:
                        printf("线性表未初始化！\n");
                        break;
                }
                break;
            case 7:
                //printf("\n----LocateElem功能待实现！\n");
                printf("请输入元素值e:");
                scanf("%d", &e);
                i = LocateElem(L, e);
                if (i != INFEASIBLE) {
                    printf("线性表中e的位序为%d\n", i);
                } else {
                    printf("线性表中不存在这样的元素！\n");
                }
                break;
            case 8:
                //printf("\n----PriorElem功能待实现！\n");
                printf("请输入线性表中的某元素e:");
                scanf("%d", &e);
                if (PriorElem(L, e, e_ad) == OK)printf("元素%d的直接前驱为%d\n", e, e_ad);
                else printf("操作失败！\n");
                break;
            case 9:
                //printf("\n----NextElem功能待实现！\n");
                printf("请输入线性表中的某元素e:");
                scanf("%d", &e);
                if (NextElem(L, e, e_ad) == OK)printf("元素%d的直接后继为%d\n", e, e_ad);
                else printf("操作失败！\n");
                break;
            case 10:
                //printf("\n----ListInsert功能待实现！\n");
                printf("请输入插入元素e:");
                scanf("%d", &e);
                printf("请输入插入位置i:");
                scanf("%d", &i);
                if (ListInsert(L, i, e) == OK)printf("插入成功！\n");
                else printf("插入失败！\n");
                break;
            case 11:
//                printf("\n----ListDelete功能待实现！\n");
                printf("请输入待删除元素的位序i:");
                scanf("%d", &i);
                if (ListDelete(L, i, e) == OK)printf("删除成功！\n被删除元素为%d", e);
                else printf("删除失败\n");
                break;
            case 12:
                //printf("\n----ListTraverse功能待实现！\n");
                switch (ListEmpty(L)) {
                    case INFEASIBLE:
                        printf("线性表尚未初始化！\n");
                        break;
                    case TRUE:
                        printf("线性表为空！\n");
                        break;
                    case FALSE:
                        ListTraverse(L);
                        break;
                    default:
                        break;
                }
                break;
            case 13:
                if (ListQSort(L) == OK)printf("排序成功！\n");
                else printf("排序操作失败！线性表为空或未初始化\n");
                break;
            case 14:
                if (LoadList(L, "test.in") == OK)cout << "成功" << endl;
                else cout << "失败" << endl;
                break;
            case 15:
                if (SaveList(L, "test.out") == OK)cout << "成功" << endl;
                else cout << "失败" << endl;
                break;
            case 16:
                printf("请输入待查找的元素：");
                scanf("%d", &e);
                pos_res = ListBiSearch(L, e);
                switch (pos_res) {
                    case EXCEPTION:
                        printf("不满足调用条件(表已初始化;递增排序)\n");
                        break;
                    case -1:
                        printf("元素%d不存在！\n", e);
                        break;
                    default:
                        printf("元素%d的位序为%d\n", e, pos_res + 1);
                }
                break;
            case 0:
                break;
        }//end of switch
        system("pause");
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()

