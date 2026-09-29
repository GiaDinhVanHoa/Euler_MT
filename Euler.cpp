#include <iostream>
using namespace std;

class DoThi
{
private:
    int soDinh;      // Số đỉnh của đồ thị
    int a[100][100]; // Ma trận kề lưu đồ thị 

    // Hàm đếm bậc của 1 đỉnh u
    int demBacMotDinh(int u)
    {
        int bac = 0;
        for (int v = 0; v < soDinh; v++)
        {
            if (a[u][v] == 1)
            {
                bac++;
            }
        }
        return bac;
    }

public:
    // Khởi tạo đồ thị với n đỉnh
    DoThi(int soDinh)
    {
        this->soDinh = soDinh;
        for (int i = 0; i < soDinh; i++)
        {
            for (int j = 0; j < soDinh; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    // Thêm cạnh nối giữa đỉnh u và đỉnh v
    void themCanh(int u, int v)
    {
        a[u][v] = 1;
        a[v][u] = 1; // Đồ thị vô hướng
    }

    // Kiểm tra loại euler
    int kiemTraEuler()
    {
        int soDinhBacLe = 0;
        for (int i = 0; i < soDinh; i++)
        {
            if (demBacMotDinh(i) % 2 != 0)
            {
                soDinhBacLe++;
            }
        }

        if (soDinhBacLe == 0)
            return 2; // Chu trình Euler
        if (soDinhBacLe == 2)
            return 1; // Đường đi Euler
        return 0;     // Không phải Euler
    }

    // In kết quả 
    void inKetQuaEuler()
    {
        int loai = kiemTraEuler();
        if (loai == 0)
        {
            cout << "Loai do thi: khong phai euler\n";
            cout << "Ket luan: Khong co duong di hay chu trinh Euler.\n";
            return;
        }
        else if (loai == 1)
        {
            cout << "Loai do thi: nua euler\n";
            cout << "Ket luan: Co duong di euler\n";
        }
        else if (loai == 2)
        {
            cout << "Loai do thi: do thi euler\n";
            cout << "Ket luan: Co chu trinh euler\n";
        }

        //tìm đỉnh xuất phát
        int u = 0;
        if (loai == 1)
        { // Nếu là đường đi Euler, xuất phát từ đỉnh bậc lẻ
            for (int i = 0; i < soDinh; i++)
            {
                if (demBacMotDinh(i) % 2 != 0)
                {
                    u = i;
                    break;
                }
            }
        }

        //Tạo ma trận tạm để đi qua đâu thì xóa cạnh đó
        int temp[100][100];
        for (int i = 0; i < soDinh; i++)
        {
            for (int j = 0; j < soDinh; j++)
            {
                temp[i][j] = a[i][j];
            }
        }

        // in các đỉnh
        cout << "Thu tu cac dinh: " << u;

        while (true)
        {
            int v = -1;
            // Tìm đỉnh v kề với u còn đường đi
            for (int i = 0; i < soDinh; i++)
            {
                if (temp[u][i] == 1)
                {
                    v = i;
                    break;
                }
            }

            // Nếu không còn cạnh nào đi tiếp thì dừng
            if (v == -1)
                break;

            // In đỉnh v ra màn hình
            cout << " -> " << v;

            // Xóa cạnh u - v đã đi qua
            temp[u][v] = 0;
            temp[v][u] = 0;

            // Chuyển sang đỉnh tiếp theo
            u = v;
        }
        cout << "\n";
    }
};

int main()
{
    cout << "Bai 1:\n";
    DoThi dt1(4);
    dt1.themCanh(0, 1);
    dt1.themCanh(1, 2);
    dt1.themCanh(2, 3);
    dt1.themCanh(3, 0);
    dt1.inKetQuaEuler();
    cout << "\n";

    cout << "Bai 2:\n";
    DoThi dt2(4);
    dt2.themCanh(0, 1);
    dt2.themCanh(1, 2);
    dt2.themCanh(2, 3);
    dt2.themCanh(3, 0);
    dt2.themCanh(0, 2); 
    dt2.inKetQuaEuler();
    cout << "\n";

    cout << "Bai 3:\n";
    DoThi dt3(4);
    dt2.themCanh(0, 3);
    dt2.themCanh(1, 2);
    dt2.themCanh(2, 3);
    dt2.themCanh(3, 1);
    dt2.themCanh(0, 2); 
    dt2.inKetQuaEuler();

    return 0;
}
