#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    string name;
    int d;
    int h;
    int m;
    string state;
}a[1005];
bool cmp(node& x, node& y) {
    if (x.name == y.name) {
        if (x.d == y.d) {
            if (x.h == y.h) {
                return x.m < y.m;
            }
            else {
                return x.h < y.h;
            }
        }
        else {
            return x.d < y.d;
        }
    }
    else {
        return x.name < y.name;
    }
}

int main()
{
    double p[25];
    double sum_p = 0;
    for (int i = 0; i <= 23; i++) {
        cin >> p[i];
        p[i] *= 0.01;
        sum_p += p[i] * 60;
    }
    int n;
    int month;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name;
        scanf("%2d:%2d:%2d:%2d", &month, &a[i].d, &a[i].h, &a[i].m);
        cin >> a[i].state;
    }
    sort(a + 1, a + 1 + n, cmp);
    /*for(int i=1;i<=n;i++){
        cout<<a[i].name<<" "<<a[i].d<<" "<<a[i].h<<" "<<a[i].m<<" "<<a[i].state<<endl;
    }*/
    node last;
    last.name = "";
    int is_out = 0;//�ӵ㣡�Ƿ���ƥ����������� 
    double totel = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            last.name = a[i].name;
            last.d = a[i].d;
            last.h = a[i].h;
            last.m = a[i].m;
            last.state = a[i].state;
            is_out = 0;
            continue;
        }
        if (a[i].name != last.name) {
            if (is_out)
            {
                //����ǰһ����
                printf("Total amount: $%.2lf\n", totel);
                totel = 0;
            }
            is_out = 0; //��䵼�µ�1��2�����Ե�����ˣ�����һ����ͬ��������û���������is_outҪ��ʼ�� 
        }
        else {
            //����״̬�Բ��Ե��ϣ��Բ���Ϊ"";
            if (last.state == "on-line" && a[i].state == "off-line") {
                //����ʱ��
                int t = a[i].d - last.d;
                int t1 = t * 24 * 60;
                int t2 = (a[i].h - last.h) * 60;
                int t3 = (a[i].m - last.m);
                //����bill������Ҫһ����һ���ӵ��ܣ��ҵ����ɼ��� 
                double money = 0;
                money += t * sum_p;
                //Сʱ 
                if (a[i].h > last.h)//�ȴ�С 
                {
                    for (int j = last.h; j < a[i].h; j++) {
                        money += p[j] * 60;
                    }
                }
                else {
                    for (int j = a[i].h; j < last.h; j++) {
                        money -= p[j] * 60;
                    }
                }
                //���� 
                money -= last.m * p[last.h];//��ļ�ȥ��ע���� p[last.h]
                money += a[i].m * p[a[i].h];//�ٵļ��ϣ�ע���� p[a[i].h]
                //��������û�б������ 
                if (is_out == 0)
                {
                    cout << a[i].name << " ";
                    printf("%02d\n", month);
                    is_out = 1;//ƥ����������� 
                }
                printf("%02d:%02d:%02d %02d:%02d:%02d ", last.d, last.h, last.m, a[i].d, a[i].h, a[i].m);
                printf("%d $%.2lf\n", t1 + t2 + t3, money);
                totel += money;
            }
        }
        last.name = a[i].name;
        last.d = a[i].d;
        last.h = a[i].h;
        last.m = a[i].m;
        last.state = a[i].state;
    }
    if (is_out) {//ƥ���ϵĲ���� 
        printf("Total amount: $%.2lf\n", totel);
    }
    return 0;
}