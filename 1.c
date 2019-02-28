#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ResultManagement 
{
    char ketQuaDoi1;
    char ketQuaDoi2;
};

struct Team
{
    char code[20];
    char name[50];
    char manager[20];
};

struct Lich 
{
    char maTran[50];
    char ngayThiDau[20];
    char gioThiDau[10];
    char sanThiDau[30];
    struct Team doiNha;
    struct Team doiKhach;
    int ketQuaDoiNha;
    int ketQuaDoiKhach;
};

void thongKe();
void ketQua();
void xemLich();
void taoLich();
void quanli();
void displayTeam();
void updateTeam(); 
void addTeam();     
void teamMenu();
void mainMenu();

struct ResultManagement results[200];
struct Lich lichs[200];
struct Team teams[200];

int count = 0;
int countLich = 0;
int countKetQua = 0;

int main(int argc, char const *argv[])
{

    mainMenu();

    return 0;
}
void mainMenu()
{
    char choice;
    do
    {

        printf("--- Chào Mừng Bạn Đến Với V-League 2018 ---\n");
        printf("===========================================\n");
        printf("1. Quản lí danh sách đội bóng\n");
        printf("2. Quản lí lịch thi đấu\n");
        printf("3. Quản lí kết quả thi đấu\n");
        printf("4. Thống kê\n");
        printf("0. thoát\n");
        fflush(stdin);

        printf("#Chọn: ");
        scanf("%c", &choice);

        switch (choice)
        {
        case '1':
            teamMenu();
            break;

        case '2':
            quanli();
            break;

        case '3':
            ketQua();
            break;

        case '4':
            thongKe();
            break;

        case 0:

            break;

        default:
            break;
        }
    } while (choice != '0');
}

void teamMenu()
{
    char choice;
    do
    {
        printf("-------------------------------------------\n");
        printf("         Quản lí danh sách đội bóng        \n");
        printf("==========================================\n");
        printf("1. Xem danh sách đội bóng\n");
        printf("2. Cập nhật thông tin đội bóng\n");
        printf("3. Thêm một đội bóng mới\n");
        printf("0. Trở về Menu chính\n");
        printf("#Chọn: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice)
        {
        case '1':
            displayTeam();
            break;

        case '2':
            updateTeam();
            break;

        case '3':
            addTeam();
            break;

        case 0:
            break;

        default:
            break;
        }

    } while (choice != '0');
}

void addTeam()
{
    struct Team team;
    char yn;
    do
    {
        printf("Nhập mã đội: ");
        fflush(stdin);
        scanf("%[^\n]s", team.code);
        fflush(stdin);
        printf("Nhập tên đội: ");
        scanf("%[^\n]s", team.name);
        fflush(stdin);
        printf("Nhập tên huấn luyện viên: ");
        scanf("%[^\n]s", team.manager);
        fflush(stdin);

        printf("Bạn muốn tiếp tục?(Y/N): ");
        fflush(stdin);
        scanf("%c", &yn);

        while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N')
        {
            printf("Bạn nhập sai, mời nhập lại: ");
            fflush(stdin);
            scanf("%c", &yn);
        }

        teams[count] = team;
        count++;

    } while (yn != 'n' && yn != 'N');
}
void displayTeam()
{

    printf("--------------DANH SACH DOI BONG----------------\n");
    printf("-------------------------------------------------\n");
    printf("| %-6s | %-16s | %-26s |\n", "Mã Đội", "Tên Đội", "Tên Huấn luyện viên");
    printf("|----------------------------------------------|\n");
    for (int i = 0; i < count; i++)
    {
        printf("| %-6s | %-12s | %-20s |\n", teams[i].code, teams[i].name, teams[i].manager);
        printf("|----------------------------------------------|\n");
    }
}
void updateTeam()
{
    if (count == 0)
    {
        return;
    }
    int index;
    char yn;
    do
    {
        struct Team team;
        printf("Nhập mã đội: ");

        do
        {
            fflush(stdin);
            scanf("%[^\n]s", team.code);
            index = -1;

            for (int i = 0; i < count; i++)
            {

                if (strcmp(team.code, teams[i].code) == 0)
                {
                    index = i;
                }
            }

            if (index == -1)
            {
                printf("Mã đội không tồn tại, mời bạn nhập lại: ");
            }
        } while (index == -1);

        char cn; 

        printf("Nhập tên đội: ");
        fflush(stdin);
        scanf("%[^\n]s", team.name);
        fflush(stdin);
        printf("Nhập tên huấn luyện viên: ");
        fflush(stdin);
        scanf("%[^\n]s", team.manager);
        fflush(stdin);

        printf("Bạn muốn cập nhật thông tin? (Y/N): ");
        scanf("%c", &cn);

        if (cn == 'y' || cn == 'Y')
        {
            teams[index] = team;
            printf("Thông tin đã được cập nhật!\n");
        }
        else
        {
            printf("Thông tin không được cập nhật!\n");
        }

        printf("Bạn có muốn tiếp tục?(Y/N)");
        fflush(stdin);
        scanf("%c", &yn);

        while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N')
        {
            printf("Bạn nhập sai, mời nhập lại: ");
            fflush(stdin);
            scanf("%c", &yn);
        }

        teams[index] = team;
    } while (yn != 'n' && yn != 'N');
}
void quanli()
{
    char choice1;
    do
    {

        printf("------------------------------------------\n");
        printf("           Quản lí lịch thi đấu            \n");
        printf("==========================================\n");
        printf("1. Xem lịch thi đấu\n");
        printf("2. Tạo lịch thi đấu\n");
        printf("0. Trở về Menu chính\n");
        printf("#Chọn: ");
        fflush(stdin);
        scanf("%c", &choice1);

        switch (choice1)
        {
        case '1':
            xemLich();
            break;

        case '2':
            taoLich();
            break;

        case 0:
            break;

        default:
            break;
        }
    } while (choice1 != '0');
}
void xemLich()
{
    printf("--------------------------------------LICH THI DAU--------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-23s | %-10s | %-14s | %-15s | %-12s | %-15s |\n", "Mã TRận", "Đội Nhà", "Đội Khách", "Ngày", "Giờ", "Sân");
    printf("|--------------------------------------------------------------------------------------------|\n");

    for (int i = 0; i < countLich; i++)
    {
        printf("| %-20s | %-7s | %-7s | %-14s | %-10s | %-14s |\n", lichs[i].maTran, lichs[i].doiNha.name, lichs[i].doiKhach.name, lichs[i].ngayThiDau, lichs[i].gioThiDau, lichs[i].sanThiDau);
        printf("|--------------------------------------------------------------------------------------------|\n");
    }
}
void taoLich()
{
    char yn;
    char maDoiNha[20];
    char maDoiKhach[20];
    int index = -1;

    do
    {
        struct Lich lich;

        printf("Nhập mã trận thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", lich.maTran);

        while (1)
        {
            int flag = 0;
            printf("Nhập đội nhà: ");
            fflush(stdin);
            scanf("%[^\n]s", maDoiNha);
            for (int i = 0; i < count; i++)
            {
                if (strcmp(maDoiNha, teams[i].code) == 0)
                {
                    lich.doiNha = teams[i];
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                break;
            }
            printf("Đội bóng không tồn tại\n");
        }
        while (1)
        {
            int flag = 0;
            printf("Nhập Đội Khách: ");
            fflush(stdin);
            scanf("%[^\n]s", maDoiKhach);
            for (int i = 0; i < count; i++)
            {
                if (strcmp(maDoiKhach, teams[i].code) == 0)
                {
                    lich.doiKhach = teams[i];
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
            printf("Đội bóng không tồn tại\n");
        }

        printf("Nhập ngày thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", lich.ngayThiDau);
        fflush(stdin);
        printf("Nhập giờ thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", lich.gioThiDau);
        fflush(stdin);
        printf("Nhập sân thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", lich.sanThiDau);
        fflush(stdin);
        lichs[countLich] = lich;
        countLich++;
        printf("Bạn có muốn tiếp tục tạo lịch thi đấu? (Y/N): ");
        fflush(stdin);
        scanf("%c", &yn);

    } while (yn != 'n' && yn != 'N');
}
void ketQua()
{
    int index1;
    char yn1;
    int ketQua1;
    do
    {
        struct Lich lich;
        printf("Nhập mã trận: ");

        do
        {
            fflush(stdin);
            scanf("%[^\n]s", lich.maTran);
            index1 = -1;

            for (int i = 0; i < count; i++)
            {

                if (strcmp(lich.maTran, lichs[i].maTran) == 0)
                {
                    index1 = i;
                    break;
                }
            }

            if (index1 == -1)
            {
                printf("Mã đội không tồn tại, mời bạn nhập lại: ");
            }
        } while (index1 == -1);

        char kq;
        struct ResultManagement result;

        printf("Nhập kết quả đội 1: ");
        fflush(stdin);
        scanf("%d", &result.ketQuaDoi1);
        fflush(stdin);
        printf("Nhập kết quả đội 2: ");
        fflush(stdin);
        scanf("%d", &result.ketQuaDoi2);
        fflush(stdin);

        printf("Bạn có muốn cập nhật? (Y/N): ");
        scanf("%c", &kq);

        if (kq == 'y' || kq == 'Y')
        {
            lichs[index1].ketQuaDoiNha = result.ketQuaDoi1;
            lichs[index1].ketQuaDoiKhach = result.ketQuaDoi2;
            printf("Thông tin đã được cập nhật!\n");
        }
        else
        {
            printf("Thông tin không được cập nhật!\n");
        }

        printf("Bạn muốn tiếp tục?(Y/N)");
        fflush(stdin);
        scanf("%c", &yn1);

        while (yn1 != 'y' && yn1 != 'Y' && yn1 != 'n' && yn1 != 'N')
        {
            printf("Bạn nhập sai, mời nhập lại: ");
            fflush(stdin);
            scanf("%c", &yn1);
        }
    } while (yn1 != 'n' && yn1 != 'N');

    printf("------------Kết quả thi đấu------------\n");
    printf("-----------------------------\n");
    printf("| %s | %s |\n", "Kết quả đội 1", "Kết quả đội 2");
    printf("-----------------------------\n");
     for (int j = 0; j < countLich; j++)
    {
        printf("| %-11d | %-10d |\n", lichs[j].ketQuaDoiNha, lichs[j].ketQuaDoiKhach);
        printf("|------------------------|\n");
        printf("=========================\n");
    }
}
void thongKe()
{
}