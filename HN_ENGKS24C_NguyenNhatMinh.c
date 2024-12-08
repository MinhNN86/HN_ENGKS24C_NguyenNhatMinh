#include <stdio.h>
int main(){
    int mang[100];
    int nguoiDungNhap;
    int check = 0;
    int checkSapXep = 0;
    while(1){
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cua mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong cac so nguyen to co trong mang\n");
        printf("5. Tim gia tri lon thu hai trong mang\n"); 
        printf("6. Tim gia tri nho thu hai trong mang\n");
        printf("7. Them mot phan tu vao trong mang\n");
        printf("8. Xoa phan tu trong mang\n");
        printf("9. Sap xep mang theo tang dan\n"); 
        printf("10. Sap xep mang theo thu tu giam dan\n");
        printf("11. Tim phan tu co trong mang\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n"); //
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n"); //
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &nguoiDungNhap);
        switch(nguoiDungNhap){
            case 1: //Nhap so phan tu va gia tri cua mang
                check = 1;
                int soPhanTu;
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &soPhanTu);
                if(soPhanTu < 0 || soPhanTu > 100){
                    printf("so phan tu khong hop le");
                    break;
                }
                for(int i = 0; i < soPhanTu; i++){
                    printf("mang[%d]= ", i);
                    scanf("%d", &mang[i]);
                }
                break;
            
            case 2: //In ra gia tri cac phan tu trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                for(int i = 0; i < soPhanTu; i++){
                    printf("mang[%d]= %d\n", i, mang[i]);
                }
                break;
            
            case 3: // Dem so luong so hoan hao
                if (check == 0) {
                    printf("chua nhap mang");
                    break;
                }
                int soLuongSoHoanHao = 0;
                int tong; 
                printf("cac so hoan hao la: ");
                for (int i = 0; i < soPhanTu; i++) {
                    tong = 0; 
                    if (mang[i] > 0) { 
                        for (int j = 1; j <= mang[i] / 2; j++) { 
                            if (mang[i] % j == 0) {
                                tong += j;
                            }
                        }
                        if (tong == mang[i]) { 
                            printf("%d ", mang[i]); 
                            soLuongSoHoanHao++;
                        }
                    }
                }
                if (soLuongSoHoanHao == 0) {
                    printf("Khong co so hoan hao\n");
                } else {
                    printf("\nSo luong so hoan hao trong mang la: %d", soLuongSoHoanHao);
                }
                break;

            case 4: //Dem so luong cac so nguyen to co trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int checkSoNguyenTo;
                int soLuongSoNguyenTo = 0;
                printf("cac so nguyen to trong mang la: ");
                for(int i = 0; i < soPhanTu; i++){
                    checkSoNguyenTo = 1;
                    if(mang[i] < 2){
                        checkSoNguyenTo = 0;
                    } else {
                        for(int j = 2; j < mang[i]; j++){
                            if(mang[i] % j == 0){
                                checkSoNguyenTo = 0;
                            }
                        }
                    }
                    if(checkSoNguyenTo == 1){
                        soLuongSoNguyenTo += 1;
                        printf("%d ", mang[i]);
                    }
                }
                printf("\nso luong cac so nguyen to trong mang la: ");
                printf("%d ", soLuongSoNguyenTo);
                
                break;
            
            case 5: // Tim gia tri lon thu hai trong mang
                if (check == 0) {
                    printf("chua nhap mang");
                    break;
                }
                if (soPhanTu < 2) {
                    printf("mang phai co it nhat hai phan tu.");
                    break;
                }

                int max1 = mang[0], max2 = -1;
                for (int i = 1; i < soPhanTu; i++) {
                    if (mang[i] > max1) {
                        max2 = max1; 
                        max1 = mang[i]; 
                    } else if (mang[i] > max2 && mang[i] < max1) {
                        max2 = mang[i]; 
                    }
                }

                if (max2 == -1) {
                    printf("Mang khong co gia tri lon thu hai.\n");
                } else {
                    printf("Phan tu lon thu hai la: %d\n", max2);
                }
                break;

            case 6: // Tim gia tri nho thu hai trong mang
                if (check == 0) {
                    printf("chua nhap mang");
                    break;
                }
                if (soPhanTu < 2) {
                    printf("mang phai co it nhat hai phan tu.");
                    break;
                }
                int mangMin[100];
                int dem = soPhanTu;  
                for (int i = 0; i < soPhanTu; i++) {
                    mangMin[i] = mang[i];
                }
                int min_idx = 0;
                for (int i = 1; i < dem; i++) {
                    if (mangMin[min_idx] > mangMin[i]) {
                        min_idx = i;
                    }
                }
                for (int i = min_idx; i < dem - 1; i++) {
                    mangMin[i] = mangMin[i + 1];
                }
                dem--;
                min_idx = 0;
                for (int i = 1; i < dem; i++) {
                    if (mangMin[min_idx] > mangMin[i]) {
                        min_idx = i;
                    }
                }

                printf("Phan tu be thu hai la: %d\n", mangMin[min_idx]);
                break;

            case 7: //Them mot phan tu vao trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int i;
                int viTriThem, gtriThem;
                printf("vi tri muon them trong mang: ");
                scanf("%d", &viTriThem);
                if(viTriThem < 0 || viTriThem > soPhanTu){
                    printf("vi tri them khong hop le");
                    break;
                }
                printf("gia tri them vao trong mang: ");
                scanf("%d", &gtriThem);
                for(int i = soPhanTu; i >= 0; i--){
                    mang[i + 1] = mang[i];
                }
                soPhanTu++;
                mang[i + 1] = gtriThem;
                printf("da them phan tu vao trong mang");
                break;
            
            case 8: //Xoa phan tu trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int viTriXoa;
                printf("nhap vi tri xoa cua mang");
                scanf("%d", &viTriXoa);
                if(viTriXoa < 0 || viTriXoa >= soPhanTu){
                    printf("vi tri xoa khong hop le");
                    break;
                }
                for(int i = viTriXoa; i < soPhanTu; i++){
                    mang[i] = mang[i + 1];
                }
                soPhanTu--;
                printf("da xoa phan tu trong mang");
                break;

            case 9: //Sap xep mang tang dan (Insertion sort)
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                checkSapXep = 1;
                for(int i = 1; i < soPhanTu; i++){
                    int key = mang[i];
                    int j = i - 1; 
                    for (j; j >= 0 && key < mang[j]; j--){
                        mang[j + 1] = mang[j];
                    }
                    mang[j + 1] = key;
                }
                printf("da sap xep");
                break;

            case 10: //Sap xep mang theo thu tu giam dan (Insertion sort)
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                checkSapXep = 1;
                for(int i = 1; i < soPhanTu; i++){
                    int key = mang[i];
                    int j = i - 1;
                    for(j; j >= 0 && key > mang[j]; j--){
                        mang[j + 1] = mang[j];
                    }
                    mang[j + 1] = key;
                }
                printf("da sap xep");
                break;
            
            case 11: //Tim phan tu co trong mang
                if (check == 0) {
                    printf("chua nhap mang");
                    break;
                }
                if (checkSapXep == 0) {
                    printf("chua sap xep mang");
                    break;
                }
                int start = 0;
                int end = soPhanTu - 1;
                int mid;
                int searchValue;
                printf("nhap phan tu can tim trong mang: ");
                scanf("%d", &searchValue);
                while(start <= end){
                    mid = (start+end)/2;
                    if(mang[mid] == searchValue){
                        printf("vi tri phan tu trong mang do la %d", mid);
                        break;
                    } else if (mang[mid] < searchValue){
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                printf("khong tim thay phan tu trong mang");
                break;

            case 12: // Xoa phan tu trung lap va in phan tu doc nhat
                if (check == 0) {
                    printf("Chua nhap mang\n");
                    break;
                }
                int soPhanTuMoi = 0; 
                for (int i = 0; i < soPhanTu; i++) {
                    int trungLap = 0;
                    for (int j = 0; j < soPhanTuMoi; j++) {
                        if (mang[i] == mang[j]) {
                            trungLap = 1; 
                            break;
                        }
                    }
                    if (!trungLap) {
                        mang[soPhanTuMoi] = mang[i];
                        soPhanTuMoi++;
                    }
                }
                soPhanTu = soPhanTuMoi;

                printf("Mang sau khi xoa phan tu trung lap: ");
                for (int i = 0; i < soPhanTu; i++) {
                    printf("%d ", mang[i]);
                }
                printf("\n");
                break;

            case 13: // Sap xep va hien thi so chan dung truoc, so le dung sau
                if (check == 0) {
                    printf("Chua nhap mang\n");
                    break;
                }
                int mangChan[100], mangLe[100];
                int demChan = 0, demLe = 0;
                for (int i = 0; i < soPhanTu; i++) {
                    if (mang[i] % 2 == 0) {
                        mangChan[demChan++] = mang[i]; 
                    } else {
                        mangLe[demLe++] = mang[i];   
                    }
                }
                int viTri = 0;
                for (int i = 0; i < demChan; i++) {
                    mang[viTri++] = mangChan[i];
                }
                for (int i = 0; i < demLe; i++) {
                    mang[viTri++] = mangLe[i];
                }
                printf("Da sap xep");
                break;

            case 14: //Dao Nguoc Mang
                if (check == 0) {
                    printf("Chua nhap mang");
                    break;
                }
                int bienNho;
                for (int i = 0; i < soPhanTu / 2; i++){
                    bienNho = mang[i];
                    mang[i] = mang[soPhanTu - 1 - i];
                    mang[soPhanTu - 1 - i] = bienNho;
                }
                    
                printf("da dao nguoc mang");
                break;

            case 15: // thoat
                return 0;
            
            default:
                printf("nhap sai ky tu vui long nhap lai");
        }   

    }
}