#include "sqlist.h"
#include <iostream>

using namespace std;

int main() {
    SqList L;
    int op = 1;//����ָ��

    int i;//Ԫ��λ��
    int e;//Ԫ��
    int e_ad;//Ԫ��ǰ������
    int pos_res;//Ԫ�ز���λ��

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
        printf("    ��ѡ����Ĳ���[0~15]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
//                printf("\n----IntiList���ܴ�ʵ�֣�\n");
                if (InitList(L) == OK) printf("���Ա����ɹ���\n");
                else printf("���Ա���ʧ�ܣ�\n");
                break;
            case 2:
//                printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                if (DestroyList(L) == OK)printf("���Ա����ٳɹ���\n");
                else printf("���Ա�����ʧ�ܣ�\n");
                break;
            case 3:
//                printf("\n----ClearList���ܴ�ʵ�֣�\n");
                if (ClearList(L) == OK)printf("���Ա���ճɹ���\n");
                else printf("���Ա����ʧ�ܣ�\n");
                break;
            case 4:
//                printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
                if (ListEmpty(L))printf("���Ա�Ϊ�գ�\n");
                else printf("���Ա�ǿգ�\n");
                break;
            case 5:
//                printf("\n----ListLength���ܴ�ʵ�֣�\n");
                if (ListLength(L) == -1)printf("���Ա���δ��ʼ����\n");
                else printf("���Ա���Ϊ%d\n", ListLength(L));
                break;
            case 6:
//                printf("\n----GetElem���ܴ�ʵ�֣�\n");
                printf("����������ȡԪ�ص�λ��i:");
                scanf("%d", &i);
                switch (GetElem(L, i, e)) {
                    case OK:
                        printf("���Ա���λ��Ϊi��Ԫ��ֵΪ%d\n", e);
                        break;
                    case ERROR:
                        printf("λ��i���벻�Ϸ���\n");
                        break;
                    case INFEASIBLE:
                        printf("���Ա�δ��ʼ����\n");
                        break;
                }
                break;
            case 7:
                //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
                printf("������Ԫ��ֵe:");
                scanf("%d", &e);
                i = LocateElem(L, e);
                if (i != INFEASIBLE) {
                    printf("���Ա���e��λ��Ϊ%d\n", i);
                } else {
                    printf("���Ա��в�����������Ԫ�أ�\n");
                }
                break;
            case 8:
                //printf("\n----PriorElem���ܴ�ʵ�֣�\n");
                printf("���������Ա��е�ĳԪ��e:");
                scanf("%d", &e);
                if (PriorElem(L, e, e_ad) == OK)printf("Ԫ��%d��ֱ��ǰ��Ϊ%d\n", e, e_ad);
                else printf("����ʧ�ܣ�\n");
                break;
            case 9:
                //printf("\n----NextElem���ܴ�ʵ�֣�\n");
                printf("���������Ա��е�ĳԪ��e:");
                scanf("%d", &e);
                if (NextElem(L, e, e_ad) == OK)printf("Ԫ��%d��ֱ�Ӻ��Ϊ%d\n", e, e_ad);
                else printf("����ʧ�ܣ�\n");
                break;
            case 10:
                //printf("\n----ListInsert���ܴ�ʵ�֣�\n");
                printf("���������Ԫ��e:");
                scanf("%d", &e);
                printf("���������λ��i:");
                scanf("%d", &i);
                if (ListInsert(L, i, e) == OK)printf("����ɹ���\n");
                else printf("����ʧ�ܣ�\n");
                break;
            case 11:
//                printf("\n----ListDelete���ܴ�ʵ�֣�\n");
                printf("�������ɾ��Ԫ�ص�λ��i:");
                scanf("%d", &i);
                if (ListDelete(L, i, e) == OK)printf("ɾ���ɹ���\n��ɾ��Ԫ��Ϊ%d", e);
                else printf("ɾ��ʧ��\n");
                break;
            case 12:
                //printf("\n----ListTraverse���ܴ�ʵ�֣�\n");
                switch (ListEmpty(L)) {
                    case INFEASIBLE:
                        printf("���Ա���δ��ʼ����\n");
                        break;
                    case TRUE:
                        printf("���Ա�Ϊ�գ�\n");
                        break;
                    case FALSE:
                        ListTraverse(L);
                        break;
                    default:
                        break;
                }
                break;
            case 13:
                if (ListQSort(L) == OK)printf("����ɹ���\n");
                else printf("�������ʧ�ܣ����Ա�Ϊ�ջ�δ��ʼ��\n");
                break;
            case 14:
                if (LoadList(L, "test.in") == OK)cout << "�ɹ�" << endl;
                else cout << "ʧ��" << endl;
                break;
            case 15:
                if (SaveList(L, "test.out") == OK)cout << "�ɹ�" << endl;
                else cout << "ʧ��" << endl;
                break;
            case 16:
                printf("����������ҵ�Ԫ�أ�");
                scanf("%d", &e);
                pos_res = ListBiSearch(L, e);
                switch (pos_res) {
                    case EXCEPTION:
                        printf("�������������(���ѳ�ʼ��;��������)\n");
                        break;
                    case -1:
                        printf("Ԫ��%d�����ڣ�\n", e);
                        break;
                    default:
                        printf("Ԫ��%d��λ��Ϊ%d\n", e, pos_res + 1);
                }
                break;
            case 0:
                break;
        }//end of switch
        system("pause");
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

