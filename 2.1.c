#include <stdio.h>
#include <string.h>
#include <time.h>


struct Item {
    char code[20];   // 条码
    char name[50];   // 名称
    double price;    // 价格

};//商品信息的储存结构


struct Item items[100] = {
    {"001", "Cola",     3.50},
    {"002", "Lollipop", 0.50},
    {"003", "Noodles",  6.00}
};//储存的所有商品
int item_count = 3;   // 现在有 3 个商品


struct CartItem {
    char code[20];   // 条码，哪一个商品
    int qty;         // 数量，买了几个
};//购物车暂存

struct CartItem cart[100];
int cart_count = 0;  // 购物车里现在有几种商品


int find_item(char *code)
{
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}// 在 items 数组里把条码从头到尾找一遍。
//如果找到了，就把这个商品在数组里的下标返回给你。
//如果找完了都没找到，就返回 -1    这样只要有数字就大于0，没有数字就小于0，方便后续作判断



int find_cart( char *code)
{
    for (int i = 0; i < cart_count; i++) {
        if (strcmp(cart[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}//与上一个步骤同理，在购物车里查找有没有这个商品


void print_cart()
{
    printf("Item     Pri.   Qty   Amount\n");
    printf("-----------------------------\n");
    double total = 0.0;
    for (int i = 0; i < cart_count; i++) {
        int idx = find_item(cart[i].code);
        if (idx >= 0) {
            double amount = items[idx].price * cart[i].qty;
            total += amount;//把各个商品的价格加起来
            printf("%-8s %.2f   x%d    %.2f\n",items[idx].name,items[idx].price,cart[i].qty,amount);
        }
    }
    printf("-----------------------------\n");
    printf("Total = %.2f\n", total);//打印小票部分的函数
}


void checkout()
{
    if (cart_count == 0) {
        printf("Cart is empty.\n");
        return;
    }

    print_cart();

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[100];
    char date_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", t);

    char filename[100];
    snprintf(filename, sizeof(filename), "data_%s.txt", date_str);//仍然创建两个个字符串数组，
    //把日期这一字符串全部存到数组中，
    //文件名和存有日期的数组存到文件名的字符串数组里，
    //最后把文件名字符串数组作为文件名输出

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("please check the content\n");
    } else {
        double total = 0.0;
        fprintf(fp, "Time: %s\n", time_str);
        for (int i = 0; i < cart_count; i++) {
            int idx = find_item(cart[i].code);
            if (idx >= 0) {
                double amount = items[idx].price * cart[i].qty;
                total += amount;
                fprintf(fp, "%s,%s,%.2f,%d,%.2f\n",items[idx].code,items[idx].name,items[idx].price,cart[i].qty,amount);
            }//把商品信息存储到带日期里的文件中
        }
        fprintf(fp, "TOTAL,%.2f\n", total);
        fprintf(fp, "---\n");
        fclose(fp);
    }

    cart_count = 0;   // 清空购物车
}


void sales_ask( char *day)
{
    char date_str[20];
    if (day == NULL || strlen(day) == 0) {
        time_t now = time(NULL);
        strftime(date_str, sizeof(date_str),
                 "%Y-%m-%d", localtime(&now));
    } else {
        strncpy(date_str, day, sizeof(date_str) - 1);
        date_str[sizeof(date_str) - 1] = '\0';
    }

    char filename[100];
    snprintf(filename, sizeof(filename), "data_%s.txt", date_str);

    FILE *fp = fopen(filename, "r");
    double daily = 0.0;
    if (fp != NULL) {
        char hang[200];
        while (fgets(hang, sizeof(hang), fp)) {
            printf("%s", hang);
            if (strncmp(hang, "TOTAL,", 6) == 0) {
                double t;
                sscanf(hang + 6, "%lf", &t);
                daily += t;
            }
        }
        fclose(fp);
    }
    printf("--------------------------------\n");
    printf("Daily: %.2f\n", daily);
}

/* ========== 打印商品表 ========== */
void print_prices()
{
    printf("Item No. Pri.\n");
    printf("---\n");
    for (int i = 0; i < item_count; i++) {
        printf("%s %s %.2f\n",
               items[i].name, items[i].code,
               items[i].price);
    }
}

/* ========== 管理员模式 ========== */
void admin_mode()
{
    char password[50];
    printf("Password: ");
    scanf("%49s", password);

    if (strcmp(password, "admin123") != 0) {
        printf("Wrong password.\n");
        return;
    }
    printf("Admin mode.\n");//判断初始密码的正误

    char cmd[50];
    while (1) {
        printf("admin> ");
        scanf("%49s", cmd);

        if (strcmp(cmd, "back") == 0) {
            printf("Bye.\n");
            break;
        }
        else if (strcmp(cmd, "prices") == 0) {
            print_prices();
        }
        else if (strcmp(cmd, "setprice") == 0) {
            char code[20];
            double np;
            scanf("%19s %lf", code, &np);

            int idx = find_item(code);
            
                items[idx].price = np;
                printf("Price updated.\n");
            }
        
        else if (strcmp(cmd, "itemadd") == 0) {
            char code[20], name[50];
            double np;
            scanf("%19s %49s %lf", code, name, &np);

            if (find_item(code) >= 0) {                                      
                printf("ERROR: code already exists\n");
            } else if (item_count >= 100) {
                printf("ERROR: too many items\n");
            } else {
                strcpy(items[item_count].code, code);//strcpy：字符串复制函数。
                strcpy(items[item_count].name, name);
                items[item_count].price = np;
                item_count++;
                printf("%s(%s) added.\n", name, code);
            }//用户输入的条码 code，去 items 数组里找。
               //如果找到了，find_item 返回这个商品的下标，比如 0、1、2。
               //因为下标一定大于等于 0，所以 find_item(code) >= 0 就表示“这个条码已经存在”。
               //如果条码已经存在，就不能再加同一个条码，于是打印 ERROR: code already exists。
               //否则把字符串的对应部分复制到对应的序号里去





        }
        else if (strcmp(cmd, "itemdel") == 0) {
            char code[20];
            scanf("%19s", code);

            int idx = find_item(code);
            if (idx < 0) {
                printf("ERROR: code not found\n");
            } else {
                printf("%s(%s) removed.\n",
                       items[idx].name, items[idx].code);

                /* 从商品数组删除：后面的往前挪 */
                for (int i = idx; i < item_count - 1; i++) {
                    items[i] = items[i + 1];
                }
                item_count--;

                /* 如果购物车里有这个商品，也删掉 */
                for (int i = 0; i < cart_count; ) {
                    if (strcmp(cart[i].code, code) == 0) {
                        for (int j = i; j < cart_count - 1; j++) {
                            cart[j] = cart[j + 1];
                        }
                        cart_count--;
                    } else {
                        i++;
                    }
                }
            }
        }
        else {
            printf("Unknown admin command.\n");
        }
    }
}
//主程序：
int main(void)
{
    char number[20];

    printf("please input the number to gain the ticket\n");

    while (1) {
        scanf("%19s", number);

        /* ---------- 先判断是不是命令 ---------- */
        if (strcmp(number, "print") == 0) {
            print_cart();
        }
        else if (strcmp(number, "drop") == 0) {
            cart_count = 0;
            printf("Cart cleared.\n");
        }
        else if (strcmp(number, "checkout") == 0) {
            checkout();
        }
        else if (strcmp(number, "sales") == 0) {
            char day[100];
            int duqu = getchar();
            if (duqu == ' ') {
                scanf("%99s", day);
            } else {
                day[0] = '\0';
            }
            sales_ask(day);
        }
        else if (strcmp(number, "newday") == 0) {
            printf("New day started. Today's sales records cleared.\n");
        }
        else if (strcmp(number, "prices") == 0) {
            print_prices();
        }
        else if (strcmp(number, "admin") == 0) {
            admin_mode();
        }
        else if (strcmp(number, "exit") == 0 || strcmp(number, "quit") == 0) {
            printf("Bye.\n");
            break;
        }
        /* ---------- 不是命令，就当条码扫描 ---------- */
        else {
            int delta = 1;              // +1 表示加，-1 表示减
            char *code = number;  // 真正的条码

            if (number[0] == '-') {     // 如果输入是 -001
                delta = -1;
                code = number + 1;      // 跳过减号
            }

            int idx = find_item(code);  // 找商品
            if (idx < 0) {
                printf("ERROR: code not found\n");
            } else {
                int ci = find_cart(code);  // 找购物车里有没有
                if (ci < 0) {
                    // 购物车里没有这个商品
                    if (delta < 0) {
                        printf("%s %.2f x0 = 0.00\n",
                               items[idx].name, items[idx].price);
                    } else {
                        ci = cart_count;
                        strcpy(cart[ci].code, code);
                        cart[ci].qty = 0;
                        cart_count++;
                    }
                }

                if (ci >= 0) {
                    cart[ci].qty += delta;

                    if (cart[ci].qty <= 0) {
                        printf("%s %.2f x0 = 0.00\n",
                               items[idx].name, items[idx].price);
                        // 从购物车删除
                        for (int i = ci; i < cart_count - 1; i++) {
                            cart[i] = cart[i + 1];
                        }
                        cart_count--;
                    } else {
                        printf("%s %.2f x%d = %.2f\n",
                               items[idx].name,
                               items[idx].price,
                               cart[ci].qty,
                               items[idx].price * cart[ci].qty);
                    }
                }
            }
        }
    }
    return 0;
}

