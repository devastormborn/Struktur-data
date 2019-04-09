void printstrip(){
    //Mencetak strip setiap dipanggil
    int i;
    printf("|");
    for(i=1;i<=67;i++){
        printf("-");
    }
    printf("|\n");
}
void TampilkanJadwal(Schedule jadwal){
    //Header atas
    int i,j,k,y,z,L;
    int x=100;
    char h[5][10]={"Senin ","Selasa","Rabu  ","Kamis ","Jumat "};
    printstrip();
    printf("|Ruang Praktikum |    LAB1    |    LAB2    |    LAB3    |    LSS    |\n");
    printf("|----------------|------------|------------|------------|-----------|\n");
    printf("|Minggu |  Hari  |------------|------------|------------|-----------|\n");
    printf("|-------|--------|------------|------------|------------|-----------|\n");
    //Mendisplaykan kan jadwal yang tidak NULL serta menyesuaikan agar tabel tidak berubah
    for(i=0;i<=6;i++){
            for(j=0;j<5;j++){
                printf("|   %d   | %s |",i+3,h+j);
                for(k=0;k<=2;k++){
                    if(checkarr(jadwal,i,j,k) == 1){
                        printf(" %s-%s  |",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
                    }else if(checkarr(jadwal,i,j,k) == 2){
                        printf(" %s-%s   |",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
                    }else{
                        printf("            |");
                    }
                }
            k=3;
            if(checkarr(jadwal,i,j,k) == 1){
                printf(" %s-%s |\n",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
            }else if(checkarr(jadwal,i,j,k) == 2){
                printf(" %s-%s  |\n",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
            }else{
                printf("           |\n");
            }}
        printstrip();
    }

    for(i=7;i<=9;i++){
            for(j=0;j<5;j++){
                printf("|   %d  | %s |",i+3,h+j);
                for(k=0;k<=2;k++){
                    if(checkarr(jadwal,i,j,k) == 1){
                        printf(" %s-%s  |",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
                    }else if(checkarr(jadwal,i,j,k) == 2){
                        printf(" %s-%s   |",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
                    }else{
                        printf("            |");
                    }
                }
                k=3;
                if(checkarr(jadwal,i,j,k) == 1){
                    printf(" %s-%s |\n",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
                }else if(checkarr(jadwal,i,j,k) == 2){
                    printf(" %s-%s  |\n",jadwal.week[i].day[j].lab[k].group.praktikum,jadwal.week[i].day[j].lab[k].group.rombongan);
                }else{
                    printf("           |\n");
                }
            }
            printstrip();
    }
}

int checkarr(Schedule jadwal,int a,int b,int d){
    //fungsi ini akan mengeluarkan int 0 jika jadwal hari itu NULL, int 1 jika jadwal hari itu jika hari tersebut memiliki jadwal dengan rombongan 2 char, int 2 jika rombongan hari itu 1 char
    char *c;
    c=jadwal.week[a].day[b].lab[d].group.rombongan;
    if(jadwal.week[a].day[b].lab[d].group.rombongan == NULL){
        return 0;
    }
    if(c[0] == 'B' && c[1]== '1'||
       c[0] == 'B' && c[1]== '2'||
       c[0] == 'B' && c[1]== '3'||
       c[0] == 'A' && c[1]== '1'||
       c[0] == 'A' && c[1]== '2'||
       c[0] == 'A' && c[1]== '3'||
       c[0] == 'C' && c[1]== '1'||
       c[0] == 'C' && c[1]== '2'){
        return 1;
    }else{
        return 2;
    }
}

/*//Check pake ini
Schedule jadwal;
int main()
{   ScheduleManual(&jadwal);
    TampilkanJadwal(jadwal);
    return 0;
}*/
