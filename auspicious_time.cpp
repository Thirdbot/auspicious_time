#include <stdio.h>

struct DOB
{
    int date;
    int month;
    int time;
};

int main(){
    struct DOB dob;
    printf("Enter date:");
    scanf("%d",&dob.date);
    printf("Enter month:");
    scanf("%d",&dob.month);
    printf("Enter time:");
    scanf("%d",&dob.time);

    char table[][12] = {"Capricorn","Aquarius ","Pisces ","Aries  ","Taurus  ","Gemini ","Cancer ","Leo ","Virgo ","Libra ","Scorpio ","Sagittarius"};
    int datetime[12] = {5,7,9,11,13,15,17,19,21,23,1,3};
    int date_adj[12] = {15,13,14,13,14,14,15,17,17,17,16,16};

    for (int j =0;j<12;j++){
            int validation = (dob.time) % datetime[j];
            /*
            printf("\nvalid: %d",validation);
            printf("\ndatetime: %d",datetime[j]);
            printf("\nmonth-1: %d",dob.month-1);
            printf("\ntime: %d",dob.time);
            printf("\nj: %d",j);
            printf("\nFinding:%d",((dob.month-1)+j)%12);
            */
           if ((dob.date < date_adj[dob.month-1])){
                dob.month -= 1;
           }
            if ((dob.time >= datetime[j] && dob.time < datetime[j+1]) && ((validation == 0) || validation < datetime[j+1])){
                printf("\nMonth:%s",table[((dob.month-1)+j)%12]);
                break;
            }
        }

    return 0;
}