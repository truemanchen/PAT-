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
    int is_out = 0;//坑点！是否有匹配上且输出的 
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
                //结算前一个人
                printf("Total amount: $%.2lf\n", totel);
                totel = 0;
            }
            is_out = 0; //这句导致第1，2个测试点过不了，名字一旦不同，不管有没有输出过，is_out要初始化 
        }
        else {
            //看看状态对不对的上，对不上为"";
            if (last.state == "on-line" && a[i].state == "off-line") {
                //计算时间
                int t = a[i].d - last.d;
                int t1 = t * 24 * 60;
                int t2 = (a[i].h - last.h) * 60;
                int t3 = (a[i].m - last.m);
                //计算bill，不需要一分钟一分钟的跑，找到规律即可 
                double money = 0;
                money += t * sum_p;
                //小时 
                if (a[i].h > last.h)//比大小 
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
                //分钟 
                money -= last.m * p[last.h];//多的减去，注意是 p[last.h]
                money += a[i].m * p[a[i].h];//少的加上，注意是 p[a[i].h]
                //如果这个人没有被输出过 
                if (is_out == 0)
                {
                    cout << a[i].name << " ";
                    printf("%02d\n", month);
                    is_out = 1;//匹配上且输出了 
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
    if (is_out) {//匹配上的才输出 
        printf("Total amount: $%.2lf\n", totel);
    }
    return 0;
}