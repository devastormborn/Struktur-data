#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Load.h"

void ScheduleManual(Schedule *jadwal){
    //ALGORITMA UNTUK MENERIMA DAN MEMVALIDASI INPUT
    char prak[8];
    char romb[3],in[2];
    int m,c,i,bol,valm,j,k,vald,vald1,vald2,vald3,valdc;
    char h[7];
    char r[5];
    char *ch,*cx1,*cx2,*cx3,*cx4;
    do{
        for(i=0;i<=3;i++){
            romb[i]='\0';
        }
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        gets(prak);
        if(strcmp (prak, "EL2208") == 0){
            do{
                printf("Rombongan (A1,A2,A3,B1,B2,B3 atau C):");
                gets(romb);
            }while(strcmp (romb, "A1") != 0&&
                   strcmp (romb, "A2") != 0&&
                   strcmp (romb, "A3") != 0&&
                   strcmp (romb, "B1") != 0&&
                   strcmp (romb, "B2") != 0&&
                   strcmp (romb, "B3") != 0&&
                   strcmp (romb, "C") != 0&&
                   strcmp (romb, "A") != 0&&
                   strcmp (romb, "B") != 0);
            vald=0;
            vald1=0;
            vald2=0;
            vald3=0;
            valdc=0;
            for(k=0;k<=9;k++){
                for(j=0;j<=4;j++){
                    for(i=0;i<=3;i++){
                        cx3=jadwal->week[k].day[j].lab[i].group.praktikum;
                        cx4=jadwal->week[k].day[j].lab[i].group.rombongan;
                        if(jadwal->week[k].day[j].lab[i].group.praktikum==NULL){
                        }else if(cx3[5]=='8' && cx4[0]==romb[0] && cx4[1]==romb[1]){
                            vald++;
                        }else if(cx3[5]=='8' && cx4[0]==romb[0] && romb[1]=='\0'){
                            if(cx4[1]=='1'){
                                vald1++;
                            }else if(cx4[1]=='2'){
                                vald2++;
                            }else if(cx4[1]=='3'){
                                vald3++;
                            }else{
                                valdc++;
                            }
                        }
                    }
                }
            }
            if(vald <= 8 && vald1<=8 && vald2<=8 && vald3<=8 && valdc<=8){
                do{
                    printf("Minggu ke: ");
                    scanf("%d",&m);
                }while(m<3 || m>12);
                while((c=getchar())!= '\n' && c!=EOF);
                valm=0;
                for(j=0;j<=4;j++){
                    for(i=0;i<=3;i++){
                        cx1=jadwal->week[m-3].day[j].lab[i].group.praktikum;
                        cx2=jadwal->week[m-3].day[j].lab[i].group.rombongan;
                        if(jadwal->week[m-3].day[j].lab[i].group.praktikum==NULL){
                        }else if(cx1[5]=='8' && cx2[0]==romb[0] && cx2[1]==romb[1]){
                            valm++;
                        }else if(romb[1]=='\0' && cx1[5]=='8' && cx2[0]==romb[0]){
                            valm++;
                        }
                    }
                }
                if(valm==0){
                    do{
                        printf("Hari :");
                        gets(h);
                    }while(cekhari(h)== 99);
                    bol=0;
                    for(i=0;i<=2;i++){
                        ch=jadwal->week[m-3].day[cekhari(h)].lab[i].group.praktikum;
                        if(jadwal->week[m-3].day[cekhari(h)].lab[i].group.praktikum==NULL){
                        }else if(ch[5]=='5'){
                            bol=1;
                        }
                    }
                    if(strcmp (romb,"A")!= 0 && strcmp (romb, "B") != 0 && strcmp (romb, "C") != 0 ){
                        do{
                            printf("Ruangan :");
                            gets(r);
                        }while(ceklab(r)>4);
                        if(bol == 0){
                            jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum = malloc(strlen(prak)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum, prak);
                            jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan = malloc(strlen(romb)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan, romb);
                            jadwal->week[m-3].element=m;
                            jadwal->week[m-3].day[cekhari(h)].element =malloc(strlen(h)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].element, h);
                            jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element =malloc(strlen(r)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element, r);
                        }else{
                            printf("Terdapat Praktikum EL2205 pada hari ini\n");
                        }
                    }else if(strcmp (romb,"C")== 0){
                    do{
                        printf("Ruangan :");
                        gets(r);
                    }while(ceklab(r)!=3);
                        jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum = malloc(strlen(prak)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum, prak);
                        jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan = malloc(strlen(romb)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan, romb);
                        jadwal->week[m-3].element=m;
                        jadwal->week[m-3].day[cekhari(h)].element =malloc(strlen(h)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].element, h);
                        jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element =malloc(strlen(r)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element, r);
                    }else{
                        if(bol == 0){
                            for(i=1;i<=3;i++){
                                do{
                                    printf("Ruangan %d :",i);
                                    gets(r);
                                }while(ceklab(r)>=4);
                                if(i == 1){
                                    romb[1]='1';
                                }else if (i==2){
                                    romb[1]='2';
                                }else {
                                    romb[1]='3';
                                }
                                jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum = malloc(strlen(prak)+1);
                                strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum, prak);
                                jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan = malloc(strlen(romb)+1);
                                strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan, romb);
                                jadwal->week[m-3].element=m;
                                jadwal->week[m-3].day[cekhari(h)].element =malloc(strlen(h)+1);
                                strcpy(jadwal->week[m-3].day[cekhari(h)].element, h);
                                jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element =malloc(strlen(r)+1);
                                strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element, r);

                            }
                        }else{
                            printf("Terdapat Praktikum EL2205 pada hari ini\n");
                        }
                    }
                }else{
                    printf("Sudah terdapat praktikum rombongan ini pada minggu ini\n");
                }
            }else{
                printf("Terdapat rombongan yang telah menyelesaikan parktikum\n");
            }
        }else if(strcmp (prak, "EL2205") == 0){
            do{
                printf("Rombongan (A1,A2,B1,B2,C1, atau C2):");
                gets(romb);
            }while(strcmp (romb, "A1") != 0&&
                   strcmp (romb, "A2") != 0&&
                   strcmp (romb, "A3") != 0&&
                   strcmp (romb, "B1") != 0&&
                   strcmp (romb, "B2") != 0&&
                   strcmp (romb, "C1") != 0&&
                   strcmp (romb, "C2") != 0&&
                   strcmp (romb, "A") != 0&&
                   strcmp (romb, "B") != 0&&
                   strcmp (romb, "C") != 0);
            vald=0;
            vald1=0;
            vald2=0;
            valdc=0;
            for(k=0;k<=9;k++){
                for(j=0;j<=4;j++){
                    for(i=0;i<=3;i++){
                        cx3=jadwal->week[k].day[j].lab[i].group.praktikum;
                        cx4=jadwal->week[k].day[j].lab[i].group.rombongan;
                        if(jadwal->week[k].day[j].lab[i].group.praktikum==NULL){
                        }else if(cx3[5]=='5' && cx4[0]==romb[0] && cx4[1]==romb[1]){
                            vald++;
                        }else if(cx3[5]=='5' && cx4[0]==romb[0] && romb[1]=='\0'){
                            if(cx4[1]=='1'){
                                vald1++;
                            }else if(cx4[1]=='2'){
                                vald2++;
                            }else{
                                valdc++;
                            }
                        }
                    }
                }
            }
            if(vald <= 6 && vald1<=6 && vald2<=6 && valdc<=6){
                do{
                    printf("Minggu ke: ");
                    scanf("%d",&m);
                }while(m<3 || m>12);
                while((c=getchar())!= '\n' && c!=EOF);
                valm=0;
                for(j=0;j<=4;j++){
                    for(i=0;i<=3;i++){
                        cx1=jadwal->week[m-3].day[j].lab[i].group.praktikum;
                        cx2=jadwal->week[m-3].day[j].lab[i].group.rombongan;
                        if(jadwal->week[m-3].day[j].lab[i].group.praktikum==NULL){
                        }else if(cx1[5]=='5' && cx2[0]==romb[0] && cx2[1]==romb[1]){
                            valm++;
                        }else if(romb[1]=='\0' && cx1[5]=='5' && cx2[0]==romb[0]){
                            valm++;
                        }
                    }
                }
                if(valm==0){
                do{
                    printf("Hari :");
                    gets(h);
                }while(cekhari(h)==99);
                bol=0;
                for(i=0;i<=2;i++){
                    ch=jadwal->week[m-3].day[cekhari(h)].lab[i].group.praktikum;
                    if(jadwal->week[m-3].day[cekhari(h)].lab[i].group.praktikum==NULL){
                    }else if(ch[5]=='8'){
                        bol=1;
                    }
                }
                if(strcmp (romb,"A")!= 0 && strcmp (romb, "B") != 0 && strcmp (romb, "C") != 0 ){
                    do{
                        printf("Ruangan :");
                        gets(r);
                    }while(ceklab(r)>=3);
                    if(bol == 0){
                        jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum = malloc(strlen(prak)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum, prak);
                        jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan = malloc(strlen(romb)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan, romb);
                        jadwal->week[m-3].element=m;
                        jadwal->week[m-3].day[cekhari(h)].element =malloc(strlen(h)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].element, h);
                        jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element =malloc(strlen(r)+1);
                        strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element, r);
                    }else{
                        printf("Terdapat Praktikum EL2208 pada Hari ini\n");
                    }
                }else{
                    if(bol==0){
                        for(i=1;i<=2;i++){
                            do{
                                printf("Ruangan %d :",i);
                                gets(r);
                            }while(ceklab(r)>=3);
                            if(i == 1){
                                romb[1]='1';
                            }else{
                                romb[1]='2';
                            }
                            jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum = malloc(strlen(prak)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum, prak);
                            jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan = malloc(strlen(romb)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan, romb);
                            jadwal->week[m-3].element=m;
                            jadwal->week[m-3].day[cekhari(h)].element =malloc(strlen(h)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].element, h);
                            jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element =malloc(strlen(r)+1);
                            strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element, r);
                        }
                    }else{
                        printf("Terdapat Praktikum EL2208 pada Hari ini");
                    }
                }
            }else{
                printf("Sudah terdapat praktikum rombongan ini pada minggu ini\n");
            }
        }else{
            printf("Terdapat rombongan yang telah menyelesaikan parktikum\n");
        }
    }else if(strcmp (prak, "EL2200") == 0){
        do{
            printf("Rombongan (A atau B):");
            gets(romb);
        }while(strcmp (romb, "A") != 0 && strcmp (romb, "B") != 0);
        vald=0;
        for(k=0;k<=9;k++){
            for(j=0;j<=4;j++){
                for(i=0;i<=3;i++){
                    cx3=jadwal->week[k].day[j].lab[i].group.praktikum;
                    cx4=jadwal->week[k].day[j].lab[i].group.rombongan;
                    if(jadwal->week[k].day[j].lab[i].group.praktikum==NULL){
                    }else if(cx3[5]=='0' && cx4[0]==romb[0]){
                        vald++;
                    }
                }
            }
        }
        if(vald<=4){
            do{
                printf("Minggu ke: ");
                scanf("%d",&m);
            }while(m<3 || m>12);
            while((c=getchar())!= '\n' && c!=EOF);
            valm=0;
            for(j=0;j<=4;j++){
                for(i=0;i<=3;i++){
                    cx1=jadwal->week[m-3].day[j].lab[i].group.praktikum;
                    cx2=jadwal->week[m-3].day[j].lab[i].group.rombongan;
                    if(jadwal->week[m-3].day[j].lab[i].group.praktikum==NULL){
                    }else if(cx1[5]=='0' && cx2[0]==romb[0] && cx2[1]==romb[1]){
                        valm++;
                    }else if(romb[1]=='\0' && cx1[5]=='0' && cx2[0]==romb[0]){
                        valm++;
                    }
                }
            }
            if(valm==0){
                do{
                    printf("Hari:");
                    gets(h);
                }while(cekhari(h)!= 1 && cekhari(h)!=3);
                do{
                    printf("Ruangan :");
                    gets(r);
                }while(ceklab(r)>=3);
                    jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum = malloc(strlen(prak)+1);
                    strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.praktikum, prak);
                    jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan = malloc(strlen(romb)+1);
                    strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].group.rombongan, romb);
                    jadwal->week[m-3].element=m;
                    jadwal->week[m-3].day[cekhari(h)].element =malloc(strlen(h)+1);
                    strcpy(jadwal->week[m-3].day[cekhari(h)].element, h);
                    jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element =malloc(strlen(r)+1);
                    strcpy(jadwal->week[m-3].day[cekhari(h)].lab[ceklab(r)].element, r);
            }else{
                printf("Sudah terdapat praktikum rombongan ini pada minggu ini\n");
            }
        }else{
            printf("Terdapat rombongan yang telah menyelesaikan parktikum\n");
        }
    }else if((strcmp (prak, "Q") == 0)||(strcmp (prak, "q") == 0)){
}else{
    printf("Input Tidak Sesuai");
}
    printf("\n");
}while((strcmp (prak, "Q") != 0)&&(strcmp (prak, "q") != 0));

}

int cekhari(char c[]){
    //MENGUBAH HARI KE INTEGER
    if(strcmp(c,"Senin") == 0){
        return 0;
    }else if(strcmp(c,"Selasa") == 0){
        return 1;
    }else if(strcmp(c,"Rabu") == 0){
        return 2;
    }else if(strcmp(c,"Kamis") == 0){
        return 3;
    }else if(strcmp(c,"Jumat") == 0){
        return 4;
    }else{
        return 99;
    }
}

int ceklab(char r[]){
    //MENGUBAH RUANGAN KE INT
    if(strcmp(r,"LAB1") == 0){
        return 0;
    }else if(strcmp(r,"LAB2") == 0){
        return 1;
    }else if(strcmp(r,"LAB3") == 0){
        return 2;
    }else if(strcmp(r,"LSS") == 0){
        return 3;
    }else{
        return 99;
    }
}

